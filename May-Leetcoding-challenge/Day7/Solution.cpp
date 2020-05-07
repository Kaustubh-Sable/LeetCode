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
    int getDepth(TreeNode* root, int num_to_find, int other_num, int level)
    {
        if(!root)
            return -1;
        
        if(root->val==num_to_find)
            return level;
        
        int ld = getDepth(root->left, num_to_find, other_num, level+1);
        if(ld>=0)
        {
            // check if same parent
            if(root->right && root->right->val==other_num)
                return -1;
            return ld;
        }
        int rd = getDepth(root->right, num_to_find, other_num, level+1);
        if(rd>=0)
        {
            // check if same parent
            if(root->left && root->left->val==other_num)
                return -1;
            return rd;
        }
        
        return -1;
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        int xd = getDepth(root, x, y, 0);
        if(xd<0)
            return false;
        int yd = getDepth(root, y, x, 0);
        if(yd<0 || xd!=yd)
            return false;
        
        return true;
    }
};
