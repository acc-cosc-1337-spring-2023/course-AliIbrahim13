// TicTacToeManager.cpp

#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(const TicTacToeManager& manager)
    : games{ } {
    for (auto& game : manager.games) {
        games.push_back(std::make_unique<TicTacToe>(*game));
    }
    x_wins = manager.x_wins;
    o_wins = manager.o_wins;
    ties = manager.ties;
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::update_winner_count(std::string winner) {
    if (winner == "X") {
        x_wins++;
    }
    else if (winner == "O") {
        o_wins++;
    }
    else {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& os, const TicTacToeManager& manager) {
    for (auto& game : manager.games) {
        os << *game << "\n";
    }
    os << "X wins: " << manager.x_wins << "\n";
    os << "O wins: " << manager.o_wins << "\n";
    os << "Ties: " << manager.ties << "\n";
    return os;
}

void TicTacToeManager::get_winner_totals(int& o, int& w, int& t) {
    o = o_wins;
    w = x_wins;
    t = ties;
}

TicTacToeManager::~TicTacToeManager() {
}
