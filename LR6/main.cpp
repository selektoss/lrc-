#include "FuncStruct.hpp"
#include <iomanip>

int main(void)
{
	std::cout << "0. Enter data Train info." << std::endl
		<< "1. Show all data Train info." << std::endl
		<< "2. Begin search search for a train by its number." << std::endl
		<< "3. Sort element train by number." << std::endl
		<< "4. Exit programm" << std::endl << std::endl;
	uint16_t ChoiceNumberMenu = NULL; Train elementTrain; std::string filename; std::fstream fileData;
	do
	{
		std::cout << "Make your choice: ";
		Try_Error_Cin(ChoiceNumberMenu);
		if (ChoiceNumberMenu <= 4) {
			switch (ChoiceNumberMenu)
			{
			case 0:
				GreateDataTrain(fileData, filename, elementTrain);
				break;
			case 1:
				ShowToConsoleAllDataTrain(fileData, filename, &elementTrain);
				break;
			case 2:
				SearchTrainDataByNumber(fileData, filename, &elementTrain);
				break;
			case 3:
				SortDataTrain(fileData, filename, elementTrain);
				break;
			case 4:
				//			EXIT Program/
				break;
			}
		}
		else std::cout << "Error. Repeat your choice " << std::endl << "Waiting : ";
	} while (ChoiceNumberMenu != 4);

	return 0;
};