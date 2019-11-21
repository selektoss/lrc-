#include "try_error_cin.hpp"

void Try_Error_Cin(int16_t& ChoiceNumber)
{
	while (!(std::cin >> ChoiceNumber))
	{
		std::cout << "Invalid value!" << std::endl << "Repeat : ";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
};

bool Try_Error_Cin(char& ChoiceYesOrNo)
{
	while (ChoiceYesOrNo != 'y' || ChoiceYesOrNo != 'n')
	{
		std::cin >> ChoiceYesOrNo;
		if (ChoiceYesOrNo == 'y' || ChoiceYesOrNo == 'n')
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return (ChoiceYesOrNo == 'y');
		}
		else
		{
			std::cout << "Invalid character" << std::endl << "Repeat : ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
};