class Solution {
public:
    int dp[10001] = { 0 };
    
    int sol(int n) {
        if (dp[n] != 0) return dp[n];
        if (sqrt(n) - (int) sqrt(n) == 0) {
            dp[n] = 1;
            return 1;
        }
        
        int MIN = 1e9;
        for (int i = 1; i <= sqrt(n); i++) {
            MIN = min(sol(n-i*i) + 1, MIN);
        }
        
        // cout << n << " MIN val : " << MIN << endl;
        dp[n] = MIN;
        return dp[n];
    }
    
    int numSquares(int n) {
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        return sol(n);
    }
};
