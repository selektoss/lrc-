#include <iostream>
#include <string>
#include "try_error.hpp"
std::string RepeatMessageWait = "Repeat: ";
const int16_t MaxError = 5;
void Try_Error_Cin(int16_t& ChoiceNumberMenu)
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
			std::cout << "Invalid value!" << std::endl << RepeatMessageWait;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');		
		}
}

float Try_Error_Cin(float& ElementNumberInsertArray)
{
	while (!(std::cin >> ElementNumberInsertArray))
	{
		std::cout << "Invalid value!" << std::endl << RepeatMessageWait;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	return ElementNumberInsertArray;
};
bool Try_Error_Cin(char& —hoiceYesOrNo)
{	
	while (—hoiceYesOrNo != 'y' || —hoiceYesOrNo != 'n')
	{
		std::cin >> —hoiceYesOrNo;
		if (—hoiceYesOrNo == 'y' || —hoiceYesOrNo == 'n')
			return (—hoiceYesOrNo == 'y');
		else 
		{
			std::cout << "Invalid character!" << std::endl << RepeatMessageWait;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}		
}
