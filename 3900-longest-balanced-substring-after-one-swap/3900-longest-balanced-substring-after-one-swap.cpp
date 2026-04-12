class Solution {
public:
    int f(string &s){
        int n=s.size(),ans=0,c=0;
        map<int,int>mpp;
        int av1=0,av0=0;
        mpp[0]=-1;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0') av0++;
            else av1++;
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){ av0--;c--;}
            else {av1--;c++;}

            if(mpp.find(c)!=mpp.end()){
                ans=max(ans,i-mpp[c]);
            }
            if(av1 && mpp.find(c+2)!=mpp.end()){
                ans=max(ans,i-mpp[c+2]);
            }
            if(av0 && mpp.find(c-2)!=mpp.end()){
                ans=max(ans,i-mpp[c-2]);
            }
            

            if(mpp.find(c)==mpp.end()) mpp[c]=i;
        }


        return ans;
    }
    int longestBalanced(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        return max(f(s),f(s1));
    }
};