#pragma once
#include "PatientAccount.h"
#include <string>
class Surgery
{
private:
	double surg1, surg2, surg3, surg4, surg5;
	std::string names[5] =  { "Stiches","Cast", "Surgery 3", "Heart Surgery", "Surgery 5" };
	//string of name of meds
	

public:
	Surgery(double a, double b, double c, double d, double e);
	
	void updateCharges(double charge, PatientAccount &p);
	void displaySurgery();
	double getSurgery1();
	double getSurgery2();
	double getSurgery3();
	double getSurgery4();
	double getSurgery5();
};

