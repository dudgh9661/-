#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

char square[1001][1001]; //0=>dummy
vector<pair<int,int>> point; //x,y
vector<int> LIMIT;

void init() {
    for(int i = 0; i < 1000; i ++) {
        for(int j= 0; j < 1000; j++) {
            square[i][j] = '.';
        }
    }
}
bool isJungsu(double a) {
    if( a - (int)a == 0 ) return true;
    else return false;
}

void crossPoint(vector<int> a, vector<int> b) {
    int A = a[0]; int B = a[1]; int E = a[2];
    int C = b[0]; int D = b[1]; int F = b[2];

    double x, y;
    long long xup = ((B*F)-(E*D));
    long long xdn = ((A*D)-(B*C));
//    cout << "xdn : " << xdn << endl;
    if( xdn != 0 ) {
        x = (float)xup / xdn;
        long long yup = ((E*C)-(A*F));
        long long ydn = ((A*D)-(B*C));
        y =  (float)yup / ydn;
    } else if ( xdn == 0 ) {
//        cout << "평행한 경우 " << endl;
        return;
    }
    //두 좌표가 정수인 경우 저장,
    if( isJungsu(x) && isJungsu(y) ) {
        point.push_back({x,y});
    }
}

void limitLine() {
    int colMax = -1000000, colMin = 1e9, rowMax = -1000000, rowMin = 1e9;

    for(int i = 0; i < point.size(); i++) {
        colMax = max(point[i].first, colMax);
        colMin = min(point[i].first, colMin);

        rowMax = max(point[i].second, rowMax);
        rowMin = min(point[i].second, rowMin);
    }
//    printf("col max : %d, min : %d \n row max : %d, min : %d\n", colMax, colMin, rowMax, rowMin);
    LIMIT.push_back(rowMax);
    LIMIT.push_back(rowMin);
    LIMIT.push_back(colMin);
    LIMIT.push_back(colMax);

}

void Print(vector<string> &answer) {
//    cout << LIMIT[0] <<  LIMIT[1] << LIMIT[2] << LIMIT[3] << endl;
    for(int row = LIMIT[0]; row >= LIMIT[1]; row--) { // 4 ~~~ -4
        string res;
        for(int col = LIMIT[2]; col <= LIMIT[3]; col++) { // -4 ~~ 4
            bool star = false;
            for(int i = 0; i < point.size(); i++) {
//                cout << "현재 좌표(col,row) : " << col <<"," << row;
                if (point[i].second == row && point[i].first == col) {
//                    cout << '*';
                    res += '*';
                    star = true;
                    break;
                }
            }
            if( !star ) {
//                cout << '.';
                res += '.';
            }
        }
        answer.push_back(res);
//        cout << "\n";
    }
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    init();
    //정수인 좌표들 저장
    for(int i = 0; i < line.size(); i++) {
        for(int j = i+1; j < line.size(); j++)
            crossPoint(line[i], line[j]);
    }
    //정수인 좌표들을 기반으로 그림 그리기
    limitLine();
//    cout << "point test" << endl;
//    for(int i = 0; i < point.size(); i++) {
//        cout << point[i].first << "," << point[i].second << endl;
//    }

    Print(answer);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return answer;
}

int main() {
    //{{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}}
    //{{0, 1, -1}, {1, 0, -1}, {1, 0, 1}}
    //{{1, -1, 0}, {2, -1, 0}}
    //{{1, -1, 0}, {2, -1, 0}, {4, -1, 0}}
    solution({{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}});
    return 0;
}