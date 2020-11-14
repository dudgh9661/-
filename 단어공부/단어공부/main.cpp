#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 문자열을 받고
    string alphabet = "";
    freopen("input.txt", "r", stdin);
    cin >> alphabet;
//    cout << alphabet << endl;
    // 각 문자열에 대해 카운트를 한다. //이 때 배열을 사용할건데 a-z까지 순서대로 배열에 위치한다.
    vector<int> cnt(26, 0);
    for(int i = 0; i < alphabet.length(); i++){
        char alpha = alphabet[i];
        
        if( alpha == 'a' || alpha == 'A' ){
            cnt[0]++;
        } else if ( alpha == 'b' || alpha == 'B' ) {
            cnt[1]++;
        } else if ( alpha == 'c' || alpha == 'C' ) {
            cnt[2]++;
        } else if ( alpha == 'd' || alpha == 'D' ) {
            cnt[3]++;
        } else if ( alpha == 'e' || alpha == 'E' ) {
            cnt[4]++;
        } else if ( alpha == 'f' || alpha == 'F' ) {
            cnt[5]++;
        } else if ( alpha == 'g' || alpha == 'G' ) {
            cnt[6]++;
        } else if ( alpha == 'h' || alpha == 'H' ) {
            cnt[7]++;
        } else if ( alpha == 'i' || alpha == 'I' ) {
            cnt[8]++;
        } else if ( alpha == 'j' || alpha == 'J' ) {
            cnt[9]++;
        } else if ( alpha == 'k' || alpha == 'K' ) {
            cnt[10]++;
        } else if ( alpha == 'l' || alpha == 'L' ) {
            cnt[11]++;
        } else if ( alpha == 'm' || alpha == 'M' ) {
            cnt[12]++;
        } else if ( alpha == 'n' || alpha == 'N' ) {
            cnt[13]++;
        } else if ( alpha == 'o' || alpha == 'O' ) {
            cnt[14]++;
        } else if ( alpha == 'p' || alpha == 'P' ) {
            cnt[15]++;
        } else if ( alpha == 'q' || alpha == 'Q' ) {
            cnt[16]++;
        } else if ( alpha == 'r' || alpha == 'R' ) {
            cnt[17]++;
        } else if ( alpha == 's' || alpha == 'S' ) {
            cnt[18]++;
        } else if ( alpha == 't' || alpha == 'T' ) {
            cnt[19]++;
        } else if ( alpha == 'u' || alpha == 'U' ) {
            cnt[20]++;
        } else if ( alpha == 'v' || alpha == 'V' ) {
            cnt[21]++;
        } else if ( alpha == 'w' || alpha == 'W' ) {
            cnt[22]++;
        } else if ( alpha == 'x' || alpha == 'X' ) {
            cnt[23]++;
        } else if ( alpha == 'y' || alpha == 'Y' ) {
            cnt[24]++;
        } else if ( alpha == 'z' || alpha == 'Z' ) {
            cnt[25]++;
        }
        
       
       
        
    }
    int max = 0;
    int num = 0;
    char ans;
    for(int i = 0; i < 26; i++) {
        num = cnt[i];
        if( max < num ) {
            max = num;
        }
    }
    
    int flag = 0;
    for(int i = 0; i < 26; i++) {
        if( max == cnt[i]) {
            ans = i+65;
            flag ++;
        }
    }
    
    if(flag > 1 ) cout << "?";
    else cout << ans;
    //정렬하기 전 제일 큰 수를 찾는다.
    // 같은 수가 존재하면 return ?
    
//    char test = 65;
//    cout << "test : " << test << endl;
    
//    sort(cnt.begin(), cnt.end(), greater<int>());



    return 0;
}

