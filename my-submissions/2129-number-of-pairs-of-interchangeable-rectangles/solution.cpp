class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        unordered_map<double,long long> freq;
        for(auto& rect: rectangles){
            double ratio = (double)rect[0]/rect[1];
            ans+=freq[ratio];
            freq[ratio]++;
        }
        return ans;
    }
};
