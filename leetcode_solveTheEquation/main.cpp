class Solution {
public:
    vector<string> left;
    vector<string> right;
    
    void init(string equation) {
        queue<char> que;
        int pos = equation.find('='); // left : [0,pos-1], right : [pos+1, len-1]
        // left
        for (int i = 0; i < pos; i++) {
            char ch = equation[i];
            if (ch == '+' || ch == '-') {
                if (que.empty()) {
                    que.push(ch);
                    continue;
                }
                string res = "";
                while (!que.empty()) {
                    res.push_back(que.front());
                    que.pop();
                }
                left.push_back(res);
                que.push(ch);
            } else {
                que.push(ch);
            }
        }
        string tmp = "";
        while (!que.empty()) {
            tmp.push_back(que.front());
            que.pop();
        }
        left.push_back(tmp);
        que = queue<char>();
        
        // right
        for (int i = pos + 1; i < equation.size(); i++) {
            char ch = equation[i];
            if (ch == '+' || ch == '-') {
                if (que.empty()) {
                    que.push(ch);
                    continue;
                }
                string res = "";
                while (!que.empty()) {
                    res.push_back(que.front());
                    que.pop();
                }
                right.push_back(res);
                que.push(ch);
            } else {
                que.push(ch);
            }
        }
        tmp = "";
        while (!que.empty()) {
            tmp.push_back(que.front());
            que.pop();
        }
        right.push_back(tmp);
        que = queue<char>();
        
    }
    
    void move() {
        vector<string> leftTmp = left;
        vector<string> rightTmp = right;
        left.clear();
        right.clear();
        
        for (auto s : leftTmp) {
            // x가 들어있으면,
            string tmp = "";
            if (s.find('x') != string::npos) {
                left.push_back(s);
            } else {
                tmp = to_string(stoi(s) * -1);
                right.push_back(tmp);
            }
        }
        for (auto s : rightTmp) {
            string tmp = "";
            if (s.find('x') != string::npos) {
                tmp = s.substr(0, s.find('x'));
                if (tmp.empty()) tmp = "-x";
                else if (tmp == "+") tmp = "-x";
                else if (tmp == "-") tmp = "+x";
                else tmp = to_string(stoi(s.substr(0, s.find('x'))) * -1) + "x";
                left.push_back(tmp);
            } else {
                right.push_back(s);
            }
        }
    }
    
    int getSumForX() {
        int sum = 0;
        for (auto s : left) {
            int pos = s.find('x');
            string res = s.substr(0,pos);
            if (res.empty()) res = "1";
            else if (res.length() == 1) {
                if (res == "+") res = "1";
                else if (res == "-") res = "-1";
            }
        
            sum += stoi(res);
        }
        return sum;
    }
    
    int getSum() {
        int sum = 0;
        for (auto s : right) {
            sum += stoi(s);
        }
        return sum;
    }
    
    string solveEquation(string equation) {
        string ans = "";
        
        init(equation);
        for (auto s : left) cout << s << endl;
        cout << "right" << endl;
        for (auto s : right) cout << s << endl;
        
        cout << "after" << endl;        
        move();
        for (auto s : left) cout << s << endl;
        cout << "right" << endl;
        for (auto s : right) cout << s << endl;
        
        double leftSum = (double) getSumForX();
        double rightSum = (double) getSum();
        
        cout << "leftSum : " << leftSum << endl;
        cout << "rightSum : " << rightSum << endl;
        
        if (leftSum == 0 && rightSum != 0) {
            ans = "No solution";
        } else if (leftSum == 0 && rightSum == 0) {
            ans = "Infinite solutions";
        } else if ( rightSum == 0) {
            ans = "x=0";
        } else {
            double result = rightSum / leftSum;
            if ( (int) result == result) {
                ans = "x=" + to_string((int)result);
            } else {
                ans = "No solution";
            }
        }
        return ans;
    }
};
