#include <iostream>
#include <vector>
using namespace std;

//BUGS: 
//IF COMP WINS ON FIRS MOVE SHOW THE CARDS
//make the face cards always the same if possible
//fix stuf

//ADD:
//SCORE(MONEY)
//DOUBLE

vector<int> ComputersCard(vector<int> &cards);
vector<int> PlayersCard(vector<int> &cards);
void drawBoard(vector<int> &PlayersCards, vector<int> &ComputersCards, vector<char> &faceCards);
void drawBoardOnFirsMove(vector<int> &PlayersCards, vector<int> &ComputersCards, vector<char> &faceCards);
void playerMove(vector<int> &PlayersCards, vector<int> &cards, vector<char> &faceCards);
void computerMove(vector<int> &ComputersCards, vector<int> &cards);//
int checkWinner(vector<int> &PlayersCards, vector<int> &ComputersCards);//
bool checkWinnerOnFirsMove(vector<int> &PlayersCards, vector<int> &ComputersCards);

int main(){
    vector<int> cards = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,
                         6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,
                         10,10,10,10,10,10,10,10,10,10,10,10,1,1,1,
                         1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,
                         7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,
                         10,10,10,10,10,10,10,10,10,10};

   vector<char> faceCards = {'J', 'J', 'J', 'J', 'J', 'J', 'J', 'J', 'K', 'K', 'K', 'K', 'K', 'K', 'K', 'K', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q'};

    cout << "\n*************************************\n";
    cout << "              BLACKJACK              \n";
    cout << "        (NO DOUBLE OR SPLIT)         \n";
    cout << "*************************************\n\n";

    vector<int> ComputersCards = ComputersCard(cards);
    vector<int> PlayersCards = PlayersCard(cards);
    drawBoardOnFirsMove(PlayersCards, ComputersCards, faceCards);
    bool pWin = checkWinnerOnFirsMove(PlayersCards, ComputersCards);
    if(pWin == 0){
        playerMove(PlayersCards, cards, faceCards);
        computerMove(ComputersCards, cards);
        drawBoard(PlayersCards, ComputersCards, faceCards);
        int isTrue = checkWinner(PlayersCards, ComputersCards);
        if(isTrue == 1){
          cout << "\n*************YOU WIN***************\n\n";
        }else if(isTrue == 0){
          cout << "\n*************YOU LOSE***************\n\n";
        }else if(isTrue == 2){
          cout << "\n****************DRAW***************\n\n";
        }
    }

    return 0;
}

vector<int> ComputersCard(vector<int> &cards){
    int cardA, cardB, a, b;
    srand(time(NULL));
    
    a = rand() % cards.size();
    cardA = cards[a];
    cards.erase(cards.begin() + a);

    b = rand() % cards.size();
    cardB = cards[b];
    cards.erase(cards.begin() + b);

    return {cardA, cardB};
}

vector<int> PlayersCard(vector<int> &cards){
    int cardA, cardB, a, b;
    srand(time(NULL));
    
    a = rand() % cards.size();
    cardA = cards[a];
    cards.erase(cards.begin() + a);

    b = rand() % cards.size();
    cardB = cards[b];
    cards.erase(cards.begin() + b);

    return {cardA, cardB};
}

void drawBoard(vector<int> &PlayersCards, vector<int> &ComputersCards, vector<char> &faceCards){
    cout << "\nCOMPUTERS CARDS: ";

    for(auto i : ComputersCards){
        if(i == 1){
            cout << "A" << " ";
        }else if (i == 10){
            srand(time(NULL));
            int a = rand() % faceCards.size();
            cout << faceCards[a] << " ";
            faceCards.erase(faceCards.begin() + a);
        }else{
           cout << i << " ";
        }
    }
    cout << "\n";

    cout << "PLAYERS CARDS: ";
    for(auto i : PlayersCards){ 
        if(i == 1){
            cout << "A" << " ";
        }else if (i == 10){
            srand(time(NULL));
            int a = rand() % faceCards.size();
            cout << faceCards[a] << " ";
            faceCards.erase(faceCards.begin() + a);
        }else{
           cout << i << " ";
        }
    }

    cout << "\n";
}

void drawBoardOnFirsMove(vector<int> &PlayersCards, vector<int> &ComputersCards, vector<char> &faceCards){
    cout << "\nCOMPUTERS CARDS: ";

    for(int i = 0;i < 2;i++){
        if(i == 1){
          cout << "#" << " ";
        }else if(ComputersCards[i] == 1){
            cout << "A" << " ";
        }else if (ComputersCards[i] == 10){
            srand(time(NULL));
            int a = rand() % faceCards.size();
            cout << faceCards[a] << " ";
            faceCards.erase(faceCards.begin() + a);
        }else{
           cout << ComputersCards[i] << " ";
        }
    }
    cout << "\n";

    cout << "PLAYERS CARDS: ";
    for(auto i : PlayersCards){ 
        if(i == 1){
            cout << "A" << " ";
        }else if (i == 10){
            srand(time(NULL));
            int a = rand() % faceCards.size();
            cout << faceCards[a] << " ";
            faceCards.erase(faceCards.begin() + a);
        }else{
           cout << i << " ";
        }
    }

    cout << "\n";
}

void playerMove(vector<int> &PlayersCards, vector<int> &cards, vector<char> &faceCards){
    char move = 's';  

    int sum = 0;
    for(auto i : PlayersCards){
       sum += i;
    }
    if(sum >= 21) return;

    do{
        cout << "\nHIT(H/h) or STAND(S/s): ";
        cin >> move;
        tolower(move);
    } while (!( move == 'h' || move == 's'));

    if(move == 's') return;
    cout << "\n";

    if(sum < 21){
            int cardA, a;
            char guess;
            srand(static_cast<unsigned int>(time(NULL)));

            a = rand() % cards.size();
            cardA = cards[a];
            cards.erase(cards.begin() + a);
            PlayersCards.push_back(cardA);

            cout << "PLAYERS CARDS: ";
            for(auto i : PlayersCards){ 
                if(i == 1){
                  cout << "A" << " ";
                }else if (i == 10){
                  srand(time(NULL));
                  int a = rand() % faceCards.size();
                  cout << faceCards[a] << " ";
                  faceCards.erase(faceCards.begin() + a);
                }else{
                  cout << i << " ";
                }
           }
           cout << "\n";

            if(sum < 21){
                playerMove(PlayersCards, cards, faceCards);
            }else if(sum >= 21){
              cout << "\nYOU CANT HIT\n";
              return;
            }

    }else if(sum >= 21){
      cout << "\nYOU CANT HIT\n";
    }
    
}

void computerMove(vector<int> &ComputersCards, vector<int> &cards){
     int sum = 0;
     int cSum = 0, cASum = 0;
       while (sum < 17){
             sum = 0;
             for(auto i : ComputersCards){
                   cSum += i;
             } 
             for(auto i : ComputersCards){
                   if(i == 1){
                    cASum += 11;
                   }else cASum += i;
             }

    if(cASum > cSum && cASum <= 21){
      sum = cASum;
    }
    else if(cSum > cASum && cSum <= 21){
      sum = cSum;
    }else{
      sum = cSum;
    }

        if (sum < 17){
            int cardA, a;
            srand(static_cast<unsigned int>(time(NULL)));

            a = rand() % cards.size();
            cardA = cards[a];
            cards.erase(cards.begin() + a);
            ComputersCards.push_back(cardA);
        }
    }
} 

int checkWinner(vector<int> &PlayersCards, vector<int> &ComputersCards){
    int pSum = 0, cSum = 0, pASum = 0, cASum = 0;
    for(auto i : PlayersCards){
       pSum += i;
    }
    for(auto i : ComputersCards){
       cSum += i;
    }
    for(auto i : PlayersCards){
       if(i == 1)pASum += 11;
         else pASum += i;
    }
    for(auto i : ComputersCards){
       if(i == 1)cASum += 11;
         else cASum += i;
    }

    if(pASum > pSum && pASum <= 21) pSum = pASum;
    if(cASum > cSum && cASum <= 21) cSum = cASum;


   // cout << "\nP: " << pSum << " C: " << cSum;

    if(pSum > cSum && pSum <= 21){
      return 1;
    }else if(pSum < cSum && cSum <= 21){
      return 0;
    }else if(pSum > 21){
      return 0;
    }else if(cSum > 21){
      return 1;
    }else if(pSum == cSum){
      return 2;
    }
    return 0;
}

bool checkWinnerOnFirsMove(vector<int> &PlayersCards, vector<int> &ComputersCards){
    int sumP = 0, sumC = 0, pASum = 0, cASum = 0;
     for(auto i : PlayersCards){ //sum of players cards
        sumP += i;
     }
     for(auto i : ComputersCards){//sum of computesrs cards
        sumC += i;
     }

     for(auto i : PlayersCards){
       if(i == 1)pASum += 11;
         else pASum += i;
    }
    for(auto i : ComputersCards){
       if(i == 1)cASum += 11;
         else cASum += i;
    }

    if(pASum > sumP && pASum <= 21) sumP = pASum;
    if(cASum > sumC && cASum <= 21) sumC = cASum;

    //cout << "\nP: " << sumP << " C: " << sumC;

     if(sumP == 21 && sumC != 21){
        cout << "\n*************YOU WIN***************\n\n";
        return 1;
     }else if(sumP == 21 && sumC == 21){
        cout << "\n***************DRAW***************\n\n";
        return 1;
     }else if(sumC == 21 && sumP != 21){
        cout << "\n*************YOU LOSE***************\n\n";
        return 1;
     }
     return 0;
}