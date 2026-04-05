// Last updated: 4/5/2026, 11:44:16 AM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low=0,high=arr.size()-1,mid;
        int missing;
        while(low<=high){
            mid=(low+high)/2;
            missing=arr[mid]-mid-1;
            if(missing>=k) high=mid-1;
            else low = mid+1;
        }
        return low+k;
    }
};