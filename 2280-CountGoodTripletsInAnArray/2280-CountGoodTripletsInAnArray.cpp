// Last updated: 4/5/2026, 11:43:28 AM
class Solution {
public:

    void in(int i,int ind,int vl,int vr,vector<int>&seg){
    if(ind<vl || ind>vr) return;
    if(vl==vr){
        seg[i]=1;
        return;
    }
    int m=vl+(vr-vl)/2,left=2*i+1,right=2*i+2;
    in(left,ind,vl,m,seg);
    in(right,ind,m+1,vr,seg);

    seg[i]=seg[left]+seg[right];
}

    int con(int i,int l,int r,int vl,int vr,vector<int>&seg){
        if(l>vr || r<vl) return 0;
        if(vl>=l && vr<=r) return seg[i];
        int left=2*i+1,right=2*i+2,m=vl+(vr-vl)/2;
        return con(left,l,r,vl,m,seg)+con(right,l,r,m+1,vr,seg);
    }


    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>seg(4*n,0);
        map<int,int>mpp;
        long long ans=0;
        for(int i=0;i<n;i++) mpp[nums2[i]]=i;
        for(int i=0;i<n;i++){
            int n2ind=mpp[nums1[i]];

            long long left=con(0,0,n2ind,0,n-1,seg);
            long long leftnotcom=i-left;
            long long afteridx=n-n2ind-1;
            long long right=afteridx-leftnotcom;
            cout<<right<<endl;
            ans+=(left*right);
            in(0,n2ind,0,n-1,seg);
        }

        return ans;
    }
};