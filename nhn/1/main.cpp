#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef struct PLAYER{
    char player;
    int num;
} Player;

//vector<Player> P;
//vector<char> playerArr;
Player soole;
vector<Player> playerArr;
void init(int numOfAllPlayers) {
    for(int i = 0; i < numOfAllPlayers-1; i++) {
        Player p;
        p.player = 65+i+1;
        p.num = 0;
        playerArr.push_back(p);
    }

    soole.player = 'A';
    soole.num = 1;
//    for(int i = 0; i < playerArr.size(); i++) {
//        cout << playerArr[i] << endl;
//    }
}

int Right(int &towerPos, int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers) {
    int gameOver = 0;
    int flag = 0;
    if( towerPos >= numOfAllPlayers-1 ) towerPos = towerPos - (numOfAllPlayers - 1); //범위 초과했을때
    cout << "양수 바뀐후 : " << towerPos << endl;

    for(int faster = 0; faster < numOfQuickPlayers; faster++) { //수건을 놓은 자리에 달리기가 빠른 사람이 앉은 경우
        if (playerArr[towerPos].player == namesOfQuickPlayers[faster] ) {
            gameOver = 1;
            flag = 1;
            soole.num++;
        }
    }
    if( flag == 0 ) {
        Player tmp;
        tmp.player = soole.player;
        tmp.num = soole.num;

        Player next;
        next.player = playerArr[towerPos].player;
        next.num = playerArr[towerPos].num + 1;

        soole.player = next.player;
        soole.num = next.num;


        playerArr[towerPos].player = tmp.player;
        playerArr[towerPos].num = tmp.num;
        gameOver = 1; //게임이 끝난다.
//                    cout << i << ":" << soole.player << " and " << soole.num << endl;
    }
    return gameOver;
}
int Reverse(int &towerPos, int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers) {
    int gameOver = 0;
    int flag = 0;
    if( towerPos < 0 ) towerPos = towerPos + numOfAllPlayers - 1; //범위 초과했을때
    cout << "음수 바뀐후 : " << towerPos << endl;

    for(int faster = 0; faster < numOfQuickPlayers; faster++) { //수건을 놓은 자리에 달리기가 빠른 사람이 앉은 경우
        if (playerArr[towerPos].player == namesOfQuickPlayers[faster] ) {
            gameOver = 1;
            flag = 1;
            soole.num++;
        }
    }

    if( flag == 0 ) {
        Player tmp;
        tmp.player = soole.player;
        tmp.num = soole.num;

        Player next;
        next.player = playerArr[towerPos].player;
        next.num = playerArr[towerPos].num + 1;

        soole.player = next.player;
        soole.num = next.num;

        playerArr[towerPos].player = tmp.player;
        playerArr[towerPos].num = tmp.num;

        gameOver = 1; //게임이 끝난다
//        cout << soole.player << " and " << soole.num << endl;
    }
    return gameOver;
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
    // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
    int gameOver = 0;
    int towerPos = 0;
    int game = 0;

    for (int i = 0; i < numOfGames; i++) {
        int move = numOfMovesPerGame[i];
//        if( move > numOfAllPlayers ) move -= numOfAllPlayers;
//        if( move < -numOfAllPlayers ) move += numOfAllPlayers;
        while (gameOver != 1) {
            if (move > 0) { //시계방향
                cout << "move : " << move << endl;
                move = move % (numOfAllPlayers -1);
                towerPos += move; //수건의 위
//                towerPos = towerPos % ( numOfAllPlayers - 1);
                cout << "양수 바뀌기전  : " << towerPos << endl;
                gameOver = Right(towerPos, numOfAllPlayers, numOfQuickPlayers, namesOfQuickPlayers);
            } else if (move < 0) { //반시계
                cout << "move : " << move << endl;
                move = move % (numOfAllPlayers -1);
                towerPos += move; //수건의 위
//                towerPos = towerPos % ( numOfAllPlayers - 1);
                cout << "음수 바뀌기 전: " << towerPos << endl;
                gameOver = Reverse(towerPos, numOfAllPlayers, numOfQuickPlayers, namesOfQuickPlayers);
            }

        }

        gameOver = 0;
    }
}

struct input_data {
    int numOfAllPlayers;
    int numOfQuickPlayers;
    char *namesOfQuickPlayers;
    int numOfGames;
    int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.numOfAllPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfQuickPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
    for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
        iss >> inputData.namesOfQuickPlayers[i];
    }

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfGames;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.numOfMovesPerGame = new int[inputData.numOfGames];
    for (int i = 0; i < inputData.numOfGames; i++) {
        iss >> inputData.numOfMovesPerGame[i];
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    init(inputData.numOfAllPlayers);
    solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);

    for(int i = 0; i < playerArr.size(); i++) {
        cout << playerArr[i].player << " " << playerArr[i].num << endl;
    }
    cout << (char)soole.player << " " << soole.num << endl;
    return 0;
}