class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0] = 1;   // empty prefix

        int prefix = 0;
        int ans = 0;

        for (int x : nums) {
            if (x == target)
                prefix += 1;
            else
                prefix -= 1;

            // count how many previous prefix < current prefix
            for (auto &it : mp) {
                if (it.first < prefix) {
                    ans += it.second;
                }
            }

            mp[prefix]++;
        }

        return ans;
    }
};
