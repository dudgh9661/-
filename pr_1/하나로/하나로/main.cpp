#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;

bool visit[1000000][1000000] = { false };
vector< pair<long long, long long> > in;
vector< vector< pair<long long, long long> > > arr;
int condition = 0;


void sol(vector< pair<long long, long long> > dist, bool visit[][1000000], vector< pair<long long, long long> > tmp, int N ){
    
    queue<pair<long long, long long> > que;
    pair<long long, long long> xy;
    pair<long long, long long> origin_xy;
    
    int cnt = 1;
    double d = 0;
    long long x = dist[0].first;
    long long y = dist[0].second;
//    stk.push(make_pair(x,y));
    condition++;
    tmp[0].first = x;
    tmp[0].second = y;
    visit[x][y] = true;
    double min = 1000000;
    
    while( condition != N ){
        min = 100000;
        for( int j = 0; j < cnt; j++){
//            printf("j : %d\n",j);
            x = tmp[j].first;
            y = tmp[j].second;
            
            
//            double min = 1000000;
            long long Nx = 0, Ny = 0;
            
            //가장 가까운 섬을 찾는 과정.
            for(int i = 0; i < N; i++ ){
                Nx = dist[i].first;
                Ny = dist[i].second;
                //            printf("Nx : %lld Ny : %lld t/f : %d",Nx,Ny, visit[Nx][Ny]);
                if( visit[Nx][Ny] == false ){
                    d = sqrt( pow((Nx-x),2) + pow((Ny-y), 2) );
//                    printf("hihi ");
                    //                printf("min : %lf d : %lf\n", min, d);
                    if( min > d ) {
                        min = d;
                        xy = make_pair(Nx,Ny);
                        origin_xy = make_pair(x, y);
//                        printf("Nx:%lld, Ny:%lld oxy.x:%lld oxy.y:%lld d=%lf\n",xy.first,xy.second, origin_xy.first,origin_xy.second, min);
                        
                    }
                }
            }
        }
        
        d = 0;
        
        //가까운 섬의 좌표는 xy에 저장되어 있다. 이 좌표를 que에 넣는다.
        if( visit[xy.first][xy.second] == false){
//            printf("in here!!");
            for(int i = 0; i < N; i++){
                if( arr[0][i].first == xy.first && arr[0][i].second == xy.second ){
                    arr[1][i].first = origin_xy.first;
                    arr[1][i].second = origin_xy.second;
//                    printf("final xy.x:%lld xy.y:%lld\n", xy.first, xy.second);
                }
            }
            
            visit[xy.first][xy.second] = true;
            //            printf("x : %lld y:%lld\n\n", xy.first, xy.second);
//            stk.push(make_pair(xy.first, xy.second));
            condition++;
            tmp[cnt].first = xy.first;
            tmp[cnt].second = xy.second;
            cnt++;
        }
    }
}
  
int main()
{
    freopen("input.txt", "r", stdin);
    
    int N = 0; scanf("%d", &N); getchar();//island
    long long x = 0, y = 0;
    long long *arrX = new long long[N];
    long long *arrY = new long long[N];
    
    //visit된 node들을 저장할 저장소
    vector< pair<long long, long long> > tmp(N);

    //arr[0].push_back , arr[1].push_back;

    for(int i = 0; i < N; i++){
        in.push_back( make_pair(0,0));
    }
    
    for(int i = 0; i < 2; i++){
           arr.push_back( in );
       }
   
    
    for(int i = 0; i < N; i++){
        //        printf("i : %d ",i);
        scanf("%lld", &x);
        arrX[i] = x;
    }
    
    for(int i = 0; i < N; i++){
        scanf("%lld", &y);
        arrY[i] = y;
    }
    
    vector< pair<long long,long long> > dist;
    for(int i = 0; i < N; i++){
        dist.push_back(make_pair(arrX[i], arrY[i]));
        arr[0][i].first = arrX[i];
        arr[0][i].second = arrY[i];
    }
    
    double E = 0;
    getchar();
    scanf("%lf", &E);
    printf("%lf",E);
//
//    for(int i = 0; i < N; i++){
//        printf("(%lld, %lld) ", dist[i].first, dist[i].second);
//    }
    printf("\n");
    sol(dist, visit, tmp, N);
    //    printf("what %lld", stk.size() );
    vector< pair<long long, long long> > sum(N);
    
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            printf("(%lld,%lld) ", arr[i][j].first, arr[i][j].second);
        }
        printf("\n");
    }

    
    
    //arr 백터를 이용해 거리 계산.
    double d = 0;
    double length = 0;
    double fee = 0;
    for(int i = 1; i < N; i++){
        d = sqrt( pow( (arr[0][i].first-arr[1][i].first), 2)+
                 pow( arr[0][i].second-arr[1][i].second, 2) ) ;
        
        length = E * pow(d, 2);
        printf("%lf, %lf\n",d, length);
        fee = fee + length;
    }
    
    
    fee = floor(fee+0.5);
    printf("\nfee : %lf\n",fee);
    delete []arrX;
    delete []arrY;
    return 0;
}

