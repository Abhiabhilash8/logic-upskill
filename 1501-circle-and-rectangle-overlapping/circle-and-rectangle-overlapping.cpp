class Solution {
public:


    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        if(cx >= x1 && cx <= x2 && cy >= y1 && cy <= y2) return 1;
        int kx = x1 , ky = y1;
        r *= r;
        do{
            cout<<kx<<" "<<ky<<endl;
            int d = (ky - cy) * (ky - cy) + (kx - cx) * (kx - cx);
            // d *= d;
            if(r >= d) return true; 
            if(x1 == kx && y1 == ky) ky++;
            else if(x1 == kx && y2 == ky) kx++;
            else if(x2 == kx && y2 == ky) ky--;
            else if(x2 == kx && y1 == ky) kx--;
            else if(x1 == kx) ky++;
            else if(x2 == kx) ky--;
            else if(y1 == ky) kx--;
            else kx++;
        }while(!(kx == x1 && ky == y1));

        return 0;
    }
};