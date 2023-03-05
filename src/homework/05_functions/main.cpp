/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
#include <iostream>
#include <string>
#include <algorithm>
#include "func.h"

int main() {
    int choice;
    std::string dna;

    while(true) {
        std::cout << "Menu\n";
        std::cout << "1- Get GC Content\n";
        std::cout << "2- Get DNA Complement\n";
        std::cout << "3- Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter DNA string: ";
                std::cin >> dna;
                std::cout << "GC content is: " << get_gc_content(dna) << std::endl;
                break;
            case 2:
                std::cout << "Enter DNA string: ";
                std::cin >> dna;
                std::cout << "DNA complement is: " << get_dna_complement(get_reverse_string(dna)) << std::endl;
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
        }
    }
}
