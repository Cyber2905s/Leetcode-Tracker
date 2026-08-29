class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int num: asteroids){
            if(num>0) st.push_back(num);
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(num)){
                    st.pop_back();
                }
                if(!st.empty() && st.back()==abs(num)) st.pop_back();
                else if(st.empty() || st.back()<0) st.push_back(num);
            }
        }
        return st;
    }
};
