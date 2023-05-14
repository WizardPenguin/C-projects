#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char board[3][3]; 
const char PLAYER = 'X'; 
const char COMPUTER = 'O'; 
void reset();  // resetting board
bool possible(); // check if there is empty cell
void printRow(int i); // printing ith row
void printDots(); // printing dots
void print(); // printing whiole board
bool checkWinner(); // check for winner
void computerMove(); // make computers move
void playerMove(); // make players move
int getVal(); // checking for validity of value taken as player move 
bool checkAgain(); // 
int main(){
    bool playAgain = true; 
    reset(); 
    while(playAgain){
        if(not possible()){
            printf("\nGame Draw\n"); 
            playAgain = checkAgain();
            continue;  
        }
        print(); 
        playerMove();
        if(checkWinner()){
            printf("\nYou Won \n"); 
            playAgain = checkAgain(); 
            continue; 
        }
        if(not possible()){
            printf("\nGame Draw\n"); 
            playAgain = checkAgain(); 
            continue; 
        }
        print(); 
        computerMove();
        if(checkWinner()){
            printf("\n You lost\n"); 
            playAgain = checkAgain(); 
        }
    }
    printf("\nThank You for playing this game"); 
    return 0; 
}
void reset(){
    for(int i=0;i<3;i+=1){
        for(int j=0;j<3;j+=1){
            board[i][j] = ' '; 
        }
    }
}
bool checkWinner(){
    for(int i=0;i<3;i+=1){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] and board[i][0] != ' ') return true; 
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] and board[0][i] != ' ') return true; 
    }
    if(board[1][1] == ' ')  return false; 
    if(board[1][1] == board[2][2] and board[0][0] == board[1][1]) return true; 
    if(board[2][0] == board[0][2] and board[1][1] == board[0][2]) return true; 
    return false; 
}
int getVal(){
    int val; 
    while(1){
        scanf("%d",&val);
        if(val < 0 or val > 3) printf("try again #[1,3] : "); 
        else break;  
    };
    return --val; 
}
void printRow(int i){
    printf(" %c | %c | %c",board[i][0],board[i][1],board[i][2]); 
} 
void printDots(){
    printf("\n---|---|---\n"); 
}
void print(){
    printRow(0); 
    printDots(); 
    printRow(1);
    printDots(); 
    printRow(2); 
    return; 
}
void playerMove(){
    printf("\nplayers Move\n"); 
    int x,y; 
    while(1){
        printf("enter row #[1,3] : "); 
        x = getVal(); 
        printf("enter col #[1,3] : "); 
        y = getVal(); 
        if(board[x][y] == ' '){
            board[x][y] = PLAYER; 
            return; 
        }
        else{
            printf("invalid move Try again \n"); 
        }
    }
    return;  // winner would necessary have returned 
}
void computerMove(){
    srand(time(0));
    printf("\ncomputers Move\n"); 
    while(1){
        int x = rand()%3; 
        int y = rand()%3; 
        if(board[x][y] == ' '){
            board[x][y] = COMPUTER; 
            return; 
        }
    }
    return; // winner would necessary have returned
}
bool possible(){
    for(int i=0;i<3;i+=1){
        for(int j=0;j<3;j+=1){
            if(board[i][j] == ' ') return true; 
        }
    } 
    return false; // no extra move possible
}
bool checkAgain(){
    printf("\nPlease type Y/y to play again : ");
    char val; 
    while (((val = getchar()) != '\n' or val == ' ') && val != EOF); // means we are getting last character 
    scanf("%c",&val); 
    reset(); 
    if(val == 'Y') val = 'y'; 
    return (val == 'y'); 
}