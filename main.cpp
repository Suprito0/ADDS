#include "Referee.h"
int main(){
    Player* player1 = new Human;
    Player* player2 = new Computer;

    Referee ref;
    Player* winner = ref.refGame(player1, player2);
    if (winner){
        cout << winner->getName() << " wins" << endl;
    } else{
        cout << "it's a tie" << endl;
    }
}
