// Last updated: 4/5/2026, 11:43:38 AM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<int>st;
        long long mx=pow(2,nums.size())-1;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=n-1,k=1;j>=0;j--,k*=2){
                if(nums[i][j]=='1') x|=k;
            }
            st.insert(x);
        }

        for(int i=0;i<=mx;i++){
            if(st.find(i)==st.end()){
                string ans="";
                while(i){
                    ans+=((i%2)+'0');
                    i/=2;
                }
                reverse(ans.begin(),ans.end());
                string temp="";
                while(temp.size()+ans.size()<n) temp+="0";
                ans=temp+ans;
                
                return ans;
            }
        }

        return "";
    }
};