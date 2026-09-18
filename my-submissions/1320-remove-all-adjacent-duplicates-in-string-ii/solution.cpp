class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c: s){
            if(!st.empty() && st.top().first == c){
                st.top().second++;
            }
            else{
                st.push({c,1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            int cnt = st.top().second;
            for(int i=0;i<cnt;i++){
                ans+=st.top().first;
            }
            st.pop();
        }
        if(ans.size()>0)reverse(ans.begin(),ans.end());
        return ans;
    }
};
