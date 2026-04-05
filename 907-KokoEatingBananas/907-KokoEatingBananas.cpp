// Last updated: 4/5/2026, 11:45:03 AM
class Solution {
public:
    long long int gethours(int k,vector<int>&piles){
        long long int ans=0;
        for(int i=0;i<piles.size();i++){
           ans += (piles[i] + k - 1) / k;
        }
        return ans;
    }



    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high = *max_element(piles.begin() , piles.end()),mid;
        long long hours;

        while(low<=high){
            mid=low+(high-low)/2;
            hours=gethours(mid,piles);
            if(hours<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};