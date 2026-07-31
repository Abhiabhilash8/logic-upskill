class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>f(26 , 0);
        for(auto c: tasks) f[c - 'A']++;
        // pq contains {freq,letter} , queue contains {in time , letter}
        priority_queue<pair<int , int>>pq;
        queue<pair<int,int>>q;
        for(int i = 0; i<26; i++){
            if(f[i]) pq.push({f[i] , i});
        }
        int curtime = 0;
        while(pq.size() || q.size()){
            curtime++;
            while(q.size() && curtime - q.front().first > n){
                pq.push({f[q.front().second] , q.front().second});
                q.pop();
            }
            if(pq.empty()){
                continue;
            }
            auto it = pq.top();
            pq.pop();
            f[it.second]--;
            if(f[it.second])q.push({curtime , it.second});
        }

        return curtime;
    }
};