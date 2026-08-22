class Solution {
public:
    bool checkDivisibility(int n) {
        int p = 1, s = 0 , k = n;
        while(n){
            p *= (n % 10);
            s += (n % 10);

            n /= 10;
        }

        return !(k % (s + p));
    }
};