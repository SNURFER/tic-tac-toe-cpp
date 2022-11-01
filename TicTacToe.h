//
// Created by 이시도 on 2022/10/22.
//

#ifndef TIC_TAC_TOE_CPP_TICTACTOE_H
#define TIC_TAC_TOE_CPP_TICTACTOE_H

class Board;
class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();

    void startGame();

private:
    Board* m_board;
    char m_curTurn;
private:
    void resetGame();
    void putOX(int row, int col);
    void printManual() const;
    void printBoard() const;
    void eventDispatcher(char input);
    void endGame();
    void toggleTurn();
};

#endif //TIC_TAC_TOE_CPP_TICTACTOE_H
