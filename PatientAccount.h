#pragma once
class PatientAccount
{
private: 
	double charges;  //cost of hosptial stay
	int days;        //days in hospital
	double  dailyRate; //daily rate of stay for the patient
public:
	PatientAccount();
	PatientAccount(double c, int d);

	double getCharges();
	int getDays();
	double getDaily();

	void setCharges(double x);
	void setDays(int x);
	void setDailyRate(double d);
};

