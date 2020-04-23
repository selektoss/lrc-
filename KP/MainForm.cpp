#include "__MainForm__.hpp"
#include "__CurPosition__.hpp"
#include <iostream>

void DrawBoxFormHeader(const COORD& weight_height_size_position, const std::string& headerTitle, const uint16_t &border)

{	
	setlocale(LC_CTYPE, "C");
	for (uint16_t i(0); i < 2; ++i)
	{
		SetCurPos(border, (i << 1));
		std::cout << char(201 - i) << std::string(weight_height_size_position.X - ((border << 1) + 2), '\xCD') << char(187 + i);
		if (i == 1)
		{
			CONSOLE_SCREEN_BUFFER_INFO conInfo;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &conInfo);
			SetCurPos(conInfo.dwCursorPosition.X - i, i); std::cout << char(186);
			SetCurPos(border, i); std::cout << char(186);
			SetCurPos(static_cast<uint16_t>((weight_height_size_position.X) >> 1) - static_cast<uint16_t>((headerTitle.length()) >> 1), i);
			setlocale(LC_ALL, ""); std::cout << headerTitle;
		}
	}
};

void DrawMenuBox(const COORD& coordXY, const uint16_t& sizeMenu, const uint16_t& border, 
	uint16_t*& ArrLenTitleMenu, uint16_t& MenuWeight, const button* Menu)
{
	uint16_t outchar(2), iter(0); setlocale(LC_CTYPE, "C");
	ArrLenTitleMenu = new uint16_t[sizeMenu]; MenuWeight = NULL;
	for (uint16_t iter(0); iter < sizeMenu; ++iter)
	{
		*(ArrLenTitleMenu + iter) = static_cast<uint16_t>((Menu + iter)->nameButton.length());
		MenuWeight < *(ArrLenTitleMenu + iter) ? MenuWeight = (*(ArrLenTitleMenu + iter)) + outchar : NULL;
	}
	while ( iter < outchar)
	{
		SetCurPos(coordXY.X - (MenuWeight + border ), (coordXY.Y - (sizeMenu + border + 1)) +  ((sizeMenu + 1) * iter++));
		std::cout << std::string(MenuWeight, ('\xDC' + (3*(iter - 1))));
	}
};

void DrawHelpTextBox(const ModelOBJ* form)
{
	uint16_t charcout(2); uint16_t* tmpPTR = const_cast<uint16_t*>(&form->lineCountTextHelp); *tmpPTR = 0;
	for (uint16_t iter(0); iter < form->sizeMenu; ++iter)
	{
		form->lineCountTextHelp < (form->Menu + iter)->txtHelp.length() ? *tmpPTR = static_cast<uint16_t>(((form->Menu + iter))->txtHelp.length()) : NULL;
	}
	*tmpPTR = (form->lineCountTextHelp / (form->MenuWeight - 2)) + charcout; tmpPTR = nullptr;
	uint16_t tAG(217), tAG1(192), iterY(0);
 	for (uint16_t iterX(0); iterX <= form->lineCountTextHelp; iterX += form->lineCountTextHelp, ++iterY, tAG -= 25, tAG1 += 25)
	{
		SetCurPos(form->coordXY.X - (form->MenuWeight + form->border), (form->coordXY.Y - (form->sizeMenu + (form->border << 1))) - iterX);
		std::cout << char(tAG1 + iterY) << std::string(form->MenuWeight - charcout, '\xC4') << char(tAG - iterY);
	}
	for (uint16_t iter(0); iter < form->lineCountTextHelp - 1; ++iter)
	{
		SetCurPos(form->coordXY.X - (form->MenuWeight + form->border), (form->coordXY.Y - (form->sizeMenu + (form->border << 1) + (form->lineCountTextHelp - 1))) + iter); std::cout << char(179);
		SetCurPos(form->coordXY.X - (form->border + 1), (form->coordXY.Y - (form->sizeMenu + (form->border << 1) + (form->lineCountTextHelp - 1))) + iter); std::cout << char(179);
	}
};

void InitWeightColumnSectionContentBox(char**& nameSection, const uint16_t& content_weight, uint16_t& Summ,
	uint16_t* minLenColumnSection, uint16_t& size)
{
	int16_t temp(0);
	for (int16_t iter(0); iter < size; ++iter)
	{
		uint16_t sizeLen(static_cast<uint16_t>(strlen(*(nameSection + iter))));
		sizeLen > * (minLenColumnSection + iter) ? *(minLenColumnSection + iter) = sizeLen : NULL;
		Summ += *(minLenColumnSection + iter);
	}
	Summ < content_weight ? temp = content_weight - Summ : NULL; Summ = 0;
	while (temp) for (size_t iter = 0; iter < size && --temp; ++iter) ++(*(minLenColumnSection + iter));
};

void DrawContentDataBox	(const ModelOBJ* form, char *&titleContent, char**&nameSection)
{	
	using namespace std; CONSOLE_SCREEN_BUFFER_INFO infoConsole; uint16_t lenTitle(static_cast<uint16_t>(strlen(titleContent) - 1));
	uint16_t* tmpH = const_cast<uint16_t*>(&form->heightContent); uint16_t* tmpW = const_cast<uint16_t*>(&form->weightContent);
	*tmpW = form->coordXY.X - (((form->border << 1) + form->MenuWeight) + form->border);
	*tmpH = form->coordXY.Y - (form->border + form->headerHeight); HANDLE poinOut(GetStdHandle(STD_OUTPUT_HANDLE));
	tmpW = tmpH = nullptr;
	SetCurPos(form->border, form->headerHeight);
	cout << char(201) << string(((form->weightContent >> 1) - (lenTitle >> 1)) - 2, '\xCD') << char(185);
	GetConsoleScreenBufferInfo(poinOut, &infoConsole);
	SetCurPos(infoConsole.dwCursorPosition.X, (infoConsole.dwCursorPosition.Y)); setlocale(LC_ALL, "");
	cout << titleContent; setlocale(LC_ALL, "C"); delete [] titleContent; titleContent = nullptr;

		for (uint16_t iterY(0); iterY < 2; ++iterY)
		{
			SetCurPos(infoConsole.dwCursorPosition.X - 1, (infoConsole.dwCursorPosition.Y - 1) + (iterY << 1));
			cout << char(201 - iterY) << string(lenTitle, '\xCD') << char(187 + iterY);
			if (iterY)
			{
				SetCurPos(infoConsole.dwCursorPosition.X + lenTitle, (infoConsole.dwCursorPosition.Y)); cout << char(204);
				cout << string(((form->weightContent >> 1) - (lenTitle >> 1)) - iterY, '\xCD') << char(187);
			}
		}
		GetConsoleScreenBufferInfo(poinOut, &infoConsole); DWORD* tmpD = const_cast<DWORD*>(&form->consoleATR);
		*tmpD = infoConsole.wAttributes;
		for (uint16_t iter(0); iter < (form->coordXY.Y - (form->border << 1)); ++iter)
		{
			SetCurPos(infoConsole.dwCursorPosition.X - 1, form->border + iter); cout << char(186);
			SetCurPos(form->border, form->border + iter); cout << char(186);
		}
		SetCurPos(form->border, (form->coordXY.Y - form->border));
		cout << char(200) << string((form->weightContent - 1), '\xCD') << char(188);
		for (uint16_t iter(form->headerHeight + 2); iter < 9; iter += 2)
		{
			SetCurPos(form->border + 1, (iter)); cout << string((form->weightContent - 1), '\xC4');
		}
		uint16_t* tmpArr = const_cast<uint16_t*&>(form->minLenColumnSection);
		tmpArr = new uint16_t[form->countColumnTitle]; uint16_t iterZ(0);
		uint16_t minLenColumnSection[] = { 4U, 32U, 10U, 10U, 7U, 5U, 4U, 4U, 4U, 10U }; uint16_t Summ(0);
		while (iterZ < form->countColumnTitle)
			tmpArr[iterZ++] = minLenColumnSection[iterZ];
		uint16_t sizeM(sizeof(minLenColumnSection) >> 1);
		InitWeightColumnSectionContentBox(nameSection, form->weightContent, Summ, minLenColumnSection, sizeM);

		for (int16_t iterMas(0); iterMas < sizeM; ++iterMas)
		{
			Summ += *(minLenColumnSection + iterMas);
			SetCurPos((form->border + form->weightContent) - (form->weightContent - Summ), (form->headerHeight + 3));
			if (iterMas != (sizeM - 1))
			{
				cout << char(179);
				for (uint16_t iterS(form->headerHeight + 2), ch(0); iterS <= (form->headerHeight << 1); iterS += 2, ++ch)
				{
					SetCurPos((form->border + form->weightContent) - (form->weightContent - Summ), (iterS));
					cout << char(194 - ch);
				}
			}
			SetCurPos(static_cast<uint16_t>((((form->border + form->weightContent + 1) - (form->weightContent - Summ)) - (minLenColumnSection[iterMas] >> 1)) - ((strlen(*(nameSection + iterMas)) + 1) >> 1)), (form->headerHeight + 3));
			setlocale(LC_ALL, ""); SetConsoleTextAttribute(poinOut, FOREGROUND_GREEN);
			cout << *(nameSection + iterMas); setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(poinOut, form->consoleATR);
		}
		delete[] * nameSection; delete[] nameSection; nameSection = nullptr;	
};
