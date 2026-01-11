class Solution {
public:
    int divisorSubstrings(int num, int k) {

        string s = to_string(num);
        int count = 0;

        for(int i = 0; i + k <= s.length(); i++) {

            string part = s.substr(i, k);
            int val = stoi(part);

            if(val != 0 && num % val == 0)
                count++;
        }

        return count;
    }
};
