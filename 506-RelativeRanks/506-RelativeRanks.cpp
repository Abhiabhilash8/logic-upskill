// Last updated: 4/5/2026, 11:45:47 AM
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(score.size());
        ans[pq.top().second]="Gold Medal";
        pq.pop();
        if(!pq.empty()){
            ans[pq.top().second]="Silver Medal";
            pq.pop();
        }
        if(!pq.empty()){
            ans[pq.top().second]="Bronze Medal";
            pq.pop();
        }
        int count=4;
        
        while(!pq.empty()){
            int ind=pq.top().second;
            int val=score[ind];
            pq.pop();
            ans[ind]=to_string(count++);
        }


        return ans;
    }
};