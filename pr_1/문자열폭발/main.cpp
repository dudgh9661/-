#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string input;
    string boom;
    cin >> input;
    cin >> boom;

    int pos = input.find(boom);
    // printf("first pos : %d", pos);
    int start = 0;
    string str1;
    string str2;
    string sumStr = input;
    while( pos != string::npos) {
        str1 = sumStr.substr(start, pos - start);
       
        // cout << "str1 : " << str1 << endl;
        int nextpos = pos + boom.length();
        if( nextpos >= sumStr.length()) {
            sumStr = str1;
            break;
        }
        str2 = sumStr.substr(nextpos, sumStr.length() - nextpos );
        // printf("nextpos : %d %d", nextpos, sumStr.length() - nextpos );
        // cout << "str2 : " << str2 << endl;
        sumStr = str1 + str2;

        // cout << "In while sumStr : " << sumStr << endl;

        pos = sumStr.find(boom);

    }

    if( sumStr.compare("") == 0 ) printf("FRULA");
    else { cout << sumStr << endl;}
    return 0;
}