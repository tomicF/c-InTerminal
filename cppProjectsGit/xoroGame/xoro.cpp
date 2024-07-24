#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main (){
    char spaces[9] = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
    char player = 'X', computer = 'O';
    bool isRunning = true;
    while (isRunning)
    {
        drawBoard(spaces);
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            isRunning = false;
            break;
        }
        if(checkTie(spaces)){
            isRunning = false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            isRunning = false;
            break;
        }
        if(checkTie(spaces)){
            isRunning = false;
            break;
        }
    }
    
    return 0;
}

void drawBoard(char *spaces){
   cout << "\n";
   cout << "   |   |   " << "\n";
   cout << " " << spaces[0] << " | "<< spaces[1] <<" | " << spaces[2] << "\n";
   cout << "___|___|___" << "\n";
   cout << "   |   |   " << "\n";
   cout << " " << spaces[3] << " | "<< spaces[4] <<" | " << spaces[5] << "\n";
   cout << "___|___|___" << "\n";
   cout << "   |   |   " << "\n";
   cout << " " << spaces[6] << " | "<< spaces[7] <<" | " << spaces[8] << "\n";
   cout << "   |   |   " << "\n";
   cout << "\n";
}
void playerMove(char *spaces, char player){
    int guess;
    do{
        cout << "Chose where to place the " << player << "(1 - 9): ";
        cin >> guess;
        guess--;
        if(spaces[guess] == ' '){
          spaces[guess] = player;
        }
    }while (guess < 0 || guess > 8);
    
}
void computerMove(char *spaces, char computer){
   srand(time(NULL));
   while(true){
    int guess = rand() % 9;
    if(spaces[guess] == ' '){
        spaces[guess] = computer;
        break;
    }
   }
}
bool checkWinner(char *spaces, char player, char computer){
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
       spaces[0] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
       spaces[3] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
       spaces[6] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    //
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
       spaces[0] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
       spaces[1] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
       spaces[2] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    }
    //
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[9]){
       spaces[0] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
       spaces[2] == player ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
    } 
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for(int i = 0;i < 9;i++)
       if(spaces[i] == ' ') return false;

    cout << "TIE\n";   
    return true;
}