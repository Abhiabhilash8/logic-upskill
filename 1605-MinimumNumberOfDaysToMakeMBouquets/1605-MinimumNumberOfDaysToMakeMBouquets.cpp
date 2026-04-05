// Last updated: 4/5/2026, 11:44:20 AM
class Solution {
public:
    bool help(int days,int m,int k,vector<int>&bloomDay){
        int ans=0,count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                count++;
                continue;
            }
            else{
                ans+=count/k;
                count=0;
            }
        }
        ans+=count/k;
        if(ans>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long temp=m*1ll*k*1ll;
        if(bloomDay.size()<temp) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(help(mid,m,k,bloomDay))   high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};