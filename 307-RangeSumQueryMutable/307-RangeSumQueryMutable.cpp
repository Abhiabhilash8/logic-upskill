// Last updated: 4/5/2026, 11:46:20 AM
class NumArray {
public:
vector<int>seg;
int n;
void bt(int i,int vl,int vr,vector<int>&nums){
    if(vl==vr){
        seg[i]=nums[vr];
       
        return;
    }
    int m=vl+(vr-vl)/2,l=2*i+1,r=2*i+2;
    bt(l,vl,m,nums);
    bt(r,m+1,vr,nums);

    seg[i]=seg[l]+seg[r];
}


int con(int i,int l,int r,int vl, int vr ){
    if(r<vl || l>vr) return 0;
    if(vl>=l && vr<=r) return seg[i];

    int m=vl+(vr-vl)/2;
    return con(2*i+1,l,r,vl,m)+con(2*i+2,l,r,m+1,vr);
}
void upd(int i,int ind,int val,int vl,int vr){
    if(ind<vl || ind>vr) return;
    if(vl==vr){
        seg[i]=val;
        return;
    }

    int l=2*i+1,r=2*i+2,m=vl+(vr-vl)/2;
    upd(l,ind,val,vl,m);
    upd(r,ind,val,m+1,vr);
    seg[i]=seg[l]+seg[r];
}





    NumArray(vector<int>& nums) {
        vector<int>t(nums.size()*4,0);
        seg=t;
        bt(0,0,nums.size()-1,nums);
        n=nums.size();
    }
    
    void update(int index, int val) {
        upd(0,index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return con(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */