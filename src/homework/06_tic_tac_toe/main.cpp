#include <iostream>
#include <string>
#include "tic_tac_toe.h"

int main() {
    std::string player;
    char choice;

    do {
        TicTacToe game;
        std::cout << "Enter X or O to start the game: ";
        std::cin >> player;
        game.start_game(player);

        int position;
        do {
            std::cout << "Player " << game.get_player() << " enter position between 1 and 9: ";
            std::cin >> position;
            game.mark_board(position);
            game.display_board();
        } while (!game.game_over());

        std::cout << "The winner is " << game.get_winner() << std::endl;

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
