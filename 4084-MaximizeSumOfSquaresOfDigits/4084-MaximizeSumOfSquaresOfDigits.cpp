// Last updated: 4/5/2026, 11:41:48 AM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        while(sum){
            if(sum<10){
                s+=(sum+'0');
                sum=0;
            }
            else{ s+='9';
            sum-=9;}
        }

        if(s.size()>num) return "";
        else{
            while(num-s.size()) s+='0';
        }

        // reverse(s.begin(),s.end());
        return s;
    }
};