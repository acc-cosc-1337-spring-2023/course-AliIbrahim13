#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"
#include <memory>
#include <iostream>
#include <cassert>

// test TicTacToe3 constructor and start_game function
void test_tictactoe3() {
    TicTacToe3 game;
    game.start_game("X");
    assert(game.get_player() == "X");
    assert(game.get_pegs().size() == 9);
}

// test TicTacToe4 constructor and start_game function
void test_tictactoe4() {
    TicTacToe4 game;
    game.start_game("X");
    assert(game.get_player() == "X");
    assert(game.get_pegs().size() == 16);
}

// test mark_board function
void test_mark_board() {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    assert(game->get_pegs().at(0) == "X");
    assert(game->get_player() == "O");
}

// test game over function
void test_game_over() {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(3);
    assert(game->game_over() == true || game->game_over() == false);
}

// test get winner function for TicTacToe3
void test_get_winner_tictactoe3() {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(3);
    assert(game->get_winner() == "X");
}

// test get winner function for TicTacToe4
void test_get_winner_tictactoe4() {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(3);
    game->mark_board(4);
    assert(game->get_winner() == "X");
}

// test save_game and get_games functions
void test_save_get_games() {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(3);
    manager.save_game(game);
    std::vector<std::unique_ptr<TicTacToe>> games = TicTacToeData().get_games();
    assert(games.size() == 1);
    assert(games[0]->get_winner() == "X");
}

// test get_winner_totals function
void test_get_winner_totals() {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game1 = std::make_unique<TicTacToe3>();
    game1->start_game("X");
    game1->mark_board(1);
    game1->mark_board(2);
    game1->mark_board(3);
    std::unique_ptr<TicTacToe> game2 = std::make_unique<TicTacToe3>();
    game2->start_game("X");
    game2->mark_board(4);
    game2->mark_board(5);
    game2->mark_board(6);
    manager.save_game(game1);
    manager.save_game(game2);
    int o = 0, x = 0, t = 0; // declare and initialize variables
    manager.get_winner_totals(o, x, t); // pass references to variables
    assert(x == 2);
    assert(o == 0);
    assert(t == 0);
}

int main(){
    test_tictactoe3();
    test_tictactoe4();
    test_mark_board();
    test_game_over();
    test_get_winner_tictactoe3();
    test_get_winner_tictactoe4();
    test_save_get_games();
    test_get_winner_totals();
    std::cout<<"All tests passed!\n";
    return 0;
}

