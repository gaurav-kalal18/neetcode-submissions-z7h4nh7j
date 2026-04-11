class Solution {
public:
//sliding window of size k -> Airbnb
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
       unordered_set<int> st;
       for(int i=0;i<nums.size();i++)
       {
            if(st.count(nums[i]))
            return true;

            else
            st.insert(nums[i]);

            if(st.size()>k)
            st.erase(nums[i-k]);

       }

       return false;

        }

            
           
    };

/*class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++)
       {
            if(mp.find(nums[i])!=mp.end()
               && abs(mp[nums[i]]-i)<=k)
            return true;

            else
            mp[nums[i]]=i; //value,index
       }

       return false;
       
       
       
       }

            
           
    };
*/