*/想法：直接找邊界*/
int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int left=-1,right=-1,up=-1,down=-1;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]){
                if(up==-1)up=i;
                if(left==-1)left=j;
                if(down==-1)down=i;
                if(right==-1)right=j;
                if(up>i)up=i;
                if(down<i)down=i;
                if(left>j)left=j;
                if(right<j)right=j;
            }
        }
        
    }
   return (right-left+1)*(down-up+1);
}
