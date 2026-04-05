// Last updated: 4/5/2026, 11:45:35 AM
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int  sum=0,j;
        double msum=INT_MIN;
        for(j=0;j<k;){
          sum+=nums[j++];  
        }
        j--;
        for(int i=0;j<nums.size()-1;){
            if(msum<sum)
                msum=sum;
            
                sum-=nums[i++];
                j++;
                sum+=nums[j];
            
        }
        if(msum<sum)
                msum=sum;
        return msum/k;
    }
};