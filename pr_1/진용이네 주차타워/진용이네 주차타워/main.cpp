#include <stdio.h>
#include <vector>
#include <stdlib.h> //abs()
#include <queue>

using namespace std;

int main()
{
    
    
    // freopen("input.txt", "r", stdin);
    int test_case = 0;
    scanf("%d", &test_case);
    
    for(int i = 0; i < test_case; i++)
    {
        
        
        
        int NumOfCar = 0, park_price = 0;
        
        int space = 0;
        int weight = 0;
        int car_idx = 0;
        int park_idx = 0;
        int sum = 0;
        
        //고쳐야 할 것들 1부터 시작한다는 것...
        //            printf("주차 공간 : ");
        scanf("%d", &space);
        if( space < 1 || space > 100 ) return 0;
        vector<int> park_space(space); //주차공간 배열
        
        //           printf("%d", park_space.size());
        vector<int> check_space(space, -100); //주차공간 사용 유무 파악 배열
        
        //주차공간, 차량의 무게 데이터 저장
        //            printf("차량 대수 : ");
        scanf("%d", &NumOfCar);
        if( NumOfCar < 1 || NumOfCar > 2000) return 0;
        vector<int> WeightOfCar(NumOfCar); //각 차량의 무게가 기록된 배열
        //            printf("%d", park_space.size());
        //            printf("단위 주차 비용 : ");
        for(vector<int>::size_type itr = 0; itr < park_space.size(); itr++){
            //        printf("itr : %d", itr);
            scanf("%d", &park_price);
            if( park_price < 1 || park_price > 100 ) return 0;
            park_space[itr] = park_price;
        }
        //            for( int i = 0; i < park_space.size(); i++)
        //                printf("parck : %d ", park_space[i]);
        
        //            printf("\n");
        //            printf("차량 무게 : ");
        for(vector<int>::size_type itr2 = 0; itr2 < WeightOfCar.size(); itr2++)
        {
            scanf("%d", &weight);
            WeightOfCar[itr2] = weight;
        }
        
        //            for( int i = 0; i < WeightOfCar.size(); i++)
        //                printf("Weight : %d ", WeightOfCar[i]);
        
        //            printf("\n");
        //차량의 idx를 받는다.
        int check_full = 0;
        int pre_car_idx =0;
        
        queue<int> q;
        
        
        //            vector<int> temp;
        //            int tmp_idx = 0;
        
        for(int i = 0; i < 2*NumOfCar; i++)
        {
            //                    printf("pre car idx : ");
            scanf("%d", &pre_car_idx);
            
            if( pre_car_idx < 0 ) {
                car_idx = pre_car_idx + 1;
            }
            else car_idx = pre_car_idx-1;
            
            
            
            //주차 공간이 꽉 차있을 때 어떻게 처리할 것인가..?
            //큐를 이용해서 선입선출을 한다. 큐에 들어가는 데이터는 car_idx
            if( pre_car_idx > 0 && check_full == check_space.size()){
                
                //                            printf("\n 주차 공간이 꽉 차있습니다.\n");
                //                            printf("push car idx : %d\n", car_idx);
                q.push(car_idx);
            }
            
            
            
            for(int i = 0; i < park_space.size(); i++){
                if ( pre_car_idx < 0 ){ // 차량이 나간다면
                    check_full--;
                    int exit_car_idx = abs(car_idx);
                    int empty_space = 0;
                    for(int i = 0; i < check_space.size(); i++){
                        if( check_space[i] == exit_car_idx )
                        {
                            empty_space = i;
                            // sum = sum + ( WeightOfCar[exit_car_idx] * park_space[empty_space] );
                            check_space[empty_space] = -100;
                            //해당 공간에 주차 공간이 있음.
                            //                                        printf("exit idx : %d\n", exit_car_idx);
                            //대기중인 차가 있다면, 대기중인 차들 중 앞에서부터 넣는다.
                            //                            printf("is empty? : %d \n", q.empty());
                            break;
                        }
                        
                    }
                    
                    if(q.empty() != 1 ) //대기중인 차가 있다면,
                    {
                        check_space[empty_space] = q.front();
                        car_idx = q.front();
                        q.pop();
                        sum = sum + ( WeightOfCar[car_idx] * park_space[empty_space] );
                        //                        printf("in q sum : %d\n", sum);
                        
                        /*
                         for(int i = 0; i < check_space.size(); i++){
                         if( check_space[i] < 0 ){
                         check_space[i] = q.front(); //주차 공간 유무 배열에 car_idx를 넣어 사용중임을 표시.
                         car_idx = q.front();
                         if(q.empty() != 1) q.pop();
                         
                         sum = sum + WeightOfCar[abs(car_idx)] * park_space[i];
                         //                            printf("in q sum : %d\n", sum);
                         
                         }
                         
                         }
                         */
                        check_full++;
                    }
                    //                    printf("\n");
                    
                    
                    break;
                }
                
                
                //자 발견된 무제가 뭐냐면 idx는 0부터 시작하기 때문에...
                if( check_space[i] < 0 ){// 주차공간이 비어있다면,
                    park_idx = i; //빈 주차 공간이 확인된 idx를 이용하여, 해당 자리의 주차 요금이 얼마인지 조회
                    check_space[park_idx] = car_idx; //주차 공간 유무 배열에 car idx를 넣어 사용중임을 표시.
                    sum = sum + ( WeightOfCar[car_idx] * park_space[park_idx] ); //주차요금 = 차량의 무게 * 주차 공간 단위 무게
                    //                                    printf("check_space[%d] : %d ", park_idx, check_space[park_idx]);
                    //                                    printf("sum[%d] : %d\n", car_idx, sum);
                    check_full++;
                    //                                    printf("check_full : %d\n", check_full);
                    break;
                }
                
            }
            
        }
        
        printf("#%d %d\n",i+1, sum);
        park_space.clear();
        WeightOfCar.clear();
        check_space.clear();
        
    }
    
    
    return 0;
}
