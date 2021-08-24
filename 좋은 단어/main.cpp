#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
int ans = 0;

vector<string> vec;
stack<char> st;

void init() {
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        vec.push_back(str);
    }
}

void sol() {
    for(string str : vec) {
        for(int i = 0; i < str.length(); i++) {
            if (!st.empty()) {
                int top = st.top();
                if (str[i] == top) st.pop();
                else st.push(str[i]);
            } else if (st.empty()) st.push(str[i]);
        }
        if (st.empty()) ans++;
        //stack flush
        while (!st.empty()) st.pop();
    }
}
int main() {
    init();
    sol();
    cout << ans;
    return 0;
}
