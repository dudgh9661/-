#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<pair <int, int> > que;
int visit[1000][1000] = { 0 };
int keypad[4][4] = { 0 };

int UD[4] = {-1, 1, 0, 0};
int LR[4] = {0, 0, -1, 1};

void BFS(int row, int col) {
    visit[row+1][col+1] = true;
    que.push( {row, col} );
    
    if( !que.empty() ) {
        int pop_row = que.front().first;
        int pop_col = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++ ){
            int next_row = pop_row + UD[i];
            int next_col = pop_col + LR[i];
            if( keypad[row][col] != -1 && visit[row][col] == 0 ) {
                que.push( {next_row, next_col} );
                visit[next_row][next_col] += 1;
            }
            else if( visit[row][col] > 0 ) { //눌러야하는 키패드에 도착했다면
                return;
            }
        }
        
    }
}

int main() {
    vector<int> numbers;
    string hand;
    
    for(int i = 0; i < numbers.size(); i++) {
    }
    
    if( hand.compare("right") == 0 ) { //같은 거리인 경우 오른손잡이면 오른손으로 처리
        
    }
    
    else if ( hand.compare("left") == 0 ) {
        
    }
    string answer = "";
    return 0;
}
