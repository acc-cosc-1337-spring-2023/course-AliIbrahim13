//cpp 
#include "tic_tac_toe.h"
#include <iostream>

bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    std::cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << "\n";
    std::cout << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << "\n";
    std::cout << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << "\n";
}

void TicTacToe::set_next_player() {
    if (player == "X") {
        player = "O";
    }
    else {
        player = "X";
    }
}

bool TicTacToe::check_board_full() {
    for (auto peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    for (auto& peg : pegs) {
        peg = " ";
    }
}
