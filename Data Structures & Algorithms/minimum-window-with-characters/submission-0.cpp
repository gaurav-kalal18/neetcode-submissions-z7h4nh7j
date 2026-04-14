class Solution {
public:
    // O(m)+O(2n)
    string minWindow(string s, string t) {
        // order doesnt matter , extra char are allowed , we only need to
        // fulffil     our requirement
        int m = s.size();
        int n = t.size();
        vector<int> freq(256, 0);
        for (char c : t)
            freq[c]++; // freq[65]=1

        int l = 0, r = 0;
        int cnt = 0; // total char of t must be in s
        int minlen = INT_MAX, st = -1;

        while (r < m) {
            if (freq[s[r]] > 0) {
                cnt++;
            }

            freq[s[r]]--;

            while (cnt == n) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    st = l;
                }

                freq[s[l]]++; // shrink remove from window

                if (freq[s[l]] > 0) // value has been reinserted in map
                    cnt--;          // cnt can reduce s=ddaaabbca t=abc
                           //  3rd a ko htane ke bad l moves to b=invalid
                l++;
            }

            r++;
        }

        return minlen == INT_MAX ? "" : s.substr(st, minlen);
    }
};