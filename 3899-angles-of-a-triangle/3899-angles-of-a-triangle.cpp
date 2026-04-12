class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        vector<double>d;
        sort(s.begin(),s.end());
        if(s[0]+s[1]<=s[2]) return d;
        d.push_back(acos( (s[1] *  s[1] + s[2]*s[2] -s[0] *s[0]) / (2.0*s[1] * s[2]))*180.0/M_PI );
        d.push_back(acos( (s[0] *  s[0] + s[2]*s[2] -s[1] *s[1]) / (2.0*s[0] * s[2]))*180.0/M_PI );
        d.push_back(acos( (s[1] *  s[1] + s[0]*s[0] -s[2] *s[2]) / (2.0*s[0] * s[1]))*180.0/M_PI );
        sort(d.begin(),d.end());
        return d;
    }
};