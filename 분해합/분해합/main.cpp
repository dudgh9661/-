#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input = "";
    cin >> input;
//    cout << 1 << endl;
    int length = input.size();
    int stringToInteger = stoi(input);
//    cout << length << endl;
    int total = 0;
    int charToInteger = 0;
    int totalTmp = 0;
    string IntegerToString = "";
    for(int j = 0; j <= length*9; j++) {
        total = stringToInteger-(length*(9))+j;
        string totalString = to_string(total);
        int totalSize = totalString.size();
        IntegerToString = to_string(total);
        totalTmp = total;
//        cout << "totalTmp : " << totalTmp << endl;
        for(int i = 0; i < totalSize; i++) {
            charToInteger = IntegerToString[i]-'0';
            total += charToInteger;
//            cout << "cTi : " << charToInteger << " total : " << total << endl;
        }
        if( total == stringToInteger ) { //생성자가 나온 경우
//            cout << "wttttf" << endl;
            cout << totalTmp;
            return 0;
        }
        else total = 0;
    }
    
    
    
    return 0;
}
