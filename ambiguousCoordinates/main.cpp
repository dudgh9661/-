class Solution {
public:
    vector<string> answer;
    
    bool zeroCheck(string s, int idx) {
        for (int i = idx; i < s.size(); i++) {
            if (s[i] != '0') return true;
        }
        return false;
    }
    
    vector<string> DFS(string s, vector<string> vec, int idx) {
        if (idx == s.length() - 1) {
            vec.push_back(s);
            return vec;
        }
        
        
        if (s[0] == '0') {   
            string res = "0." +  s.substr(1);
            vec.push_back(res);
            return vec;
        }
        
        if (s[s.size()-1] == '0') {
            vec.push_back(s);
            return vec;
        }
        
        string str = s.substr(0,idx+1) + "." + s.substr(idx+1);
        vec.push_back(str);
        return DFS(s, vec, idx+1);
    }
    
    void makeAns(vector<string> v1, vector<string> v2) {
        for (auto s1 : v1) {
            string input = "(" + s1 + ", ";
            for (auto s2 : v2) {
                string input2 = s2 +")";
                answer.push_back(input + input2);
            }
        }
    }
    
    vector<string> ambiguousCoordinates(string s) {
        string input = s.substr(1, s.length()-2);
        for (int i = 0; i < input.length()-1; i++) {
            string s1 = input.substr(0,i+1);
            string s2 = input.substr(i+1);
            if (s1.size() > 1) {
                if (s1[0] == '0' && !zeroCheck(s1,0)) continue;
                if (s1[0] == '0' && s1[s1.size()-1] == '0') continue;
            }
            
            if (s2.size() > 1) {
                if (s2[0] == '0' && !zeroCheck(s2,0)) continue;
                if (s2[0] == '0' && s2[s2.size()-1] == '0') continue;
            }
        
            // cout << "s1 : " << s1 << endl;
            // cout << "s2 : " << s2 << endl;
            vector<string> s1Vec = DFS(s1, vector<string> {}, 0);
            vector<string> s2Vec = DFS(s2, vector<string> {}, 0);
            makeAns(s1Vec, s2Vec);
        }
        return answer;
    }
};
