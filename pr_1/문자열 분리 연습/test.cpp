//문자열 분리

//1. find함수는 찾은 문자열의 첫번째 idx를 반환한다.
//2. str1.substr(a,b)을 이용해서 a번재 인자부터 길이 b만큼 찾은 문자열을 뽑는다. 
//2. find(a, b) 문자열 a를 b번째부터 찾는다. 
//3. 언제까지 반복해야해? 찾는 문자열이 없을때까지

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string input;
    getline(cin, input);
    cout << input;
    vector<string> str;

    int start = 0;
    string subStr;
    int pos = input.find(" ", 0);
    printf("%d\n", pos);
    subStr = input.substr(start, pos - start );
    // str.push_back(subStr);

    while(pos != string::npos) {
        str.push_back(subStr);
        start = pos + 1;
        pos = input.find(" ", start);
        subStr = input.substr(start, pos - start );
        printf("(%d, %d)\n", start,pos);
        
    }
    
    subStr = input.substr(start, input.length() - start);
    str.push_back(subStr);

    for(int i = 0; i < str.size(); i++) {
        cout << "wtf : " << str[i] << endl;
    }
    return 0;
}