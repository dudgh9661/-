class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans((int)temperatures.size(), 0);
        stack<int> st;
        
        for (int curIdx = 0; curIdx < temperatures.size(); curIdx++) {
            int curTemp = temperatures[curIdx];
            while (!st.empty() && curTemp > temperatures[st.top()]) {
                ans[st.top()] = curIdx - st.top();
                st.pop();
                
            }
            st.push(curIdx);
        }
        
        return ans;
    }
};
