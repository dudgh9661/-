package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static ArrayList<String> arrayList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));

        StringTokenizer st = new StringTokenizer(br.readLine(), "-|+", true);

        while(st.hasMoreTokens()) {
            arrayList.add(st.nextToken());
        }
    }

    static void sol() {
        int sum = 0;
        int minusSum = 0;
        for(int i = 0; i < arrayList.size(); i++) {
            minusSum = 0;
            if( arrayList.get(i).equals("-") ) { //-가 나오면, 다시 -가 나올 때까지 계속해서 더해준다.
                for(int j = i+1; j < arrayList.size(); j++) {
                    if (arrayList.get(j).equals("-")) {
                        sum = sum - minusSum;
                        i = j-1;
                        break;
                    } else if(arrayList.get(j).equals("+")) //+인 경우
                         continue;
                    else { //숫자인 경우
                        minusSum += Integer.parseInt(arrayList.get(j));
//                        System.out.println(j + " minus sum : " + minusSum);
                        if( j == arrayList.size() - 1 ) i = j;
                    }
                }
            } else if ( arrayList.get(i).equals("+") ) continue;
            else {
                sum += Integer.parseInt(arrayList.get(i));
//                System.out.println(i + " sum : " + sum);
            }
        }
        sum -= minusSum;
        System.out.println(sum);
    }
}