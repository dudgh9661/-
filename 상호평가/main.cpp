#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 만약, 학생들이 자기 자신을 평가한 점수가 유일한 최고점 또는 유일한 최저점이라면 그 점수는 제외하고 평균을 구합니다.
vector<vector<int>> scoreCopy;

bool isOnly(int studentNum, vector<int> score) {
    
    int selfScore = score[studentNum];
    bool minFlag = true;
    bool maxFlag = true;
    
    for(int i = 0; i < score.size(); i++) {
        
        if (i != studentNum && selfScore == score[i]) return false;
        else if (selfScore > score[i]) minFlag = false;
        else if (selfScore < score[i]) maxFlag = false;
    }

    return minFlag || maxFlag;
}

double getScore(int studentNum, vector<int> score) {
    int sum = 0;
    double ans = 0;
    int n = score.size();
    // cout << studentNum << " is only " << isOnly(studentNum, score) << endl;
    if (isOnly(studentNum, score)) {
        for(int i = 0; i < score.size(); i++) {
            if (i == studentNum) continue;
            sum += score[i];
        }
        ans = sum / (n-1);
    } else {
        for(int s: score) {
            sum += s;
        }
        ans = sum / n;
    }
    // cout << studentNum << " : " << " sum : " << sum << " ans :" << ans << endl;
    return ans;
}

char getGrade(double score) {
    char grade;
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 50) grade = 'D';
    else grade = 'F';
    
    return grade;
}
void copyVec(vector<vector<int>> scores) {
    vector<int> vec;    
    for(int i = 0; i < scores.size(); i++) {
        vec.clear();
        for(int j = 0; j < scores.size(); j++) {
            vec.push_back(scores[j][i]);
        }
        scoreCopy.push_back(vec);
    }
}
string solution(vector<vector<int>> scores) {
    string answer = "";
    copyVec(scores);
    
    for(int i = 0; i < scoreCopy.size(); i++) {
        answer.push_back(getGrade(getScore(i,scoreCopy[i])));
    }
    cout << answer;
    return answer;
}
