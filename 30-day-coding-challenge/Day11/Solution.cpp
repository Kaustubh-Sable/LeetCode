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
public:
    int maxDiameter(TreeNode* root, int *max)
    {
        if(!root)
            return 0;
        
        int left = maxDiameter(root->left, max);
        int right = maxDiameter(root->right, max);
        
        if(left+right>*max)
            *max = left+right;
        
        return left>=right?left+1:right+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int *max = new int(0);
        maxDiameter(root, max);
        return *max;
    }
};
