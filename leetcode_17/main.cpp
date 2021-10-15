class Solution {
public:
    vector<char> vec[10];
    vector<string> ans;
    
    void init() {
        vec[2] = {'a','b','c'};
        vec[3] = {'d','e','f'};
        vec[4] = {'g','h','i'};
        vec[5] = {'j','k','l'};
        vec[6] = {'m', 'n', 'o'};
        vec[7] = {'p','q','r','s'};
        vec[8] = {'t','u','v'};
        vec[9] = {'w','x','y','z'};
    }
    
    void DFS(string digits, int curIdx, string res) {
        
        if ( curIdx == digits.size()) {
            ans.push_back(res);
            return;
        }
        
        int num = digits[curIdx] - '0';
        
        for(int i = 0; i < vec[num].size(); i++) {
            res.push_back(vec[num][i]);
            DFS(digits, curIdx + 1, res);
            res.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        init();
        DFS(digits, 0, "");
        return ans;
    }
};
