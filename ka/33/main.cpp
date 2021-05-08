#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

list<int> lst;
queue<int> que;
list<int>::iterator curItr;

vector<string> split(string str, char ch) {
    vector<string> splitStr;
    int start = 0;
    int pos = 0;
    pos = str.find(ch,start);
    string s = str.substr(start, pos - start);
    splitStr.push_back(s);

    while( pos != string::npos ) {
        start = pos + 1;
        pos = str.find(ch, start);
        s = str.substr(start, pos - start);
        splitStr.push_back(s);
    }

    for( string S : splitStr) {
        cout << S << endl;
    }
    return splitStr;
}

void cmdUX(int num) {
    for(int i = 0; i < num; i++) {
        curItr--;
    }
}
void cmdDX(int num) {
    for(int i = 0; i < num; i++) {
        curItr++;
    }
}
void cmdC() {
    que.push(*curItr);
    curItr = lst.erase(curItr);
    if( curItr == lst.end() ) curItr--;
}
void cmdZ() {
    int idx = que.front();
    que.pop();

    for( auto itr = lst.begin(); itr != lst.end(); itr++) {
        if( *itr == idx - 1) {
            lst.insert(itr,idx);
        }
    }
}

void Print() {
    for( auto itr = lst.begin(); itr != lst.end(); itr++) {
        cout << *itr << " ";
    }
}
void init(int n, int k) {
    for(int i = 0; i < n; i++) {
        lst.push_back(i);
    }
    curItr = lst.begin();
    for(int i = 0; i < 2; i++) {
        ++curItr;
    }
    cout << *curItr << endl;
}
string solution(int n, int k, vector<string> cmd) {
    //"0X000000"
    init(n,k);

    for(int i = 0; i < cmd.size(); i++) {
        string str = cmd[i];
        if( str.size() > 2 ) {
            vector<string> splitStr = split(str, ' ');
            if( "D" == splitStr[0] ) {
                cmdDX(stoi(splitStr[1]));
            }
        }
    }
    cmdC();
    Print();
    string answer = "";
    return answer;
}

int main() {

    //"D 2","C","U 3","C","D 4","C","U 2","Z","Z"
    solution(8,2,{"D 2"});
    return 0;
}