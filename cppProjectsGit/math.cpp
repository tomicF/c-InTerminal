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


bool getAnswerAndQuestionE(double guess, int score){
   srand(time(NULL));
   int a = rand() % 11 + 1, b = rand() % 11 + 1;
   int operators = rand() % 2;

   switch (operators){
   case 0:
      cout << a << " + " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a + b) == guess ? score += 10, true : false;
    break;
    case 1:
      cout << a << " - " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a - b) == guess ? score += 10, true : false;
    break;
   }
   return 0;
};

bool getAnswerAndQuestionM(double guess, int score){
   srand(time(NULL));
   int a = rand() % 51 + 21, b = rand() % 51 + 21;
   int operators = rand() % 4;

   switch (operators){
   case 0:
      cout << a << " + " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a + b) == guess ? true, score += 30 : false;
    break;
    case 1:
      cout << a << " - " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a - b) == guess ? true, score += 30 : false;
    break;
    case 2:
      cout << a << " * " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a * b) == guess ? true, score += 50 : false;
    break;
    case 3:
      cout << a << " / " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a / b) == guess ? true, score += 50 : false;
    break;
   }
   return 0;
};

bool getAnswerAndQuestionH(double guess, int score){
   srand(time(NULL));
   int a = rand() % 101 + 51, b = rand() % 101 + 51;
   int operators = rand() % 4;

   switch (operators){
   case 0:
      cout << a << " + " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a + b) == guess ? true, score += 50 : false;
    break;
    case 1:
      cout << a << " - " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a - b) == guess ? true, score += 50 : false;
    break;
    case 2:
      cout << a << " * " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a * b) == guess ? true, score += 100 : false;
    break;
    case 3:
      cout << a << " / " << b <<" is: ?\n";
      cout << "\nANSWER IS ?: ";
      cin >> guess;
      return (a / b) == guess ? true, score += 100 : false;
    break;
   }
   return 0;
};