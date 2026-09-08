class Solution {
private:
    bool isPal(string &s,int l,int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        int cnt = 0;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return isPal(s,l+1,r)||isPal(s,l,r-1);
            }
        }
        return true;
    }
};
