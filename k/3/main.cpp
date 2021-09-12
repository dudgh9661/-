#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct Time{
    int hour;
    int min;
};

struct Info{
    Time t;
    string status;
};

multimap<string, Info> parkingStatus;
map<string, int> parkingFee;
//map<string, int> parkingTime;

Time splitTime(string t) {
   int s = 0;
   int p = t.find(':');
   string hour = t.substr(s, p-s);
   string min = t.substr(p+1,-1);
   return {stoi(hour), stoi(min)};
}
void makeInfo(string str) {
    vector<string> tmp;
    int s = 0;
    int p = str.find(' ');
    string res = str.substr(s, p-s);
    tmp.push_back(res);

    while ( p != string::npos) {
        s = p + 1;
        p = str.find(' ', s);
        res = str.substr(s, p-s);
        if (res.empty()) break;
        tmp.push_back(res);
    }
    string t = tmp[0];
    string carNum = tmp[1];
    parkingFee.insert({carNum, 0}); // 주차된 차량 정보 초기화
    string status = tmp[2];
    parkingStatus.insert({carNum, Info({splitTime(t), status})});
}

int getTotalTime(string carNum) {
    int totalTime = 0;
    vector<Info> tmp[2]; //차 번호에 해당하는 데이터들을 저장한다.
    for(auto itr = parkingStatus.lower_bound(carNum); itr != parkingStatus.upper_bound(carNum); itr++) {
        if (itr->second.status == "IN") tmp[0].push_back(itr->second);
        else if (itr->second.status == "OUT") tmp[1].push_back(itr->second);
    }

    for(int i = 0; i < tmp[0].size(); i++) {
        int IN = tmp[0][i].t.hour * 60 + tmp[0][i].t.min;
        int OUT = 23 * 60 + 59; //default
        if ( i < tmp[1].size() ) { // 주의
            OUT = tmp[1][i].t.hour * 60 + tmp[1][i].t.min;
        }
        totalTime += OUT - IN;
    }

    cout << carNum << " pay is " << totalTime << endl;
    return totalTime;
}

int getFee(vector<int> fees, string carNum) {
    int fee = 0;
    int defaultMin = fees[0];
    int defaultOne = fees[1];
    int unitMin = fees[2];
    int unitOne = fees[3];

    int totalTime = getTotalTime(carNum);

    if (totalTime <= defaultMin) fee = defaultOne;
    else {
        fee += defaultOne;
        int overTime = totalTime - defaultMin;
        if (overTime % unitMin != 0 ) {
            overTime = overTime / unitMin + 1;
        } else {
            overTime = overTime / unitMin;
        }
        fee += overTime * unitOne;
    }

    return fee;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(string str : records) {
        makeInfo(str);
    }

    for(auto info : parkingStatus) {
        cout << info.first << " : " << " 시간 : " << info.second.t.hour << info.second.t.min << " 상태 : " <<info.second.status << endl;
    }

    for(auto info : parkingFee) {
        string carNum = info.first;
        parkingFee[carNum] = getFee(fees, carNum);
    }

    for(auto info : parkingFee) {
        answer.push_back(info.second);
    }
//    cout << getFee(fees, "0148");
    return answer;
}

int main() {
    solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
    return 0;
}