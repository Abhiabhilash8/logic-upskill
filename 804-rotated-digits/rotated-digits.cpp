class Solution {
public:

    int f(int x){
        int res = 0,k=1,god = x;
        bool hc = false;
        while(x){
            int r = x%10;
            if(r == 3 || r == 4 || r == 7 ) return 0;

            if(r == 2 || r == 5 || r == 6 || r == 9) hc = 1;
            x/=10;
        }

        

        return hc;
    }

    int rotatedDigits(int n) {
        int prev = 0,cur = 0;
        for(int i = 1 ;i<=n;i++){
            cur = prev + f(i);
            prev = cur;

            cout<<"for: "<<i<<" valid: "<<f(i)<<"\n";
        }

        return cur;

    }
};