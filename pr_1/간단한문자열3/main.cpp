#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vector<string> vec;
    for(int i = 0; i < input.length(); i++) {
        string sub = input.substr(i);
        vec.push_back(sub);
    }

    sort(vec.begin(), vec.end(), less<string>());

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}
