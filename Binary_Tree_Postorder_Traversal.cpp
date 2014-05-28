/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode *root) {
        if(root == NULL)
            return v;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        
        v.push_back(root->val);
        return v;
    }
};