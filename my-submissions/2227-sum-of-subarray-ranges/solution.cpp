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
    vector<int> NGE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
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
    vector<int> PGGE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psse = PSSE(arr);
        int n = arr.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long left = i-psse[i];
            long long right = nse[i]-i;
            long long freq = left*right;
            long long val = freq*arr[i];
            sum+=val;
        }
        return sum;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nse = NGE(arr);
        vector<int> psse = PGGE(arr);
        int n = arr.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long left = i-psse[i];
            long long right = nse[i]-i;
            long long freq = left*right;
            long long val = freq*arr[i];
            sum+=val;
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};
