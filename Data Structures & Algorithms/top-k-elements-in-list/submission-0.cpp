class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //follow up:O(n) solution

        int n=nums.size();
        unordered_map<int,int> mp;
        for(int num:nums)
        mp[num]++;

        vector<vector<int>> bucket(n+1);
        //index=freq, value=elements
        //bucket[i]=elements with freq i

        for(auto& it:mp)
        {
            int element=it.first;
            int freq=it.second;
            bucket[freq].push_back(element);
        }

        vector<int> ans;
        for(int i=n;i>=0;i--)
        {
            if(bucket[i].size()==0)
            continue;

            while(bucket[i].size()>0 && k>0)
            {
                ans.push_back(bucket[i].back()); //no shift O(1)
                bucket[i].pop_back();
                k--;
            }
        }

        return ans;


        

     
    }
};

/*class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for (int n : nums)
            mp[n]++;

        priority_queue<P, vector<P>,
                       greater<P>>
            minheap;

        for(auto &it:mp)
        {
            minheap.push({it.second,it.first});

            if(minheap.size()>k)  //nlogk
            minheap.pop();

        }

        vector<int> ans;
        while(!minheap.empty())
        {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;
    }
};*/

/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> vp;
        for (auto& it : freq) {
            vp.push_back({it.first, it.second});
        }

        sort(vp.begin(), vp.end(), //nlogn
             [](auto& a, auto& b) { return a.second > b.second; });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vp[i].first);
        }

        return ans;
    }

};*/