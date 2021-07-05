#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
int ans = 0;

vector<string> vec;

bool isExist(string str) {
    if(vec.empty()) return false;
    else if ( vec[vec.size()-1] == str ) return true;
    else return false;
}

void DFS(int cnt, int curIdx) {
    if( cnt == input.size() ) {
        ans++;
        return;
    }
    
    for(int i = curIdx; i < input.size(); i++) {
        if (input[i] == 'd') { // in case 'number'
            for(int itr = 0; itr < 10; itr++) { // 0 ~ 9
                string itos = to_string(itr);
                //1. int to string
                if( !isExist(itos) ) {
                    vec.push_back(itos);
                    DFS(cnt+1, i+1);
                    vec.pop_back();
                } else continue;
            }
        } else { // In case 'alpha'
            for(int itr = 0; itr < 26; itr++) { // 'a' ~ 'z'
                char alpha = 97 + itr;
                string alphaStr;
                alphaStr = alpha;
                if( !isExist(alphaStr) ) {
                    vec.push_back(alphaStr);
                    DFS(cnt+1, i+1);
                    vec.pop_back();
                }
            }
        }
    }
}
int main() {
    cin >> input;
    DFS(0,0);
    cout << ans;
}
