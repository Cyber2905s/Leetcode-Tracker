class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();
        int rowin=0;
        int colin=column-1;
        while(rowin<row && colin>=0){
            int element= matrix[rowin][colin];
            if(element == target){
                return 1;
            }
            else if(element<target){
                rowin++;
            }
            else{
                colin--;
            }
        }
        return 0;
    }
};
