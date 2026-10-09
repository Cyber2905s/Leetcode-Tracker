class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xor_sum = 0;
        for (int x : nums) {
            xor_sum ^= x;
        }
        return xor_sum == 0 || nums.size() % 2 == 0;
    }
};
