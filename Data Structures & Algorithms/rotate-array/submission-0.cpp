class Solution {
public:

    void rev(vector<int> &nums,int l,int r)
    {
         while(l<r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) { 
        int n = nums.size();
        if(k>n)
        k=k%n;  //after n rotation array becomes same

        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);
        
        
         }
};