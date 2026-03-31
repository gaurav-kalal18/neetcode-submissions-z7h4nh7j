class Solution {
public:
//SOLUTUION 1: MY LOGIC
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for (int fix = 0; fix < n - 2; fix++) {

            // ✅ Skip duplicate 'fix' elements
            // WHY: avoid duplicate triplets starting with same number
            if (fix > 0 && nums[fix] == nums[fix - 1])
                continue;

            int l = fix + 1;
            int r = n - 1;

            int need = -nums[fix]; // cleaner than * -1

            // ❗ Always run two-pointer loop (not inside else)
            while (l < r) {

                int sum = nums[l] + nums[r];  
                // ✅ recompute every time because l/r change

                if (sum < need) {
                    l++;
                }
                else if (sum > need) {
                    r--;
                }
                else {
                    // ✅ Found valid triplet phla to orginal hi hoga
                    res.push_back({nums[fix], nums[l], nums[r]});

                    l++;
                    r--;

                    // ✅ Skip duplicates for l
                    // WHY: avoid repeating same triplet
                    while (l < r && nums[l] == nums[l - 1]) l++;

                    // ✅ Skip duplicates for r
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return res;
    }
};