// Last updated: 4/5/2026, 11:44:53 AM
// #include<boost/algorithm/string.hpp>
class Solution {
public:

    string  to_lower(string q){
        string s="";
        for(int i=0;i<q.size();i++){
            s+=tolower(q[i]);
        }


        return s;

    }

    string tocons(string q){
        q=to_lower(q);
        string s="";
        for(int i=0;i<q.size();i++){
            if((q[i]=='a')||(q[i]=='e')||(q[i]=='i')||(q[i]=='o')||(q[i]=='u')) s+="1";
            else s+=q[i];
        }

        return s;
    }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string,bool>exact;
        map<string,string>lwr;
        map<string,string>cons;
        vector<string>ans;

        for(int i=0;i<wordlist.size();i++){
            exact[wordlist[i]]=true;
            if(lwr.find(to_lower(wordlist[i]))==lwr.end()) lwr[to_lower(wordlist[i])]=wordlist[i];
            if(cons.find(tocons(wordlist[i]))==cons.end()) cons[tocons(wordlist[i])]=wordlist[i];

        }



        for(int i=0;i<queries.size();i++){
            if(exact.find(queries[i])!=exact.end()){
                ans.push_back(queries[i]);
                continue;
            }
            else if(lwr.find(to_lower(queries[i]))!=lwr.end()){
                ans.push_back(lwr[to_lower(queries[i])]);
                continue;
            }
            else if(cons.find(tocons(queries[i]))!=cons.end()){
                ans.push_back(cons[tocons(queries[i])]);

            }
            else ans.push_back("");
        }


        return ans;
    }
};