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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> temp;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; i++){
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        vector<vector<int>> anss;
        for(int i=ans.size()-1; i>=0; i--){
            anss.push_back(ans[i]);
        }
        return anss;
    }
};