class Solution {
public:
    //My solution using dry run
    bool check(vector<int>& w, int m, int d) {
        int n = w.size();
        int cnt = 1;
        int tot = 0;
        for (auto w : w) {
            if (tot + w <= m) {
                tot += w;
            }

            else {
                tot = 0;
                if (tot + w <= m)
                    tot += w;

                else
                    return false;
                cnt++;
            }
        }

        if (cnt <= d)
            return true;

        else
            return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++)
            high += weights[i];

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }
};