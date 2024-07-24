#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

void checkAnswer(char *spaces,char *cGuess); //CHECK ANSWER AND DISPLAY CORRECT COLORS
bool checkWinner(char *spaces, char *cGuess); //CHECK IF THE PLAYER WON
void getAnswer(char *spaces); //PROMPT THE PLAYER FOR A ANSWER

const string YELLOW = "\033[33m", GREEN = "\033[1;32m", RESET = "\033[0m";
int score = 1; //AMMOUNT OF TRIES



int main (){
 
    srand(time(NULL));
   
    cout << "**************************************\n";
    cout << "            ---WORDLE---\n";
    cout << "**************************************\n";

    string possibleWords[] =  {"SHAFT", "DOLLY", "CHAOS", "APPLE", "BEACH", "CLOUD",  // POSSIBLE ANSWERS
                               "FROST", "GRACE", "HUMOR", "IVORY", "JAZZY", "KICKS",
                               "LEMON", "MAGIC", "NOVEL", "OPERA", "PIXEL", "QUIET",
                               "ROCKY", "SALSA", "TANGO", "UNITY", "VENUS", "WAVES",
                               "YUMMY", "BRAVE", "CHESS", "DELTA", "EAGLE", "FLUTE",
                               "GHOST", "HAPPY", "IGLOO", "JOKER", "KIWIS", "LEASH",
                               "MANGO", "NAIVE", "OASIS", "PUPPY", "QUEEN", "RAVEN",
                               "SUNNY", "TIARA", "UMBRA", "VIXEN", "WILDS", "XENON"};

    int size = sizeof(possibleWords) / sizeof(possibleWords[0]);
    string correctGuessS = possibleWords[rand() % size]; // ANSWER
    char correctGuess[5];

    for(int i = 0;i < 5;i++)
       correctGuess[i] = correctGuessS[i];
       
    char spaces[5] = {' ',' ', ' ', ' ', ' '};
    int running = 0; 

    while (running < 5) //5 TRIES TO GUESS A WORD
    {
        getAnswer(spaces);
        checkAnswer(spaces ,correctGuess);
        if(checkWinner(spaces ,correctGuess) == true){
          cout << "\n     ---YOU WIN!---\n";
          return 0;
        }else if(running == 4){
           cout << "YOU LOST, ANSWER WAS: " << correctGuessS << ". \n";
        }
        running++;
    }

    return 0;
}
void checkAnswer(char *spaces,char *cGuess){
    
     for(int i = 0;i < 5;i++){
        auto pos = find(cGuess, cGuess + sizeof(cGuess) / sizeof(cGuess[0]), spaces[i]);

        if(spaces[i] == cGuess[i]){ //CHECK FOR GREENS
            cout << GREEN << "  " << spaces[i] << "  " << RESET;
        }else if(pos != cGuess + sizeof(cGuess) / sizeof(cGuess[0])){ //CHECK FOR YELLOWS
            cout << YELLOW << "  " << spaces[i] << "  " << RESET; 
        }else{
            cout << "  " << spaces[i] << "  "; //THE REST
        } 
     }
 cout << "\n  _    _    _    _    _\n\n";
}
bool checkWinner(char *spaces,char *cGuess){
    for(int i = 0;i < 5;i++){
        if(spaces[i] != cGuess[i]) return 0; //CHECK FOR WINNER
    }
  return 1;
}
void getAnswer(char *spaces){
    string strGuess;
    do
    {
        cout << "\nENTER YOUR 5 LETTER WORD GUESS (" << score <<"/5): "; 
        getline(cin >> ws, strGuess); //PROMPT USER
        transform(strGuess.begin(), strGuess.end(), strGuess.begin(),::toupper); //TRANSFORM TO UPPERCASE
        cout << "\n"; 
    } while (strGuess.size() != 5);
     

    for(int i = 0;i < 5;i++)
       spaces[i] = strGuess[i];

    score++;
}