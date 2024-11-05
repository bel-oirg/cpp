#pragma once

#include "AForm.hpp"

class Intern
{
    private:
        AForm   *MakeP(std::string target);
        AForm   *MakeR(std::string target);
        AForm   *MakeS(std::string target);

    public:
        Intern();
        ~Intern();
        Intern(const Intern &cpy);
        Intern &operator=(const Intern &eq);
        AForm   *makeForm(std::string form_name, std::string target);
        
        class invalid_name : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
};