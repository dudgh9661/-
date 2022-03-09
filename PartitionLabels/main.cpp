class Solution {
public:
    unordered_map<char, int> mp;
    
    void init(string s) {
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;
        }
    }
    
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int start = 0;
        init(s);
        //1. [ startIdx, last[first letter] ] 사이의 문자 중 last[char]가 가장 큰 idx까지 하나의 문자열이 된다.
        while (start < s.length()) {
            char startCh = s[start];
            int lastIdx = mp.find(startCh)->second;
            string subStr = s.substr(start, lastIdx - start + 1);
            
            int tmp = 0;
            while (tmp != lastIdx) {
                tmp = lastIdx;
                // cout << "before : " << subStr << endl;
                for (int i = 0; i < subStr.length(); i++) {
                    lastIdx = max(lastIdx, (int)mp.find(subStr[i])->second);
                }
                subStr = s.substr(start, lastIdx - start + 1);
                // cout << "after : " << subStr << endl;
            }
            
            // cout << "ans : " << s.substr(start, lastIdx - start + 1) << endl;
            ans.push_back(lastIdx - start + 1);
            start = lastIdx + 1;
        }
        
        return ans;
    }
};
