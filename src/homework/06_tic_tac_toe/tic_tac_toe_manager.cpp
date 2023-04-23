// TicTacToeManager.cpp

#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager()
    : data{} {
    std::vector<std::unique_ptr<TicTacToe>> games = data.get_games();
    for (auto& game : games) {
        update_winner_count(game->get_winner());
        this->games.push_back(std::move(game));
    }
}

TicTacToeManager::TicTacToeManager(TicTacToeData& data)
    : data{data} {
    std::vector<std::unique_ptr<TicTacToe>> games = data.get_games();
    for (auto& game : games) {
        update_winner_count(game->get_winner());
        this->games.push_back(std::move(game));
    }
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
    data.save_games(games);
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

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t) {
    o = o_wins;
    x = x_wins;
    t = ties;
}

TicTacToeManager::~TicTacToeManager() {
    data.save_games(games);
}
