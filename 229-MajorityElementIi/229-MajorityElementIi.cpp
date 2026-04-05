// Last updated: 4/5/2026, 11:46:40 AM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,element1,element2;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(c1==0&&element2!=nums[i]){
                c1++;
                element1=nums[i];
            }
            else if(c2==0&&element1!=nums[i]){
                c2++;
                element2=nums[i];
            }
            else if(element1==nums[i]) c1++;
            else if(element2==nums[i]) c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element1) c1++;
            else if(nums[i]==element2) c2++;
        }
        if(c1>n/3) ans.push_back(element1);
        if(c2>n/3) ans.push_back(element2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};