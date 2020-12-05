#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> vec; //알파벳이 담겨있는 배열
vector<char> tmp; //만들어진 암호가 담겨있는 배열
bool visited[26] = { false };

bool isMoum(vector<char> tmp, vector<char> moum) { //만들어진 암호인 tmp안에 모음이 있나 확인한다.
    for(int i = 0; i < tmp.size(); i++) {
        for(int j = 0; j < 5; j++) {
            if( tmp[i] == moum[j] ) return true;
        }
    }
    return false;
}
bool isJaum(vector<char> tmp, vector<char> moum) {
    int cnt = 0;
    int flag = 0;
    for(int i = 0; i < tmp.size(); i++) {
        flag = 0;

        for(int j = 0; j < moum.size(); j++) {
            if( tmp[i] == moum[j] ) {
                flag = 1;
                break;
            }
        }
        if ( flag == 0 ) {
            cnt++;
            if (cnt >= 2) return true;
        }

    }
    return false;
}
void ansPrint(vector<char> tmp) {
    for(int i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
    }
    cout << "\n";
}
void init() {
    cin >> L >> C;
    char input;
    for(int i = 0; i < C; i++) {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), less<>());
//    cout << " 정렬 : ";
//    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
//    cout << "\n";
}

void DFS(int cnt, vector<char> moum, int start) {
    if( cnt == L ) {
        if( isMoum(tmp, moum) && isJaum(tmp, moum) ) {
            //조건이 만족한 것이므로 출력한다.
//            cout << "true !! " << isMoum(tmp, moum) << isJaum(tmp, moum) << endl;
            ansPrint(tmp);
            return;
        }
        else {
//            cout << "false !! " << isMoum(tmp, moum) << isJaum(tmp, moum) << endl;
//            ansPrint(tmp);
        }
    }

    for(int i = start; i < vec.size(); i++) {
        char alpha = vec[i];
        int idx = alpha % 97;

        if( !visited[idx] ) {
            visited[idx] = true;
            tmp.push_back(alpha);
            DFS(cnt+1, moum, i+1);
            visited[idx] = false;
            tmp.pop_back();

        }
    }
}
int main() {
    vector<char> moum{'a','e','i','o','u'};
    init();
    DFS(0, moum, 0);
    return 0;
}
