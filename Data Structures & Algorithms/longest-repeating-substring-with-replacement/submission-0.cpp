class Solution {
public:
    //LEN-maxfreq<=k
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, ans = 0, r = 0, n = s.size();
        //MAXFREQ EVER SEEN IN WINDOW
        //we twmporaily allow invalid window but thats not valid in real ans remain fix
        while (r < n) {
            freq[s[r] - 'A']++; //  A->freq[0]

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // If window invalid → shrink only once even if invalid
            if((r - l + 1) - maxFreq > k) { //if works bcos we dont decr maxfreq
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};