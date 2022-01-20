class Solution {
public:
    stack<int> st;
    queue<int> que;
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        for (int num : popped) {
            que.push(num);
        }
        
        // push to stack
        for (int num : pushed) {
            st.push(num);
            while (!st.empty() && !que.empty() && st.top() == que.front()) {
                st.pop();
                que.pop();
            }
        }
        
        if (!st.empty()) return false;
        return true;
    }
};
