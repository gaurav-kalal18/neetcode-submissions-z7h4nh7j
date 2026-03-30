/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
        {
            int freq[26]={0};
            string key="";
            for(char c:s)
            {
                freq[c-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                key+='#';
                key+=to_string(freq[i]); //to make unique key(key is string) no clash
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &it:mp)
        res.push_back(it.second);

        return res;
    }
};*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sorted string to the val
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &s : mp) {  //reference not a copy.. modifies actual map
            ans.push_back(s.second);
        }

        return ans;
    }
};