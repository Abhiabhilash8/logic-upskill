// Last updated: 4/5/2026, 11:45:27 AM
class Solution {
public:
    bool hasAlternatingBits(int n) {
      int f=!(n&1);
      while(n){
        if(f==(n&1)) return false;

        f=!f;
        n/=2;
      }  
      return true;
    }
};