//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include <memory>
#include <vector>
#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    TicTacToeManager() = default;
    TicTacToeManager(const TicTacToeManager&) = delete;
    TicTacToeManager(TicTacToeManager&&) = delete;
    TicTacToeManager& operator=(const TicTacToeManager&) = delete;
    TicTacToeManager& operator=(TicTacToeManager&&) = delete;

    void start_game(std::unique_ptr<TicTacToe>& game);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
    void get_winner_totals(int& o, int& x, int& t) const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int o_wins{0};
    int x_wins{0};
    int ties{0};

    void update_winner_account(std::string winner);
};

#endif // TIC_TAC_TOE_MANAGER_H
