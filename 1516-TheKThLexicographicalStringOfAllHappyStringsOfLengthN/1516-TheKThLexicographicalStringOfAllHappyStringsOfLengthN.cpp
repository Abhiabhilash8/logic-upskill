// Last updated: 4/5/2026, 11:44:24 AM
class Solution {
public:
int c=0;
string ans="";
    void f(string cur,int i,int n,int k,char prev){
        // cout<<i<<" "<<cur<<endl;
        if(i==n+1){
            // if(c==k && ans=="") ans=cur;
            c++;
            return;
        }

        string t="abc";
        for(auto e: t){
            if(e!=prev){ f(cur+e,i+1,n,k,e);if(c==k && ans=="") ans=cur+e;}
            // cout<<c<<" after call\n";
        }
    }

    string getHappyString(int n, int k) {
        // if(k>(1<<n)) return "";
        f("",1,n,k,'e');
        return ans;
    }
};