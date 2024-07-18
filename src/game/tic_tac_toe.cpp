#include <cstring>
#include <game/tic_tac_toe.h>

namespace tic_tac_toe
{
    TicTacToe::TicTacToe()
    {
        alloc();
    }
    TicTacToe::TicTacToe(tic_tac_toe::TicTacToe&& other)
    {
        m_mtx = other.m_mtx;
        other.m_mtx = nullptr;
    }
    TicTacToe::TicTacToe(tic_tac_toe::TicTacToe const& other)
    {
        alloc();
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                *(m_mtx + i * COL + j) = *(other.m_mtx + i * COL + j);
            }
        }
    }
    const int* TicTacToe::getMatrix() const noexcept
    {
        return m_mtx;
    }
    void TicTacToe::set(int pos, tic_tac_toe::User const& usr)
    {
        switch(pos)
        {
            case 1:
                *(m_mtx + 0 * COL + 0) = static_cast<int>(usr.getSign());
            break;
            case 2:
                *(m_mtx + 0 * COL + 1) = static_cast<int>(usr.getSign());
            break;
            case 3:
                *(m_mtx + 0 * COL + 2) = static_cast<int>(usr.getSign());
            break;
            case 4:
                *(m_mtx + 1 * COL + 0) = static_cast<int>(usr.getSign());
            break;
            case 5:
                *(m_mtx + 1 * COL + 1) = static_cast<int>(usr.getSign());
            break;
            case 6:
                *(m_mtx + 1 * COL + 2) = static_cast<int>(usr.getSign());
            break;
            case 7:
                *(m_mtx + 2 * COL + 0) = static_cast<int>(usr.getSign());
            break;
            case 8:
                *(m_mtx + 2 * COL + 1) = static_cast<int>(usr.getSign());
            break;
            case 9:
                *(m_mtx + 2 * COL + 2) = static_cast<int>(usr.getSign());
            break;
            default:
                throw std::out_of_range("Invalid position!");
        }

        int val = static_cast<int>(usr.getSign());
        if(val == *(m_mtx + 0 * COL + 0) && val == *(m_mtx + 0 * COL + 1) && val == *(m_mtx + 0 * COL + 2) ||
           val == *(m_mtx + 1 * COL + 0) && val == *(m_mtx + 1 * COL + 1) && val == *(m_mtx + 1 * COL + 2) ||
           val == *(m_mtx + 2 * COL + 0) && val == *(m_mtx + 2 * COL + 1) && val == *(m_mtx + 2 * COL + 2) ||
           val == *(m_mtx + 0 * COL + 0) && val == *(m_mtx + 1 * COL + 0) && val == *(m_mtx + 2 * COL + 0) ||
           val == *(m_mtx + 0 * COL + 1) && val == *(m_mtx + 1 * COL + 1) && val == *(m_mtx + 2 * COL + 1) ||
           val == *(m_mtx + 0 * COL + 2) && val == *(m_mtx + 1 * COL + 2) && val == *(m_mtx + 2 * COL + 2) ||
           val == *(m_mtx + 0 * COL + 0) && val == *(m_mtx + 1 * COL + 1) && val == *(m_mtx + 2 * COL + 2) ||
           val == *(m_mtx + 0 * COL + 2) && val == *(m_mtx + 1 * COL + 1) && val == *(m_mtx + 2 * COL + 0))
        {
            m_winner  = usr;
            m_running = false;
        }
        else if(!empty())
        {
            m_running = false;
        }
    }
    bool TicTacToe::running() noexcept
    {
        return m_running;
    }
    User TicTacToe::getWinner() const noexcept
    {
        return m_winner;
    }
    bool TicTacToe::empty() const noexcept
    {
        bool res = false;
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                if(0 == *(m_mtx + i * COL + j))
                {
                    res = true;
                    break;
                }
            }
        }
        return res;
    }
    TicTacToe::~TicTacToe()
    {
        delete[] m_mtx;
        m_mtx = nullptr;
    }
    void TicTacToe::alloc()
    {
        m_mtx = new int[ROW * COL];
        memset(m_mtx, 0, sizeof(int) * (ROW * COL));
    }
    void TicTacToe::printBanner()
    {
        std::cout << "\n\n\n" << std::endl;
        std::cout << "=============================================================================" << std::endl;
        std::cout << "                            WELCOME TO TIC TAC TOE                           " << std::endl;
        std::cout << "                                                                             " << std::endl;
        std::cout << "                            USER_01[X] / USER_02[O]                          " << std::endl;
        std::cout << "                                                                             " << std::endl;
        std::cout << "=============================================================================" << std::endl;
    }
    void TicTacToe::init(tic_tac_toe::User& usr1, tic_tac_toe::User& usr2)
    {
        std::string name;
        usr1.setSign(tic_tac_toe::Sign::X);
        usr2.setSign(tic_tac_toe::Sign::O);

        std::cout << "\nEnter user_01 name: ";
        std::cin >> name;
        usr1.setName(name);

        name.clear();
        std::cout << "\nEnter user_02 name: ";
        std::cin >> name;
        usr2.setName(name);
    }
    void TicTacToe::run(
        tic_tac_toe::TicTacToe& game,
        tic_tac_toe::User& usr1, 
        tic_tac_toe::User& usr2, 
        tic_tac_toe::User& curUsr)
    {
        int pos;
        while(game.running())
        {
            std::cout << game << std::endl;

            std::cout << "\n" << curUsr;
            std::cout << "Enter position: ";
            std::cin >> pos;
            game.set(pos, curUsr);

            if(curUsr.getSign() == tic_tac_toe::Sign::X)
            {
                curUsr = usr2;
            }
            else
            {
                curUsr = usr1;
            }
        }
    }
    void TicTacToe::result(tic_tac_toe::TicTacToe& game)
    {
        std::cout << game << std::endl;
        if(game.getWinner().getSign() == tic_tac_toe::Sign::UNKNOWN)
        {
            std::cout << "\nOpps looks like DRAW!!!" << std::endl;  
        }
        else
        {
            std::cout << "\nCongratulations " << game.getWinner().getName() << " you are WINNER!" << std::endl;
        }
    }
    std::ostream& operator<<(std::ostream& cout, tic_tac_toe::TicTacToe& game)
    {
        std::cout << std::endl;
        const int* pMatrix = game.getMatrix();
        for(int i = 0; i < ROW; i++)
        {
            std::cout << "\t\t\t";
            for(int j = 0; j < COL; j++)
            {
                std::cout << " | ";
                if(0 == *(pMatrix + i * COL + j))
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << ((static_cast<int>(Sign::X) == *(pMatrix + i * COL + j)) ? "X" : "O");
                }
            }
            std::cout << " |" << std::endl;
        }
        return cout;
    }
} // namespace tic_tac_toe
