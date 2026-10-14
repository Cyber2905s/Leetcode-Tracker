class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9LL * num) {
            return "";
        }
        int q = sum / 9;
        int r = sum % 9;
        string result = "";
        result.reserve(num);
        result.append(q, '9');
        if (r > 0) {
            result.push_back('0' + r);
        }
        int zeros = num - result.size();
        if (zeros > 0) {
            result.append(zeros, '0');
        }
        return result;
    }
};
