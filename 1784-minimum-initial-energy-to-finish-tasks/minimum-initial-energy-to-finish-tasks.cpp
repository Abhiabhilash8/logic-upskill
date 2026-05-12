class Solution {
public:

    static bool comp(vector<int>&v1 , vector<int>&v2){
        return v1[1] - v1[0] < v2[1] - v2[0];
    }

    int minimumEffort(vector<vector<int>>& t) {
        sort(t.begin() , t.end() , comp);

        int a = 0;
        for(auto &v: t){
            a = max(a+v[0] , v[1]);
        }
        return a;
    }
};