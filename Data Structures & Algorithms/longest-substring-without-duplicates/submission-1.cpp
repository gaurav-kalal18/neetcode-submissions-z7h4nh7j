class Solution {
public:
    // beats 100%
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // all charcaters
        int l = 0, r =0, maxlen = 0;
        while (r < s.size()) {
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
                // move left ptr to right of        last           occurence of s[r]
            }

            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r; //current idx
            r++;
        }

        return maxlen;
    }
    };
    /*class Solution {
    public:
        //my solution
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0;
            int max_len = 0;
            unordered_set<char> st;

            while (r < s.size()) {
                while(st.count(s[r])) {
                    st.erase(s[l]);
                    l++; //remove until duplicate is gone
                }

                st.insert(s[r]);
                max_len = max(max_len, r - l + 1);
                r++;
            }

            return max_len;
        }
    };*/