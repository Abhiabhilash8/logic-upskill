// Last updated: 4/5/2026, 11:41:59 AM
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int>mpplet;
        map<int,int>mppfre;  //freq to no of lett
        for(int i=0;i<s.size();i++){
            mpplet[s[i]]++;
        }
        for(auto it: mpplet){
            mppfre[it.second]++;
        }
        int ansfreq=0,maxletters=0;
        for(auto it:mppfre){
            if(it.second>=maxletters){
                maxletters=it.second;
                ansfreq=it.first;
            }
        }

        string str="";
        for(auto it: mpplet){
            if(it.second==ansfreq) str+=it.first;
        }

        return str;
        
    }
};