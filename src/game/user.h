#pragma once

#include <iostream>
#include <string>
#include <utils/constants.h>

namespace tic_tac_toe
{
    class User
    {
        std::string m_name;
        Sign m_sign = Sign::UNKNOWN;
    public:
        Sign getSign() const;
        void setSign(tic_tac_toe::Sign);

        std::string getName() const;
        void setName(std::string const&); 
    };
    std::ostream& operator<<(std::ostream&, tic_tac_toe::User&);
} // namespace tic_tac_toe
