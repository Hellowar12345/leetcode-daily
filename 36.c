bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    
    for(int i=0;i<boardSize;i++){
        bool row[10]={false};
        for(int j=0;j<boardColSize[0];j++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'0';
                if(row[num])return false;
                row[num]=true;
            }
        }
    }
     for(int j=0;j<boardColSize[0];j++){
        bool col[10]={false};
        for(int i=0;i<boardSize;i++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'0';
                if(col[num])return false;
                col[num]=true;
            }
        }
    }
    for(int box=0;box<9;box+=3){
        for(int boxcol=0;boxcol<9;boxcol+=3){
            bool boxes[10]={false};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row=box+i;
                    int col=boxcol+j;
                    if(board[row][col]!='.'){
                        int num=board[row][col]-'0';
                        if(boxes[num])return false;
                        boxes[num]=true;
                    }
                }
            }
        }
    }
    return true;
}
