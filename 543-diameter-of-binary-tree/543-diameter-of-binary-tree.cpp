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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        count(root);
        return ans;
    }
    
    int count(TreeNode* node){
        if(!node)
            return 0;
        int x = count(node->left), y = count(node->right);
        ans = max(x+y, ans);
        return max(x, y)+1;
    }
};