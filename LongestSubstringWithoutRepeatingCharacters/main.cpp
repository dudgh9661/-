class Solution {
public:
    unordered_map<char, int> mp;
    
    void deleteMap(int start, int idx) {
        for (int i = start; i <= idx; i++) {
            for (auto itr = mp.begin(); itr != mp.end(); itr++) {
                if (itr->second == i) {
                    mp.erase(itr);
                    break;
                }
            }
        }
    }
    
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int MAX = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char ch = s[end];
            if (mp.find(ch) != mp.end()) {
                MAX = max(MAX, end - start);
                int findIdx = mp.find(ch)->second;
                deleteMap(start, findIdx);
                start = findIdx + 1;
                mp[ch] = end;
            } else {
                mp[ch] = end;
            }
        }
        MAX = max(MAX, (int)s.length() - start);
        return MAX;
    }
};
