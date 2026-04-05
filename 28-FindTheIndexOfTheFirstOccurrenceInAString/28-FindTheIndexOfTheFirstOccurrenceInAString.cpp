// Last updated: 4/5/2026, 11:48:56 AM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int f=-1;
        for(int i=0;haystack[i]!='\0';i++){
           
            for(int j=0,k=i;needle[j]!='\0';j++,k++){
                if(haystack[k]!=needle[j])
                break;
                if(needle[j+1]=='\0'){
                return i;
                    break;
                }
            }
            
        }
        return f;
    }
};