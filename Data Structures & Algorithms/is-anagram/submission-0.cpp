class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqs(26,0);
        vector<int> freqt(26,0);
        for(char c:s)
        freqs[c-'a']++;

        for(char c:t)
        freqt[c-'a']++;

       bool isvalid;
        for(int i=0;i<26;i++)
        {    isvalid=true;
            if(freqs[i]!=freqt[i])
            {
                isvalid=false;
                break;
            }
        }

        if(isvalid)
        return true;

        else
        return false;


    }
};
