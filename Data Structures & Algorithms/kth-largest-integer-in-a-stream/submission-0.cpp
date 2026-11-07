class KthLargest {
public:
    int s;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(int n : nums){
            pq.push(n);
        }
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>s) pq.pop();
        return pq.top();
    }
};
