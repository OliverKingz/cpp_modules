#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class Class
{
	public:
		Class(void);
		Class(const Class& src);
		Class& operator=(const Class& src);
		~Class(void);
};