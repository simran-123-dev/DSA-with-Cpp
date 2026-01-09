class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);

        while (ans.size() < n) {
            vector<int> temp;

            // odd part
            for (int x : ans) {
                if (2 * x - 1 <= n)
                    temp.push_back(2 * x - 1);
            }

            // even part
            for (int x : ans) {
                if (2 * x <= n)
                    temp.push_back(2 * x);
            }

            ans = temp;
        }

        return ans;
    }
};
