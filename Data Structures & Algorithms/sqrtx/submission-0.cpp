class Solution {
public:
    int mySqrt(int x) {
        //My solution:find largest mid st mid^2<=x , ss[2,x-1]
                if (x == 0 || x == 1)
            return x;

        int mid;
        int l = 2, h = x - 1;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (mid == x / mid) // avoid overflow
                return mid;

            else if (mid < x / mid)
                l = mid + 1;

            else
                h = mid - 1;
        }

        return h; // when loop ends h contains floor(sqrt(x))
    }
};