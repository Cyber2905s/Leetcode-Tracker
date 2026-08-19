class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> res;
        for(auto& seat: reservedSeats){
            res[seat[0]].push_back(seat[1]);
        }
        int ans = 2*(n-(int)res.size());
        for(auto& entry: res){
            vector<int> seats = entry.second;
            bool left = false;
            bool right = false;
            bool mid = false;
            for(auto& seat: seats){
                if(seat>=2 && seat<=5) left = true;
                if(seat>=4 && seat<=7) mid = true;
                if(seat>=6 && seat<=9) right = true;
            }
            if(!left && !right) ans+=2;
            else if(!left||!right||!mid) ans+=1;
        }
        return ans;
    }
};
