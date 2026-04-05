// Last updated: 4/5/2026, 11:40:58 AM
class Solution {
public:
    int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a % b);
}
    long long gcdSum(vector<int>& nums) {
        int mk=0;
        vector<long long>v;
        for(int i=0;i<nums.size();i++){
            mk=max(mk,nums[i]);
            v.push_back(gcd(nums[i],mk));
        }

        sort(v.begin(),v.end());
        long long s=0;
        for(int i=0,j=v.size()-1;i<j;i++,j--){
            s+=gcd(v[i],v[j]);
        }

        return s;
    }
};