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
        long long low = 1, high = n ,mid;
        while (low <= high) {
             mid = low + (high - low) / 2;
            int get = guess(mid); 
                if (get == 0)
                    break;

                else if (get == -1)
                    high = mid - 1;

                else
                    low = mid + 1;
            
        }
        return mid;
    }
};