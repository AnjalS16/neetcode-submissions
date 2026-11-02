class Solution {
public:
    vector<string> res;
    map<string, vector<string>> mp;
    

    void dfs(string s){
        //base case
        while(!mp[s].empty()){
            string dest = mp[s].back();
            mp[s].pop_back();
            dfs(dest);
        }
        res.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        
        for(int i = 0; i<n; i++){
            mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        for(auto &[airport, destinations] : mp){
            sort(destinations.rbegin(), destinations.rend());
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
