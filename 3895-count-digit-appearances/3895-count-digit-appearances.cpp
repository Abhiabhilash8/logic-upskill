class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int a=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]){
                if(nums[i]%10 == digit) a++;
                nums[i]/=10;
            }
        }

        return a;
    }
};