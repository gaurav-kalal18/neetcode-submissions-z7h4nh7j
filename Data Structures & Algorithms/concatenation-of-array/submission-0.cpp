class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s=nums.size();
        vector<int> ans(2*s);
        for(int i=0;i<2*s;i++)
        {
            if(i<s)
            ans[i]=nums[i];

            else
            ans[i]=nums[i-s];
        }

        return ans;
    }
};