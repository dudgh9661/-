#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

int col = 0, row = 0;
using namespace std;
void Print(vector <vector<int> > arr){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void Print(int **arr){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void BFS(int x, int y, int **visit, vector< vector<int> > arr, queue<pair<int, int>> que){
    if( arr[x][y] == 0 || visit[x][y] != -1 ) return;
    
    visit[x][y] = 0;
    que.push(make_pair(x,y));
    
    while( !que.empty()){
        int popx = que.front().first;
        int popy = que.front().second;
        que.pop();
        
        if(popx-1 >= 0){
            if( arr[popx-1][popy] == 1 && visit[popx-1][popy] == -1){
                visit[popx-1][popy] = visit[popx][popy] + 1;
                que.push(make_pair(popx-1,popy));
            }
        }
        if(popx+1 < col ){
            if( arr[popx+1][popy] == 1 && visit[popx+1][popy] == -1){
                visit[popx+1][popy] = visit[popx][popy] + 1;
                que.push(make_pair(popx+1,popy));
            }
        }
        if(popy-1 >= 0){
            if( arr[popx][popy-1] == 1 && visit[popx][popy-1] == -1){
                visit[popx][popy-1] = visit[popx][popy] + 1;
                que.push(make_pair(popx,popy-1));
            }
        }
        if(popy+1 < row ){
            if( arr[popx][popy+1] == 1 && visit[popx][popy+1] == -1){
                visit[popx][popy+1] = visit[popx][popy] + 1;
                que.push(make_pair(popx,popy+1));
            }
        }
        
    }
    
}

int MAX(int **visit){
    int max = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if( max < visit[i][j]){
                max = visit[i][j];
            }
        }
    }
    return max;
}

int main()
{
    freopen("input.txt", "r", stdin);
    vector< vector<int> > map;
    vector<int> element;
    
    queue<pair<int, int>> que;
    
    scanf("%d %d", &col, &row);
    if( col > 50 || row > 50 ) return 0;
    
    int **visit = new int *[col];
    for(int i = 0; i < col; i++){
        visit[i] = new int[row];
        memset(visit[i], -1, sizeof(int)*row);
    }
    
    
    string input;
    int inp = 0;
    for(int i = 0; i < col; i++){
        cin >> input;
        for(int j = 0; j < input.length(); j++){
            if(input[j] == 'W')
                inp = 0;
            else inp = 1;
            element.push_back(inp);
        }
        //cin.ignore(256,'\n');
        map.push_back(element);
        element.clear();
    }
    int max = 0;
    
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            BFS(i,j, visit, map, que);
            Print(visit);
            printf("\n");
            if( max < MAX(visit) )
                max = MAX(visit);
            for(int i = 0; i < col; i++){
                memset(visit[i], -1, sizeof(int)*row);
                }
            }
        }
    
    Print(map);
    printf("\n");
    
    printf("%d\n", max);

    for(int i = 0; i < col; i++){
        delete [] visit[i];
        map[i].clear();
    }
    delete [] visit;
    
    return 0;
    
}
