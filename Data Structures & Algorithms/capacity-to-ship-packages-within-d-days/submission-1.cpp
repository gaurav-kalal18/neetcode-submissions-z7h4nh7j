class Solution {
public:
//clean solution
    bool check(vector<int>& weights, int capacity, int days) {
        int cnt = 1;
        int total = 0;

        for (int w : weights) { // fixed shadowing
            if (total + w <= capacity) {
                total += w;
            } else {
                cnt++;          // new day
                total = w;      // no reset logic
            }
        }

        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end()); // min possible cap
         //otherwise capacity 3 he max 4 he usko kaha rkhoge
        int high = accumulate(weights.begin(), weights.end(), 0); // total sum

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(weights, mid, days)) {
                high = mid - 1; // try smaller
            } else {
                low = mid + 1;  // need bigger
            }
        }

        return low; // final answer
    }
};