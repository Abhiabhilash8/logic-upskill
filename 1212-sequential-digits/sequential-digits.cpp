class Solution {
public:

    void f(int num , int l , int h , vector<int>&ans){
        if(num > h) return;
        else if(num >= l && num <= h){
            ans.push_back(num);
        }
        if(num % 10 == 9) return ;

        f(num*10 + num%10 + 1 , l , h , ans);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1; i<9; i++) f(i  , low , high , ans);
        sort(ans.begin() , ans.end());

        return ans;
    }
};