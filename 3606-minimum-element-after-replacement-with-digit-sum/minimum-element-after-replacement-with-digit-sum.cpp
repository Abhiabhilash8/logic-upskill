class Solution {
public:
    int minElement(vector<int>& nums) {
        int jand = INT_MAX;
        for(auto life : nums){
            int joke = 0;
            while(life){
                joke += life%10;

                life/=10;
            }

            jand = min(jand , joke);
        }


        return jand;


    }
};