// Last updated: 4/5/2026, 11:40:38 AM
class EventManager {
public:
    struct comp{
        bool operator()(pair<int,int>&p1,pair<int,int>&p2){
            if(p1.first<p2.first) return true;
            else if(p2.first<p1.first) return false;
            else return p1.second>p2.second;
        }
        
    };
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    unordered_map<int,int>f,st;
    
    EventManager(vector<vector<int>>& events) {
        for(auto e: events){
            pq.push({e[1],e[0]});
            f[e[0]]=1;
            st[e[0]]=e[1];
        }
    }
    
    void updatePriority(int ei, int np) {
        pq.push({np,ei});
        f[ei]++;
        st[ei]=np;
    }
    
    int pollHighest() {
        while(pq.size() && st[pq.top().second]!=pq.top().first ){
            f[pq.top().second]--;
            pq.pop();
        }
        if(!pq.size()) return -1;
        f[pq.top().second]--;
        st[pq.top().second]=-1;
        int k=pq.top().second;
        pq.pop();
        return k;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */