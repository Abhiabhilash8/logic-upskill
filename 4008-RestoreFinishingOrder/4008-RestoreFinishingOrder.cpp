// Last updated: 4/5/2026, 11:42:12 AM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>res;
        int temp[101]={0};
        for(int i=0;i<friends.size();i++){
            temp[friends[i]]=-1;
        }

        
        for(int i=0;i<order.size();i++){
            if(temp[order[i]]==-1) res.push_back(order[i]);
        }

        return res;
        
    }
};