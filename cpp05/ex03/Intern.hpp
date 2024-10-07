#pragma once

#include "AForm.hpp"

class Intern
{
    public:
    //ORTHDX
    Intern();
    ~Intern();
    Intern(const Intern &cpy);
	Intern &operator=(const Intern &eq);

    AForm   *makeForm(std::string form_name, std::string target);
};