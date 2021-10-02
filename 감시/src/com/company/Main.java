package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr = new int[8][8];
    static ArrayList<Integer> arrayList = new ArrayList<>();
    static ArrayList<cctvPos> cctvPosArrayList = new ArrayList<cctvPos>();
    static int r, c;
    static int ans = Integer.MAX_VALUE;

    static class cctvPos {
        int cctvNum;
        int row;
        int col;

        cctvPos(int cctvNum, int row, int col) {
            this.cctvNum = cctvNum;
            this.row = row;
            this.col = col;
        }
    }

    static void init() throws IOException{
        StringTokenizer st;

        for (int i = 0; i < r; i++) {
            st  = new StringTokenizer(br.readLine());
            for (int j = 0; j < c; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (isCCTV(arr[i][j])) {
                    cctvPosArrayList.add(new cctvPos(arr[i][j],i,j));
                }
            }
        }
    }
    static boolean isCCTV(int num) {
        if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5 ) return true;
        return false;
    }
    static void move(int arrow, int curR, int curC) {
        if (arrow == 0) { // left
            for (int i = curC-1; i >= 0; i--) {
                if (arr[curR][i] == 6) break; //wall
                else if (isCCTV(arr[curR][i])) continue; //cctv
                arr[curR][i] = 9;
            }
        } else if (arrow == 1) { // up
            for (int i = curR-1; i >= 0; i--) {
                if (arr[i][curC] == 6) break; //wall
                else if (isCCTV(arr[i][curC])) continue; //cctv
                arr[i][curC] = 9;
            }
        } else if (arrow == 2) { // down
            for (int i = curR+1; i < r; i++) {
                if (arr[i][curC] == 6) break; //wall
                else if (isCCTV(arr[i][curC])) continue; //cctv
                arr[i][curC] = 9;
            }
        } else if (arrow == 3) { // right
            for (int i = curC+1; i < c; i++) {
                if (arr[curR][i] == 6) break; //wall
                else if (isCCTV(arr[curR][i])) continue; //cctv
                arr[curR][i] = 9;
            }
        }
    }
    static void cctvOne(int arrow, int cctvR, int cctvC) {
        if (arrow == 0) { // default
            move(3, cctvR, cctvC); //right
        } else if (arrow == 1) { // right rotation
            move(2, cctvR, cctvC); // down
        } else if (arrow == 2) {
            move(0, cctvR, cctvC);
        } else if (arrow == 3) {
            move(1, cctvR, cctvC);
        }
    }

    static void cctvTwo(int arrow, int cctvR, int cctvC) {
        if (arrow == 0 || arrow == 2) { // default
            move(3, cctvR, cctvC); //right
            move(0, cctvR, cctvC); //left
        } else if (arrow == 1 || arrow == 3) { // right rotation
            move(1, cctvR, cctvC);
            move(2, cctvR, cctvC);
        }
    }

    static void cctvThree(int arrow, int cctvR, int cctvC) {
        if (arrow == 0 || arrow == 3) { // default
            move(3, cctvR, cctvC); //right
            move(1,cctvR, cctvC);
        } else if (arrow == 1) { // right rotation
            move(3, cctvR, cctvC); //right
            move(2, cctvR, cctvC); // down
        } else if (arrow == 2) {
            move(1,cctvR, cctvC);
            move(0,cctvR, cctvC);
        }
    }

    static void cctvFour(int arrow, int cctvR, int cctvC) {
        if (arrow == 0) { // default
            move(3, cctvR, cctvC); //right
            move(1,cctvR, cctvC); // up
            move(0,cctvR,cctvC); // left
        } else if (arrow == 1) { // right rotation
            move(1,cctvR, cctvC); // up
            move(3, cctvR, cctvC); //right
            move(2, cctvR, cctvC); //down
        } else if (arrow == 2) {
            move(3, cctvR, cctvC); //right
            move(2, cctvR, cctvC); //down
            move(0,cctvR,cctvC); // left
        } else if (arrow == 3) {
            move(0,cctvR,cctvC); // left
            move(2, cctvR, cctvC); //down
            move(1,cctvR, cctvC); // up
        }
    }

    static void cctvFive(int arrow, int cctvR, int cctvC) {
        move(3, cctvR, cctvC); //right
        move(0,cctvR,cctvC); // left
        move(1,cctvR, cctvC); // up
        move(2, cctvR, cctvC); //down
    }

    static void cctv(int cctvNum, int cctvR, int cctvC, int arrow) {
        if ( cctvNum == 1) {
            cctvOne(arrow, cctvR, cctvC);
        } else if (cctvNum == 2) {
            cctvTwo(arrow, cctvR, cctvC);
        } else if (cctvNum == 3) {
            cctvThree(arrow, cctvR, cctvC);
        } else if (cctvNum == 4) {
            cctvFour(arrow, cctvR, cctvC);
        } else if (cctvNum == 5) {
            cctvFive(arrow, cctvR, cctvC);
        }
    }

    static int getAns() {
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }

    static void initArr() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 9) arr[i][j] = 0;
            }
        }
    }

    static void Print() {
        System.out.print("순서 : ");
        for (int i = 0; i < arrayList.size(); i++) {
            System.out.print(arrayList.get(i) + " ");
        }
        System.out.println();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void DFS() {
        // if arryList size equals the Number of CCTV,
        // then, do simulation
        if ( arrayList.size() == cctvPosArrayList.size()) {
            for(int i = 0; i < cctvPosArrayList.size(); i++) {
                int arrow = arrayList.get(i);
                cctvPos cctv = cctvPosArrayList.get(i);
                cctv(cctv.cctvNum, cctv.row, cctv.col, arrow);
            }
//            Print();
            ans = Math.min(ans, getAns());
            initArr();
            return;
        }

        for (int i = 0; i < 4; i++) {
            arrayList.add(i);

            DFS();

            arrayList.remove(arrayList.size()-1);
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        init();
        DFS();
        System.out.print(ans);
    }
}
