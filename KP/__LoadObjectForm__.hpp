#pragma once
#include "MenuTitle.hpp"
#include <Windows.h>

ModelOBJ*& LoadObjectForm(void);

void UpdateMenu(const ModelOBJ*, const int&);
int ChoisMenu(const ModelOBJ*);