#pragma once

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <time.h>
#include <exception>

void identify(Base* p);
void identify(Base &p);
Base *generate(void);
