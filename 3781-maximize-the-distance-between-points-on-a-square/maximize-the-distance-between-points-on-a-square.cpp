class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& pts, int k) {

        auto getPos = [&](vector<int>& p) -> long long {
            long long x = p[0], y = p[1];
            if (y == 0) return x;
            if (x == side) return side + y;
            if (y == side) return 3LL * side - x;
            return 4LL * side - y;
        };

        vector<long long> pos;
        for (auto &p : pts) pos.push_back(getPos(p));
        sort(pos.begin(), pos.end());

        int n = pos.size();

        auto isInvalid = [&](long long dist) {
            for (int i = 0; i < n; i++) {
                int curr = i, count = 1;

                while (count < k) {
                    long long nextPos = pos[curr] + dist;
                    int idx = lower_bound(pos.begin(), pos.end(), nextPos) - pos.begin();

                    if (idx == n) break;

                    curr = idx;
                    count++;

                    if (dist + pos[curr] > pos[i] + 4LL * side) {
                        count = 0;
                        break;
                    }
                }

                if (count == k) return false;
            }
            return true;
        };

        long long left = 0, right = side, result = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (!isInvalid(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (int)result;
    }
};