#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tmp;

void Split(string test) {
//    string test = "a b c d e";


    int start = 0;
    int pos = test.find(" ");
    string sub = test.substr(start, pos - start);
    tmp.push_back(sub);

    while( pos != string::npos) {
        start = pos + 1;
        pos = test.find(" ", start);
        sub = test.substr(start, pos - start);
        tmp.push_back(sub);
    }
}

int main() {

   Split("a b c d e");

    for(int i = 0; i < tmp.size(); i++) {
        cout << " i : " << tmp[i] << endl;
    }
    return 0;
}
