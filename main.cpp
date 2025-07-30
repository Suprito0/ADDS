#include "Referee.h"
int main(){
    Player* player1 = new Human;
    Player* player2 = new Computer;

    Referee ref;
    Player* winner = ref.refGame(player1, player2);
    if (winner){
        cout << winner->getName() << endl;
    } else{
        cout << "Tie" << endl;
    }
    delete player1;
    delete player2;
    delete winner;
}
