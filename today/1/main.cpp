#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string str = "";
string res = "";

vector<pair<string, int> > vec;

void split() {

    for (int i = 0; i < str.length(); i++) {
        string base;
        base = str[i];
        if ( isdigit(str[i]) ) {
            continue;
        }
        for(int j = i + 1; j < str.length(); j++) {
            if ( !isdigit(str[j]) ) {
                string num =  str.substr(i+1, j - (i+1));
                vec.push_back({base,stoi(num)});
                break;
            } else {
                if ( j == str.length() - 1) {
                    string num = str.substr(i+1, -1);
                    vec.push_back({base,stoi(num)});
                }
            }
        }
    }

}
void sol(vector<bool> &visited) {
    for(int i = 0; i < vec.size(); i++) {
        if ( visited[i] ) continue;

        string ch = vec[i].first;
        int sum = vec[i].second;
        visited[i] = true;

        for(int j = i + 1; j < vec.size(); j++) {
            if ( ch == vec[j].first ) {
                sum += vec[j].second;
                visited[j] = true;
            }
        }
        string getStr = ch + to_string(sum);
        res.append(getStr);
    }
}
int main() {
    cin >> str;
    split();
    vector<bool> visited(vec.size(), false);
    sol(visited);
    cout << res << "\n";
    return 0;

}
