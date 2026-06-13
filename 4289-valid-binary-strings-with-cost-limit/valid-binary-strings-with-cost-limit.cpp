class Solution {
public:
    void f(vector<string>&ans , int i ,string s, char prv , int n , int c , int k){
        if(c > k) return;
        if( i == n){
            ans.push_back(s);
            return;
        }

        f(ans , i+1 , s + '0' , '0', n , c , k);
        if(prv  != '1') f(ans , i+1 , s + '1' , '1' , n , c+i , k);
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        f(ans , 0 , "" , '-' , n , 0 , k);

        return ans;
    }
};