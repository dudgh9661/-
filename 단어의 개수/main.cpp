#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

multiset<string> st;

void trim(string &str) {
    while (!isalpha(str.front())) {
        if (str.empty()) break;
        str = str.substr(1,-1);
    }
    while (!isalpha(str.back())) {
        if (str.empty()) break;
        str.pop_back();
    }
}

void split(string &str) {
    int start = 0;
    int pos = str.find(' ', start);
    string res = str.substr(start, pos - start);
    st.insert(res);


    while (pos != string::npos) {
        start = pos + 1;
        pos = str.find(' ', start);
        res = str.substr(start, pos - start);
        if ( res.empty() ) break;
        st.insert(res);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin,str);
    trim(str);
    if (str.length() != 0 ) {
        split(str);
    }

    cout << st.size();
    return 0;
}

