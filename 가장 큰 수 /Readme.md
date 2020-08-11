sort함수에서 compare함수의 리턴 값은 

```
bool compare( int a, int b ) {
  return a > b; // a가 b 앞에 위치할 수 있는 조건을 적어준다. 즉, a > b이면 a가 b 앞에 위치한다. a <= b라면 a는 b 앞에 위치할 수 없다. 즉 b의 뒤에 위치한다. 
}
```
