#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vec;
char arr[2];


// :, 공백 문자를 제거해라.
void Split(string input) {
    int start = 0;
    int pos = 0;
    int count = 0;

    for(int idx = 0; idx < input.length(); idx++) {
        count++;
        if(input[idx] == ':' || input[idx] == ' '|| input[idx] == '!') {
            pos = idx;
            break;
        }
    }

    string sub = input.substr(start, pos - start);
    vec.push_back(sub);

    while ( count < input.length() ) {
        start = pos + 1;

        for(int idx = start; idx < input.length(); idx++) {
            count++;
            if( input[idx] == ':' || input[idx] == ' ' || input[idx] == '!') {
                pos = idx;
                if( pos == start ) { //바로 다음에 문자가 뜨는 경우, 스타트를 하나 증가시켜주고 넘어간다
                    printf("is %d, %d\n", pos, start);
                    break;
                }

                sub = input.substr(start, pos - start);
                printf("%d, %d ", start, pos);
                cout << sub << endl;
                vec.push_back(sub);
                break;
            }
        }
    }
    start = pos + 1;
    sub = input.substr(start, (input.length() ) - start);
    vec.push_back(sub);

}

int main() {
    Split("a:b:c:d f g!abc");
    for(auto & i : vec) {
        cout << i << endl;
    }


    return 0;
}
