#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MAX = -1;
int A,B;
string strA, strB;

string getSubStrB(int len) {
    return strB.substr(0, len);
}

void DFS(string tmpStr, vector<bool> &visited) {
//    if (tmpStr.length() > 0 && stoi(tmpStr) > stoi(getSubStrB(tmpStr.length())) ) {
//        cout << "false case : " << tmpStr << endl;
//        return;
//    }
    if ( tmpStr.length() == strA.length() && stoi(tmpStr) < B ){
//        cout << tmpStr << endl;
        MAX = max(stoi(tmpStr), MAX);
        return;
    }

    for (int i = 0; i < strA.length(); i++) {
        if (visited[i]) continue;
        if (tmpStr[0] == '0') continue;
        visited[i] = true;
        tmpStr.push_back(strA[i]);

        DFS(tmpStr, visited);
        tmpStr.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin >> A >> B;
    strA = to_string(A);
    strB = to_string(B);

    vector<bool> visited(strA.length(), false);
    DFS("", visited);
    cout << MAX;
    return 0;
}
