//
// Created by 이시도 on 2022/10/22.
//

#include "TicTacToe.h"
#include "Board.h"
#include <iostream>

TicTacToe::TicTacToe(): m_board(new Board()), m_curTurn('X'){

}

TicTacToe::~TicTacToe() {
    delete m_board;
}

void TicTacToe::startGame() {
    // print how to play
    std::cout << "==============================================" << std::endl;
    std::cout << "============start tic tac toe!================" << std::endl;
    std::cout << "==============================================" << std::endl;
    printManual();

    std::cout << "set initial turn: 'x' or 'o'" << std::endl;
    std::cin >> m_curTurn;

    // convert lower to upper
    m_curTurn = (m_curTurn + ('A' - 'a'));

    std::cout << "initial turn: " << m_curTurn << std::endl;

    char input = '\0';
    while (input != 'e') {
        std::cin >> input;
        eventDispatcher(input);
    }
}

void TicTacToe::resetGame() {
    std::cout << "============you pressed game reset!================" << std::endl;
    char turn = '\0';

    while (turn != 'x' && turn != 'o') {
        std::cout << "set first player: 'x' or 'o'" << std::endl;
        std::cin >> turn;
    }

    // convert lower to upper
    this->m_curTurn = (turn + ('A' - 'a'));

    this->m_board->cleanBoard();
}

void TicTacToe::putOX(int row, int col) {
    status progress = this->m_board->putOX(row, col, m_curTurn);

    if (progress == status::SUCCESS) toggleTurn();
    if (progress == status::FINISHED) resetGame();
}

void TicTacToe::printManual() const {
    std::cout << "==============================================" << std::endl;
    std::cout << "'m' : print manual" << std::endl;
    std::cout << "'e' : end game" << std::endl;
    std::cout << "'r' : reset game" << std::endl;
    std::cout << "'p' : print board" << std::endl;
    std::cout << "'t' : type mode. after typing t, type two-digit-number to put 'O' or 'X' in row, num" << std::endl;
    std::cout << "==============================================" << std::endl;
}

void TicTacToe::eventDispatcher(char input) {
    switch(input) {
        case 'm':
            printManual();
            break;
        case 'e':
            endGame();
            break;
        case 'r':
            resetGame();
            break;
        case 'p':
            printBoard();
            break;
        case 't':
            int row, col;
            std::cout << "press row" << std::endl;
            std::cin >> row;
            std::cout << "press col" << std::endl;
            std::cin >> col;

            putOX(row, col);
            break;
        default:
            std::cout << "input error" << std::endl;
            break;
    }
}

void TicTacToe::endGame() {
    std::cout << "End game. See you later~" << std::endl;
    exit(1);
}

void TicTacToe::printBoard() const {
    m_board->printBoard();
}

void TicTacToe::toggleTurn() {
    m_curTurn = (m_curTurn == 'X') ? 'O' : 'X';
}



