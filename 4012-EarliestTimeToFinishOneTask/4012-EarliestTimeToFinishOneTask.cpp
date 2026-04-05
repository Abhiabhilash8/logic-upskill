// Last updated: 4/5/2026, 11:42:10 AM
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int finishtime=201,mintime=201;
        for(int i=0;i<tasks.size();i++){
            int temp=tasks[i][0]+tasks[i][1];
            if(temp<=mintime){
                finishtime=tasks[i][1]+tasks[i][0];
                mintime=temp;
            }
        }

        return finishtime;
    }
};