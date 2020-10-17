#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int map[21][21] = { 0, };
int visit[21][21] = { 0, };
int UD[4] = {-1, 0, 1, 0};
int LR[4] = {0, -1, 0, 1};

typedef struct driver{
    int row = 0;
    int col = 0;
} driver;

driver Driver;
typedef struct passenger{
    int startRow = 0;
    int startCol = 0;
    int desRow = 0;
    int desCol = 0;
} passenger;

vector<passenger> Passenger;
vector< pair<int, passenger> > passengerMin;

void PrintMap(int n ) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void PrintPassenger() {
    for(int i = 0; i < Passenger.size(); i++) {
        cout << Passenger[i].startRow << ", " << Passenger[i].startCol << endl;
    }
}
void initVisit() {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            visit[i][j] = 0;
        }
    }
}
void init() {
    int M = 0, initFuel = 0;
    cin >> N >> M >> initFuel;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int input = 0;
            cin >> input;
            map[i][j] = input;
        }
    }

    int row, col;
    cin >> row >> col;
    Driver.row = row;
    Driver.col = col;

    for(int i = 0; i < M; i++) {
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        passenger P;
        P.startRow = sr;
        P.startCol = sc;
        P.desRow = dr;
        P.desCol = dc;

        Passenger.push_back(P);
    }


    cout << " is map " << endl;
//    PrintPassenger();
    PrintMap(N);
    cout << endl;
}

void COPY(int mapCopy[][21] ) {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j  < 21; j++) {
            mapCopy[i][j] = map[i][j];
        }
    }
}

void PrintVisit() {
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int mapcopy[][21] ) {
//    cout << "dff?";
    queue<pair<int, int> > que;
    cout << "driver : " << Driver.row << " , " << Driver.col << endl;
    que.push({Driver.row, Driver.col});
    visit[Driver.row][Driver.col] = 1;
//    PrintVisit();
    while (!que.empty()) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + UD[i];
            int nc = col + LR[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N) {
                cout << " idx out of range!!! " << endl;
                continue;
            }
            if (mapcopy[nr][nc] != 1 && visit[nr][nc] == 0) {
//                cout << "다음 " << nr << "," << nc << endl;
                que.push({nr, nc});
                visit[nr][nc] = visit[row][col] + 1;

            }
        }
    }
    PrintVisit();
}

void sol() {
    int mapCopy[21][21] = {0,};
//Passenger.size()
    for(int i = 0; i < Passenger.size(); i++) {
        COPY(mapCopy);

        int startrow = Passenger[i].startRow;
        int startcol = Passenger[i].startCol;
//        mapCopy[startrow][startcol] = 100;
        BFS(mapCopy);
        passengerMin.push_back({visit[startrow][startcol] - 1, Passenger[i]});
        initVisit();

        for(auto itr = passengerMin.begin(); itr != passengerMin.end(); itr++) {
            cout << itr->first << endl;
            if( itr->first > (itr+1)->first ) {


//                itr + 1 = tmp;
        }
        }
        for(int itr = 0; itr < passengerMin.size(); itr++) {
            cout << "is : " << passengerMin[itr].first << endl;

        }

    }
}

int main() {
    init();
    sol();
    return 0;
}
