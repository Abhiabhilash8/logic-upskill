// Last updated: 4/5/2026, 11:49:11 AM
class Solution {
public:
int pred(char a){
    int sum;
    switch(a){
                case 'I':sum=1;
                        break;
                case 'V': sum=5;
                        break;
                case 'X':sum=10;
                        break;
                case 'L':sum=50;
                        break;
                case 'C':sum=100;
                        break;
                case 'D':sum=500;
                        break;
                case 'M':sum=1000;
                        break;                                                
            }
            return sum;
}
    int romanToInt(string s) {
        int sum=0,sum2=0;
        
        for(int i=0;s[i]!='\0';i++){
            if(i==s.size()-1||pred(s[i])>=pred(s[i+1])){
                sum+=pred(s[i]);
                       }
            else{
                sum2+=pred(s[i]);
                           }
        }
        return sum-sum2;
    }
};