class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool>p(2050 , false);
        for(int i = 0; i<n; i++) for(int j = i; j<n; j++) p[nums[i] ^ nums[j]] = 1;
        int c = 0;
        for(int k = 0; k<2048; k++){
            for(int  z = 0; z<n; z++){
                if(p[nums[z] ^ k]){
                    c++;
                    break;
                }
            }
        }

        return c;
    }
};