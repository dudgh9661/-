#include <string>
#include <vector>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int MaxDay = -1;

string strDay[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int monthDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool allHoliday[13][32] = { false }; //1~12월, 1일~31일
vector<pair<int,int>> holiVec; //month, day
vector<int> ansCnt;

string getDay(int month, int day) {
    int totalDay = 0;
    for(int i = 1; i < month; i++) {
        totalDay += monthDay[i-1];
    }
    totalDay += day - 1;
    int ansDay = ( 5 + totalDay ) % 7;
    return strDay[ansDay];
}
void makeHoliday() {
    for(int month = 1; month <= 12; month++) {
        for(int day = 1; day <= monthDay[month-1]; day++) {
            string today = getDay(month,day);
            if( today == "SUN" || today == "SAT" ) {
                allHoliday[month][day] = true;
            }
        }
    }
}

void split(string input) {
    string res;
    int start = 0;
    int pos = input.find('/');
    res = input.substr(start, pos - start);

    while( pos != string::npos) {
        start = pos + 1;
        pos = input.find('/', start);
        res += input.substr(start, pos - start);
    }

    //0124
    string month = res.substr(0,2);
    string day = res.substr(2);
    cout << month << " : " << day << endl;
    holiVec.push_back({stoi(month), stoi(day)});

    int intMonth = stoi(month);
    MaxDay = max(MaxDay, intMonth);

}

void makeInputHoliday() {
    for(int i = 0; i < holiVec.size(); i++) {
        int month = holiVec[i].first;
        int day = holiVec[i] .second;
        allHoliday[month][day] = true;
    }
}

void countHoliday() {
    int cnt = 0;
    for(int month = 1; month <= MaxDay; month++) {
        for(int day = 1; day <= monthDay[month-1]; day++) {
            if( allHoliday[month][day] ) {
                cnt++;
            } else {
                if( cnt > 0 ) ansCnt.push_back(cnt);
                cnt = 0;
            }
        }
    }
}
int solution(vector<string> holidays, int k) {
    int answer = -1;
    makeHoliday();
    //날짜를 쪼개서 holiVec에 저장
    for(int i = 0; i < holidays.size(); i++) {
        split(holidays[i]);
    }
    //holiVec을 이용해, 휴일 표시
    makeInputHoliday();
    //휴일 카운트
    countHoliday();

    sort(ansCnt.begin(), ansCnt.end(), greater<>());
    ansCnt.erase(unique(ansCnt.begin(), ansCnt.end()),ansCnt.end());
    answer = ansCnt[k-1];
    cout <<" ans !! :  " << answer << endl;
    for(int i = 0; i < ansCnt.size(); i++) {
        cout << ansCnt[i] << " ";
    }

    return answer;
}

int main() {
    vector<string> holidays = {"01/14","01/15","01/18","01/22","01/23","01/29","02/01","02/03","02/07"};
    int k = 1;
    solution(holidays,5);
    return 0;

}