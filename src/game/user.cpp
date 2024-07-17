#include <game/user.h>

namespace tic_tac_toe
{
    Sign User::getSign() const
    {
        return m_sign;
    }
    void User::setSign(tic_tac_toe::Sign sign)
    {
        m_sign = sign;
    }
    std::string User::getName() const
    {
        return m_name;
    }
    void User::setName(std::string const& name)
    {
        m_name = name;
    }
    std::ostream& operator<<(std::ostream& cout, tic_tac_toe::User& usr)
    {
        std::cout << "NAME: " << usr.getName() << std::endl;
        std::cout << "SIGN: " << ((Sign::X == usr.getSign()) ? "X" : "O") << std::endl;
        return cout;
    }
} // namespace tic_tac_toe
