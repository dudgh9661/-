#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long MAX = -100;
long long ANS;

bool visited[3] = { false };

string _operator[3] = {"-", "+", "*"};
vector<int> prior;

vector<string> uniqueOp;
vector<string> splitStr;

bool isOperator(string op) {
    for(int i = 0; i < 3; i++) {
        if( op == _operator[i] ) return true;
    }
    return false;
}

bool doPop(string s1, string s2) { //들어온, 들어있는
    int s1Idx = -1;
    int s2Idx = -1;

    for(int i = 0; i < uniqueOp.size(); i++) {
        if( s1 == uniqueOp[i] ) s1Idx = prior[i];
        if( s2 == uniqueOp[i] ) s2Idx = prior[i];
    }

//    cout << s1 << "의 우선순위 : " << s1Idx << endl;
//    cout << s2 << "의 우선순위 : " << s2Idx << endl;
    if( s1Idx <= s2Idx ) {
//        cout << s1 << " 은 " << s2 << " 보다 우선순위가 '낮다' " << endl;
        return true;
    }
    else {
//        cout << s1 << " 은 " << s2 << " 보다 우선순위가 '높다' " << endl;
        return false;
    }
}

void getUniqueOper(string exp) {
    string str;
    for(int i = 0; i < exp.size(); i++) {
        str = exp[i];
        if( isOperator(str) ) uniqueOp.push_back(str);
    }

    sort(uniqueOp.begin(), uniqueOp.end());
    uniqueOp.erase(unique(uniqueOp.begin(), uniqueOp.end()), uniqueOp.end());
}

void doSplit(string exp) {
    string str;
    int idx = 0;

    for(int start = 0; start < exp.size(); start++) {
        str = exp[start];
        if( isOperator(str) ) {
            string _split = exp.substr(idx, start - idx);
            splitStr.push_back(_split);
            splitStr.push_back(str);
            idx = start + 1;
        }
    }
    splitStr.push_back(exp.substr(idx, 0-1));
//    for(int i = 0; i < splitStr.size(); i++) {
//        cout << splitStr[i] << " ";
//    }
}

long long getResultOfOper(long long num, long long num2, string op) {
    if( op == "-" ) {
        return num - num2;
    } else if ( op == "+") {
        return num + num2;
    } else if ( op == "*" ) {
        return num * num2;
    }
}
long long getResult(queue<string> que) {
    stack<long long> resultSt;
    while( !que.empty() ) {
        if( isOperator(que.front()) ) {
            long long back = resultSt.top();
            resultSt.pop();
            long long front = resultSt.top();
            resultSt.pop();

             long long result = getResultOfOper(front,back,que.front());
//             cout << "연산값 : " << result << endl;
             resultSt.push(result);
        } else resultSt.push(stol(que.front()));
        que.pop();
    }

    long long ans = abs(resultSt.top());
    cout << " res : " << ans << endl;
    return ans;
}

void Print(queue<string> postfixQue) {
    while( !postfixQue.empty() ) {
        cout << postfixQue.front() << " ";
        postfixQue.pop();
    }
}
void getPostfix() {
    stack<string> st;
    queue<string> postfixQue;
    //스택을 이용해, queue에 후위연산자를 담는다.
    string str;
    for(int i = 0; i < splitStr.size(); i++) {
        str = splitStr[i];
        if( isOperator(str) ) {
            if( st.empty() ) st.push(str);
            else {
                bool flag = false;
                //st에 있는 요소들이 우선순위가 '들어오는 놈' 보다 높으면 다 빼준다.
                while( !st.empty() && doPop(str, st.top()) ) { //st.empty를 먼저 체크하는 점 중요!!
                    flag = true;
                    postfixQue.push(st.top());
                    st.pop();
                }
                if ( flag ) st.push(str);
                else st.push(str);
            }
        } else postfixQue.push(str);
    }
    //남은 것들 넣어주기
    while( !st.empty() ) {
        postfixQue.push(st.top());
        st.pop();
    }
//    Print(postfixQue);
//    cout << endl;
    ANS = getResult(postfixQue);
}

bool test = false;
void DFS(int cnt) {
    if( cnt == uniqueOp.size() ) {
//        for(int i = 0; i < uniqueOp.size(); i++) {
//            cout << uniqueOp[i] << " ";
//        }
//        cout << endl;
        //만들어진 우선순위 기준으로, 후위연산자를 만든다.
//        for(int i = 0; i < prior.size(); i++) {
//            cout << prior[i] << " ";
//        }
//        cout << endl;

        //만들어진 후위연산자로, 결과값을 계산한다.
        //최대, 최소값을 비교한다.
        getPostfix();
        MAX = max(MAX, ANS);
    }
    for(int i = 0; i < uniqueOp.size(); i++) {
        if( test ) return;
        if( visited[i] ) continue;

        prior.push_back(i);
        visited[i] = true;

        DFS(cnt + 1);

        prior.pop_back();
        visited[i] = false;
    }
}

long long solution(string expression) {
    long long answer = 0;
    getUniqueOper(expression);
    doSplit(expression);

    DFS(0);
    cout << MAX << endl;
    return answer;
}

int main() {
    //"100-200*300-500+20"
    //60420
    solution("50*6-3*2");
}
