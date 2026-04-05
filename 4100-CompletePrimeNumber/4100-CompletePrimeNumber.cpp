// Last updated: 4/5/2026, 11:41:41 AM
class Solution {
public:
    bool check(int n){

        int c=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        // if(num==1) return false;
        vector<int>p(1e5+2,1);
        p[1]=0;
        for(int i=2;i<1e5+2;i++){

            for(int j=2*i;j<1e5+2;j+=i){
                p[j]=0;
            }
            
        }

        if(num>=1 && num<=9) return p[num];

            string s = to_string(num);
        string pre="",post="";
            pre+=s[0],post+=s[s.size()-1];
        int k=1;
        while(k<s.size()){
            int x = stoi(pre);
            string te=post;
            reverse(te.begin(),te.end());
            int y=stoi(te);
            cout<<p[x]<<" "<<p[y]<<" ";
            if((!p[x])||(!p[y])) return false;

            pre+=s[k],post+=s[s.size()-k-1];
            k++;

        }

        return check(num);

        
        
    }
};