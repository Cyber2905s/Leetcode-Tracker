class Solution {
public:
    vector<string> result;
    int values[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
    
    void backtrack(int idx, int count, int h, int m, int limit) {
        if (h > 11 || m > 59) return;
        
        if (count == limit) {
            string time = to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
            result.push_back(time);
            return;
        }
        
        for (int i = idx; i < 10; i++) {
            if (i < 4) {
                backtrack(i + 1, count + 1, h + values[i], m, limit);
            } else {
                backtrack(i + 1, count + 1, h, m + values[i], limit);
            }
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        backtrack(0, 0, 0, 0, turnedOn);
        return result;
    }
};
