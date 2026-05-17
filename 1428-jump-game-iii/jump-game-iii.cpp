class Solution {
public:

    bool f(vector<int> &st, vector<int>&arr, int i){
        if(i<0 || i>=arr.size()) return 0;
        if(st[i] != -1) return st[i];
        if(arr[i] == 0) return 1;
        st[i] = 0;

        return st[i] = f(st,arr,i-arr[i]) || f(st,arr,i+arr[i]);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>st(n,-1);
        return f(st,arr,start);
    }
};