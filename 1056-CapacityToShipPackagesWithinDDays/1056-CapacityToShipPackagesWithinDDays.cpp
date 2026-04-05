// Last updated: 4/5/2026, 11:44:43 AM
class Solution {
public:
    int help(int capacity,vector<int>&weights){
        int days=0,temp=0;
        for(int i=0;i<weights.size();i++){
            if(temp+weights[i]>capacity) {
                days++;
                temp=weights[i];
            }
            else {
                
            temp+=weights[i];
            }
        }
        if(temp>0) days++;
        return days;
    }
    int sumof(vector<int>&weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=sumof(weights),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(help(mid,weights)<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};