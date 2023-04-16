//h
#ifndef TICTACTOE4_H
#define TICTACTOE4_H

#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe {
public:
    TicTacToe4();
    TicTacToe4(std::vector<std::string> p, std::string winner);
    
private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;
    void set_winner() override;
};

#endif
