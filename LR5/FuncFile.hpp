#pragma once
#include "try_error_cin.hpp"
void GreateNameFile(char*, const size_t&);
FILE* ConnectFile(FILE*, char*);
char* SearchSuggestionsAndGreateDynamicMemory(FILE*, char*, char*);
void CloseFile(FILE*);