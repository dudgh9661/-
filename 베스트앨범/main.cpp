#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> playCnt;
unordered_map<string, unordered_map<int,int>> info;

struct INFO {
    string genre;
    int id;
    int cnt;
};

vector<INFO> infoVec;

void getPlayCnt(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++) {
        playCnt[genres[i]] += plays[i];
    }
}

void getInfo(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++) {
        info[genres[i]].insert({i,plays[i]});
    }
}

bool cmp(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}
vector<pair<string,int>> sortPlay() {

    vector<pair<string,int>> tmp;
    for (auto itr = playCnt.begin(); itr != playCnt.end(); itr++) {
        tmp.push_back(*itr);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    return tmp;
}

bool cmp2(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
void sortInfo() {
    //1. info의 second 값을 뽑는다.
    //2. vector를 이용해 second 값의 횟수 내림차순으로 정렬
    //3. infor->first에 정렬된 vector값들을 삽입
    for (auto itr = info.begin(); itr != info.end(); itr++) {
        vector<pair<int,int>> tmp;
        auto tmpMp = itr->second;
        for (auto itr2 = tmpMp.begin(); itr2 != tmpMp.end(); itr2++) {
            tmp.push_back(*itr2);
        }
        sort(tmp.begin(), tmp.end(), cmp2);
        cout << "정렬" << endl;
        for (auto v : tmp) {
            cout << v.first << " , " << v.second << endl;
        }
        for(auto v : tmp) {
            infoVec.push_back({itr->first, v.first, v.second}); //장르, id, 횟수
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //각 장르 별 총 재생횟수
    getPlayCnt(genres, plays);
    //재생횟수가 높은 순으로 장르를 정렬한다.
    vector<pair<string,int>> sortPlayCnt = sortPlay();
    getInfo(genres, plays);
    sortInfo();

//     for (auto itr = info.begin(); itr != info.end(); itr++) {
//         cout << "genre : " << itr->first;
//         auto tmp = itr->second;
//         for (auto itr2 = tmp.begin(); itr2 != tmp.end(); itr2++) {
//             cout << " 고유 번호 : " << itr2->first << " 횟수 : " << itr2->second;
//         }
//         cout << endl;
//     }

    for (int i = 0; i < sortPlayCnt.size(); i++) {
        string genre = sortPlayCnt[i].first;
        int cnt = 2;
        for (int j = 0; j < infoVec.size(); j++) {
            if (cnt == 0) break;
            if (infoVec[j].genre == genre) {
                answer.push_back(infoVec[j].id);
                cnt--;
            }
        }
    }
    return answer;
}
