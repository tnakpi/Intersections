#pragma once
#include <iomanip>
#include "cells.h"
#include "roads.h"


void PrintLine_h(Lane l)
{
	for (size_t i = 0; i < l.get_lenght(); i++) {
		std::cout << std::setw(2) << "--";
	}
	std::cout << std::endl;
}
void PrintLine_v(Lane l)
{
	for (size_t i = 0; i < l.get_lenght(); i++) {
		std::cout << std::setw(2) << "--";
	}
	std::cout << std::endl;
}


void Graphics(Lane l)
{
		PrintLine_h(l);
		for (size_t i = 0; i < l.get_lenght(); i++)
		{
			if (!l.get_vector()[i]->IsEmpty())
			{
				std::cout << std::setw(2) << ">";
			}
			else { std::cout << std::setw(2) << " "; }
		}
		std::cout << std::endl;
		PrintLine_h(l);
}