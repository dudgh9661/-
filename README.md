# SW_practice

-----
### 내가 자주 실수하는 것들

1. BFS 구현할 때, que.pop()을 자주 빼먹는다.
2. 범위 검사할 때, 실수하지 말자
3. 배열 사이즈 선언을 실수할 때가 있다.
-----
주어진 테스트 케이스 이외의 테스트 케이스도 반드시 테스트 해볼것..

-----

### cmp 함수 주의할 점!
sort의 cmp함수는 Strict Weak Ordering을 따른다.

이 조건 중, 반드시 R(a,a) = false 이어야 하는 조건이 있으므로 if ( a == b ) return true; 로 하게 되면 오류가 발생한다.

그러므로, if( a == b ) return false; 가 되어야 한다.

-----
#### 런타임 에러의 원인
1. 배열에 할당된 크기를 넘어서 접근했을 때 또는 -idx에 접근했을때
2. 전역 배열의 크기가 메모리 제한을 초과할 때
3. 지역 배열의 크기가 스택 크기 제한을 넘어갈 때
4. 0으로 나눌 떄
5. 라이브러리에서 예외를 발생시켰을 때
6. 재귀 호출이 너무 깊어질 때
7. 이미 해제된 메모리를 또 참조할 때

-------
#### 재귀함수 

```
void f( 1 ) {
	f(0);
	printf("%d", n);
}
```

```
void f( 1 ) {
	return; //return으로 치환되는 것이 아니다. 단지 그냥 f(0) 함수가 종료될 뿐, 밑에 코드는 진행된다.
	printf("%d", n);
}
```

------
#### 배열 크기 할당은 웬만하면 데이터 영역에 하기

```
// 전역 변수로 선언했다고 가정!!!

int num = 1; 
int *ptr = &num; // num, ptr, 1 모두 데이터 영역에 저장된다.

int *ptr = new int[1]; // ptr -> 데이터 영역, *ptr -> 힙 영역에 저장된다.

//포인터를 전역으로 잡으면
//포인터를 저장하는 변수만!! 데이터 영역에 잡히고,
//실제 유효한 데이터를 저장하는 배열 공간은 힙에 잡힌다.
```

-----
### vector erase 사용할 때 주의할 점
<img src="./images/erase.jpeg" width="700" height="700">

------
### vector 요소 옆으로 옮기기 

```
vector<int> abc{1,2,3,4,5};
    int tmp = abc[0];
    int tmp2 = 0;
    for(int i = 0; i < 4; i++) {
        tmp2 = abc[i+1]; // 1
        abc[i+1] = tmp;
        tmp = tmp2;
    }
    
//그냥 이렇게하면 편하긴 함
for(int i = 5; i > 0; i--) {
        abc[i] = abc[i-1];
    }

abc[0] = 0;
```

----
### BST vs max/minheap
BST : 자기보다 작은 놈 왼쪽, 큰 놈 오른쪽

heap : max 또는 min 값을 빠르게 찾아내기 위한 자료구조, complete binary tree로 구성

----
### BFS vs 다익스트라 알고리즘
BFS는 모든 간선의 가중치가 동일할 때, 다익스트라는 동일하지 않을 때 사용하면 됩니다.
'트리의 경우'에는 두 정점을 잇는 경로가 유일하기 때문에 가중치의 유무에 상관 없이 BFS를 해도 되고, 심지어는 BFS가 아니라 DFS를 해도 됩니다. 거리가 '갱신되는' 과정 자체가 없기 때문입니다.

"그래프일 경우"

간선의 가중치가 모두 동일 -> BFS

그렇지 않은 경우 -> 다익스트라


"트리인 경우"

DFS or BFS

####"다익스트라 알고리즘에서 if( d[cur] < dist ) continue는 왜 존재해야하는가?"

```
   if( d[cur] < dist ) continue; //예를 들어, 1->des 거리가 2, 1->cur가 3이면, 1->cur->des를 비교해봤자 의미가 없으므로 pass.
        for(int i = 0; i < map[cur].size(); i++) {
            int nextDist = dist + map[cur][i].first;
            int next = map[cur][i].second;
            if( d[next] > nextDist ) {
                d[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
```
