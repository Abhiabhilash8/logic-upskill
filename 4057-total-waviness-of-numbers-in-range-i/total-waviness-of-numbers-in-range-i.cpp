class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int w = 0;
        for(int i = num1; i<=num2; i++){
            vector<int>v;
            int k = i;
            while(k){
                v.push_back(k%10);
                k/=10;
            }
            for(int j = 1; j<v.size() - 1; j++){
                w += (v[j] > v[j-1] && v[j] > v[j+1]) || (v[j] < v[j-1] && v[j] < v[j+1]);
            }
        }


        return w;
    }
};