#include "FuncStruct.hpp"
#include <iomanip>
void GreateDataTrain(std::fstream& fileOut, std::string& filename, Train& elemetTrain)
{
	const int16_t time[3] = { 0,59,23 };
	using namespace std;

	cout << "Please enter path file binary name : "; cin >> filename;
	cin.clear(); cin.ignore(INT_MAX, '\n');
	fileOut.open(filename, ios_base::out | ios_base::app | ios_base::ate | ios_base::binary);
	if (fileOut.is_open())
	{
		char ChoiceYesOrNo = NULL;
		if (fileOut.tellg())
		{
			cout << "There are train entries in the file. Show to console now? (y/n) : ";
			if (Try_Error_Cin(ChoiceYesOrNo))
			{
				fileOut.close();
				ShowToConsoleAllDataTrain(fileOut, filename, &elemetTrain);
				ChoiceYesOrNo = NULL;
				fileOut.open(filename, ios_base::out | ios_base::app | ios_base::binary);
			}
		}
		do {
			cout << endl << "Enter info Train." << endl << endl << "Destination : "; cin.clear(); cin.getline(elemetTrain.destination, sizeDestination);
			jump:
			cout << "Number train. MaxID - 60000: "; Try_Error_Cin(elemetTrain.numberTrain);
			if (elemetTrain.numberTrain > 60000)
				goto jump;
			do {
				cout << "Departure time hour : ";
				Try_Error_Cin(elemetTrain.time.hours);
			} while (elemetTrain.time.hours > time[2]);

			do {
				cout << "Departure time minute : ";
				Try_Error_Cin(elemetTrain.time.minute);
			} while (elemetTrain.time.minute > time[1]);
			
			fileOut.write((char*)& elemetTrain, sizeof(Train));

			cout << "Do you add info Train again? (y/n) : ";

		} while (Try_Error_Cin(ChoiceYesOrNo));
		fileOut.close();
	}
};

void ShowToConsoleAllDataTrain(std::fstream& fileIn, std::string& filename, Train* elemetTrain)
{
	using namespace std;
	jump:
	fileIn.open(filename, ios_base::in | ios_base::ate | ios_base::binary);
	if (fileIn.is_open() && fileIn.tellg())
	{
		fileIn.seekp(0);
		cout << "Here are the current contents of the Train " << filename << " file:\n" << endl;
		for (size_t i = 0; i < 41; i++)
			cout << '-';
		cout << endl;
		cout << std::setw(7) << left << "Train #" << "|" << setw(18) << left << "Destination" << "|" <<
			setw(14) << left << "Time Departure" << "|" << endl;
		while (fileIn.read((char*)& *elemetTrain, sizeof(Train)))
		{
			CoutTrainForm(elemetTrain);
		}
		fileIn.close();
	}
	else { 
		cout << "Error open data file or file is empty!" << endl; 
		cout << "Please enter path file binary name : "; cin >> filename;
		cin.clear(); cin.ignore(INT_MAX, '\n');
		goto jump;
	}
	
};

void SortDataTrain(std::fstream& fileData, std::string& filename, Train& elemetTrain)
{
	using namespace std;
	fileData.open(filename, ios_base::out | ios_base::in | ios_base::ate | ios_base::binary);

	if (fileData.is_open())
	{
		Train elementTrain2;
		size_t sizeByteData = fileData.tellg();
		size_t countElementTrainData = (sizeByteData / sizeof(Train)) - 1;

		if (sizeByteData && countElementTrainData >= 1)
		{
			for (size_t i = 0; i < countElementTrainData; i++)
			{
				fileData.seekg((sizeof(Train)) * (i + 1));
				fileData.read((char*)& elementTrain2, sizeof(Train));

				for (int j = i; j >= 0; j--)
				{
					fileData.seekg((sizeof(Train)) * (j));
					fileData.read((char*)& elemetTrain, sizeof(Train));

					if (elementTrain2.numberTrain < elemetTrain.numberTrain)
					{
						fileData.seekg((sizeof(Train)) * (j));
						fileData.write((char*)& elementTrain2, sizeof(Train));
						fileData.write((char*)& elemetTrain, sizeof(Train));
					}
				}
			}
			cout << "Sort completed." << endl;
		} else { cout << "Nothing to sort! File is empty or data train < 2." << endl; }
		
		fileData.close();
	} else { cout << "Error open file!" << endl; }
};

void SearchTrainDataByNumber(std::fstream& fileData, std::string& filename, Train* elementTrain)
{
	fileData.open(filename, std::ios_base::in | std::ios_base::binary | std::ios_base::ate);
	if (fileData.is_open() && fileData.tellg())
	{
		fileData.seekp(0);
		uint16_t numberTrain = NULL, count = NULL;
		std::cout << "Enter number Train search: ";
		Try_Error_Cin(numberTrain);
		while (fileData.read((char*) & *elementTrain, sizeof(Train)))
		{
			if (elementTrain->numberTrain == numberTrain)
			{
				count++;
				CoutTrainForm(elementTrain);
			}
		}
		if (!count)
		{
			std::cout << "No trains found." << std::endl;
		}
		fileData.close();
	}
	else { std::cout << "Error. Nothing to search or file is empty or error open file!" << std::endl; }

};

void CoutTrainForm(Train* elementTrain)
{
	for (size_t i = 0; i < 41; i++)
		std::cout << '-';
	std::cout << std::endl;
	std::cout 
		<< std::setw(7) << std::left << elementTrain->numberTrain << "|"
		<< std::setw(18) << std::left << elementTrain->destination << "|"
		<< std::setw(2) << std::left << elementTrain->time.hours 
		<< ":" << std::setw(11) << std::left << elementTrain->time.minute << "|" << std::endl;
		
};