package com.company;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class POS {
        int r, c;

        POS(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int[][] arr = new int[19][19];
    static POS[] posArr = new POS[8];
    static int ansR = -1, ansC = -1;

    static boolean inRange(int r, int c) {
        if ( r < 0 || r > 18 || c < 0 || c > 18) return false;
        return true;
    }
    //  검은 바둑알은 1, 흰 바둑알은 2, 알이 놓이지 않는 자리는 0
    // 연속적이란 가로, 세로 또는 대각선 방향 모두를 뜻함
    static boolean isFive(int sR, int sC, int badook) {
        for (int i = 0; i < 8; i++) {
            int cnt = 0;
            int leftR = sR, leftC = sC;
            int nR = 0, nC = 0;

            for (int step = 0; step < 5; step++) {
                nR = sR + posArr[i].r * step;
                nC = sC + posArr[i].c * step;
                if (!inRange(nR,nC)) break;
                if (badook == arr[nR][nC]) {
                    // 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알(연속된 다섯 개의 바둑알이 세로로 놓인 경우, 그 중 가장 위에 있는 것)의 가로줄, 세로줄 번호 출력
                    if (leftC > nC) {
                        leftR = nR;
                        leftC= nC;
                    }
                    cnt++;
                }
                else break;
            }
            if (cnt == 5) {
                // 하지만 여섯 알 이상이 연속적으로 놓인 경우에는 이긴 것이 아니다.
                if (inRange(sR+posArr[i].r*-1, sC+posArr[i].c*-1) && arr[sR+posArr[i].r*-1][sC+posArr[i].c*-1] == badook) continue;
                if (inRange(sR+posArr[i].r*5, sC+posArr[i].c*5) && arr[sR+posArr[i].r*5][sC+posArr[i].c*5] == badook) continue;
                    ansR = leftR + 1;
                    ansC = leftC + 1;
                    return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        posArr[0] = new POS(-1,0);
        posArr[1] = new POS(0,1);
        posArr[2] = new POS(1,0);
        posArr[3] = new POS(0,-1);
        posArr[4] = new POS(-1,1);
        posArr[5] = new POS(1,1);
        posArr[6] = new POS(1,-1);
        posArr[7] = new POS(-1,-1);

        System.setIn(new FileInputStream("./input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < 19; i++) {
             st = new StringTokenizer(br.readLine());
             for (int j = 0; j < 19; j++) {
                 arr[i][j] = Integer.parseInt(st.nextToken());
             }
        }

        for (int i = 0; i < 19; i++) {
            for(int j = 0; j < 19; j++) {
                if (arr[i][j] == 0) continue;
                if (isFive(i,j,arr[i][j])) {
                    System.out.println(arr[i][j]);
                    System.out.print(ansR + " " + ansC);
                    return;
                }
            }
        }
        System.out.print(0);
    }
}
