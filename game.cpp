#include "game.h"

Game::Game() : player1(white), player2(black), checkerboard(){}

void Game::play() {
    bool end = false;
    Player* currentPlayer = &player1;
    while(!end) {
        if(currentPlayer == &player1)
            currentPlayer = &player2;
        else
            currentPlayer = &player1;
    }
}
