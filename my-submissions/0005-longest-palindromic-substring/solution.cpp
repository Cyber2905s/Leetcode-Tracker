class Solution {
public:
    int len(string s,int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }
        int start=0,maxl=0;
        for(int i=0;i<=s.length()-1;i++){
            int odd = len(s,i,i);
            int even = len(s,i,i+1);
            int cmax = max(odd,even);
            if(cmax>maxl){
                maxl=cmax;
                start=i-(cmax-1)/2;
            }
        }
        return s.substr(start,maxl);
    }
};
