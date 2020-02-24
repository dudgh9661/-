#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int col = 0;
int cnt = 0;

void Printarr(int col, int **arr){
    for(int i = 0; i <= col; i++){
        for(int j = 0; j <= col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void DFS(int start_col, int start_row, bool **check, int **arr){
    if( start_col == 0 || start_col > col ||
       start_row == 0 || start_row > col ||
       ( check[start_col][start_row] == true ) ) return;
    else{
        
        //만약 방문했는데, 방문을 했었거나, 집이 아니면
        if( arr[start_col][start_row] == 0 ||
           check[start_col][start_row] == true) {
            return;
        }
        //방문하지 않았고 집이면
        else if ( arr[start_col][start_row] == 1 &&
                 check[start_col][start_row] == false ){
            //방문표시를 하고, 상하좌우를 탐색한다.
            check[start_col][start_row] = true;
            cnt++;
            DFS(start_col-1, start_row, check, arr);
            DFS(start_col+1, start_row, check, arr);
            DFS(start_col, start_row-1, check, arr);
            DFS(start_col, start_row+1, check, arr);
            
        }
    }
    
}


int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &col);
    
    //bool함수 초기화
    bool **check = new bool*[col+1];
    for(int i = 0; i <= col; ++i){
        check[i] = new bool[col+1];
        memset(check[i], 0, sizeof(bool)*col);
    }
    //2차원 배열 생성
    int **arr = new int*[col+1];
    for(int i = 0; i <= col; ++i){
        arr[i] = new int[col+1];
        memset(arr[i], 0, sizeof(int)*col);
    }
    //2차원 배열을 채움
    string element;
    
    for(int i = 1; i <= col; i++){
        cin >> element;
        for(int j = 1; j <= col; j++){
            char ele = element[j-1];
            int real_ele = ele - 48;
            arr[i][j] = real_ele;
        }
    }
    vector<int> num; //단지 수
    int total = 0;
    //탐색이 한번 끝나면 cnt저장 후 초기화
    for(int i = 0; i <= col; i++){
        for(int j = 0; j <= col; j++){
            DFS(i+1, j+1, check, arr);
            if( cnt > 0 ){
                num.push_back(cnt);
                total++;
            }
            cnt = 0;
        }
    }
    
    //num 오름차순으로 정리
    printf("%d\n", total);
    sort(num.begin(), num.end());
    for(auto i = num.begin(); i != num.end(); i++){
        cout << *i << endl;
    }
    
    
    //    Printarr(col, arr);
    
    for(int i = 0; i <= col; ++i){
        delete [] check[i];
        delete [] arr[i];
    }
    delete [] arr;
    delete [] check;
    
    return 0;
}

