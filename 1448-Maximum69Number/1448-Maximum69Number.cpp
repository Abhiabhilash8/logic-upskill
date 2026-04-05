// Last updated: 4/5/2026, 11:44:29 AM
class Solution {
public:
    int maximum69Number (int num) {
        int temp=1;

        while(num/temp){
            temp=temp*10;
        }

        temp=temp/10;
        for(temp;temp!=0;temp=temp/10){
            if((num/temp)%10==6){
                num=(num/(temp*10))*temp*10 + 9*temp+num%temp;
                break;
            }

        }
            return num;

    }
};