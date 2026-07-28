class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int gk;
public:
    KthLargest(int k, vector<int>& nums) {
        gk=k;
        for(int n: nums){
            minHeap.push(n);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>gk){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
