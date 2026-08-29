class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = -1e9;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1:st.top();
                maxi = max(maxi,heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1:st.top();
            maxi = max(maxi,heights[ele]*(nse-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> pre(m,0);
        int maxi = -1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') pre[j]+=1;
                else pre[j] = 0;
            }
            maxi = max(maxi,largestRectangleArea(pre));
        }
        return maxi;
    }
};
