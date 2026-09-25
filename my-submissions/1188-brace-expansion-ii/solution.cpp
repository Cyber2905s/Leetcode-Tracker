class Solution {
private:
    set<string> parseFactor(int& i, const string& s) {
        if (s[i] == '{') {
            i++; // skip '{'
            set<string> res = parseExpression(i, s);
            i++; // skip '}'
            return res;
        }

        string word = "";
        while (i < s.size() && isalpha(s[i])) {
            word += s[i++];
        }
        return {word};
    }

    set<string> parseTerm(int& i, const string& s) {
        // Multiplicative identity: {""} allows direct Cartesian concatenation
        set<string> res = {""};

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> factor = parseFactor(i, s);
            set<string> nextRes;

            for (const string& a : res) {
                for (const string& b : factor) {
                    nextRes.insert(a + b);
                }
            }
            res = move(nextRes);
        }

        return res;
    }

    set<string> parseExpression(int& i, const string& s) {
        set<string> res = parseTerm(i, s);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            set<string> nextTerm = parseTerm(i, s);
            res.insert(nextTerm.begin(), nextTerm.end());
        }

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> resultSet = parseExpression(i, expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
