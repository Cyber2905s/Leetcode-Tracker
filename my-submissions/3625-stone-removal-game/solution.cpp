class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        bool alice = true;
        int num = 10;
        while(n-num>=0){
            n -= num;
            num--;
            alice = !alice;
        }
        return !alice;
    }
};
