class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> st;
        queue<pair<int,int>> q;
        q.push({x,0});
        st.insert(x);
        while(!q.empty()){
            int num = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(num==y) return steps;
            if(num%11==0 && st.find(num%11)==st.end()){
                q.push({num/11,steps+1});
                st.insert(num/11);
            }
            if(num%5==0 && st.find(num%5)==st.end()){
                q.push({num/5,steps+1});
                st.insert(num/5);
            }
            if(st.find(num-1)==st.end()){
                q.push({num-1,steps+1});
                st.insert(num-1);
            }
            if(st.find(num+1)==st.end()){
                q.push({num+1,steps+1});
                st.insert(num+1);
            }
        }
        return 0;
    }
};
