class Solution {
public:
    
    vector<string> ans;
    void DFS(int n, string str, int open, int close) {
        if (str.length() == n*2) {
            ans.push_back(str);
            return;
        }
        
        if (open > 0) {
            str.push_back('(');
            DFS(n, str, open - 1, close);
            str.pop_back();
        }
        if (close > open) {
            str.push_back(')');
            DFS(n, str, open, close - 1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        DFS(n, "", n, n);
        
        return ans;
    }
};
