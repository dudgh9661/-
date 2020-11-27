#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int error = 0;

vector<int> answer;
vector<int> vec;

void init() {
    vec.push_back(-100); //null
}
void parse(string input) {
    string res;
    int start = 0;
    int pos = input.find('-');
    if( pos == string::npos ) {
        if ( input.length() != 16 ) {
            cout << "error len" << endl;
            error = 1;
            return;
        }

        for(int i = input.length()-1; i >= 0 ; i--) {
            int a = input[i] - '0';
            vec.push_back(a);
        }
        return;
    }

    string substr = input.substr(0, pos);
    if( substr.length() != 4 ) {
        error = 1;
        return;
    }
    res += substr;

    while( pos != string::npos ) {
        start = pos + 1;
        pos = input.find('-', start);
        substr = input.substr(start, pos - start);
        if( substr.length() != 4 ) {
//            cout << " 길이 4 미만 " << "\n";
            error = 1;
            return;
        }
        res += substr;

//        cout << substr << endl;
    }

    if( res.length() != 16 ) {
        cout << " error len" << endl;
        error = 1;
        return;
    }

    for(int i = res.length()-1; i >= 0 ; i--) {
        int a = res[i] - '0';
        vec.push_back(a);
    }
}

int odd() {
    int sum = 0;

    for(int i = 1; i < vec.size(); i += 2) {
        sum += vec[i];
    }
    cout << "odd sum : " << sum << endl;
    return sum;
}
int even() {
    int sum = 0;

    for(int i = 2; i < vec.size(); i += 2) {
        int value = vec[i] * 2;
//        cout << "even "  << value << endl;
        string str = to_string(value);
        if ( str.length() == 2 ) {
            int one = str[0] - '0';
            int two = str[1] - '0';
//            cout << one << " , " << two << endl;
            sum += one + two;
            cout << str << " : " << one + two << endl;
        } else sum += value;
    }

    cout << "even sum : " << sum << endl;
    return sum;
}

void sol() {
    int sum = even() + odd();
//    cout << "sum : " << sum << "\n";
    if ( sum % 10 == 0 ) {
        answer.push_back(1);
    } else if ( sum % 10 != 0) {
        answer.push_back(0);
    }
    vec.clear();
    //연산 후 vec.clear()할 것!!!!!!
}
vector<int> solution(vector<string> card_numbers) {

    for(int i = 0; i < card_numbers.size(); i++) {
        init();
//        cout << i << "번째" << "\n";
        parse(card_numbers[i]);
//        cout << "size : " << vec.size() << "\n";
        if( error == 1 ) {
            answer.push_back(0);
            error = 0;
//            cout << "\n";
            continue;
        }
        sol();
//        cout << endl;
    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return answer;
}

int main() {
    solution({"3285376499342452"});
//    solution({"3285-3764-9934-2453", "3285376499342453", "3285-3764-99342453", "328537649934245", "3285376499342459", "3285-3764-9934-2452"});


}