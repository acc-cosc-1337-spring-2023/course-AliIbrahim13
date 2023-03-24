#include <iostream>
#include "tic_tac_toe.h"

int main()
{
    std::string first_player;
    std::cout << "Enter first player (X or O): ";
    std::cin >> first_player;

    TicTacToe game;
    game.start_game(first_player);

    bool continue_game = true;
    while (continue_game)
    {
        int position;
        std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
        std::cin >> position;
        game.mark_board(position);

        game.display_board();
        if (game.game_over())
        {
            std::cout << "Game over!\n";
            continue_game = false;
        }
    }

    std::cout << "Would you like to play again? (Y/N): ";
    char play_again;
    std::cin >> play_again;
    if (play_again == 'Y' || play_again == 'y')
    {
        game.clear_board();
        main();
    }

    return 0;
}
