// Last updated: 4/5/2026, 11:43:16 AM
class Solution {
public:
    string sortVowels(string s) {
        string vowc="";
        string vows="";

        for(int i=0;i<s.size();i++){
            if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')) vows+=s[i];
            else if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U')) vowc+=s[i];
        }

        int ptr=0,i=0;
        sort(vowc.begin(),vowc.end());
        sort(vows.begin(),vows.end());


        for(;i<s.size()&&ptr<vowc.size();i++){
            if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U')||(s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
                s[i]=vowc[ptr++];
                if(ptr>=vowc.size()){
                    i++;
                    break;
                }
            }
        }
        ptr=0;
        for(;(i<s.size())&&(ptr<vows.size());i++){
            if((s[i]=='A')||(s[i]=='E')||(s[i]=='I')||(s[i]=='O')||(s[i]=='U')||(s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
                s[i]=vows[ptr++];
                if(ptr>=vows.size()) break;
            }

        }


        return s;
    }
};