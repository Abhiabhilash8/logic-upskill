class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        sort(as.begin() , as.end());
        long long s = mass;

        for(int i=0; i<as.size(); i++){
            if(as[i] > s) return false;

            else s += as[i];
        }

        return true;
    }
};