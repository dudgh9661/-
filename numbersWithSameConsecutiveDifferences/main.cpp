class Solution {
public:
    vector<int> ans;
    
    void DFS(int n, int k, string str) {
        if (str.length() == n) {
            ans.push_back(stoi(str));
            return;
        }
        
        for (int i = 0; i < 10; i++) {
            if (str.empty()) {
                if (i == 0) continue;
                str += to_string(i);
                DFS(n, k, str);
                str.pop_back();
            } 
            else {
                int sub = abs(i - (str[str.length()-1]-'0'));
                if (sub != k) continue;
                str += to_string(i);
                DFS(n, k, str);
                str.pop_back();
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        DFS(n, k, "");
        // for(int n : ans) {
        //     cout << "ans : " << n << endl;
        // }
        return ans;
    }
};
