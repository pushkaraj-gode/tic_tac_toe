#pragma once

#define ROW 3
#define COL 3

#include <iostream>
#include <vector>
#include <exception>
#include <game/user.h>

namespace tic_tac_toe
{
    /**
     * @brief This class handles the Tic Tac Toe game mechanics
     *        It manages all logical & non-logical parts for the
     *        game consisting two users into the game
     * 
     * @author Pushkaraj Gode
     */
    class TicTacToe
    {
        /**
         * @brief This stores winner user once the game ends
         * 
         */
        User m_winner;
        /**
         * @brief It's a 2D game matrix used to represent (X/O) 
         * 
         */
        int* m_mtx = nullptr;
        /**
         * @brief It indicates that game is still running or ended
         * 
         */
        bool m_running = true;
    public:
        /**
         * @brief Construct a new Tic Tac Toe object
         * 
         */
        TicTacToe();
        /**
         * @brief Construct a new Tic Tac Toe object (Move Constructor)
         * 
         */
        TicTacToe(tic_tac_toe::TicTacToe&&);
        /**
         * @brief Construct a new Tic Tac Toe object
         * 
         */
        TicTacToe(tic_tac_toe::TicTacToe const&);

        /**
         * @brief Get the Matrix object
         * 
         * @return const int* 
         */
        const int* getMatrix() const noexcept;

        /**
         * @brief 
         * 
         * @param [IN]  int pos
         *        It stores position over matrix to draw the signature
         * 
         * @param [IN] tic_tac_toe::User const& usr
         *        It represents current playing user information
         * 
         * @exception std::out_of_range
         *            This is thrown in case in-valid position is given
         */
        void set(int, tic_tac_toe::User const&);
        /**
         * @brief It indicates if game is still running or not
         * 
         * @return true In case game is still running
         * @return false In case game is not running
         */
        bool running() noexcept;
        /**
         * @brief Get the Winner object
         * 
         * @return User 
         */
        User getWinner() const noexcept;
        /**
         * @brief It helps understand if the game matrix is empty or not
         *        With the help of it we can dermine when to stop and don't
         *        stop the game.
         * 
         * @return true When matrix is empty
         * @return false When matrix is not empty
         */
        bool empty() const noexcept;

        /**
         * @brief It prints banner of Tic Tac Toe game
         * 
         */
        static void printBanner();
        /**
         * @brief It initializes both user accept user information
         *        From console input
         * 
         * @param [IN-OUT] tic_tac_toe::User& usr1
         *        It accepts usr1 and get details from console
         *        Store into it.
         * 
         * @param [IN-OUT] tic_tac_toe::User& usr2
         *        It accepts usr1 and get details from console
         *        Store into it.
         */
        static void init(tic_tac_toe::User&, tic_tac_toe::User&);
        /**
         * @brief This acts as game loop which give chances to users
         *        Switch users. It automatically shuts down when game
         *        is won by anyone or when it's a draw match
         * 
         * @param [IN-OUT] tic_tac_toe::TicTacToe& game
         *        It stores game information 
         * 
         * @param [IN-OUT] tic_tac_toe::User& usr1
         *        It store usr1 information
         * 
         * @param [IN-OUT] tic_tac_toe::User& usr2
         *        It store usr2 information
         *  
         * @param [IN-OUT] tic_tac_toe::User& curUsr
         *        This store current playing user information
         * 
         */
        static void run(
            tic_tac_toe::TicTacToe&,
            tic_tac_toe::User&, 
            tic_tac_toe::User&, 
            tic_tac_toe::User&);
        /**
         * @brief It displays game result
         * 
         * @param [IN-OUT] tic_tac_toe::TicTacToe& game
         *        Game information and current status
         * 
         */
        static void result(tic_tac_toe::TicTacToe&);

        /**
         * @brief Destroy the Tic Tac Toe object
         * 
         */
        virtual ~TicTacToe();
    private:
        /**
         * @brief It allocates memory for matrix
         * 
         */
        void alloc();
    };
    /**
     * @brief It appends game metrix onto the console
     * 
     * @return std::ostream& console output
     */
    std::ostream& operator<<(std::ostream&, tic_tac_toe::TicTacToe&);
} // namespace tic_tac_toe
