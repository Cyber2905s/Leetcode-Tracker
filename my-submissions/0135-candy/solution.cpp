class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1) return n;
        int candy = n;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                candy+=peak;
                i++;
            }
            int down = 0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                candy+=down;
                i++;
            }
            candy -= min(down,peak);
        }
        return candy;
    }
};
