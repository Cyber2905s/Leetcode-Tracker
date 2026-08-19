class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;
        for(char c:moves){
            if(c=='U') up++;
            if(c=='D') down++;
            if(c=='L') left++;
            if(c=='R') right++;
        }
        return (up==down && left==right);
    }
};
