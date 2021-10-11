package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr;
    static int N;
    static int M;
    static int B;
    static int ans = Integer.MAX_VALUE;

    static int getAns(int floor) {
        int res = -1;
        int inventory = B;
        int blockCnt = 0;
        int time = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                int needsBlock = floor - arr[i][j]; // 양수 : floor가 더 높음(쌓아야함), 음수 : floor가 더 낮음(깎아야함)
                if (needsBlock > 0) {
                    blockCnt += needsBlock;
                    time += needsBlock;
                } else if (needsBlock <= 0){
                    inventory += Math.abs(needsBlock);
                    time += 2 * Math.abs(needsBlock);
                }
            }
        }

        if ( inventory >= blockCnt) return time;

        return res;
    }
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        int maxFloor = -1;
        int MAX = Integer.MIN_VALUE;
        int MIN = Integer.MAX_VALUE;

        arr = new int[N+1][M+1];
        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                MAX = Math.max(MAX, arr[i][j]);
                MIN = Math.min(MIN, arr[i][j]);
            }
        }
//        getAns(3);

        for(int floor = MIN; floor <= MAX; floor++) {
            int result = getAns(floor);
            if (result != -1) {
                if (ans >= result) {
                    ans = result;
                    maxFloor = Math.max(floor, maxFloor);
                }
            }
        }
        System.out.print(ans + " " + maxFloor);
    }
}
