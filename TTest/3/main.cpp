#include <iostream>
#include <string>
#include <vector>

using namespace std;

string day[] = {"SUN", "MON", "THU", "WED","THR","FRI", "SAT"};
int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> vec;
string returnDay(int m, int d) {
    int sumDay = 0;
    for(int i = 1; i < m; i++) {
        sumDay += month[i-1];
    }
    sumDay += d - 1;

    int resDay = ( 5 + sumDay) % 7;
    return day[resDay];
}
void split(string str) {
    string res;
    int start = 0, pos = 0;
    pos = str.find(" ");
    res = str.substr(start, pos - start);
    vec.push_back(res);

    while( pos != string::npos) {
        start = pos + 1;
        pos = str.find(" ", start);
        res = str.substr(start, pos - start);
        vec.push_back(res);
    }
}
int main() {
    string str;
    getline(cin, str);
    split(str);
    int M = stoi(vec[0]);
    int D = stoi(vec[1]);
    if( M < 1 || M > 12 || D < 1 || D > 31 ) {
        cout << "ERROR" << endl;
        return 0;
    }
    if( M == 4 || M == 6 || M == 9|| M == 11) {
        if( D > 30 ) {
            cout << "ERROR" << endl;
            return 0;
        }
    }
    if( M == 2 ) {
        if ( D > 28 ) {
            cout << "ERROR" << endl;
            return 0;
        }
    }
    cout << returnDay(M,D);

    return 0;
}