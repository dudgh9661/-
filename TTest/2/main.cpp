#include <iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;

char special[4] = {'!','@','#','$'};

bool isID(string input) { //소문자이거나, 숫자
    //islower : 소문자라면 1를 반환, 소문자가 아니라면 0을 반환
    int lowerCnt = 0, numCnt = 0;
    for(int i = 0; i < input.size(); i++) {
        if( islower(input[i]) != 0 ) {
            lowerCnt++;
        } else if ( isdigit(input[i]) != 0 ) {
            numCnt++;
        }
    }
    if( numCnt + lowerCnt == input.size() ) return true;
    else return false;
}

bool isPassword(string input) {
    int alphaCnt = 0, numCnt = 0, specialCnt = 0;
    if( input.size() < 8 || input.size() > 20 ) return false;

    for(int i = 0; i < input.size(); i++) {
        if( isalpha(input[i]) != 0 ) alphaCnt++;
        else if ( isdigit(input[i]) != 0 ) numCnt++;
        else {
            for(int itr = 0; itr < 4; itr++) {
                if( input[i] == special[itr] ) {
                    specialCnt++;
                    break;
                }
                return false;
            }
        }
    }
    if( alphaCnt >= 1 && numCnt >= 1 && specialCnt >= 1 ) return true;
    else return false;
}
int main()
{
    string id;
    string pw1;
    string pw2;
    cin >> id >> pw1 >> pw2;

//    cout << "test : " << isPassword(pw1);
    if( isID(id) && isPassword(pw1) && (pw1 == pw2) ) cout << "pass" << endl;
    else cout << "fail" << endl;
    return 0;
}