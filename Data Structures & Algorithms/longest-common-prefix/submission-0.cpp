class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end()); //agar first last same he to bich wale bhi same hi honge
       int i=0;
       string ans="";
       while(i<strs[0].size() && strs[0][i]==strs[strs.size()-1][i])
       {
            ans+=strs[0][i];
            i++;
       }
       return ans;
    }
};