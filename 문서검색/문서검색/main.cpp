#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    
    string input;
    string search;
    
    getline(cin, input);
    getline(cin, search);
    
    int cnt = 0;
    //0. npos를 반납할 때까지,
    int idx = 0;
    int start = 0;
    idx = input.find(search);
    if( idx != string::npos ) cnt++;
    start = idx + search.length();
    while ( idx != string::npos) {
    //1. find(search)
        idx = input.find(search, start);
        if( idx != string::npos ) cnt++;
    //2. 돌려받은 인덱스 + 1 부터 다시 find(search)
        start = idx + search.length();
    }
    
    cout << cnt << endl;
    return 0;
}
