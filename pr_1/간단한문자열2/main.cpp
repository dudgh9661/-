#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<string> vec;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        vec.push_back(input);
    }


    string answer = vec[0];
    for(int i = 1; i < vec.size(); i++) {
        string str = vec[i];
        for(int j = 0; j < str.length(); j++) {
            if( answer[j] != str[j] ) {
                answer[j] = '?';
            }
        }
    }

    cout << answer << endl;
    return 0;
}
