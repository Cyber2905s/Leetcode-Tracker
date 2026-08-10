class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word,vector<string> &seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return; 
        }
        int steps = mpp[word];
        int size = word.size();
        for(int i=0;i<size;i++){
            char og = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=og;
        }
    }
public:
    vector<vector<string>> findLadders(string s, string e, vector<string>& wordList) {
        b=s; 
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(s);
        mpp[s]=1;
        int size = s.size();
        st.erase(s);
        while(!q.empty()){
            string word = q.front();
            int step = mpp[word];
            q.pop();
            if(word==e) break;
            for(int i=0;i<size;i++){
                char og = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word]= step+1;
                    }
                }
                word[i]=og;
            }
        }
        if(mpp.find(e)!=mpp.end()){
            vector<string> seq;
            seq.push_back(e);
            dfs(e,seq);
        }
        return ans;
    }
};
