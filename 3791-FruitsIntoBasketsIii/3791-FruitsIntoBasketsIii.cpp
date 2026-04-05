// Last updated: 4/5/2026, 11:42:41 AM
class Solution {
public:
void bt(int i,int vl,int vr,vector<int>&seg,vector<int>&baskets){
    if(vl==vr){
        seg[i]=baskets[vl];
        return;
    }

    int m=vl+(vr-vl)/2,left=2*i+1,right=2*i+2;
    bt(left,vl,m,seg,baskets);
    bt(right,m+1,vr,seg,baskets);

    seg[i]=max(seg[left],seg[right]);
}

void upd(int i,int vl,int vr,int tg,vector<int>&seg){
    if(vl==vr){ seg[i]=-1;return;}
    int left=2*i+1,right=2*i+2,m=vl+(vr-vl)/2;
    if(seg[left]>=tg) upd(left,vl,m,tg,seg);
    else upd(right,m+1,vr,tg,seg);

    seg[i]=max(seg[left],seg[right]);
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int>seg(4*n,0);
        bt(0,0,n-1,seg,baskets);
        int c=0;
        for(int i=0;i<n;i++){
            if(fruits[i]>seg[0])
                c++;
            else upd(0,0,n-1,fruits[i],seg);
        }

        return c;
    }
};