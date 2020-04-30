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
    bool checkIfValid(TreeNode* root, vector<int>& arr, int pos) 
    {
        if(!root || root->val!=arr[pos])
            return false;
        
        cout<<root->val<<"->";
        
        if(pos==arr.size()-1)
        {
            if(root->left || root->right)
                return false;
            
            return true;
        }
        
        if(!checkIfValid(root->left, arr, pos+1) && !checkIfValid(root->right, arr, pos+1))
            return false;
        
        return true;
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return checkIfValid(root, arr, 0);
    }
};
