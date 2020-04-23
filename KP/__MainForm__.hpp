#pragma once

//#!!!
#pragma warning (disable:4996)
//#!!!

#include <Windows.h>
#include "MenuTitle.hpp"


void DrawBoxFormHeader(const COORD&, const std::string&, const uint16_t&);

void DrawMenuBox(const COORD&, const uint16_t&, const uint16_t&,
	uint16_t*&, uint16_t&, const button*);

void DrawHelpTextBox(const ModelOBJ*);

void DrawContentDataBox(const ModelOBJ*, char*&, char**&);

void InitWeightColumnSectionContentBox	(	char**&, 
											const uint16_t&, 
											uint16_t&, 
											uint16_t*, 
											uint16_t&
										);