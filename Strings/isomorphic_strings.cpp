// Problem: Isomorphic Strings
// Approach: Character mapping using two arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        int mapST[256];
        int mapTS[256];

        // initialize with -1 (not visited)
        for (int i = 0; i < 256; i++) {
            mapST[i] = -1;
            mapTS[i] = -1;
        }

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // agar pehle se mapping hai
            if (mapST[c1] != -1 || mapTS[c2] != -1) {

                // mapping match nahi kar rahi
                if (mapST[c1] != c2 || mapTS[c2] != c1)
                    return false;
            }
            else {
                // pehli baar mapping
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
        }
        return true;
    }
};
