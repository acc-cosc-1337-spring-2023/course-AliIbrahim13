#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp" 

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Test TicTacToe game", "[TicTacToe]")
{
    SECTION("Test player X win")
    {
        TicTacToe game;
        REQUIRE(game.get_player() == "X");

        game.mark_board(1);
        REQUIRE(game.get_player() == "O");

        game.mark_board(2);
        REQUIRE(game.get_player() == "X");

        game.mark_board(5);
        REQUIRE(game.get_player() == "O");

        game.mark_board(3);
        REQUIRE(game.get_player() == "X");

        game.mark_board(9);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == "X");
    }

    SECTION("Test player O win")
    {
        TicTacToe game;
        REQUIRE(game.get_player() == "X");

        game.mark_board(1);
        REQUIRE(game.get_player() == "O");

        game.mark_board(2);
        REQUIRE(game.get_player() == "X");

        game.mark_board(5);
        REQUIRE(game.get_player() == "O");

        game.mark_board(3);
        REQUIRE(game.get_player() == "X");

        game.mark_board(7);
        REQUIRE(game.get_player() == "O");

        game.mark_board(4);
        REQUIRE(game.get_player() == "X");

        game.mark_board(8);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == "O");
    }

    SECTION("Test draw")
    {
        TicTacToe game;
        REQUIRE(game.get_player() == "X");

        game.mark_board(1);
        REQUIRE(game.get_player() == "O");

        game.mark_board(2);
        REQUIRE(game.get_player() == "X");

        game.mark_board(3);
        REQUIRE(game.get_player() == "O");

        game.mark_board(5);
        REQUIRE(game.get_player() == "X");

        game.mark_board(4);
        REQUIRE(game.get_player() == "O");

        game.mark_board(6);
        REQUIRE(game.get_player() == "X");

        game.mark_board(7);
        REQUIRE(game.get_player() == "O");

        game.mark_board(9);
        REQUIRE(game.get_player() == "X");

        game.mark_board(8);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == "C");
    }
}
