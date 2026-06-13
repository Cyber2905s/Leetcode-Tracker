class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(const string& word : words){
            int tw=0;
            for(char c: word){
                tw+=weights[c-'a'];
            }
            int val=tw%26;
            result+=char('z'-val);
        }
        return result;
    }
};
