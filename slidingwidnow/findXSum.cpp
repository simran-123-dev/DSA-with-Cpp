class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i + k <= n; i++) {

            unordered_map<int,int> freq;

            // STEP 1: frequency count
            for(int j = i; j < i + k; j++)
                freq[nums[j]]++;

            // STEP 2: map → vector
            vector<pair<int,int>> v;
            for(auto it : freq)
                v.push_back({it.second, it.first});
                // {frequency, value}

            // STEP 3: sort
            sort(v.begin(), v.end(), [](auto &a, auto &b){
                if(a.first == b.first)
                    return a.second > b.second; // bigger value first
                return a.first > b.first;       // higher freq first
            });

            // STEP 4: sum top x elements
            int sum = 0;
            for(int t = 0; t < x && t < v.size(); t++)
                sum += v[t].first * v[t].second;

            ans.push_back(sum);
        }

        return ans;
    }
};
