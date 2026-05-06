class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            else if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low++;
                high--;
                continue;
            }

            else if (nums[low] <= nums[mid]) // left half is sorted
            {
                if (nums[low] <= target && target <= nums[mid]) // lies in left
                    high = mid - 1;

                else
                    low = mid + 1;
            }

            else // right half is sorted
            {
                if (nums[mid] <= target &&
                    target <= nums[high]) // lies in right
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};