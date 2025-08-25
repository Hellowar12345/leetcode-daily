/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <math.h>
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int count=1;
    int ptr=1;
    if(matSize==1){
        *returnSize=matColSize[0];
        return mat[0];
    }
   
    int row=matSize;
    int col=matColSize[0];
    int cnt=(sqrt(row*col)-1);
    int record[row*col+1];
    *returnSize=row*col;
    int *ans=malloc(sizeof(int)*row*col);
     if(matColSize[0]==1){
        *returnSize=matSize;
        for(int i=0;i<matSize;i++){
            ans[i]=mat[i][0];
        }
        return ans;
    }
    ans[0]=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            record[mat[i][j]]=i+j;
        }
    }
    for(int j=0;j<cnt;j++){
        for(int i=2;i<=row*col;i++){
            if(record[i]==count)ans[ptr++]=i;
        }
        count++;
        for(int i=row*col;i>=2;i--){
            if(record[i]==count){
                if(ptr<row*col) ans[ptr++]=i;;
            }
        }
        count++;
    }

    return ans;
}
