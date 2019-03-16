#include "Surgery.h"
#include <iostream>

Surgery::Surgery(double a, double b, double c, double d, double e)
{
	surg1 = a;
	surg2 = b;
	surg3 = c;
	surg4 = d;
	surg5 = e;
}

void Surgery::updateCharges(double charge, PatientAccount & p)
{
	p.setCharges(p.getCharges() + charge);


}	

void Surgery::displaySurgery()
{
	//display the options
	std::cout << "1."<<  names[0] << "-----$" <<surg1<< std::endl;
	std::cout << "2." << names[1] << "-----$" <<surg2<< std::endl;
	std::cout << "3." << names[2] << "-----$" <<surg3<< std::endl;
	std::cout << "4." << names[3] << "-----$" <<surg4<< std::endl;
	std::cout << "5." << names[4] << "-----$" <<surg5<< std::endl;


}

double Surgery::getSurgery1()
{
	return surg1;
}

double Surgery::getSurgery2()
{
	return surg2;
}

double Surgery::getSurgery3()
{
	return surg3;
}

double Surgery::getSurgery4()
{
	return surg4;
}

double Surgery::getSurgery5()
{
	return surg5;
}
