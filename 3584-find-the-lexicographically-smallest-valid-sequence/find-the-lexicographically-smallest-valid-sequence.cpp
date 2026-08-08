class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n1 = w1.size() , n2 = w2.size() , j = n2 - 1 , i;
        vector<int>ls(n1 + 1 , 0);
        for(i = n1 -1 ; i >= 0 && j >= 0; i--){
            ls[i] = ls[i + 1];
            if(w1[i] == w2[j]){
                ls[i]++;
                j--;
            }
        }
        for(int k = i; k >= 0; k--) ls[k] = ls[k + 1];

        vector<int>a;
        j = 0;
        bool changed = false;
        for(i = 0; i<n1 && j < n2; i++){
            if(w1[i] == w2[j]){
                j++;
                a.push_back(i);
            }else{
                if(changed || ls[i + 1] < n2 - j - 1) continue;
                changed = 1;
                a.push_back(i);
                j++; 
            }
        }

        if(j < n2) return {};
        return a;

    }
};