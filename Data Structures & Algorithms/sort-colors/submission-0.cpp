class Solution {
public:
    void sortColors(vector<int>& nums) {
            unordered_map<int,int> mp;
        for(int &num:nums)
        mp[num]++;
       
       auto p = minmax_element(nums.begin(), nums.end());
int mn = *p.first;
int mx = *p.second;

       int i=0;
       for(int num=mn;num<=mx;num++)
       {
          while(mp[num]>0)
          {
             nums[i]=num;
             i++;
             mp[num]--;
          }
       }

      
    }
};