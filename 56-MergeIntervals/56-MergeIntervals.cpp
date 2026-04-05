// Last updated: 4/5/2026, 11:48:31 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int si=0,ei=0;
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[ei][1]&&intervals[i][0]>=intervals[si][0]){
                if(intervals[i][1]>intervals[ei][1]) ei=i;
            }
            else{
                ans.push_back({intervals[si][0],intervals[ei][1]});
                si=i;
                ei=i;
            }
        }
         ans.push_back({intervals[si][0],intervals[ei][1]});
        return ans;
    }
};