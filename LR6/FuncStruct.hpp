#pragma once
#include <fstream>
#include "try_error_cin.hpp"
#include "StructTrain.hpp"
void GreateDataTrain(std::fstream&, std::string&, Train&);
void ShowToConsoleAllDataTrain(std::fstream&, std::string&, Train*);
void SortDataTrain(std::fstream&, std::string&, Train&);
void SearchTrainDataByNumber(std::fstream&, std::string&, Train*);
void CoutTrainForm(Train*);