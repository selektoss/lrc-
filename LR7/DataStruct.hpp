#pragma once
const int16_t fio = 36, sizeGender = 7, sizeMarital = 8;
const uint16_t month = 12, day = 31;

struct StellnData
{
	uint16_t day = 0, month = 0, year = 0;
};

struct AnketaData
{
	char gender[sizeGender];
	char surnNameMiddleName[fio];
	char maritalStatus[sizeMarital];
	uint16_t idProfile;
	uint16_t amountOfChildren = NULL;
	double salary = 0.0;
	StellnData date;
	AnketaData* nextData;
};
