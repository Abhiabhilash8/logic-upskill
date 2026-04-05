// Last updated: 4/5/2026, 11:47:02 AM
class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool>arr(n,true);
        int x=2,c=0;
        arr[0]=false,arr[1]=false;
        

        for(x=2;x<n;x++){
            for(int i=2*x;i<n;i=i+x){
                arr[i]=false;
            }
        }


        for(int i=0;i<n;i++){
            if(arr[i]) c++;
        }
        return c;
    }
};