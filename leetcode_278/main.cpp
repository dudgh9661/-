// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        long long idx = -1;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (isBadVersion(mid) == false) {
                left = mid + 1;
            } else {
                idx = mid;
                right = mid - 1;
            }
        }
        
        return idx;
    }
};
