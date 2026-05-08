constexpr int MAX_VAL = 1e6 + 1;
constexpr int MAX_N = 1e5 + 1;

bitset<MAX_VAL> isComposite;

vector<int> primeNumbers;
vector<int> primePositions[80000];

int primeIndex[MAX_VAL];
int totalPrimes = 0;

void buildSieve() {
    if (isComposite[0]) return;

    memset(primeIndex, -1, sizeof(primeIndex));

    isComposite[0] = isComposite[1] = 1;

    for (int i = 2; i * i < MAX_VAL; i++) {
        if (isComposite[i]) continue;

        for (int j = i * i; j < MAX_VAL; j += i) {
            isComposite[j] = 1;
        }
    }

    for (int i = 2; i < MAX_VAL; i++) {
        if (!isComposite[i]) {
            primeIndex[i] = totalPrimes++;
            primeNumbers.push_back(i);
        }
    }
}

class Solution {
public:

    static void clearUsedPrimeLists(bitset<80000>& usedPrimes, int highestPrimeIdx) {
        for (int i = 0; i <= highestPrimeIdx; i++) {
            if (usedPrimes[i]) {
                primePositions[i].clear();
            }
        }
    }

    static int minJumps(vector<int>& nums) {

        buildSieve();

        int n = nums.size();

        bitset<80000> usedPrimes;
        int highestPrimeIdx = -1;

        for (int i = 0; i < n; i++) {

            int value = nums[i];

            if (!isComposite[value]) {

                int idx = primeIndex[value];

                primePositions[idx].push_back(i);

                usedPrimes[idx] = 1;

                highestPrimeIdx = max(highestPrimeIdx, idx);
            }
        }

        queue<int> bfsQueue;

        bitset<MAX_N> visited;

        bfsQueue.push(n - 1);

        visited[n - 1] = 1;

        int jumps = 0;

        while (!bfsQueue.empty()) {

            int levelSize = bfsQueue.size();

            while (levelSize--) {

                int currentIndex = bfsQueue.front();
                bfsQueue.pop();

                if (currentIndex == 0) {

                    clearUsedPrimeLists(usedPrimes, highestPrimeIdx);

                    return jumps;
                }

                if (currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {

                    visited[currentIndex - 1] = 1;

                    bfsQueue.push(currentIndex - 1);
                }

                if (currentIndex + 1 < n && !visited[currentIndex + 1]) {

                    visited[currentIndex + 1] = 1;

                    bfsQueue.push(currentIndex + 1);
                }

                int value = nums[currentIndex];

                for (int i = 0; i < totalPrimes && value > 1; i++) {

                    int prime = primeNumbers[i];

                    if (!isComposite[value]) {
                        prime = value;
                    }

                    if (value % prime == 0) {

                        int idx = primeIndex[prime];

                        while (value % prime == 0) {
                            value /= prime;
                        }

                        for (int nextIndex : primePositions[idx]) {

                            if (!visited[nextIndex]) {

                                visited[nextIndex] = 1;

                                bfsQueue.push(nextIndex);
                            }
                        }

                        usedPrimes[idx] = 0;

                        primePositions[idx].clear();
                    }
                }
            }

            jumps++;
        }

        return -1;
    }
};

auto fastIO = []() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    return 0;

}();