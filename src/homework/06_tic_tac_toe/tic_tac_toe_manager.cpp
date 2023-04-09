//cpp
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>
#include <vector> 

void TicTacToeManager::start_game(std::unique_ptr<TicTacToe>& game)
{
    update_winner_account(game->get_winner());
    games.emplace_back(std::move(game));
}

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t) const
{
    o = o_wins;
    x = x_wins;
    t = ties;
}

void TicTacToeManager::update_winner_account(std::string winner)
{
    if (winner == "X")
        x_wins++;
    else if (winner == "O")
        o_wins++;
    else
        ties++;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for (const auto& game : manager.games)
    {
        out << game << "\n";
    }

    out << "X wins: " << manager.x_wins << "\n";
    out << "O wins: " << manager.o_wins << "\n";
    out << "Ties: " << manager.ties << "\n";

    return out;
}
