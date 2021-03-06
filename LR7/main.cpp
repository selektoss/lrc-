#include "FuncList.hpp"


int main(void)
{
	using namespace std;
	cout << "0. Enter personal data of a person." << endl
		<< "1. Show list of all profiles a person." << endl
		<< "2. Save data to local file." << endl
		<< "3. Delete profile from database." << endl
		<< "4. Add profile to the beginning of the second." << endl
		<< "5. Exit programm" << endl << endl;
	uint16_t ChoiceNumberMenu = NULL; AnketaData* pointBeginList = nullptr;
	pointBeginList = CheckLocalData(pointBeginList);
	
	do
	{
		cout << "Make your choice: ";
		Try_Error_Cin(ChoiceNumberMenu);
		if (ChoiceNumberMenu <= 5) {
			switch (ChoiceNumberMenu)
			{
			case 0:
				InsertListData(*&pointBeginList);
				break;
			case 1:
				ShowToConsoleAllDataList(pointBeginList);
				break;
			case 2:
				SaveDataListLocalDB(pointBeginList);
				break;
			case 3:
				pointBeginList = DeleteProfileList(pointBeginList);
				break;
			case 4:
				AddElementSecondList(*&pointBeginList);
				break;
			case 5:
				//			EXIT Program/
				break;
			}
		}
		else std::cout << "Error. Repeat your choice " << std::endl << "Waiting : ";
	} while (ChoiceNumberMenu != 5);

	SaveDataListLocalDB(pointBeginList);
	DeleteDataList(*&pointBeginList);
	return 0;
}