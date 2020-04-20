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
    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if(left>right)
            return NULL;
        if(left==right)
        {
            return new TreeNode(preorder[left]);
        }
        
        TreeNode *node = new TreeNode(preorder[left]);
        
        int i=left+1;
        while(i<=right)
        {
            if(preorder[i]>preorder[left])
                break;
            i++;
        }
        
        node->left = helper(preorder, left+1, i-1);
        node->right = helper(preorder, i, right);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};
