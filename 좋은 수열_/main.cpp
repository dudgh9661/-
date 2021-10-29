#include <iostream>
#include <vector>

using namespace std;

int N;
bool flag = false;

bool isBad(string s) {
    if (s.length() <= 1) return false;
    int idx = s.length()-1;
    int end = s.length()-1;
    string base = "";
    string another = "";

    while (true) {
        another = s.substr(idx, end-idx+1);
        base = s.substr(idx-(end-idx+1), end-idx+1);
//        cout << base << " <-> " << another << endl;
        if (another == base) return true;
        idx--;
        if ((end-idx+1)*2 > s.length()) break;
    }
    return false;
}

void DFS(int depth, string s, int limit) {
    if (flag) return;
    if (depth == limit && !isBad(s)) {
        cout << s << endl;
        flag = true;
        return;
    }
    if (isBad(s)) return;

    for (int i = 1; i <= 3; i++) {
        s.push_back((i+'0'));
        DFS(depth + 1, s, limit);
        s.pop_back();
        if (flag) return;
    }
}
int main() {
//    cout << isBad("");
    cin >> N;
    DFS(0, "", N);
    return 0;
}
