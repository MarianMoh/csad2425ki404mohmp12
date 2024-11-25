/**
 * @file game.cpp
 * @brief Contains functions for managing and playing the game, including saving/loading game state, validating moves, and interacting with the SerialPort.
 */

#include "game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

 /**
  * @brief Saves the current game state to a file.
  * @param filename The name of the file to save the game state.
  * @param mode The game mode (e.g., "Player vs Player", "Player vs AI").
  * @param player1Move The move of Player 1.
  * @param player2Move The move of Player 2.
  * @param player1Score The score of Player 1.
  * @param player2Score The score of Player 2.
  *
  * This function writes the game mode, players' moves, and their scores to a specified file, allowing the game to be resumed later.
  */
void saveGameState(const std::string& filename, const std::string& mode, const std::string& player1Move, const std::string& player2Move, int player1Score, int player2Score) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << mode << '\n'
            << player1Move << '\n'
            << player2Move << '\n'
            << player1Score << '\n'
            << player2Score << '\n';
    }
    else {
        std::cerr << "Error: Unable to save game state to file.\n";
    }
}

/**
 * @brief Loads a previously saved game state from a file.
 * @param filename The name of the file to load the game state from.
 * @param mode Reference to a string to store the loaded game mode.
 * @param player1Move Reference to a string to store the loaded move of Player 1.
 * @param player2Move Reference to a string to store the loaded move of Player 2.
 * @param player1Score Reference to an integer to store the loaded score of Player 1.
 * @param player2Score Reference to an integer to store the loaded score of Player 2.
 * @return True if the game state was loaded successfully; false otherwise.
 *
 * This function reads the game mode, players' moves, and scores from the specified file, restoring the game to a previous state.
 */
bool loadGameState(const std::string& filename, std::string& mode, std::string& player1Move, std::string& player2Move, int& player1Score, int& player2Score) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, mode);
        std::getline(inFile, player1Move);
        std::getline(inFile, player2Move);
        inFile >> player1Score >> player2Score;
        inFile.ignore();
        return true;
    }
    else {
        std::cerr << "Error: No previous game state found.\n";
        return false;
    }
}

/**
 * @brief Manages the main game loop and handles player interactions and game modes.
 * @param serialPort A reference to the SerialPort object for sending and receiving messages to/from Arduino.
 *
 * The function provides options for starting a new game or continuing a previous one, allows players to choose a game mode, and handles player moves and game results.
 * It supports multiple game modes, including Man vs Man, Man vs AI, and AI vs AI, and saves game progress after each round.
 */
void playGame(SerialPort& serialPort) {
    std::string mode, player1Move, player2Move, result;
    int player1Score = 0, player2Score = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while (true) {
        std::cout << "\n------- GAME MENU --------\n";
        std::cout << "1. Continue previous game\n";
        std::cout << "2. Start a new game\n";
        std::cout << "q. Quit program\n";
        std::cout << "--------------------------\n";
        std::cout << "Select an option: ";

        char choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 'q') {
            std::cout << "Goodbye!\n";
            exit(0);
        }

        if (choice == '1' && loadGameState("game.ini", mode, player1Move, player2Move, player1Score, player2Score)) {
            std::cout << "Previous game loaded. Resuming...\n";
            break;
        }
        else if (choice == '2') {
            std::cout << "Starting a new game...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    if (mode.empty()) {
        while (true) {
            std::cout << "\n------- SELECT MODE ---------\n";
            std::cout << "1. Player vs Player\n";
            std::cout << "2. Player vs AI (Random)\n";
            std::cout << "3. Player vs AI (Win Strategy)\n";
            std::cout << "4. AI (Random) vs AI (Win Strategy)\n";
            std::cout << "e. Return to menu\n";
            std::cout << "--------------------------------\n";
            std::cout << "Select a mode: ";

            char modeChoice;
            std::cin >> modeChoice;
            std::cin.ignore();

            if (modeChoice == 'e') return;

            switch (modeChoice) {
            case '1': mode = "Player vs Player"; break;
            case '2': mode = "Player vs AI (Random)"; break;
            case '3': mode = "Player vs AI (Win Strategy)"; break;
            case '4': mode = "AI (Random) vs AI (Win Strategy)"; break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                continue;
            }
            break;
        }
    }

    while (true) {
        std::cout << "\n------- GAME ROUND -------\n";
        if (mode == "Player vs Player") {
            std::cout << "Player 1, enter your move (rock, paper, scissors): ";
            std::getline(std::cin, player1Move);
            if (player1Move == "e") break;

            std::cout << "Player 2, enter your move: ";
            std::getline(std::cin, player2Move);
        }
        else if (mode.find("Player vs AI") != std::string::npos) {
            std::cout << "Player, enter your move (rock, paper, scissors): ";
            std::getline(std::cin, player1Move);
            if (player1Move == "e") break;
        }
        else if (mode == "AI (Random) vs AI (Win Strategy)") {
            std::cout << "AI battle! Press enter to simulate round.\n";
            std::cin.ignore();
        }

        serialPort.sendMessage(mode + '\n' + player1Move + '\n' + player2Move);
        std::string response = serialPort.receiveMessage();

        size_t pos1 = response.find('\n');
        size_t pos2 = response.find('\n', pos1 + 1);
        size_t pos3 = response.find('\n', pos2 + 1);

        player1Move = response.substr(0, pos1);
        player2Move = response.substr(pos1 + 1, pos2 - pos1 - 1);
        result = response.substr(pos3 + 1);

        if (result.find("Player1 Wins") != std::string::npos) player1Score++;
        if (result.find("Player2 Wins") != std::string::npos) player2Score++;

        std::cout << "\nResult: " << result << "\n";
        std::cout << "Score: Player 1 - " << player1Score << " | Player 2 - " << player2Score << "\n";

        saveGameState("game.ini", mode, player1Move, player2Move, player1Score, player2Score);
    }
}
