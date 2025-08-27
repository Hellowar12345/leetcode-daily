/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int cnt=0;
    int ptr=0;
    int *ans=malloc(sizeof(int)*matSize*matColSize[0]);
    while(cnt<=(matSize+matColSize[0]-2)){
        int i=cnt;
        int j=0;
        while(j<0||i>=matSize||i<0||j>=matColSize[0]){
            i--;
            j++;
        }
        while(i >= 0 && i < matSize && j >= 0 && j < matColSize[i]){
            if(ptr<matSize*matColSize[0])ans[ptr++]=mat[i][j];
            i--;
            j++;
        }
        cnt++;
        if(cnt>(matSize+matColSize[0]-2))break;
        int a=0;
        int b=cnt;
        while(b>=matColSize[0]||a<0||a>=matSize||b<0){
            a++;
            b--;
        }
        while(a >= 0 && a < matSize && b >= 0 && b < matColSize[a]){
            if(ptr<matSize*matColSize[0])ans[ptr++]=mat[a][b];
            a++;
            b--;
        }
        cnt++;
    }
    *returnSize=matSize*matColSize[0];
    return ans;
}
