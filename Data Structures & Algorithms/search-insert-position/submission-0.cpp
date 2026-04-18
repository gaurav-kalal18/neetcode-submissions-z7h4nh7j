class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //lower bound of target
        //not upper bcos if target exist in nums it gives greater ans
        int l=0,h=nums.size()-1;
        int ans=h+1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                h=mid-1;
            }

            else
            l=mid+1;

        }

        return ans;
    }
};