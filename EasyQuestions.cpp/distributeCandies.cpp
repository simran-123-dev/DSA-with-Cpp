class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        for (int c : candyType) {
            s.insert(c);
        }
        return min((int)s.size(), (int)candyType.size() / 2);
    }
};
