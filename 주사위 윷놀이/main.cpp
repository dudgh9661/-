#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[33]; //end point : 21
int turn[33] = { 0 };
int score[33] = { 0 };
bool visited[33] = { false };
int dice[10];
int horse[4] = { 0 };


int MAX = -1;

void init() {
    //init map
    int tmp = 0;
    for(int i = 0; i <= 20; i++) {
        map[i] = i + 1;
        score[i] = i * 2;
    }
    map[21] = 21; //end point
    tmp = 13;
    for(int i = 22; i <= 26; i++) {
        map[i] = i + 1;
    }
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30;
    map[27] = 20; score[27] = 35;
    map[28] = 29; score[28] = 22;
    map[29] = 25; score[29] = 24;
    map[30] = 31; score[30] = 28;
    map[31] = 32; score[31] = 27;
    map[32] = 25; score[32] = 26;
    
    //init turn
    turn[5] = 22;
    turn[10] = 28;
    turn[15] = 30;
    
    int input;
    for(int i = 0; i < 10; i++) {
        cin >> input;
        dice[i] = input;
    }
}

int move(int dice, int curNode) {
    int next = -100;
    for(int i = 1; i <= dice; i++) {
        if ( i == 1 && turn[curNode] != 0) {
            // cout << "여기에 들어옴" << endl;
            next = turn[curNode];
        } else {
            next = map[curNode];
            // cout << "dddd : " << curNode << " " << map[curNode] << endl;
        }
        if( next == 21 ) return next; // 도착
        curNode = next;
    }
    
    // cout << "neeeext : " << next << endl;
    return curNode;
}

int getScore(int dice, int curNode) {
    int sum = 0;
    
    for(int i = 1; i <= dice; i++) {
        int next;
        if( i == 1 && turn[curNode] != 0 ) {
            next = turn[curNode];
        } else next = map[curNode];
        if( next == 21 ) return sum; // 도착
        sum += score[next];
        curNode = next;
    }
    
    return sum;
}

void DFS(int _score, int depth) {
    if ( depth == 10 ) {
        MAX = max(_score, MAX);
        return;
    }
    //0. 4개의 말의 경우를 체크
    for(int i = 0; i < 4; i++) {
        int curNode = horse[i];
        // cout << i << " 번째 말, 현재 node : " << curNode;
        //1. 주사위에 따라 말 이동
        int next = move(dice[depth], curNode);
        //1-1. 이동할 node에 말이 존재한다면,
        if( visited[next] && next != 21 ) {
            // cout << "이동하는 곳에 말이 존재" << endl;
            continue;
        }
        //1-2. 도착지점이라면,
        else if ( next == 21 ) {
            horse[i] = 21;
            visited[curNode] = false;
            
            // cout << " 다음 노드1 : " << next << endl;
            DFS(_score, depth + 1);
            
            visited[curNode] = true;
            horse[i] = curNode;
        }
        //1-4. 일반적인 경우,
        else {
            visited[curNode] = false;
            horse[i] = next;
            visited[next] = true;
            
            // cout << " 다음 노드2 : " << next << endl;
            DFS(_score + score[next], depth + 1);
        
            visited[curNode] = true;
            visited[next] = false;
            horse[i] = curNode;
        }
    }
}

int main()
{
    init();
    // cout << turn[1];
    DFS(0, 0);
    cout << MAX << endl;
    return 0;
}
