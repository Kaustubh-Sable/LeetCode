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
    int getMax(TreeNode* root, int& max)
    {
        if(!root)
            return 0;
        
        int left = getMax(root->left, max);
        int right = getMax(root->right, max);
        int curr = root->val;
        
        if(curr+left+right>max)
            max = curr+left+right;
        
        if(left>0 && left>right)
            curr+=left;
        if(right>0 && right>left)
            curr+=right;
        
        if(curr>max)
            max = curr;
        
        return curr;
    }
    
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        getMax(root, max);
        
        return max;
    }
};
