class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int a = 0;

        for(int i=0;i<nums1.size();i++){
            int b = upper_bound( nums2.begin() + i , nums2.end() , nums1[i] , greater<int>()) - nums2.begin() -1;
            if(b >= i && b < nums2.size()){
                a = max( a , b-i );
            }
        }

        return a;

    }
};