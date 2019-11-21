#pragma once
#include <string>
struct TrainDeparture
{
	uint16_t hours = NULL, minute = NULL;
};
struct Train
{
	std::string destination;
	uint16_t numberTrain = NULL;
	TrainDeparture time;
};
