#pragma once
const int16_t sizeDestination = 30;
struct TrainDeparture
{
	uint16_t hours = NULL, minute = NULL;
};
struct Train
{
	char destination[sizeDestination];
	uint16_t numberTrain = NULL;
	TrainDeparture time;
};