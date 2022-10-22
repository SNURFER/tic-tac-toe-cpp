//
// Created by 이시도 on 2022/10/22.
//

#include "Board.h"
#include <iostream>

Board::Board(): m_board(kSize, std::vector<char>(kSize, '-')), m_step(0) {
}

char Board::judgeWinner() {

    if ((m_board[0][0] == m_board[0][1]) && (m_board[0][1] == m_board[0][2]) && (m_board[0][0] == 'X' || m_board[0][0] == 'O'))
        return m_board[0][0];
    if ((m_board[1][0] == m_board[1][1]) && (m_board[1][1] == m_board[1][2]) && (m_board[1][0] == 'X' || m_board[1][0] == 'O'))
        return m_board[1][0];
    if (m_board[2][0] == m_board[2][1] && m_board[2][1] == m_board[2][2] && (m_board[2][0] == 'X' || m_board[2][0] == 'O'))
        return m_board[2][0];
    if (m_board[0][0] == m_board[1][0] && m_board[1][0] == m_board[2][0] && (m_board[0][0] == 'X' || m_board[0][0] == 'O'))
        return m_board[0][0];
    if (m_board[0][1] == m_board[1][1] && m_board[1][1] == m_board[2][1] && (m_board[0][1] == 'X' || m_board[0][1] == 'O'))
        return m_board[0][1];
    if (m_board[0][2] == m_board[1][2] && m_board[1][2] == m_board[2][2] && (m_board[0][2] == 'X' || m_board[0][2] == 'O'))
        return m_board[0][0];
    if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && (m_board[0][0] == 'X' || m_board[0][0] == 'O'))
        return m_board[0][0];
    if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && (m_board[1][1] == 'X' || m_board[1][1] == 'O'))
        return m_board[1][1];

    return '\0';
}

status Board::putOX(int row, int col, char ox) {
    // range check, if row and col is out of boundary print error with no action
    if (row < 0 || row >= kSize || col < 0 || col >= kSize) {
        std::cout << "row, col bound error" << std::endl;
        return status::ERROR;
    } else if (this->m_board[row][col] != '-') {
        std::cout << "the cell is already filled" << std::endl;
        return status ::ERROR;
    }

    m_step++;
    (this->m_board)[row][col] = ox;

    char winner = judgeWinner();
    if (winner == 'X' || winner == 'O') {
        std::cout << "the winner is :"  << ox << std::endl;
        return status::FINISHED;
    } else if (m_step == 9) {
        std::cout << "game has finished, no winner found" << std::endl;
        return status::FINISHED;
    }

    printBoard();
    char nextTurn = (ox == 'X') ? 'O' : 'X';
    std::cout << "next turn : " << nextTurn << std::endl;
    return status::SUCCESS;
}

void Board::cleanBoard() {
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            m_board[i][j] = '-';
        }
    }
    m_step = 0;
    printBoard();
}

void Board::printBoard() {
    std::cout << "=========print board========" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            std::cout << m_board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
}

