#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

long long sum = 0;

stack<string> st;


string toEight(string input){
    int total = 0;
    int idx = 0;
    int num = 0;

    for(int i = input.length() - 1; i >= 0; i--) {
        num = input[i]-'0';
        if( idx == 0 ) {
            total += num;
            idx++;
        }
        else {
            total += num * 2 * idx;
            idx++;
        }
    }

    return to_string(total);

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input, sub, output;

    cin >> input;

    if( input.length() == 1 ) {
        cout << input << endl;
        return 0;
    }

    int tmp;
    for(int i = input.length() - 3; ; i-=3) {
//        cout << i << endl;
        if( i < 0 ) {
            sub = input.substr(0, tmp);
            output = toEight(sub);
            if( output != "0") st.push(output);
            break;
        }
       sub = input.substr(i, 3);
        tmp = i;
        output = toEight(sub);
//        cout << output << endl;
       st.push(output);
    }

    while ( !st.empty() ) {
        cout << st.top();
        st.pop();
    }


    return 0;
}
