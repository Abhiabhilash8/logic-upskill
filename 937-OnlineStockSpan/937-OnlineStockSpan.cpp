// Last updated: 4/5/2026, 11:45:00 AM
class StockSpanner {
public:

stack<pair<int,int>>st;
int i=1;
    StockSpanner() {}
    
    int next(int price) {
        while(st.size() && st.top().first<=price) st.pop();
        int ans=0;
        if(st.size()) ans=i-st.top().second;
        else ans=i;

        st.push({price,i});
        i++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */