class Solution {
    class Info {
        int r, c;
        Info(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    ArrayList<Info> al = new ArrayList<Info>();
    int[][] arr = new int[8][8];
    
    void init(int[][] queens, int[] king) {
        al.add(new Info(-1,-1));
        al.add(new Info(-1,0));
        al.add(new Info(-1,1));
        al.add(new Info(0,1));
        al.add(new Info(1,1));
        al.add(new Info(1,0));
        al.add(new Info(1,-1));
        al.add(new Info(0,-1));
        
        // init black queen pos
        for (int i = 0; i < queens.length; i++) {
            arr[queens[i][0]][queens[i][1]] = 1;
        }
        arr[king[0]][king[1]] = 100;
    }
    
    boolean outOfRange(int r, int c) {
        if ( r < 0 || r > 7 || c < 0  || c > 7) return true;
        return false;
    }
    
    boolean check(int r, int c, Info pos) {
        for (int i = 1; i <= 8; i++) {
            int nr = r + pos.r * i;
            int nc = c + pos.c * i;
            if (outOfRange(nr,nc) || arr[nr][nc] == 1) return false;
            else if (arr[nr][nc] == 100) return true;
        }
        return false;
    }
    
    boolean canAttack(int[] king, int[] queen) {
        int kingRow = king[0];
        int kingCol = king[1];
        int r = queen[0];
        int c = queen[1];

        for (int i = 0; i < al.size(); i++) {
            if (check(r, c, al.get(i))) return true;
        }
       
       return false;
    }
    
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        init(queens, king);
        ArrayList<List<Integer>> answer = new ArrayList<>();
        
        for (int i = 0; i < queens.length; i++) {
            if (canAttack(king, queens[i])) {
                ArrayList<Integer> ans = new ArrayList<>();
                ans.add(queens[i][0]);
                ans.add(queens[i][1]);
                answer.add(ans);
            }
        }
        return answer;
    }
}
