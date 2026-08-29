class Solution {
private:
    vector<int> NSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> PSSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psse = PSSE(arr);
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for(int i=0;i<n;i++){
            long long left = i-psse[i];
            long long right = nse[i]-i;
            long long freq = (left*right)%mod;
            long long val = (freq*arr[i])%mod;
            sum=(sum+val)%mod;
        }
        return sum;
    }
};
