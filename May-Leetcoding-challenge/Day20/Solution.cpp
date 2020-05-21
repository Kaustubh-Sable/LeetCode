/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int count;
    int ans;
public:
    void inorder(TreeNode* root, int k)
    {
        if(!root)
            return ;
        
        inorder(root->left, k);
        count++;
        if(count == k)
        {
            ans = root->val;
            return ;
        }
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return ans;
    }
};
