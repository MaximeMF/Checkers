#include "game.h"

Game::Game() : player1(white), player2(black), checkerboard(){}

void Game::play()
{
    bool end = false;
    currentPlayer = &player1;

    while(!end) {



        //..........

        changeTurn();
    }
}

void Game::changeTurn()
{
    if(currentPlayer == &player1)
        currentPlayer = &player2;
    else
        currentPlayer = &player1;
}
