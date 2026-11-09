class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> mp;
        for(char t : tasks) mp[t]++;
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        while(!pq.empty()){
            int ans = 0;
            vector<int> tmp;
            for(int i = 0; i<n+1; i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    ans++;
                }
            }
            
                for(auto t : tmp){
                    if(t) pq.push(t);
                }
            
            time += pq.empty() ? ans : n+1;
        }
        return time;
    }
};
