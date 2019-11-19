#include "try_error_cin.hpp"
const int16_t MaxError = 5;

void Try_Error_Cin(int16_t& ChoiceNumber)
{
	int CountError = 0;
	while (!(std::cin >> ChoiceNumber))
	{
		if (++CountError > MaxError)
		{
			ChoiceNumber = MaxError;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			break;
		}
		std::cout << "Invalid value!" << std::endl << "Repeat: ";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
};

float Try_Error_Cin(float& ElementNumberInsertArray)
{
	while (!(std::cin >> ElementNumberInsertArray))
	{
		std::cout << "Invalid value!" << std::endl << "Repeat: ";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	return ElementNumberInsertArray;
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
			std::cout << "Invalid character" << std::endl << "Repeat: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
};
