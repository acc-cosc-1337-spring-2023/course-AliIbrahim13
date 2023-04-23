// TicTacToeManager.h

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include <vector>
#include <memory>
 
class TicTacToeManager {
public:
    TicTacToeManager();
    TicTacToeManager(TicTacToeData& data);
    void save_game(std::unique_ptr<TicTacToe>& game);
    friend std::ostream& operator<<(std::ostream& os, const TicTacToeManager& manager);
    void get_winner_totals(int& o, int& w, int& t);
    ~TicTacToeManager();

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_wins{ 0 };
    int o_wins{ 0 };
    int ties{ 0 };
    void update_winner_count(std::string winner);
    TicTacToeData data;
};

#endif
