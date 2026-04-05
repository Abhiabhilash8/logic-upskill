// Last updated: 4/5/2026, 11:42:34 AM
class Solution {
public:
    int maxFreqSum(string s) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        int ansv=0,ansc=0;
        
        for(int i=0;i<26;i++){
            if((i+'a'=='a')||(i+'a'=='e')||(i+'a'=='i')||(i+'a'=='o')||(i+'a'=='u')){
            if(arr[i]>=ansv){
                ansv=arr[i];
            }

            }
            else{
                if(arr[i]>=ansc){
                ansc=arr[i];
            }
            }
        }

        return ansv+ansc;
    }
};