#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	static string months[12];
	static int days[12];

public:

	Date(int m, int d, int y)
	{
		setMonth(m);
		setDay(d);
		setYear(y);

	}

	void setDay(int d)
	{
		while (d < 1 || d> days[getMonth() - 1]) {
			cout << "Invalid day entry, try again!\nInput:" << endl;
			cin >> d;
		}

		day = d;

	}

	void setMonth(int m)
	{
		while (m < 1 || m>12) {
			cout << "Invalid month entry, try again!\nInput:" << endl;
			cin >> m;
		}

		month = m;
	}

	void setYear(int y)
	{
		year = y;
	}

	int getDay()
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}

	int getYear()
	{
		return year;
	}

	Date operator--()
	{//check the end case
		if (day == 1) {
			if (month == 1) {
				month = 12;
				day = 31;
				year--;
			}
			//not first month nut still 1st day
			else {
				month--;
				day = days[month - 1];
			}
		}
		//not the first day
		else {
			day--;
		}
		return *this;
	}

	Date operator--(int)
	{
		//check the end case
		if (day == 1) {
			if (month == 1) {
				month = 12;
				day = 31;
				year--;
			}
			//not first month nut still 1st day
			else {
				month--;
				day = days[month - 1];
			}
		}
		//not the first day
		else {
			day--;
		}
		return *this;
	}

	int operator-(const Date &object)
	{
		int one, two;
		//credit to Dr. Volger for the formula to calculate days between
		// 365*year + year/4 - year/100 + year/400 + date + (153*month+8)/5

		one = 365 * year + year / 4 - year / 100 + year / 400 + day + (153 * month + 8) / 5;
		two = 365 * object.year + object.year / 4 - object.year / 100 + object.year / 400 + object.day + (153 * object.month + 8) / 5;
		one = one - two;
		if (one < 0) {
			one = one * -1; //we want the days between so it needs to be an absolute value
		}


		return one;
	}

	Date operator++()
	{
		//check if new month should be ticked
		if (day == days[getMonth() - 1]) {
			//first day of next month
			day = 1;
			//check for year increment
			if (month == 12) {
				month = 1;
				year++;
			}
			else {
				month++;
			}
		}
		//it is not the last day of the month
		else {
			day++;
		}
		return *this;
	}

	Date operator++(int)
	{
		//check if new month should be ticked
		if (day == days[getMonth() - 1]) {
			//first day of next month
			day = 1;
			//check for year increment
			if (month == 12) {
				month = 1;
				year++;
			}
			else {
				month++;
			}
		}
		//it is not the last day of the month
		else {
			day++;
		}
		return *this;
	}

	friend ostream &operator << (ostream &strm, const Date &d) {
		cout << months[d.month-1] << " " << d.day << ", " << d.year << endl;
		return strm;
	}

	friend istream &operator>>(istream  &input, Date &d) {
		//get users input
		//get the month
		do {
			cout << "Enter valid month!\nInput:" << endl;
			input >> d.month;
		} while (d.month < 1 || d.month>12);

		//get the day
		do {
			cout << "Enter valid day!\nInput:" << endl;
			input >> d.day;
		} while (d.day < 1 || d.day> days[d.month - 1]);

		//get the year
		cout << "Enter the year: " << endl;
		input >> d.year;


		return input;
	}

	void printFormOne()
	{
		cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
	}

	void printFormTwo()
	{
		cout << months[getMonth() - 1] << " " << getDay() << ", " << getYear() << endl;
	}

	void printFormThree()
	{
		cout << getDay() << " " << months[getMonth() - 1] << " " << getYear() << endl;
	}

};

//define months only once because it does not change
string Date::months[] = { "January", "February", "March", "April",
	"May", "June", "July", "August", "September",
	"October", "November", "December" };

//define the number of days each month
int Date::days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


//test the date class
int main() {
	//month, day, year
	Date test(1, 1, 2020);
	Date test2(12, 31, 2020);
	Date test3(4, 4, 2045);

	//test -- overload
//print before
	cout << "Before -- operator" << endl;
	test.printFormTwo();
	//increment
	test--;
	//print after
	cout << "After -- operator" << endl;
	test.printFormTwo();

	//test "++" overload
	//print before
	cout << "\n\nBefore ++ operator" << endl;
	test2.printFormTwo();
	//increment
	test2++;
	//print after
	cout << "After ++ operator" << endl;
	test2.printFormTwo();

	//test - overload 
	cout << "\n\nTesting - overload by subtracting two dates" << endl;
	cout << "Days between" << endl;
	test.printFormOne();
	cout << " and " << endl;
	test2.printFormOne();
	cout << "is " << test - test2 << endl;

	cout << "\n\nTesting - overload by subtracting two further dates" << endl;
	cout << "Days between" << endl;
	test.printFormOne();
	cout << " and " << endl;
	test3.printFormOne();
	cout << "is " << test - test3 << endl;

	//testing cout << overload
	cout << "\n\nTesting << overload" << endl;
	cout << "Date:" << test << endl;

	//testing cin >>
	cout << "Testing >> overload" << endl;
	cin >> test;
	cout << "Displaying new date....\n" << endl;
	cout << "Date:" << test << endl;

	return 0;
}