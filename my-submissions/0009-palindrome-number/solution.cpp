class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false;
    int n = x; 
    long rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return x == rev;
    }
};
