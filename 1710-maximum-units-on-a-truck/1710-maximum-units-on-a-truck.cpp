class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        vector<pair<int,int>>products;
        for(int i=0;i<n;i++){
            products.push_back({boxTypes[i][1],boxTypes[i][0]});
        }

        sort(products.begin(),products.end());
        reverse(products.begin(),products.end());
        long long units=0;
        for(int i=0;i<n && truckSize>0;i++){
            units+=(min(1ll*truckSize*products[i].first,1ll*products[i].second*products[i].first));
            truckSize-=products[i].second;
        }

        return units;
    }
};