class Solution {
public:
    
    int getWordLength(string str) {
        vector<string> vec;
        int start = 0;
        int pos = str.find(' ');
        string subStr = str.substr(start, pos - start);
        vec.push_back(subStr);
        
        while (pos != string::npos) {
            start = pos + 1;
            pos = str.find(' ', start);
            subStr = str.substr(start, pos - start);
            if (subStr.empty()) break;
            vec.push_back(subStr);
        }
        return vec.size();
    }
    
    int mostWordsFound(vector<string>& sentences) {
        int MAX = 0;
        
        for (auto s : sentences) {
            MAX = max(MAX, getWordLength(s));
        }
        return MAX;
    }
};
