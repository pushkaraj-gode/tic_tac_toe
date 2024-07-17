#pragma once

#include <iostream>
#include <string>
#include <utils/constants.h>

namespace tic_tac_toe
{
    class User
    {
        /**
         * User name is stored in this.
         */
        std::string m_name;
        /**
         * This stores signature user has chosen
         * If any user does not wish to choose any signature
         * Default value as unknown will be stored and used
         */
        Sign m_sign = Sign::UNKNOWN;
    public:
        /**
         * It gives user chosen signature
         * 
         * @exception It does not throw any exception
         * @return User chosen signature
         */
        Sign getSign() const noexcept;
        /**
         * This binds signature to user
         * 
         * @param [IN] tic_tac_toe::Sign
         *             This accept signature for user
         *  
         * @exception It does not throw any exception
         * @return nothing
         */
        void setSign(tic_tac_toe::Sign) noexcept;
        /**
         * It gives user selected name
         * 
         * @exception It does not throw any exception
         * @return string chosen name
         */
        std::string getName() const noexcept;
        /**
         * It binds user name to given name
         * 
         * @param [IN] std::string const&
         *             This accept name for user
         * 
         * @exception It does not throw any exception
         * @return nothing
         */
        void setName(std::string const&) noexcept; 
    };
    /**
     * It displays user information such as name and signature
     * 
     * @param [OUT] std::ostream& cout
     *              This accepts console output object
     * 
     * @param [IN] tic_tac_toe:User&
     *             This accepts user object to print onto console 
     * 
     * @exception It does not throw any exception
     * @return Modified ostream object
     */
    std::ostream& operator<<(std::ostream&, tic_tac_toe::User&);
} // namespace tic_tac_toe
