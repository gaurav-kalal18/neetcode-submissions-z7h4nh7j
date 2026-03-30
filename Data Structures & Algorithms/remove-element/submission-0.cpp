class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int dup=0;
        vector<int> b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
        {
            nums.erase(nums.begin()+i);
            i--;
            continue;
        }   

            else
            b.push_back(nums[i]);
        }
        return b.size();
    }
};