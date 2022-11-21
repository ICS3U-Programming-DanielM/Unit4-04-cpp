// Copyright (c) 2022 Daniel Momoh All rights reserved.
// Created by: Daniel Momoh
// Created on: Nov. 18, 2022
// This program asks the user to guess a
// number and if they get it wrong it loops back till they get it correctly
#include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Generates random number
    int random_number;
    int counter = -1;
    int user_number;
    std::random_device rseed;
    std::mt19937 rgen(rseed());                      // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,100]
    random_number = idist(rgen);
    std::string user_input;
    while (true) {
        // get the user number as a string
        std::cout << "Enter a whole number between 0 and 9: ";
        std::cin >> user_input;
        try {
            // convert from string to int
            user_number = std::stoi(user_input);

            if (user_number >= 0 && user_number <= 9) {
                // increment the counter
                counter = counter + 1;
                if (user_number == random_number) {
                    std::cout << "YOU GUESS IT CORRECTLY." << std::endl;
                    std::cout << "THANKS FOR PLAYING." << std::endl;
                    break;
                } else {
                    std::cout << "THIS IS THE WRONG GUESS." << std::endl;
                }
            } else {
                std::cout << "THIS IS NOT BETWEEN 0 AND 9." << std::endl;
            }
            // Tells the user that inputted wasn't an integer
        } catch (std::invalid_argument) {
            std::cout << "THIS IS A STRING, TRY AGAIN" << std::endl;
        }
    }
}
