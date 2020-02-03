#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

//vector<int> arr(test_pow)로 사이즈 초기화 후,
//for문 이용해서 push_back하면 데이터가 삽입이 안됨... why..???

int main()
{
    freopen("input.txt", "r", stdin);
    int total = 0;
    scanf("%d", &total);
    int test_pow = 0;
    int test = 0;
    int input = 0;
    int sum = 0;
    
    for(int i = 0; i < total; i++)
    {

        
        
        sum = 0;
    scanf("%d", &test);
    test_pow = pow(2, test);
    
    vector<int> arr;
    arr.clear();

    
  //  printf("size %d ", arr[0]);
    for(int i = 0; i < test_pow; i++){
        scanf("%d", &input);
        arr.push_back(input);
    }
    
    while(arr.size() > 1)
    {
        
        
    int idx = 0;
    int replace = 0;
    int itr = arr.size();
    
    if( itr == 2) itr = itr + 1;
    
    for( int i = 0; i < itr/2; i++){
        if( arr.at(idx) > arr.at(idx+1) ){
            sum = sum + arr.at(idx)-arr.at(idx+1);
            arr.at(replace) = arr.at(idx);
        }
        else
        {
            
            sum = sum + arr.at(idx+1)-arr.at(idx);
            arr.at(replace) = arr.at(idx + 1);
        }
//        printf("\n if문 안 sum : %d \n", sum);
        idx = idx+2;
        replace++;
            
    }
//    printf("arr size : %d\n", arr.size());
    arr.resize(arr.size() / 2);
   
        
//    printf("arr resize : %d \n", arr.size());
//    for(int i = 0; i < arr.size(); i++) printf("%d ", arr[i]);
        
//        printf("\n");
    }
        
    printf("#%d %d\n",i+1, sum);
//        printf("\n\n");
    
        
    }
    
    
    return 0;
}
