#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

typedef struct Student{
    int id;
    float sc;
    char gra[3];
}student;

using namespace std;

float score(int mid, int fin, int homework)
{
    float score = mid * 0.35 + fin * 0.45 + homework * 0.20;
    return score;
}

bool cmp_stu(student a, student b)
{
    return a.sc > b.sc;
}

int main()
{
    printf("fadfadfads");
    freopen("input.txt", "r", stdin);
//    int num = 0, test = 0, st_id = 0;
    int test = 0;
    scanf("%d", &test);
//    scanf("%d %d", &num, &st_id);
    
    

    for(int k = 0; k < test; k++)
    {
    int num = 0, st_id = 0;
        int mid = 0, fin = 0, homework=0;
        int id = 1;
        int grading = 0;
        
    
    scanf("%d %d", &num, &st_id);
        if( (num % 10) != 0 || num < 10 || num > 100 || st_id < 1 || st_id > num) return 0;
//  printf("num : %d, stid : %d\n", num, st_id);

    vector<student> arr(num);
    arr.resize(num);
//  freopen("input.txt", "r", stdin);
    for(int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &mid, &fin, &homework);
        float Score = score(mid, fin, homework);
//      printf("score ; %d", Score);
        arr[i].sc = Score;
        arr[i].id = id;
        id++;
        Score = 0;
    }
    
    sort(arr.begin(), arr.end(), cmp_stu);
    
    grading = num / 10;
//        printf("grading : %d", grading);
    int cnt = 0;
            for(int j = 0; j < grading;j++){
                if( cnt > num) break;
                strcpy(arr[cnt].gra, "A+");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "A0");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "A-");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "B+");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "B0");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "B-");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "C+");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "C0");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "C-");
                cnt++;
            }
            for(int j = 0; j < grading;j++){
                 if( cnt > num) break;
                strcpy(arr[cnt].gra, "D0");
                cnt++;
            }
        
//        printf("size : %d\n", arr.size());
    for(int i = 0; i < arr.size(); i++)
    {
        if( st_id ==arr[i].id) printf("#%d %s\n", k+1, arr[i].gra);
//      기준점을 만들어, x이상은 A, 이하는 B 이런식으로 등급을 구조체에다가 부여하면 끝.
//      printf("g");
        printf("id : %d score : %f grade : %s\n", arr[i].id, arr[i].sc, arr[i].gra);
    }
        arr.clear();
//        printf("test : %d", k);
    }
//    중복된 값이 없댔는데 있네…………………….???
    return 0;
}
