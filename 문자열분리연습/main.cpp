#include <iostream>
#include <string>

using namespace std;

void split(string input) {
    int start = 0;
    int pos = input.find(" ");
    cout << pos << endl;
    string sub = input.substr(start, pos - start);
    string res = sub;

    while( pos != string::npos ) {
        start = pos + 1;
        pos = input.find(" ", start);
        cout << start << "," << pos << endl;
        res += input.substr(start, pos - start);
    }

//    cout << res.length() << endl;
//    res += "";
//    cout << res.length() << endl;
    cout << res << endl;
}
int main() {

    split("123 456 789  11");
    return 0;
}
