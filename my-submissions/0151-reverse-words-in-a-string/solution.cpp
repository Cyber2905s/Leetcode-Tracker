class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = s.length() - 1;
        string temp = "";
        string ans = "";

        while (start <= end && s[start] == ' ') {
            start++;
        }

        while (end >= start && s[end] == ' ') {
            end--;
        }

        while (start <= end) {
            char ch = s[start];
            if (ch != ' ') {
                temp += ch;
            } 
            else if (ch == ' ' && temp.length() > 0) {
                if (ans.length() > 0) {
                    ans = temp + " " + ans;
                } 
                else {
                    ans = temp;
                }
                temp = "";
            }
            start++;
        }

        if (temp.length() > 0) {
            if (ans.length() > 0) {
                ans = temp + " " + ans;
            } 
            else {
                ans = temp;
            }
        }
        
        return ans;
    }
};
