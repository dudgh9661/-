package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class node {
    int to;
    int value;

    node(int to, int value) {
        this.to = to;
        this.value = value;
    }
}

public class Main {

    static int[] dist = new int[20001];
    static int V, E = 0; //node, edge
    static int start = 0;
    static ArrayList<node>[] arrayList = new ArrayList[20001];

    public static void main(String[] args) throws IOException {
        //arrayList init
        input();
        init();
        dijstra();

        for(int i = 1; i <= V; i++) {
            if(dist[i] == Integer.MAX_VALUE ) System.out.println("INF");
            else System.out.println(dist[i]);
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(br.readLine());

        for(int i = 0; i <= V; i++) {
            arrayList[i] = new ArrayList<node>();
        }

        for(int i = 0; i < E; i++) {
            int from, to, val;
            st = new StringTokenizer(br.readLine(), " ");
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            val = Integer.parseInt(st.nextToken());
            arrayList[from].add(new node(to, val));
        }
    }

    static void init() {
        for(int i = 1; i <= V; i++) dist[i] = Integer.MAX_VALUE;
        dist[start] = 0;
    }

    static void dijstra() {
        PriorityQueue<node> pq = new PriorityQueue<>(new Comparator<node>() {

            @Override
            public int compare(node a, node b) {
                if(a.value > b.value) return 1;
//                else if( a.value > b.value) return -1;
                else return -1;
            }
        }); //정렬 기준은, value가 낮은 순
        pq.add(new node(start,0));

        while( !pq.isEmpty() ) {
            int cur = pq.peek().to;
            int distance = pq.peek().value;
            pq.remove();

            if( dist[cur] < distance ) continue;
            for(int i = 0; i < arrayList[cur].size(); i++) {
                int next = arrayList[cur].get(i).to;
                int nextDist = arrayList[cur].get(i).value;

                if( dist[cur] + nextDist < dist[next] ) {
                    dist[next] = dist[cur] + nextDist;
                    pq.add(new node(next, dist[next]));
                }
            }
        }
    }
}
