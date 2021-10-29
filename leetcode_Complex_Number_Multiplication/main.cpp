class Solution {
public:
    string resultI = "";
    
    string multi(string s1, string s2) {
        string s1Num = s1;
        string s2Num = s2;
        string s1i = "";
        string s2i = "";
        
        int s1Pos = s1.find("i");
        int s2Pos = s2.find("i");
        
        string ans = "";
        
        if (s1Pos != string::npos) {
            s1Num = s1.substr(0, s1Pos);
            s1i = s1.substr(s1Pos,-1);
        }
        if (s2Pos != string::npos) {
            s2Num = s2.substr(0, s2Pos);
            s2i = s2.substr(s2Pos,-1);
        }
        
        string convertNum = to_string(stoi(s1Num)*stoi(s2Num));
        ans = convertNum + s1i + s2i;
         
        // cout << "before : " << ans << endl;
        
        int cnt = count(ans.begin(), ans.end(), 'i');
        // cout << " cnt : " << cnt << endl;
        if (cnt == 2) {
            ans = to_string(stoi(convertNum)*-1);
        }
        
        // cout << s1 << " * " << s2 << " convert : " << ans << endl;
        
        return ans;
    }
    
    bool containI(string s) {
        if (s.find("i") != string::npos) return true;
        return false;
    }
    
    void getResult(string input) {
        int pos = input.find("i");
        int num = stoi(input.substr(0, pos));
        if (resultI.empty()) {
            resultI = input;
            return;
        }
        int resNum = stoi(resultI.substr(0,resultI.find("i")));
        resultI = to_string(num + resNum) + "i";
    }
    string complexNumberMultiply(string num1, string num2) {
        string ans = "";
        int pos = num1.find("+");
        string s1 = num1.substr(0, pos);
        string _s1 = num1.substr(pos+1,-1);
        
        // cout << "_s1 : " << _s1 << endl;
        
        pos = num2.find("+");
        string s2 = num2.substr(0,pos);
        string _s2 = num2.substr(pos+1,-1);
        
        // cout << "_s2 : " << _s2 << endl;
        
        string res = multi(s1,s2);
        int resultNum = 0;
        if (containI(res)) getResult(res);
        else resultNum += stoi(res);
        
        res = multi(s1,_s2);
        if (containI(res)) getResult(res);
        else resultNum += stoi(res);
        
        res = multi(_s1,s2);
        if (containI(res)) getResult(res);
        else resultNum += stoi(res);
        
        res = multi(_s1,_s2);
        if (containI(res)) getResult(res);
        else resultNum += stoi(res);
        
        ans = to_string(resultNum) + "+" + resultI;
        // cout << ans << endl;
        
        return ans;
    }
};
