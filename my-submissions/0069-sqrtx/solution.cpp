class Solution {
public:
    long long int binarysearch(int n) {
    if (n < 0) return -1; 
    if (n == 0 || n == 1) return n; 
    long long int s = 0;
    long long int e = n;
    long long int ans = 0;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;

        if (square == n) {
            return mid;
        } 
        else if (square < n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}
    int mySqrt(int x) {
        return binarysearch(x);
    }
};
