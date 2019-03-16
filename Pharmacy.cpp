#include "Pharmacy.h"
#include <iostream>

Pharmacy::Pharmacy(double a, double b, double c, double d, double e)
{
	med1 = a;
	med2 = b;
	med3 = c;
	med4 = d;
	med5 = e;
}

void Pharmacy::updatePatientAccount(double charge, PatientAccount & p)
{
	p.setCharges(p.getCharges() + charge);
}

void Pharmacy::displayPharmacy()
{
	//display the options
	std::cout << "1." << names[0] << "------$"<<med1<< std::endl;
	std::cout << "2." << names[1] << "-----$" <<med2<< std::endl;
	std::cout << "3." << names[2] << "-----$" <<med3<< std::endl;
	std::cout << "4." << names[3] << "-----$" << med4<< std::endl;
	std::cout << "5." << names[4] << "-----$" <<med5<< std::endl;
}

double Pharmacy::getMed1()
{
	return med1;
}

double Pharmacy::getMed2()
{
	return med2;
}

double Pharmacy::getMed3()
{
	return med3;
}

double Pharmacy::getMed4()
{
	return med4;
}

double Pharmacy::getMed5()
{
	return med5;
}

