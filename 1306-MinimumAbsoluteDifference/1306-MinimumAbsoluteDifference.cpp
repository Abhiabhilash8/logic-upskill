// Last updated: 4/5/2026, 11:44:33 AM
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int dif=INT_MAX;
        for(int i=1;i<n;i++) dif=min(dif,arr[i]-arr[i-1]);
        vector<vector<int>>v;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==dif){
                v.push_back({arr[i-1],arr[i]});
            }
        }

        return v;
    }
};