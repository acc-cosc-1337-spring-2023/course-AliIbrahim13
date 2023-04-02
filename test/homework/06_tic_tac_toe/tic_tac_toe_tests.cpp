#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test win detection - row", "[tic_tac_toe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(4); // O
    game.mark_board(2); // X
    game.mark_board(5); // O
    game.mark_board(3); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win detection - column", "[tic_tac_toe]") {
    TicTacToe game;
    game.start_game("O");

    game.mark_board(1); // O
    game.mark_board(2); // X
    game.mark_board(4); // O
    game.mark_board(5); // X
    game.mark_board(7); // O

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test win detection - diagonal", "[tic_tac_toe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(5); // X
    game.mark_board(3); // O
    game.mark_board(9); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test game tied", "[tic_tac_toe]") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(3); // X
    game.mark_board(5); // O
    game.mark_board(4); // X
    game.mark_board(7); // O
    game.mark_board(6); // X
    game.mark_board(8); // O
    game.mark_board(9); // X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}
