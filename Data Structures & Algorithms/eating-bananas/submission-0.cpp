class Solution {
public:
    long long gethours(vector<int>& piles, int k, int h) // overflow
    {
        long long totalhrs = 0;
        for (auto p : piles) {
            totalhrs += (p + k - 1) / k; // ceil(p/k)
            if (totalhrs > h)
                return totalhrs; // early exit
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // BS ON ASNWERS RANGE [1,MAX ELEMENT]
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high; // start from wc reduce later
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (gethours(piles, mid, h) <= h) {
                ans = mid;
                high = mid - 1; // try smaller speed
            }

            else
                low = mid + 1;
        }

        return ans; // low ends at the min valid answer
    }
};