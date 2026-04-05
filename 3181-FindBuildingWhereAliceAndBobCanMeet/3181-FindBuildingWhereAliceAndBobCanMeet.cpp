// Last updated: 4/5/2026, 11:43:11 AM
class Solution {
public:


// construction of seg
void bt(int i,int vl,int vr,vector<int>&seg,vector<int>&h){
    if(vl==vr){
        seg[i]=vl;
        return;
    }

    int left=2*i+1,right=2*i+2,mid=vl+(vr-vl)/2;
    bt(left,vl,mid,seg,h);
    bt(right,mid+1,vr,seg,h);

    int li=seg[left],ri=seg[right];
    seg[i]=(h[li]>=h[ri])? li:ri;
}
// -------------------------------------------------------
// ans construction
int con(int i,int l,int r,int vl,int vr,vector<int>&seg,vector<int>&h,int mh){
    if(r<vl ||  l>vr) return -1;
    if(h[seg[i]]<=mh) return -1;
    if(vl==vr) return seg[i];
    int left=2*i+1,right=2*i+2,m=vl+(vr-vl)/2,x1,x2,y1,y2;

        x1=con(left,l,r,vl,m,seg,h,mh);
        if(x1!=-1) return x1;
        else return con(right,l,r,m+1,vr,seg,h,mh);
}

// ----------------------------------------------------------
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n=h.size();
        vector<int>seg(4*n,0);
        bt(0,0,n-1,seg,h);
        vector<int>ans;


        for(int i=0;i<q.size();i++){
            
            int higher=max(q[i][0],q[i][1]);
            int lower=min(q[i][0],q[i][1]);

            if(h[higher]>h[lower]){
                ans.push_back(higher);
                continue;
            }
            else if(higher==lower){
                ans.push_back(lower);
                continue;
            }

            ans.push_back(con(0,higher+1,n-1,0,n-1,seg,h,max(h[q[i][0]],h[q[i][1]])));
        }


        return ans;
    }
};