var visited = [];

function init(lost, reserve) {
    var deleteInfo = [];
    //30이면, 1 ~ 30
    for(var i = 0; i <= 30; i++) visited[i] = true;
    
    //같은 거 찾아서 저장
    for(var i = 0; i < reserve.length; i++) {
        var idx = lost.indexOf(reserve[i]);
        if( idx > -1 ) {
            deleteInfo.push(lost[idx]);
        }
    }
    //같은거 삭제
    for(var i = 0; i < deleteInfo.length; i++) {
        var rsvIdx = reserve.indexOf(deleteInfo[i]);
        var lstIdx = lost.indexOf(deleteInfo[i])
        
        reserve.splice(rsvIdx, 1);
        lost.splice(lstIdx, 1);
    }
    
    
    for(var i = 0; i < lost.length; i++) {
        visited[lost[i]] = false;
    } 
}

function solution(n, lost, reserve) {
    var answer = 0;
    
    init(lost, reserve);
    
    reserve.sort(function(a,b) {
       return a - b; 
    });
    lost.sort(function(a,b) {
        return a - b;
    });
    
    for(var i = 0; i < reserve.length; i++) {
        //lost에 자기 자신이 속해있는지 확인 
        if( !visited[reserve[i]] ) {
            visited[reserve[i]] = true;
            continue;
        }
        //왼쪽, 오른쪽 확인
        else {
            if( reserve[i] - 1 >= 1 && !visited[reserve[i] - 1] ) 
                visited[reserve[i] - 1] = true;
            else if( reserve[i] + 1 <= n && !visited[reserve[i] + 1] ) 
                visited[reserve[i] + 1] = true;
        }
    }
    
    for(var i = 1; i <= n; i++) {
        if( visited[i] ) answer++;
        console.log(visited[i]);
    }
    return answer;
}
