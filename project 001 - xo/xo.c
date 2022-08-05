#include <stdio.h>
int winCheck(char board[],char sign){
    if(board[0]==sign &&board[1]==sign &&board[2]==sign){
        return 1;
    }else if(board[3]==sign &&board[4]==sign &&board[5]==sign){
        return 1;
    }else if(board[6]==sign &&board[7]==sign &&board[8]==sign){
        return 1;
    }else if(board[0]==sign &&board[3]==sign &&board[6]==sign){
        return 1;
    }else if(board[1]==sign &&board[4]==sign &&board[7]==sign){
        return 1;
    }else if(board[2]==sign &&board[5]==sign &&board[8]==sign){
        return 1;
    }else if(board[0]==sign &&board[4]==sign &&board[8]==sign){
        return 1;
    }else if(board[2]==sign &&board[4]==sign &&board[6]==sign){
        return 1;
    }

    return 0;
}

void printBoard(char board[]){
    printf("%c %c %c \n",board[0],board[1],board[2]);
    printf("%c %c %c \n",board[3],board[4],board[5]);
    printf("%c %c %c \n",board[6],board[7],board[8]);
}

int positionCheck(char board[],int position){
    if(position>9){
      return 0;
   }
   if(board[position]!='X' &&board[position]!='O'){
       return 1;
   }

   return 0;
}

int main() {
    char board [9]={'1','2','3','4','5','6','7','8','9'};
    printBoard(board);
    
    char sign='X';
    int input=-1;
    for(int i=0;i<9;i++){
        // Taking User Input
        printf("Player %c ,Please enter the position you want : ",sign);
        scanf("%d",&input);
        // Check if position valid
        while(positionCheck(board,input-1)==0){
        printf("Player %c ,Please enter a valid position  : ",sign);
        scanf("%d",&input);
        }
        board[input-1]=sign;
        
        // Print The Board
        printBoard(board);
        // Checking if it's a Win
        if(winCheck(board,sign) ==1){
            printf("Player %c Won !",sign);
            break;
        }
        //Checking if it's a Draw
        if(i==8&&winCheck(board,sign)==0){
            printf("It's a Draw !");
            break;
        }
        // Changing Turn
        if(sign=='X'){
            sign='O';
        }else{
            sign='X';
        }

    }

    return 0;
}