class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int place=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[curr])
            continue;

            else
            {
                curr++;
                nums[place]=nums[i];
                place++;
            }
        }

        return place;

    }
};

/*
class Solution {
public:

place-1 is index of last unique element
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;   // not really needed anymore, but keeping it to avoid changing your structure
        int place = 1;

        for (int i = 1; i < n; i++)
        {
            // ❌ earlier you compared with nums[curr]
            // ✔️ now compare with last placed unique element
            // WHY: nums[place-1] always stores the last unique value we have kept
            if (nums[i] == nums[place - 1])
                continue;

            else
            {
                curr++; // still harmless, but logically not required
                nums[place] = nums[i];  // place new unique element
                place++;
            }
        }

        return place;
    }
};*/