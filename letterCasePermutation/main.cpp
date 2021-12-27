class Solution {
public:
    vector<string> ans;
    void DFS(string maked, string s, int idx) {
        if (maked.length() == s.length()) {
            ans.push_back(maked);
            return;
        }
        
        maked.push_back(s[idx]);
        DFS(maked, s, idx + 1);
        maked.pop_back();
        
        // lower -> upper
        if (isupper(s[idx])) {
            maked.push_back(tolower(s[idx]));
            DFS(maked, s, idx + 1);
        } else if (islower(s[idx])) { // upper -> lower
            maked.push_back(toupper(s[idx]));
            DFS(maked, s, idx + 1);
        }
        maked.pop_back();
    }
    
    vector<string> letterCasePermutation(string s) {
        DFS("", s, 0);
        return ans;
    }
};
