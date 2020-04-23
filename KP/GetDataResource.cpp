#include <regex>
#include <fstream>
#include <sstream>
#include <iostream>
#include "resource.h"
#include "__MainForm__.hpp"
#include "__CurPosition__.hpp"

#define F ios_base

void GetDataResourceMenu(ModelOBJ*& form, char*& title_contetnt, char**& nameSection)
{
	using namespace std;
	const char* regular[] = { "#HEADER\r","^(#\\END_HEADER[\\s\\S]*)", "#MENU\r", "^(#\\END_MENU[\\s\\S]*)",
		"#HELP\r", "^(#\\END_HELP[\\s\\S]*)", "#TITLE\r", "^(#\\END_TITLE[\\s\\S]*)",
		"#CONTENT\r", "^(#\\END_CONTENT[\\s\\S]*)", "^(#\\END_CONF[\\s\\S]*)"
	};

	string lineTemp, lineTemp1; stringstream lineBuffM(F::app | F::ate | F::in | F::out); std::stringstream lineBuff;
	uint16_t check(NULL); uint16_t count(NULL); cmatch res; form->Menu = nullptr;

	if (HRSRC FileResource = FindResource(GetModuleHandle(NULL), MAKEINTRESOURCE(INITXTFILE), "ini"))
	{
		if (HGLOBAL ResourceMem = LoadResource(GetModuleHandle(NULL), FileResource))
			lineBuff << (char*)LockResource(ResourceMem);
		if (lineBuff.good())
			while (getline(lineBuff, lineTemp) && !(regex_match(lineTemp.c_str(), regex{ *(regular + 10) })))
			{
				if (regex_match(lineTemp.c_str(), res, 
					regex{ "^(#\\HEADER[\\s\\S]|#\\MENU[\\s\\S]|#\\HELP[\\s\\S]|#\\TITLE[\\s\\S]|#\\CONTENT[\\s\\S]*)" }, 
					std::regex_constants::match_not_eol))
				{
					res[0] == regular[0] ? check = 1 : res[0] == regular[2] ? check = 3 : 
						res[0] == regular[4] ? check = 5 : res[0] == regular[8] ? check = 9 : check = 7;
					while (getline(lineBuff, lineTemp) && !(regex_match(lineTemp.c_str(), 
						regex{ *(regular + check) })))
					{
						if (lineTemp == "\r" || lineTemp == "") continue;
						if (check == 1)
						{
							DrawBoxFormHeader(form->coordXY, lineTemp, form->border); break;
						}
						else if (check == 3 || check == 5 || check == 9)
						{
							lineBuffM << lineTemp + '\n'; ++count;
						}
						else if (!title_contetnt && check == 7)
						{
							title_contetnt = new char[lineTemp.length() + 1];
							strcpy(title_contetnt, lineTemp.c_str());
						}
					}
					(!(form->Menu) && count) ? form->Menu = new button[count] : NULL;
					if (count && check != 9)
					{
						form->sizeMenu = count;
						for (uint16_t iter(0); iter < count; ++iter)
							check == 3 ? getline(lineBuffM, ((form->Menu) + iter)->nameButton) : 
							getline(lineBuffM, ((form->Menu) + iter)->txtHelp);
						lineBuffM.str(std::string()); lineBuffM.clear();
					}
					else if (check == 9)
					{
						nameSection = new char* [count]; (*nameSection) = new char[lineBuffM.str().length() + 1];
						strcpy((*nameSection), lineBuffM.str().c_str());

						size_t positionL(lineBuffM.str().find("\n")); uint16_t iterF(1);
						while (positionL != std::string::npos && iterF < count)
						{
							*((*nameSection) + positionL) = '\0';
							*(nameSection + iterF) = (*nameSection) + (positionL + 1); ++iterF;
							positionL = lineBuffM.str().find("\n", positionL + 1);
						}
						lineBuffM.str(std::string()); lineBuffM.clear();
						form->countColumnTitle = count;
					}
					count = 0;
				}
			}
		else
		{
			const char* info_error = "Error load resource! Check resource ID. Exit programm";
			SetCurPos(static_cast<uint16_t>((form->coordXY.X >> 1) - ((strlen(info_error)) >> 1)), 
				static_cast<uint16_t>(form->coordXY.Y >> 1));
			std::cout << info_error;
			Sleep(2000); exit(-2);
		}
	}
	if (!title_contetnt)
	{
		title_contetnt = new char[strlen("NONE TITLE CONTENT") + 1]; strcpy(title_contetnt, "NONE TITLE CONTENT");
	}
	lineBuff.str(std::string()); lineBuff.clear();
};