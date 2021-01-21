#include <iostream>
#include <vector>

using namespace std;

int N;

void sol() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N*(N-1)+i; j += N) {
            cout << j << " ";
        }
        cout << "\n";
    }
}
int main() {
    char input[100];
    cin >> input;
    string str;
    str = input;
    cout << "input : " << input << endl;
    N = stoi(str);
    sol();


    return 0;
}