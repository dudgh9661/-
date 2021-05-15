#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input;
string change;

int arr[26] = { 0 } ;

void init() {
    cin >> input;
}
int main() {
    int cnt = 0;
    init();
    for(int i = 0; i < input.size(); i++) {
        if( isupper(input[i]) ) {
            change += tolower(input[i]);
        }
        else change += input[i];
    }

    for(int i = 0; i < change.size(); i++) {
        arr[change[i] - 97]++;
    }

    int MAX = *max_element(arr,arr+26);
    int maxIdx = max_element(arr,arr+26) - arr;

    for(int i = 0; i < 26; i++) {
        if( MAX == arr[i] ) cnt++;
        if( cnt > 1 ) {
            cout << "?" << endl;
            return 0;
        }
    }
    cout << char(toupper(char(maxIdx+97))) << endl;
    return 0;
}
