#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int N;

vector<string> vec;
vector<int> colPos;
vector<int> num[33];
vector<vector<int>> number;
vector<int> NUM;

bool  getNumber() {
    for(int i = 0; i < (4*N-1); i+=4) {
        vector<int> tmp;
        if (num[i].empty()) return false;
        for(int j = 0; j < num[i].size(); j++) {
            tmp.push_back(num[i][j]);
        }
        number.push_back(tmp);
    }

    return true;
}

void init() {
    cin >> N;
    string str;
    for(int i = 0; i < 5; i++) {
        cin >> str;
        vec.push_back(str);
    }

    for(int i = 0; i < (4*N-1); i+=4) {
        colPos.push_back(i);
    }
}

bool zero(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"#.#"},
                      {"#.#"},
                      {"#.#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool one(pair<int,int> p) {
    string str[5] = { {"..#"},
                      {"..#"},
                      {"..#"},
                      {"..#"},
                      {"..#"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool two(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"..#"},
                      {"###"},
                      {"#.."},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool three(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"..#"},
                      {"###"},
                      {"..#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool four(pair<int,int> p) {
    string str[5] = { {"#.#"},
                      {"#.#"},
                      {"###"},
                      {"..#"},
                      {"..#"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool five(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"#.."},
                      {"###"},
                      {"..#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool six(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"#.."},
                      {"###"},
                      {"#.#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool seven(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"..#"},
                      {"..#"},
                      {"..#"},
                      {"..#"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool eight(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"#.#"},
                      {"###"},
                      {"#.#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}
bool nine(pair<int,int> p) {
    string str[5] = { {"###"},
                      {"#.#"},
                      {"###"},
                      {"..#"},
                      {"###"}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            if (vec[i][p.second+j] == '#')
                if (str[i][j] == '.')
                    return false;
        }
    }
    return true;
}

void sol() {
    for(int col : colPos) { // col position
//        cout << "col : " << col << endl;
        for (int i = 0; i < 10; i++) {
            switch (i) {
                case 0:
                    if (zero({0,col})) {
                        num[col].push_back(0);
                    }
                    break;
                case 1:
                    if (one({0,col})) {
                        num[col].push_back(1);
                    }
                    break;
                case 2:
                    if (two({0,col})) {
                        num[col].push_back(2);
                    }
                    break;
                case 3:
                    if (three({0,col})) {
                        num[col].push_back(3);
                    }
                    break;
                case 4:
                    if (four({0,col})) {
                        num[col].push_back(4);
                    }
                    break;
                case 5:
                    if (five({0,col})) {
                        num[col].push_back(5);
                    }
                    break;
                case 6:
                    if (six({0,col})) {
                        num[col].push_back(6);
                    }
                    break;
                case 7:
                    if (seven({0,col})) {
                        num[col].push_back(7);
                    }
                    break;
                case 8:
                    if (eight({0,col})) {
                        num[col].push_back(8);
                    }
                    break;
                case 9:
                    if (nine({0,col})) {
                        num[col].push_back(9);
                    }
                    break;
            }
        }
    }
}

void DFS(int start, string str) {
    if (start >= number.size()) {
//        cout << "str : " << str << endl;
        NUM.push_back(stoi(str));
        return;
    }

    for(int i = 0; i < number[start].size(); i++) {
//        cout << number[start][i] << " ";
        str += (to_string(number[start][i]));
        DFS(start+1, str);
        str.pop_back();
    }
}

int main() {
    init();
    sol();
    if ( !getNumber()) {
        cout << -1;
        return 0;
    }

    double total = 0;

    int ten = pow(10, number.size()-1);
    for(int i = 0; i < number.size(); i++) {
        double sum = 0;
        for(int j = 0; j < number[i].size(); j++) {
            sum += number[i][j];
        }

//        cout << sum*ten/number[i].size() << " = " << sum << " * " << ten << " / " << number[i].size() << endl;
        total += (sum * ten) / (double)number[i].size();
        ten /= 10;
    }

//    for(int i = 0; i < number.size(); i++) {
//        cout << i << " : ";
//        for(int j = 0; j < number[i].size(); j++) {
//            cout << number[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << fixed << setprecision(6) << total << endl;
    return 0;
}
