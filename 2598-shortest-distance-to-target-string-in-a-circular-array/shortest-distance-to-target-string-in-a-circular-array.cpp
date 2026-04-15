class Solution {
public:
    int closestTarget(vector<string>& w, string tg, int si) {
        int n=w.size(),a=INT_MAX;
        for(int i=0;i<n;i++){
            if(w[i]==tg){
                a=min({a,(i - si + n) % n ,(si - i + n) % n});
            }
        }
        

        

        return a==INT_MAX? -1: a;
    }
};