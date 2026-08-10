class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({s,0});
        st.erase(s);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==e) return steps;
            for(int i=0;i<word.size();i++){
                char og = word[i];
                for(char ch='A';ch<='Z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return -1;
    }
};
