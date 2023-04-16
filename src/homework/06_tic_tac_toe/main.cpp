#include <iostream>
#include "tic_tac_toe_manager.h"


int main() {
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    char playAgain = 'y';
    while (playAgain == 'y') {
        TicTacToeManager manager;

        // Play the game
        std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>();
        manager.start_game(game);

        // Print the game board
        std::cout << *game << '\n';


        // Get the game statistics
        int x, o, t;
        manager.get_winner_totals(x, o, t);

        // Print the winner or tie message
        if (x > o) {
            std::cout << "Congratulations, X has won!" << std::endl;
        } else if (o > x) {
            std::cout << "Congratulations, O has won!" << std::endl;
        } else {
            std::cout << "The game ended in a tie." << std::endl;
        }

        // Print the game history
        std::cout << "\nGame history:\n";
        std::cout << manager << std::endl;

        // Ask if the user wants to play again
        std::cout << "Do you want to play again? (y/n) ";
        std::cin >> playAgain;
    }

    return 0;
}
