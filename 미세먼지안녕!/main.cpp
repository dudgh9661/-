#include <iostream>
#include <vector>

using namespace std;

int R = 0, C = 0, T = 0;
int UD[4] = {-1, 0, 1, 0};
int LR[4] = {0, -1, 0, 1};

vector< vector<int> > room;
vector< vector<int> > info1;

typedef struct Aircleaner{
    int upR = 0, upC = 0;
    int downR = 0, downC = 0;
} AIRCLEANER;

AIRCLEANER aircleaner;

typedef struct spreadUpdate {
    int row = 0, col = 0, amount = 0;
} UPDATE;

vector< UPDATE > Update;

void PrintRoom() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    int flag = 0;
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++) {
        vector<int> tmp;

        for(int j = 0; j < C; j++) {
            int input = 0;
            cin >> input;
            if( input == -1 ) {
                if( flag == 1 ) {
                    aircleaner.downR = i;
                    aircleaner.downC = j;
                }
                else {
                    aircleaner.upR = i;
                    aircleaner.upC = j;
                    flag = 1;
                }
            }
            tmp.push_back(input);
        }

        room.push_back(tmp);
    }

//    PrintRoom();
//    cout << endl;
}
void spread(int currentR, int currentC) {
    int cnt = 0;
    int amount = 0;
    for(int i = 0; i < 4; i++) {
        UPDATE updateTMP;

        int nextR = currentR + UD[i];
        int nextC = currentC + LR[i];

        if( nextR < 0 || nextR >= R || nextC < 0 || nextC >= C || room[nextR][nextC] == -1) continue;

        cnt++;
        amount = room[currentR][currentC] / 5;
        updateTMP.amount = amount;
        updateTMP.row = nextR;
        updateTMP.col = nextC;
        Update.push_back(updateTMP);
//        cout << nextR << "," << nextC << " amount : " << amount << endl;
//        room[nextR][nextC] += amount;
//        cout << nextR << "," << nextC << " amount : " << amount << endl;

    }
    room[currentR][currentC] -= amount * cnt;
}
void doUpdate() {
    for(int i = 0; i < Update.size(); i++) {
        int row = Update[i].row;
        int col = Update[i].col;
        int amount = Update[i].amount;

        room[row][col] += amount;
    }
    Update.clear();
}
void spreadInfo() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if( room[i][j] != 0 && room[i][j] != -1 ) {
                vector<int> INFO;
                INFO.push_back(i);
                INFO.push_back(j);
//                cout << INFO[0] << "," << INFO[1] << " " << INFO.size() << endl;
                info1.push_back(INFO);

            }
        }
    }
}
void infoInit() {
    info1.clear();
}
void reverseT() {
    int line = 0;
    for(int i = aircleaner.upR-1; i > 0; i--) {
//        if ( i == 0 ) {
//            room[i-1][line] = 0;
//        }
//        else {
            room[i][line] = room[i-1][line];
//        }
    }

    line = 0;
    for(int i = 0; i < C; i++) {
        if( i == C-1 ) {
            break;
        }
        else room[line][i] = room[line][i+1];
    }

    line = C-1;
    for(int i = 0; i < aircleaner.upR; i++ ) {
        room[i][line] = room[i+1][line];
    }

    line = aircleaner.upR;
    for(int i = C-1; i > 0; i--) {
        if( i == 1 ) {
            room[line][i] = 0;
        }
        else room[line][i] = room[line][i-1];
    }

}
void normalT() {
    int line = 0;
    for(int i = aircleaner.downR+1; i < R-1; i++) {
        room[i][line] = room[i+1][line];
//        cout << i << "," << line << " and " << i+1 << "," << line << " ff : " << room[i+1][line] << endl;
    }

    line = R-1;
    for(int i = 0; i < C; i++) {
        if( i == C-1 ) {
            break;
        }
        else room[line][i] = room[line][i+1];
    }

    line = C-1;
    for(int i = R-1; i > aircleaner.downR; i--) {
        room[i][line] = room[i-1][line];
    }

    line = aircleaner.downR;
    for(int i = C-1; i > 0; i--) {

        if( i == 1 ) {
            room[line][i] = 0;
        }
        else {
//            cout << i << "," << line << " and " << i-1 << "," << line << " ff : " << room[i-1][line] << endl;
            room[line][i] = room[line][i-1];
        }
    }
}
void airclean() {
    reverseT();
    normalT();
}
int ans() {
    int answer = 0;

    for(int i = 0; i < R; i++) {
        for(int  j = 0; j < C; j++) {
            if( room[i][j] != 0 && room[i][j] != -1 ) {
                answer += room[i][j];
            }
        }
    }

    return answer;
}
int main() {
    init();

//    //spread에 들어가는 r,c에 대한 정보를 따로 저장해놔야함.
    for(int itr = 0; itr < T; itr++) {
     spreadInfo();

     for (int i = 0; i < info1.size(); i++) {
           int r = info1[i][0];
            int c = info1[i][1];
            spread(r, c);
        }
        infoInit();
        doUpdate();
        airclean();
    }

    cout << ans() << endl;
    return 0;
}
