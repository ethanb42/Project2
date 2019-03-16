#pragma once
#include "PatientAccount.h"
#include <string>
class Pharmacy
{
private:
	double med1, med2, med3, med4, med5;
	std::string names[5] = { "Rx1","Rx2","Tylenol","Morphine", "Rx5" };

public:
	Pharmacy(double a, double b, double c, double d, double e);
	
	void updatePatientAccount(double charge, PatientAccount &p);
	void displayPharmacy();
	double getMed1();
	double getMed2();
	double getMed3();
	double getMed4();
	double getMed5();


};


