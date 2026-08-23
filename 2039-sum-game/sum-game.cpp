class Solution {
public:
    bool sumGame(string num) {
        int lq = 0 , rq = 0 , ts = 0;
        for(int i = 0; i<num.size(); i++){
            if(num[i] == '?'){
                if(i < num.size() / 2) lq++;
                else rq++;
            }
            else {
                if(i < num.size() / 2) ts += num[i] - '0';
                else ts -= num[i] - '0';
            }
        }

        if(lq == rq) return ts != 0;

        if(lq < rq){
            rq -= lq;
            return ts < 0 || ts > (rq / 2) * 9 || ts < (rq + 1) / 2 * 9;
        }else{
            lq -= rq;
            return ts > 0 || -ts > (lq / 2) * 9 || -ts < (lq + 1) / 2 * 9;
        }

    }
};