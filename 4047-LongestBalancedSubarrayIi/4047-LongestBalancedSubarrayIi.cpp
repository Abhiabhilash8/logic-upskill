// Last updated: 4/5/2026, 11:42:02 AM
class Solution {
public:

    void prop(int i,int vl,int vr,vector<int>&segmin,vector<int>&segmax,vector<int>&lazy){
        segmin[i]+=lazy[i],segmax[i]+=lazy[i];
        if(vl!=vr){
            lazy[2*i+1]+=lazy[i],lazy[2*i+2]+=lazy[i];
            lazy[i]=0;
        }

        lazy[i]=0;
    }

    void updr(int i,int l,int r,int vl,int vr,vector<int>&segmin,vector<int>&segmax,vector<int>&lazy,int val){
        prop(i,vl,vr,segmin,segmax,lazy);
        if(vl>r || vr<l) return;
        if(vl>=l && vr<=r){
            lazy[i]+=val;
            prop(i,vl,vr,segmin,segmax,lazy);   // check by rem
            return;
        }

        int left=2*i+1,right=2*i+2,m=vl+(vr-vl)/2;
        updr(left,l,r,vl,m,segmin,segmax,lazy,val);
        updr(right,l,r,m+1,vr,segmin,segmax,lazy,val);

        segmin[i]=min(segmin[left],segmin[right]);
        segmax[i]=max(segmax[left],segmax[right]);
    }

    int findleft(int i,int vl,int vr,vector<int>&segmin,vector<int>&segmax,vector<int>&lazy){
        prop(i,vl,vr,segmin,segmax,lazy);
        if(segmin[i]>0 || segmax[i]<0) return -1;
        if(vl==vr) return vl;

        int left=2*i+1,right=2*i+2,m=vl+(vr-vl)/2;

        int lr=-1,rr=-1;
        lr=findleft(left,vl,m,segmin,segmax,lazy);
        if(lr==-1) rr=findleft(right,m+1,vr,segmin,segmax,lazy);
        else return lr;

        return rr;
    }

    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        vector<int>lazy(4*n,0),segmin(4*n,0),segmax(4*n,0);
        int c=0,ans=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int val=(nums[i]&1)? -1:1;
            if(mpp.find(nums[i])!=mpp.end()){
            // range upd from 0 to mpp[nums[i]]
                updr(0,0,mpp[nums[i]],0,n-1,segmin,segmax,lazy,-val);
            }

            // prop val to all prev elem
            updr(0,0,i,0,n-1,segmin,segmax,lazy,val);

            // find left most 0 and upd ans
            int leftmosti=-1;
            leftmosti=findleft(0,0,n-1,segmin,segmax,lazy);
            if(leftmosti!=-1) ans=max(ans,i-leftmosti+1);
            mpp[nums[i]]=i;
        }



        return ans;
    }
};