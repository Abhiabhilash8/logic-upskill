class Solution {
public:

    int f(int i , vector<int>&arr , int d , vector<int>&pos){
        if(pos[i] != -1) return pos[i];

        int faah = 0;

        for(int k = 1; k <= d && i-k >= 0 && arr[i-k] < arr[i]; k++) faah = max(faah , f(i-k , arr , d , pos));

        for(int k = 1; k<=d && i+k < arr.size() && arr[i+k] < arr[i]; k++) faah = max(faah , f(i+k , arr , d , pos));

        return pos[i] = 1 + faah;
        
    }

    int maxJumps(vector<int>& arr, int d) {
        int ans = INT_MIN;
        
        for(int i = 0; i<arr.size(); i++){
            vector<int>pos(arr.size() , -1);
            ans = max(ans , f(i,arr,d,pos));
        }

        return ans;
    }
};