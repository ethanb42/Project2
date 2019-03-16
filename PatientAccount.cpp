#include "PatientAccount.h"



PatientAccount::PatientAccount()
{
	charges = 0;
	days = 0;
}

PatientAccount::PatientAccount(double c, int d)
{
	charges = c;
	days = 0;
}

double PatientAccount::getCharges()
{
	return charges;
}

int PatientAccount::getDays()
{
	return days;
}

double PatientAccount::getDaily()
{
	return dailyRate;
}

void PatientAccount::setCharges(double x)
{
	charges = x;
}

void PatientAccount::setDays(int x)
{
	days = x;
}

void PatientAccount::setDailyRate(double d)
{
	dailyRate = d;
}


