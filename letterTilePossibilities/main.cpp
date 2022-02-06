class Solution {
public:
    set<string> st;
    bool visited[7] = { false };
    
    void DFS(string str, string tiles) {
        if (!str.empty()) st.insert(str);
        
        if (str.length() == tiles.length()) {
            return;
        }
        
        for (int i = 0; i < tiles.length(); i++) {
            if (visited[i]) continue;
            
            visited[i] = true;
            str.push_back(tiles[i]);
            
            DFS(str, tiles);
            
            str.pop_back();
            visited[i] = false;
        }
    }
    
    int numTilePossibilities(string tiles) {
        DFS("", tiles);
        
        // for (string s : st) {
        //     cout << s << endl;
        // }
        
        return st.size();
    }
};
