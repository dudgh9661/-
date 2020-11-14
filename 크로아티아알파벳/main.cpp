#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;
    int sum = 0;
    vector<int> vec(8, 0);
    vector<string> str;

    int cnt = 0;

    str.push_back("c=");
    str.push_back("c-");
    str.push_back("dz=");
    str.push_back("d-");
    str.push_back("lj");
    str.push_back("nj");
    str.push_back("s=");
    str.push_back("z=");

    for(int i = 0; i < 8; i++ ) {

        int start = 0;
        int pos = 0;
        string star = "";
        for(int k = 0; k < str[i].length(); k++ ) {
            star +=  "*";
        }
        // cout << "star : " << star << endl;

        string sbstr;

        // for(int j = 0; j < input.length(); j++) {
            // cout << "찾으련느 문자열 : " << str[i] << endl;
            pos = input.find(str[i]);
            
            while( pos != string::npos) {
                vec[i] += 1;
                cnt++;
                sbstr = input.substr(pos, str[i].length());
                // cout << "sbstr : " << sbstr << endl;
                input.replace(pos, str[i].length(), star);
                start = pos + str[i].length();
                pos = input.find(str[i], start);
                // printf("pos : %d , i : %d\n", pos, i);
            }

        // }
    }

    int checkedSum = 0;
    int answer = 0;
    for(int i = 0; i < 8; i++) {
        checkedSum = checkedSum + vec[i] * str[i].length();
    }

    answer = cnt + ( input.length() - checkedSum);

    // printf("test : %d %d\n", vec[6], vec[7]);
    // printf("cnt : %d", cnt);
    printf("%d\n", answer);
    return 0;
}