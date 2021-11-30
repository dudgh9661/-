class Solution {
public:
    int ans = 0;
    
    bool visited[16] = {false};
    vector<int> vec;
    
    bool firstCond(int per, int idx) {
        if (per % idx == 0) return true;
        return false;
    }
    
    bool secondCond(int per, int idx) {
        if (idx % per == 0) return true;
        return false;
    }
    
    bool check(int per, int idx) {
        if (firstCond(per, idx) || secondCond(per, idx)) return true;
        return false;
    }
    
    void DFS(int n, int curIdx) {
        if (vec.size() == n) {
            // for (auto v : vec) cout << v << " ";
            // cout << endl;
            ans++;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            if (!check(i,curIdx)) continue;
            visited[i] = true;
            vec.push_back(i);
            DFS(n, curIdx + 1);
            vec.pop_back();
            visited[i] = false;
        }
    }
    int countArrangement(int n) {
        DFS(n, 1);
        return ans;
    }
};
