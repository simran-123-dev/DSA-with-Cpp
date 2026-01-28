class Solution {
public:
    
    int getRow(char c) {
        c = tolower(c);

        if (c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||c=='u'||c=='i'||c=='o'||c=='p')
            return 1;
        if (c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'||c=='k'||c=='l')
            return 2;
        return 3;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        for (string w : words) {
            int row = getRow(w[0]);
            bool ok = true;

            for (char c : w) {
                if (getRow(c) != row) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans.push_back(w);
        }
        return ans;
    }
};
