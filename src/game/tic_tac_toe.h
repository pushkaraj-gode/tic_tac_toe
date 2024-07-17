#pragma once

#define ROW 3
#define COL 3

#include <iostream>
#include <vector>
#include <exception>
#include <game/user.h>

namespace tic_tac_toe
{
    class TicTacToe
    {
        User m_winner;
        bool m_running = true;
        int* m_mtx = nullptr;
    public:
        TicTacToe();
        TicTacToe(tic_tac_toe::TicTacToe&&);
        TicTacToe(tic_tac_toe::TicTacToe const&);

        const int* getMatrix() const noexcept;

        void set(int, tic_tac_toe::User const&);
        bool running() noexcept;
        User getWinner() const noexcept;
        bool empty() const noexcept;

        static void printBanner();
        static void init(tic_tac_toe::User&, tic_tac_toe::User&);
        static void run(
            tic_tac_toe::TicTacToe&,
            tic_tac_toe::User&, 
            tic_tac_toe::User&, 
            tic_tac_toe::User&);
        static void result(tic_tac_toe::TicTacToe&);

        virtual ~TicTacToe();
    private:
        void alloc();
    };
    std::ostream& operator<<(std::ostream&, tic_tac_toe::TicTacToe&);
} // namespace tic_tac_toe
