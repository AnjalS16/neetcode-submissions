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

// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root==nullptr) return 0;
//         return 1+max(height(root->left), height(root->right));
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==nullptr) return true;
//         if(abs(height(root->left)-height(root->right))>1) return false;
//         return true;
//     }
// };

class Solution {
public:
    int check(TreeNode* root) {
        if (!root) return 0;

        int l = check(root->left);
        if (l == -1) return -1;          // left subtree already unbalanced

        int r = check(root->right);
        if (r == -1) return -1;          // right subtree already unbalanced

        if (abs(l - r) > 1) return -1;   // this node is unbalanced

        return 1 + max(l, r);            // normal height
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
