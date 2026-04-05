// Last updated: 4/5/2026, 11:48:43 AM
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>post(height.size());
        int maxv=height[height.size()-1];
        post[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            maxv=max(height[i],maxv);
            post[i]=maxv;
        }

        int ans=0;
        maxv=height[0];
        for(int i=1;i<height.size()-1;i++){
            maxv=max(maxv,height[i]);

            ans+=(min(maxv,post[i])-height[i]);
        }

        return ans;
    }
};