#include <iostream>
#include <ctime>
using namespace std;


bool getAnswerAndQuestionE(double guess, int score);
bool getAnswerAndQuestionM(double guess, int score);
bool getAnswerAndQuestionH(double guess, int score);

//score dosent work

int main(){
    bool running = true; 
    char yORn;
    int score = 0;

    cout << "\n----------MATH GAME----------\n\n";

    while (running == true)
    {
        int difficulty;

        do{

           cout << "CHOOSE DIFFICULTY (1-3): ";
           cin >> difficulty;
           cout << "\n";
           double guess;

           switch (difficulty){

                  case 1:
                    getAnswerAndQuestionE(guess, score) == true ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
                  break;
                  case 2:
                    getAnswerAndQuestionM(guess, score) == true ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
                  break;
                  case 3:
                    getAnswerAndQuestionH(guess, score) == true ? cout << "YOU WIN\n" : cout << "YOU LOSE\n";
                  break;

           }

          cout << "CONTINUE (Y/N): ";
          cin >> yORn;
          if(yORn == 'Y' || yORn == 'y') running = true;
             else running = false;

        } while (difficulty > 3 && difficulty < 1);

    }
    cout << "SCORE WAS: " << score;
    return 0;
}