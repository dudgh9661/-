#include <stdio.h>
#include <algorithm>
#include <vector>

typedef struct Student{
    int id;
    int sc;
    char gra;
}student;

using namespace std;

int score(int mid, int fin, int homework)
{
    int score = mid * 0.35 + fin * 0.45 + homework * 0.25;
    return score;
}

bool cmp_stu(student a, student b)
{
    return a.sc > b.sc;
}

int main()
{
    int mid = 0, fin = 0, homework=0;
    
    vector<student> arr(10);

    freopen("input.txt", "r", stdin);
    for(int i = 0; i < 10; i++)
    {
        scanf("%d %d %d", &mid, &fin, &homework);
        int Score = score(mid, fin, homework);
//        printf("score ; %d", Score);
        arr[i].sc = Score;
    }
    
    sort(arr.begin(), arr.end(), cmp_stu);
    
    for(int i = 0; i < arr.size(); i++)
    {
//     기준점을 만들어, x이상은 A, 이하는 B 이런식으로 등급을 구조체에다가 부여하면 끝. 
        printf("%d ", arr[i].sc);
    }
    
    
    
}
