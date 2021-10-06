class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0);
        string result = "";
        
        for(int i = num1.size()-1; i >= 0; i--) {
            for(int j = num2.size()-1; j>= 0; j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = ans[i+j+1] + mul;
                ans[i+j] += sum / 10;
                ans[i+j+1] = sum % 10;
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            if (result.length() == 0 && ans[i] == 0) continue;
            result.append(to_string(ans[i]));
        }
        
        if (result.empty()) return "0";
        return result;
    }
};
