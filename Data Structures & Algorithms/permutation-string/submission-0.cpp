class Solution {
public:
    //My solution use freq to track substring of window size n
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> freq(26,0);
        for(char c:s1)
        freq[c-'a']++;
        //now track this frequecny over s2 in a window of size n

        int l=0,r=0,size=0;
        while(r<m)
        {
            char c=s2[r];
            //include charcter in window
            freq[c-'a']--;

            //if window invalid shrink
            while(freq[c-'a']<0)
            {
                freq[s2[l]-'a']++;
                l++;
            }

             if(r-l+1==n)
            return true;

            r++;

        }

        return false;




        
        
    }
};