class Solution {
public:
    vector<string> ans;
    vector<string> convert;
    
    vector<string> split(string input) {
        vector<string> result;
        int start = 0;
        int pos = input.find(" ");
        string str = input.substr(start, pos - start);
        result.push_back(str);
        
        while (pos != string::npos) {
            start = pos + 1;
            pos = input.find(" ", start);
            str = input.substr(start, pos - start);
            result.push_back(str);
        }
        
        return result;
        
    }
    
    int getMaxLen() {
        int MAX = -1;
        for (int i = 0; i < convert.size(); i++) {
            MAX = max((int)convert[i].size(), MAX);
        }
        
        return MAX;
    }
    
    string endTrim(string input) {
        int idx = -1;
        for (int i = input.size()-1; i >= 0; i--) {
            if(input[i] != ' ') {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            return input.substr(0, idx+1);
        } else return input;
    }
    
    vector<string> printVertically(string s) {
        convert = split(s);
        int maxLen = getMaxLen();
        
        for (int i = 0; i < maxLen; i++) {
            string res = "";
            for (int j = 0; j < convert.size(); j++) {
                if (convert[j].size() <= i) res.push_back(' ');
                else res.push_back(convert[j][i]);
            }
            ans.push_back(endTrim(res));
        }
        
        for (string str : ans) {
            cout << str << endl;
        }
        
        return ans;
    }
};
