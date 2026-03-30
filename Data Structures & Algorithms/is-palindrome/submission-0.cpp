class Solution {
public:
    bool isPalindrome(string s) {
        //we have to remove/skip all non alpha num - non digit or letter (0-9) a-z A-Z

        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;

            if(tolower(s[left])!=tolower(s[right]))
            return false;

            left++;
            right--;

        }

        return true;
    }
};