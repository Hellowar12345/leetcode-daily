/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool ismirror(struct TreeNode* t1,struct TreeNode* t2){
    if(!t1&&!t2)return true;
    if(!t1||!t2)return false;
    if(t1->val==t2->val){
        return ismirror(t1->right,t2->left)&&ismirror(t1->left,t2->right);
    }
    return false;
}
bool isSymmetric(struct TreeNode* root) {
    if(!root)return true;
    return ismirror(root->left,root->right);
}
