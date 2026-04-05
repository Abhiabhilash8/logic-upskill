// Last updated: 4/5/2026, 11:45:29 AM
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>temp;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                if(temp.size()>=0){
                    temp.pop_back();
                }
            }
            else if(operations[i]=="D"){
                temp.push_back(temp[temp.size()-1]*2);
                
            }
            else if(operations[i]=="+"){
                if(temp.size()>=2){
                    temp.push_back(temp[temp.size()-1]+temp[temp.size()-2]);
                }
                else{
                    temp.push_back(temp[temp.size()-1]);
                }
            }
            else{
                int var=stoi(operations[i]);
                temp.push_back(var);
            }
        }

        int ans=0;
        for(int i=0;i<temp.size();i++){
            ans+=temp[i];
        }


        return ans;
    }
};