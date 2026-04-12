class Robot {
public:
    vector<int>ac={0,0};
    vector<pair<int,int>>all={{0,1} , {1,0} , {0,-1} , {-1,0} };
    pair<int,int>d=all[0];
    vector<string>hehe={"East" , "North" , "West" , "South"};
    int p=0,perimeter;
    int n,m;
    Robot(int width, int height) {
        n=height,m=width;
        perimeter=2*(n+m-2);
    }
    
    void step(int num) {
        num%=perimeter;
        if(num == 0 && ac[0] == 0 && ac[1] == 0) { p = 3; d = all[p]; }
        if(!num) return;
        vector<int>naya={ac[0]+d.first,ac[1]+d.second};
        if(naya[0]<0 || naya[0]>=n || naya[1]<0 || naya[1]>=m){
            p=(p+1)%4;
            d=all[p];
            // step(num);
        }
            ac[0]+=d.first,ac[1]+=d.second;
            step(num-1);
    }
    
    vector<int> getPos() {
        vector<int>hey={ac[1],ac[0]};
        return hey;
    }
    
    string getDir() {
        return hehe[p];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */