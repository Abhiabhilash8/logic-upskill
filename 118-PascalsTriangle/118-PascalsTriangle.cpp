// Last updated: 4/5/2026, 11:47:42 AM
class Solution {
public:
void genrow(vector<int>&temp,int row){
    int var=1;
    temp.push_back(var);
    for(int i=1;i<row;i++){
        var=(var*(row-i))/i;
        temp.push_back(var);
    }
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
       for(int i=1;i<=numRows;i++){
        vector<int>temp;
        genrow(temp,i);
        ans.push_back(temp);
       } 
       return ans;
    }
};