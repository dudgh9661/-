package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static boolean[] visited = new boolean[10001];
    static ArrayList<Integer> arrayList = new ArrayList<>();
    static ArrayList<Integer> output = new ArrayList<>();

    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        String[] input = br.readLine().split(" ");
        for(int i = 0; i < input.length; i++) {
            arrayList.add(Integer.parseInt(input[i]));
        }

        //오름차순으로 정렬
        Collections.sort(arrayList);
        DFS(0, 0);
//        for(int i = 0; i < arrayList.size(); i++) {
//            System.out.print(arrayList.get(i) + " ");
//        }
    }

    public static void DFS(int start, int cnt) {
        if( cnt == M ) {
            for(int i = 0; i < output.size(); i++)
                System.out.print(output.get(i) + " ");
            System.out.println();
            return;
        }

        for(int i = start; i < arrayList.size(); i++) {
            output.add(arrayList.get(i));

            DFS(i, cnt + 1);

            output.remove(output.size() - 1 );
        }

    };
}
