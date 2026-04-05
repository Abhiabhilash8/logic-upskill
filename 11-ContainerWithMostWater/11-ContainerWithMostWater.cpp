// Last updated: 4/5/2026, 11:49:12 AM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int w,rh=height.size()-1,h=0,lh=0,cv,mv=0;
        for(;rh>lh;){
            w=rh-lh;
            h=min(height[rh],height[lh]);
            cv=w*h;
            mv=max(cv,mv);
            if(height[rh]>height[lh]){
                lh++;
            }
            else
            rh--;
        }
        return mv;
    }
};