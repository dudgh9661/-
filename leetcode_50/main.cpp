class Solution {
public:
    
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == 0) return 0;
        
        double ans = 1;
        long  N = n;
        bool flag = false;
        if ( N < 0 ) {
            N = -N;
            flag = true;
        }
        
        while (N > 0) {
            if (N % 2 == 0) {
                x = x*x;
                N /= 2;
            } else {
                ans = ans * x;
                --N;
            }
        }
        cout << ans;
        if (flag) ans = 1 / ans;
        return ans;
    }
};
