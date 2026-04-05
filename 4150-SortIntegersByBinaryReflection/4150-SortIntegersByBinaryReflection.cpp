// Last updated: 4/5/2026, 11:41:28 AM
class Solution {
public:
    int form(int n){
        vector<int>vec;
        int t=n;
        while(n){            
            vec.push_back(n%2);
            n/=2;
        }
        cout<<"\n";
        int ans=0;
        int p=0;
        for(int i=vec.size()-1;i>=0;i--){
            ans+=(vec[i]*pow(2,p));
            p++;
        }

        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>vec;
        vector<string>st;
        for(int i=0;i<nums.size();i++){
            int x=form(nums[i]);
            vec.push_back({x,i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[vec[i].second]);
        }
        return ans;
    }
};