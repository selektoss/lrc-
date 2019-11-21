#include "FuncStruct.hpp"
#include <iomanip>

int main(void)
{

	/*
	std::string eee;
	std::cin >> eee;
	std::string filename = "planets.dat";
	elementTrain = {"Kiev", 4534, 34};

	std::fstream fout(filename,
		std::ios_base::out | std::ios_base::in | std::ios_base::app | std::ios_base::binary);
	fout.write((char*)& elementTrain, sizeof elementTrain);
	fout.close();

	std::ifstream fin(filename, std::ios_base::in | std::ios_base::binary);
	fout.read((char*)& p, sizeof p);
	int ct = 0;
	fin.seekg(0); // перейти в начало
	std::cout << "Here are the current contents of the " << filename << "file:\n";
		while (fin.read((char*)& p, sizeof p))
		{
			std::cout << ct++ << ": "
				<<std::setw(20) << p.destination << ": "
				<< std::setprecision(0) << std::setw(12) << p.numberTrain
				<< std::setprecision(2) << std::setw(6) << p.time.hours << std::endl;
		}
		*/
	std::cout << "0. Enter data Train info." << std::endl
		<< "1. Show all data Train info." << std::endl
		<< "2. Begin search search for a train by its number." << std::endl
		<< "3. Sort element train by number." << std::endl
		<< "4. Exit programm" << std::endl << std::endl;
	int16_t ChoiceNumberMenu = NULL; Train elementTrain; std::string filename; std::fstream fileData;
	do
	{
		std::cout << "Make your choice: ";
		Try_Error_Cin(ChoiceNumberMenu);
		if ((ChoiceNumberMenu <= 4) && (ChoiceNumberMenu >= NULL)) {
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
}