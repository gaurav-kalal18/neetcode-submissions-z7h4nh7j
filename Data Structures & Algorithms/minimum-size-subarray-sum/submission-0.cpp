class Solution {
public:
    //my solution-> striver inspired + dry run
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;
        while (r < n) {
            sum += nums[r];

            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }
        if (ans > n)
            return 0;
        return ans;
    }
};