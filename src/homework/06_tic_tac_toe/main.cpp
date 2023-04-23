#include <iostream>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_manager.h"


int main() {
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    char playAgain = 'y';
    while (playAgain == 'y') {
        TicTacToeData data;
        TicTacToeManager manager;

        std::unique_ptr<TicTacToe> game;

        // Play the game
        std::cout << "Do you want to play TicTacToe3 (enter 3) or TicTacToe4 (enter 4)? ";
        
        char tsize = '3';
        std::cin >> tsize;

        if (tsize == '3') {
            game = std::make_unique<TicTacToe3>();
        }
        else {
            game = std::make_unique<TicTacToe4>();
        }

        game->start_game("X");

        while (!game->game_over()) {
            int position;
            std::cout << "Player " << game->get_player() << ", enter a position (1-" << game->get_pegs().size() << "): ";
            std::cin >> position;

            try {
                game->mark_board(position);
                std::cout << *game << std::endl;
            }
            catch (const std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }

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

        // Save the game
        manager.save_game(game);

        // Print the game history
        std::cout << "\nGame history:\n";
        std::cout << manager << std::endl;

        // Ask if the user wants to play again
        std::cout << "Do you want to play again? (y/n) ";
        std::cin >> playAgain;
    }

    return 0;
}
