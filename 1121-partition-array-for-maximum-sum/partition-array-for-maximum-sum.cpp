class Solution {
public:

    vector<int>dp;

    int f(int i , vector<int>&arr , int k){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int mk = arr[i];
        int a = INT_MIN;
        for(int j = i; j < arr.size() && j < i + k; j++){
            mk = max(mk , arr[j]);

            a = max(a , (j-i+1)*mk + f(j+1 , arr,k));
        }

        return dp[i] = a;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size() , -1);
        return f(0 , arr , k);
    }
};