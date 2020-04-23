#pragma once
#include <string>
#include <Windows.h>


typedef struct menuList
{
	std::string nameButton;
	std::string txtHelp;
}button;

typedef struct LoBject
{
	const uint16_t headerHeight = 4, border = 5;
	uint16_t MenuWeight, lineCountTextHelp, sizeMenu, heightContent, weightContent, countColumnTitle; 
	uint16_t* ArrLenTitleMenu; uint16_t* minLenColumnSection;
	button* Menu;
	COORD  coordXY; DWORD consoleATR;

}ModelOBJ;