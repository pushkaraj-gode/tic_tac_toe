#include <iostream>
#include <game/user.h>
#include <game/tic_tac_toe.h>

int main(int argc, char* argv[], char* envp[])
{
    using namespace tic_tac_toe;
    try
    {
        char ch = '\0';
        do
        {
            User usr1;
            User usr2;
            TicTacToe game;
            
            TicTacToe::printBanner();
            TicTacToe::init(usr1, usr2);

            User curUsr = usr1;
            TicTacToe::run(game, usr1, usr2, curUsr);
            TicTacToe::result(game);
            std::cout << "\nDo you wish to continue (y/n): ";
            std::cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
    catch(std::exception const& e)
    {
        std::cerr << "\nError: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "\nSomething went wrong!" << std::endl;
    }
    return 0;
}