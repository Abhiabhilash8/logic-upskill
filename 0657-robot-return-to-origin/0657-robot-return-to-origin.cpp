class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(auto c: moves){
            if(c=='L') j--;
            else if(c=='R') j++;
            else if(c=='U') i--;
            else i++;
        }

        return (i==0 && j==0);
    }
};