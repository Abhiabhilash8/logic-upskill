class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = 0; i<=1000; i++ ){
            int x = n + i;
            int p = 1;
            while(x){
                p *= x%10;
                x /= 10;;
            }
            if(p%t == 0) return n+i;
        }

        return -1;
    }
};