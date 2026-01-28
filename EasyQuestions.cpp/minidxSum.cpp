class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        
        vector<string> ans;
        int minSum = INT_MAX;
        
        for (int j = 0; j < list2.size(); j++) {
            if (mp.count(list2[j])) {
                int sum = j + mp[list2[j]];
                
                if (sum < minSum) {
                    ans.clear();
                    ans.push_back(list2[j]);
                    minSum = sum;
                }
                else if (sum == minSum) {
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};
