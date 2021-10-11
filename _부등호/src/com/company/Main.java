package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Integer> arrayList = new ArrayList<>();
    static boolean[] arr = new boolean[10];

    static int k;
    static String str = "";

    static String res = "";
    static String MIN = "";
    static String MAX = "";

    static String resToString(ArrayList<Integer> arrayList) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arrayList.size(); i++) {
            sb.append(arrayList.get(i));
        }
        return sb.toString();
    }

    static boolean canInsert(int a, int b, int idx) {
        if (arr[b]) return false;

        char ch = str.charAt(idx);

        if (ch == '>') {
            if (a > b) return true;
        }
        else if (ch == '<') {
            if (a < b) return true;
        }

        return false;
    }

    static void DFS(int len) {
        if (len == k+1) {
            if (res.equals("")) {
                res = resToString(arrayList);
                MIN = res;
            } else {
                res = resToString(arrayList);
                MAX = res;
            }
            return;
        }

        for(int i = 0; i < 10; i++) {
            if (!arrayList.isEmpty() && !canInsert(arrayList.get(arrayList.size()-1), i, len-1)) continue;

            arr[i] = true;
            arrayList.add(i);

            DFS(len + 1);

            arrayList.remove(arrayList.size() - 1);
            arr[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        k = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            str += st.nextToken();
        }

        DFS(0);
        System.out.println(MAX);
        System.out.print(MIN);

    }
}
