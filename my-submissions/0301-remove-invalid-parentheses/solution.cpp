class Solution {
private:
    void solve(int index, const string& s, int remOpen, int remClose, int open, 
               string& current, unordered_set<string>& result) {
        if (open < 0) return;

        if (index == s.size()) {
            if (remOpen == 0 && remClose == 0 && open == 0) {
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        if (ch == '(' && remOpen > 0) {
            solve(index + 1, s, remOpen - 1, remClose, open, current, result);
        } else if (ch == ')' && remClose > 0) {
            solve(index + 1, s, remOpen, remClose - 1, open, current, result);
        }

        current.push_back(ch);
        if (ch == '(') {
            solve(index + 1, s, remOpen, remClose, open + 1, current, result);
        } else if (ch == ')') {
            solve(index + 1, s, remOpen, remClose, open - 1, current, result);
        } else {
            solve(index + 1, s, remOpen, remClose, open, current, result);
        }
        current.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int remOpen = 0;
        int remClose = 0;

        for (char c : s) {
            if (c == '(') {
                remOpen++;
            } else if (c == ')') {
                if (remOpen > 0) {
                    remOpen--;
                } else {
                    remClose++;
                }
            }
        }

        unordered_set<string> result;
        string current = "";
        solve(0, s, remOpen, remClose, 0, current, result);

        return vector<string>(result.begin(), result.end());
    }
};
