#include "__GetData__.hpp"
#include "__Get_SetSizeConsole__.hpp"
#include "__MainForm__.hpp"
#include "__CurPosition__.hpp"
#include <iostream>
#include <conio.h>

#define  FG FOREGROUND_GREEN
#define  FR FOREGROUND_RED
#define  FB FOREGROUND_BLUE

#define  BG BACKGROUND_GREEN
#define  BR BACKGROUND_RED
#define  BB BACKGROUND_BLUE

#define BBLACK 0x000

ModelOBJ*& LoadObjectForm(void)
						
{
	ModelOBJ* form(new ModelOBJ); 
	form->coordXY = ConsoleSize();
	char* titleContent(nullptr); char** nameSection(nullptr);
	GetDataResourceMenu(form, titleContent, nameSection);
	DrawMenuBox(form->coordXY, form->sizeMenu, form->border, form->ArrLenTitleMenu, form->MenuWeight, form->Menu);
	DrawHelpTextBox(form);
	DrawContentDataBox(form, titleContent, nameSection);
	return form;
};

void UpdateMenu(const ModelOBJ* form, const int& chois)
{
	uint16_t XYtemp[2] = { form->coordXY.X - (form->border + (form->MenuWeight)), form->coordXY.Y - (form->border + form->sizeMenu) };
	SetCurPos(*XYtemp, *(XYtemp + 1)); setlocale(LC_ALL, "");
	using namespace std;

	for (uint16_t iter(0); iter < form->sizeMenu; ++iter)
	{
		if (iter == chois)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG | BG | BB | BR);
			SetCurPos(*XYtemp, (*(XYtemp + 1)) + iter);
			cout << string(form->MenuWeight, '\x20');
			SetCurPos(((form->coordXY.X - (form->border + (form->MenuWeight >> 1))) - ((*(form->ArrLenTitleMenu + iter)) >> 1)), *(XYtemp + 1) + iter);
			cout << form->Menu[iter].nameButton;
			uint16_t lenghtStrHelpTxt = form->Menu[iter].txtHelp.length();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FB | FG | FR | BBLACK);

			for (uint16_t iterV(0), nextPosition(0); iterV < form->lineCountTextHelp - 1; ++iterV, nextPosition += (form->MenuWeight - 2))
			{

				SetCurPos((*XYtemp) + 1, (form->coordXY.Y - ((form->border << 1) + form->sizeMenu + (form->lineCountTextHelp - 1) - iterV)));
				cout << string((form->MenuWeight - 2), '\x20');
				if (nextPosition < lenghtStrHelpTxt)
				{
					SetCurPos(form->coordXY.X - (form->border + (form->MenuWeight - 1)), (form->coordXY.Y - ((form->border << 1) + form->sizeMenu + (form->lineCountTextHelp - 1) - iterV)));
					cout << form->Menu[iter].txtHelp.substr(nextPosition, (form->MenuWeight - 2));
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FB | FG | FR | BG);
			SetCurPos(*XYtemp, (*(XYtemp + 1)) + iter);
			cout << string(form->MenuWeight, '\x20');
			SetCurPos(((form->coordXY.X - (form->border + (form->MenuWeight >> 1))) - ((*(form->ArrLenTitleMenu + iter)) >> 1)), 
				(*(XYtemp + 1)) + iter);
			cout << form->Menu[iter].nameButton;
		}
	}
};

int ChoisMenu(const ModelOBJ* form)
{
	static int chois(0);
	while (true)
	{
		UpdateMenu(form, chois);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), form->consoleATR);
		while (int key = _getch())
		{
			if (key > 99) continue;
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				chois -= 1; if (chois < 0) chois = 6;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				chois += 1; if (chois == 7) chois = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) return chois;
		}
	}
};