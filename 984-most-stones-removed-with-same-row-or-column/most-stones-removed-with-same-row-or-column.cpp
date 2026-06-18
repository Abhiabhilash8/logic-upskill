class Solution {
    private:
    int connectedComponentCount = 0;

    int findRepresentative(int element, vector<int>& setRepresentatives) {
        if (setRepresentatives[element] == 0) {
            setRepresentatives[element] = element;
            connectedComponentCount++;
        }
        return setRepresentatives[element] == element ? element : 
               (setRepresentatives[element] = findRepresentative(setRepresentatives[element], setRepresentatives));
    }

    void mergeComponents(int elementA, int elementB, vector<int>& setRepresentatives) {
        int repA = findRepresentative(elementA, setRepresentatives);
        int repB = findRepresentative(elementB, setRepresentatives);
        if (repA != repB) {
            setRepresentatives[repB] = repA;
            connectedComponentCount--;
        }
    }
public:
    int removeStones(vector<vector<int>>& sp) {
        vector<int>st_rep(20003 , 0);
        for(auto &pos : sp){
            mergeComponents(pos[0] + 1, pos[1] + 10002 , st_rep);
        }

        return sp.size() - connectedComponentCount;
    }
};