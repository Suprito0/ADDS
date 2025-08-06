#include "Referee.h"
int main(){
    Human player1;
    Computer player2;

    Referee ref;
    Player* winner = ref.refGame(&player1, &player2);
    if (winner){
        cout << winner->getName() << endl;
    } else{
        cout << "Tie" << endl;
    }
}
