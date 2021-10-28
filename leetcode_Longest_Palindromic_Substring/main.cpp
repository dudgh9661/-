class Solution {
public:
    
    string expand(int left, int right, string s) {
        while (true) {
            left -= 1;
            right += 1;
            if (left < 0 || right > s.length()-1 || s[left] != s[right]) {
                left += 1;
                right -= 1;
                break;
            }
        }
        return s.substr(left, right - left + 1);
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            string str1 = expand(i, i, s);
            string str2 = "";
            if (s[i] == s[i+1] ) str2 = expand(i, i+1, s);
            if (str1.length() > str2.length()) {
                if (ans.length() < str1.length()) ans = str1;
            } else if (str1.length() < str2.length()) {
                if (ans.length() < str2.length()) ans = str2;
            }
        }
        cout << ans << endl;
        return ans;
    }
};
