class Solution {
public:

    bool DFS(long long n1, long long n2, string s, bool find) {
        if (s.empty() && find) return true;
        else if (s.empty() && !find) return false;

        long long n3 = n1 + n2;
        // cout << "substr :" << s << endl;
        // cout << n1 << " + " << n2 << " = " << n3 << endl;
        int len = min(s.length(), to_string(n3).length());

        if (n3 == stol(s.substr(0,len))) {
            if (s.length() - 1 < len) return true;
            return DFS(n2, n3, s.substr(len), true);
        } else {
            return false;
        }
    }

    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.length()-1; i++) {
            long long n1 = stol(num.substr(0,i));
            if (to_string(n1) != num.substr(0,i)) break;

            for (int j = 1; j < num.length(); j++) {
                long long n2 = stol(num.substr(i,j));
                if (to_string(n2) != num.substr(i,j)) break;

                if (i+j > num.length()-1) break;
                bool find = DFS(n1, n2, num.substr(i+j), false);
                if (find) return true;
            }
        }
        return false;
    }
};