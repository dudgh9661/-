package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//    static ArrayList<Integer> T = new ArrayList<>();
//    static ArrayList<Integer> P = new ArrayList<>();
    static int[] dp;
    static int[] T;
    static int[] P;

    static int N;
    static int MAX = -1;

    static void init() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        dp = new int[N+2];
        T = new int[N+2];
        P = new int[N+2];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N+1; i++) {
            dp[i] = 0;
        }
    }

    static void sol() {
        for (int i = 1; i <= N; i++) {
            int next = i + T[i];
            MAX = Math.max(MAX, dp[i]);
            if (next > N+1) continue;
            dp[next] = Math.max(dp[next], MAX + P[i]);
        }
    }

    static void getAns() {
        for (int i = 1; i <= N+1; i++) {
            MAX = Math.max(MAX, dp[i]);
        }
    }
    public static void main(String[] args) throws IOException {
        init();
        sol();
        getAns();
        System.out.print(MAX);
    }
}
