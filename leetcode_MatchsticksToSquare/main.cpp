class Solution {
public:
    
    vector<int> num;
    
    bool DFS(int idx, vector<int>& matchsticks, int MAX) {
        if (idx == matchsticks.size()) {
            return num[0] == num[1] && num[1] == num[2] && num[2] == num[3];
        }
        
        int element = matchsticks[idx];
        
        for (int i = 0; i < 4; i++) {
            if (num[i] + element <= MAX) {
                num[i] += element;
                if (DFS(idx+1, matchsticks, MAX)) {
                    return true;
                }
                num[i] -= element;
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        num.assign(4,0);
        double sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int MAX = sum / 4;
        
        if (sum / 4 != MAX) return false;
        
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        
        return DFS(0, matchsticks, MAX);
    }
};
