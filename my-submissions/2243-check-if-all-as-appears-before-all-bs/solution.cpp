class Solution {
public:
    bool checkString(string s) {
        int a = 0;
        int b = 0;
        for(char c: s){
            if(c=='a'){
                a++;
                if(b>0) return false;
            }
            if(c=='b'){
                b++;
            }
        }
        return true;
    }
};
