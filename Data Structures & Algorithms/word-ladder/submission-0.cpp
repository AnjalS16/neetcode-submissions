class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        vector<string> words = wordList;

        int target = -1;
        int start = -1;

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == endWord) target = i;
            if (words[i] == beginWord) start = i;
        }

        if (target == -1) return 0;

        if (start == -1) {
            start = words.size();
            words.push_back(beginWord);
        }

        int n = words.size();
        int len = beginWord.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;

                for (int k = 0; k < len; k++) {
                    if (words[i][k] != words[j][k]) diff++;
                    if (diff > 1) break;
                }

                if (diff == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        int length = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int k = 0; k < size; k++) {
                int node = q.front();
                q.pop();

                if (node == target) return length;

                for (int next : adj[node]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }

            length++;
        }

        return 0;
    }
};