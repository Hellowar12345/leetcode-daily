/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    int front=0,rear=0;
    *returnSize=0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    int **ans=malloc(sizeof(int*)*2000);
    struct TreeNode* queue[2000];
    queue[rear++]=root;
    while(front<rear){
        int levelsize=rear-front;
        int *level=malloc(sizeof(int)*levelsize);
        int ptr=0;
        for(int i=0;i<levelsize;i++){
            level[ptr++]=queue[front]->val;
        if(queue[front]->left){
            queue[rear++]=queue[front]->left;
        }
        if(queue[front]->right){
            queue[rear++]=queue[front]->right;
        }
        front++;
        }
         (*returnColumnSizes)[*returnSize] = levelsize;
        ans[(*returnSize)++]=level;
        
    }
    return ans;
}
