//h
#ifndef TICTACTOEDATA_H
#define TICTACTOEDATA_H

#include <fstream>
#include <memory>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

class TicTacToeData {
public:
    void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
    std::vector<std::unique_ptr<TicTacToe>> get_games();
private:
    const std::string file_name{ "tictactoe.txt" };
};

#endif // TICTACTOEDATA_H
