//
// Created by 이시도 on 2022/10/22.
//
#ifndef TIC_TAC_TOE_CPP_BOARD_H
#define TIC_TAC_TOE_CPP_BOARD_H

#include <vector>

const int kSize = 3;
enum status {
    ERROR,
    SUCCESS,
    FINISHED
};

class Board {
private:
    std::vector<std::vector<char>> m_board;
    int m_step;
public:
    Board();
    char judgeWinner();
    status putOX(int row, int col, char ox);
    void cleanBoard();
    void printBoard();
};

#endif //TIC_TAC_TOE_CPP_BOARD_H
