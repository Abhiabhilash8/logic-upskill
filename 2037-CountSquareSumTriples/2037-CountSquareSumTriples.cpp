// Last updated: 4/5/2026, 11:43:42 AM
class Solution {
public:
    int countTriples(int n) {
        vector<int>a;
        double c;
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int val=i*i+j*j;
                c=(double)sqrt(val);
                if((c-(int)c)==0 && c<=n){
                    cout<<i<<" "<<j<<" \n";
                    count++;
                    }
            }
        }
        return count*2;
    }
};