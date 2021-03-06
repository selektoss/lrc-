#include "try_error.hpp"
const int16_t MaxError = 5;
void Try_Error_Cin(uint16_t& ChoiceNumberMenu)
{
	int CountError = 0;
	while (!(std::cin >> ChoiceNumberMenu))
	{
		if (++CountError > MaxError)
		{
			ChoiceNumberMenu = MaxError;
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

bool Try_Error_Cin(char& —hoiceYesOrNo)
{
	while (true)
	{
		std::cin >> —hoiceYesOrNo;
		if (—hoiceYesOrNo == 'y' || —hoiceYesOrNo == 'n')
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return (—hoiceYesOrNo == 'y');
		}
		else
		{
			std::cout << "Invalid character!" << std::endl << "Repeat: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
};
