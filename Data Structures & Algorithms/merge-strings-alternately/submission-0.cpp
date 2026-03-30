class Solution { //selF
public:
    string mergeAlternately(string word1, string word2) {
        int la = 0, ra = word1.size() - 1;

        string final = "";
        int lb = 0, rb = word2.size() - 1;
        while (la <= ra && lb <= rb) {
            final += word1[la];
            final += word2[lb];
            la++;
            lb++;
        }

        while (la<=ra) {  //<= bcos if != to last char skipped
            final += word1[la];
            la++;
        }

        while (lb <= rb) {
            final += word2[lb];
            lb++;
        }

        return final;
    }
};

/* CLEANER AND LESS SPACE
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string final = "";
        int i = 0, j = 0;

        while (i < word1.size() && j < word2.size()) {
            final += word1[i++];
            final += word2[j++];
        }

        while (i < word1.size()) final += word1[i++];
        while (j < word2.size()) final += word2[j++];

        return final;
    }
};*/