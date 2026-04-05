// Last updated: 4/5/2026, 11:46:08 AM
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long int begin =1;
        long int end = n;
        while(begin<=end){
           long int mid=(begin+end)/2;
            if(guess(mid)==0)
            return mid;
            else if(guess(mid)==-1)
            end=mid-1;
            else
            begin=mid+1;
        }
        return 0;
    }
};