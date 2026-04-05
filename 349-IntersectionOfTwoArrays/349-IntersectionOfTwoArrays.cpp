// Last updated: 4/5/2026, 11:46:12 AM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>result;
        for(int begin1=0,begin2=0;begin1<nums1.size()&&begin2<nums2.size();){
            if(nums1[begin1]==nums2[begin2]){
                result.push_back(nums1[begin1]);
                begin1++;
                begin2++;
            }
            else if(nums1[begin1]<nums2[begin2]){
                begin1++;
            }
            else
            begin2++;
            if(result.size()>1&&(result[result.size()-1]==result[result.size()-2]))
            result.pop_back();
        }
        return result;
    }
};