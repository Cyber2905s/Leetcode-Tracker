class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({s,1});
        unordered_set<string> st;
        for(auto &it: wordList){
            st.insert(it);
        }
        st.erase(s);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==e) return step;
            for(int i=0;i<word.size();i++){
                char og = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};
