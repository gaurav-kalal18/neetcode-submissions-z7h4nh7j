class Solution {
public:
    //my solution
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int max_len = 0;
        unordered_set<char> st;

        while (r < s.size()) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++; //remove until duplicate is gone
            }

            st.insert(s[r]);
            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};