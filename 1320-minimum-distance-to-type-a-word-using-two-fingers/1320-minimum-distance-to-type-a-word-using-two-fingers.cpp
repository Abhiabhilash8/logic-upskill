class Solution {
public:

    int sedlyf[305][256][256];

    int d(char a , char b){

        if(a=='(' || b=='(') return 0;


        int yes=a - 'A'+1, no=b - 'A'+1;
        int ikkada1 = ceil(yes/6.0);
        int ikkada2 = (yes-1)%6 + 1;

        int akkada1 = ceil(no/6.0);
        int akkada2 = (no-1)%6 + 1;

        return abs(akkada1 - ikkada1) + abs(ikkada2 - akkada2); 
    }

    int bhAAi(int i,string &w, char kaju, char kismis){
        if(i == w.size()) return 0;

        if(sedlyf[i][kaju][kismis]!=-1) return sedlyf[ i ][ kaju ][ kismis ];

        int csk = d(w[i] , kaju) + bhAAi( i+1 , w , w[i] , kismis);

        int rcb = d(w[i] , kismis) + bhAAi( i+1 , w , kaju , w[i]);


        return sedlyf[i][kaju][kismis] = min(rcb , csk);
    }

    int minimumDistance(string w) {
        memset(sedlyf , -1, sizeof(sedlyf) );
        return bhAAi(0,w,'(','(');
    }
};