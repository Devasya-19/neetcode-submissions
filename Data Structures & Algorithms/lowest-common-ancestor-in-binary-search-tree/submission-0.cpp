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
    bool trav(TreeNode* node,TreeNode* find,vector<TreeNode*>& stored){
        if(node==nullptr)return false;
        stored.push_back(node);
        if(node==find){
            return true;
        }
        if(trav(node->left,find,stored)|| trav(node->right,find,stored)){
            return true;
        }
        stored.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>stored;
        vector<TreeNode*>stored2;
        TreeNode* node=root;
        trav(node,p,stored);
        trav(node,q,stored2);
        int i=0;
        TreeNode* ans=root;
        while(i<stored.size() && i<stored2.size()){
            if(stored[i]!=stored2[i]){
                break;
            }
            ans=stored[i];
            i++;
        }
        return ans;
    }
};
