class Solution {
public:
    char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int val[7] = { 1, 5, 10, 50, 100, 500, 1000};
    
    int res = 0;
    
    int findIdx(char c) {
        for(int i = 0; i < 7; i++) {
            if (ch[i] == c) return i;
        }
        return -1;
    }
    
    int romanToInt(string s) {
        for (int i = 0; i < s.length(); i++) {
            int curIdx = findIdx(s[i]);
            if (s.length()-1 != i) {                
                int nextIdx = findIdx(s[i+1]);
                if (curIdx < nextIdx) {
                    res += val[nextIdx] - val[curIdx];
                    i = i+1;
                    continue;
                } else {
                    res += val[curIdx];
                }
            } else {
                res += val[curIdx];
            }
        }
        return res;
    }
};
