class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Step 1: count frequency
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: find first unique
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
