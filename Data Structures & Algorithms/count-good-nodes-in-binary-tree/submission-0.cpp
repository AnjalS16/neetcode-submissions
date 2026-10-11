/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //int cnt = 0;
    int dfs(TreeNode* root, int m){
        if(!root) return 0;
        int cnt = 0;
        if(m <= root->val) cnt++;
        m = max(m, root->val);
        return cnt + dfs(root->left, m) + dfs(root->right, m);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int m = root->val;
        return dfs(root, m);
    }
};
