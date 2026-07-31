class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false;
        bool y = false;
        bool z = false;
        for(const auto& trip: triplets){
            if(trip[0]==target[0] && trip[1]<=target[1] && trip[2]<=target[2]) x=true;
            if(trip[0]<=target[0] && trip[1]==target[1] && trip[2]<=target[2]) y=true;
            if(trip[0]<=target[0] && trip[1]<=target[1] && trip[2]==target[2]) z=true;
        }
        return x&&y&&z;
    }
};
