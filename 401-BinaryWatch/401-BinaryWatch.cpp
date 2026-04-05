// Last updated: 4/5/2026, 11:46:06 AM
class Solution {
public:
string con(pair<int,int>&pr){
    string res=to_string(pr.first);
    res+=":";
    if(pr.second<=9) res+="0";
    res+=to_string(pr.second);
    return res;
}

void bt(pair<int,int>pr,vector<string>&ans,int ons,vector<int>&time,int p){
    if(pr.first>=12 || pr.second>=60) return;
    else if(ons==0){
        ans.push_back(con(pr));
        return;
    }else if(p==time.size()) return;

    if(p<=3){
        pr.first+=time[p];
        bt(pr,ans,ons-1,time,p+1);
        pr.first-=time[p];
    }else{
        pr.second+=time[p];
        bt(pr,ans,ons-1,time,p+1);
        pr.second-=time[p];
    }

    bt(pr,ans,ons,time,p+1);

}
    vector<string> readBinaryWatch(int turnedOn) {
      vector<string>ans;
      pair<int,int>pr={0,0};
      vector<int>time={8,4,2,1,32,16,8,4,2,1};
      bt(pr,ans,turnedOn,time,0);  
      return ans;
    }
};