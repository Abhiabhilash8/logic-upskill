class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = (hour%12) * 30 + minutes * 0.5;
        double k = abs(hr - minutes * 6);
        return min(k , 360 - k);

    }
};