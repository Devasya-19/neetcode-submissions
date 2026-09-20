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
    int trav(TreeNode* node,int& diameter){
        if(node==nullptr)return 0;
        int lh=trav(node->left,diameter);
        int rh=trav(node->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* node =root;
        int diameter=0;
        trav(node,diameter);
        return diameter;
    }
};
