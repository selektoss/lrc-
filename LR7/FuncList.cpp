#include "FuncList.hpp"
#include <iomanip>
#include <fstream>

void AddInfoProfile(AnketaData*& pointAdd)
{
	static uint16_t idPerson;
	uint16_t ChoiceNumber = NULL;
	std::cout << "Enter data person." << std::endl << "Enter person name. Example - Naumenko Viktor Andreevich: ";
	std::cin.getline(pointAdd->surnNameMiddleName, fio);
	std::cout << "Enter Date of Birth. Year: "; Try_Error_Cin(pointAdd->date.year);

	do
	{
		std::cout << "Month: ";
		Try_Error_Cin(pointAdd->date.month);
	} while (pointAdd->date.month > month);
	do
	{
		std::cout << "Day: ";
		Try_Error_Cin(pointAdd->date.day);
	} while (pointAdd->date.day > day);

	std::cout << "Enter gender person (0 - Male or 1 - Female)? Enter 0 or 1: ";
jump0:
	Try_Error_Cin(ChoiceNumber);
	if (ChoiceNumber <= 1)
	{
		switch (ChoiceNumber)
		{
		case 0:
			strcpy(pointAdd->gender, "Male");
			break;
		case 1:
			strcpy(pointAdd->gender, "Female");
			break;
		}
	}
	else goto jump0;
	std::cout << "Enter marital status (0 - Married or 1 - Single)? Enter 0 or 1: ";
jump:
	Try_Error_Cin(ChoiceNumber);
	if (ChoiceNumber <= 1)
	{
		switch (ChoiceNumber)
		{
		case 0:
			strcpy(pointAdd->maritalStatus, "Married");
			break;
		case 1:
			strcpy(pointAdd->maritalStatus, "Single");
			break;
		}
	}
	else goto jump;

	std::cout << "Enter amount of children: ";
	Try_Error_Cin(pointAdd->amountOfChildren);
	std::cout << "Enter salary person: ";
	Try_Error_Cin(pointAdd->salary);
	srand(time(0));
	pointAdd->idProfile = ++idPerson + rand() % 10000;

};

void InsertListData(AnketaData *&pointBegin)
{
	AnketaData* pointTemp = nullptr;
	char ChoiceYesOrNo = NULL;
	do {
		pointTemp = new AnketaData;
		AddInfoProfile(*&pointTemp);
		pointTemp->nextData = pointBegin;
		pointBegin = pointTemp;

		std::cout << "\nProfile successfully added! ";
		std::cout << "Continue adding? (y/n): ";
	} while (Try_Error_Cin(ChoiceYesOrNo));
};

void ShowToConsoleAllDataTrain(AnketaData* pointBeginList)
{
	if (pointBeginList) {
		AnketaData* temp = pointBeginList;
		for (size_t i = 0; i < 91; i++)
			std::cout << '-';
		std::cout << std::endl;
		std::cout << std::setw(9) << std::left << "Person ID" << "|" << std::setw(35) << std::left << "Initials Person" << "|" <<
			std::setw(10) << std::left << "Birth" << "|" << std::setw(6) << std::left << "Gender" << "|"
			<< std::setw(7) << std::left << "Marital" << "|" << std::setw(2) << std::left << "Children" << "|" <<
			std::setw(9) << std::left << "Salary" << "|" << std::endl;
		while (temp)
		{
			CoutList(temp);
			temp = temp->nextData;
		}
	}
	else { std::cout << "Nothing to show! DataBase is empty!"; }
	std::cout << std::endl;
};

void CoutList(AnketaData* pointNext)
{
	for (size_t i = 0; i < 91; i++)
		std::cout << '-';
	std::cout << std::endl;
	std::cout 
		<< std::setw(9) << std::left << pointNext->idProfile << "|"
		<< std::setw(35) << std::left << pointNext->surnNameMiddleName << "|"
		<< std::setw(2) << std::right << pointNext->date.day << "." <<
		std::setw(2) << std::right << pointNext->date.month << "." << std::setw(4) 
		<< std::left << pointNext->date.year << "|"
		<< std::setw(6) << std::left << pointNext->gender << "|"
		<< std::setw(7) << std::left << pointNext->maritalStatus << "|"
		<< std::setw(8) << std::left << pointNext->amountOfChildren << "|"
		<< std::setw(8) << std::left << std::setprecision(2) << std::fixed << pointNext->salary << "$" << "|" << std::endl;
};

AnketaData* CheckLocalData(AnketaData* pointList)
{
	using namespace std;
	ifstream localData;
	localData.open("localDB.dat", ios_base::in | ios_base::ate | ios_base::binary);
	AnketaData* takeData = nullptr;
	uint64_t sizeStepFileData = localData.tellg();
	if (localData.is_open())
	{
		if (localData.tellg())
		{
			localData.seekg(sizeStepFileData -= sizeof(AnketaData));
			takeData = new AnketaData;
			
			while (localData.read((char*) & (*takeData), sizeof(AnketaData)))
			{		
				takeData->nextData = pointList;
				pointList = &*takeData;				
				if (!sizeStepFileData)
					break;
				else takeData = new AnketaData;
				localData.seekg(sizeStepFileData -= sizeof(AnketaData));
			}
			cout << "\nDatabase loading completed." << endl;
		}		
		localData.close();		
	}
	return pointList;	
};

void SaveDataListLocalDB(AnketaData* pointStart)
{
	using namespace std;
	if (pointStart)
	{
		ofstream fileData;
		fileData.open("localDB.dat", ios_base::out | ios_base::binary);
		if (fileData.is_open())
		{
			while (pointStart) {
				fileData.write((char*) & *pointStart, sizeof(AnketaData));
				pointStart = pointStart->nextData;
			}
		}
		fileData.close();
	}
};


AnketaData* DeleteProfileList(AnketaData* pointData)
{
	AnketaData* backElement = NULL;
	if (pointData)
	{
		uint16_t idDeleteProfile = NULL, fixedDelete = NULL;
		std::cout << "Enter ID profile to delete in database: ";
		Try_Error_Cin(idDeleteProfile);
		AnketaData* temp = pointData, * back = NULL;
		while (temp)
		{
			if (temp->idProfile == idDeleteProfile)
			{
				if (back) back->nextData = temp->nextData;
				else
				{
					pointData = temp->nextData;
					delete temp;
					return pointData;
				}

				delete temp; break;
			}
			back = temp;
			temp = temp->nextData;
		}
		return pointData;
	}
	else std::cout << "DataList is empty. Pleas add profile to DB!" << std::endl;
};

void AddElementSecondList(AnketaData*& pointData)
{
	if (pointData)
	{
		AnketaData* elemenAddSecond = nullptr;

		elemenAddSecond = new AnketaData;
		AddInfoProfile(*&elemenAddSecond);
		elemenAddSecond->nextData = pointData->nextData;
		pointData->nextData = elemenAddSecond;

		std::cout << "\nProfile successfully added after the first element! " << std::endl;;
	}
	else std::cout << "ListData is emty!" << std::endl;
};

void DeleteDataList(AnketaData*& pointBeginList)
{
	if (pointBeginList)
	{
		AnketaData* temp = pointBeginList;
		while (temp)
		{
			pointBeginList = pointBeginList->nextData;
			delete temp;
			temp = pointBeginList;
		}
	}
};
