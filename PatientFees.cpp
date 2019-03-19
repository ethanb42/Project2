#include <string>
#include <iostream>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
using namespace std;


int main() {
	//input variables
	char input;
	int in;
	int menu = 0;
	int loop = 0;
	//create a patient
	PatientAccount account;

	//default cost per day
	account.setDailyRate(500);

	//create surgery object
	Surgery surg(100.50, 1000.99, 1600, 2500.55, 5000);

	//create pharmacy object
	Pharmacy pharm(20.49, 30, 40, 50, 60);

	cout << "Welcome to Patient Fee Menu" << endl;
	cout << "The daily fee is $" << account.getDaily() << endl;	//surgery type

	//main menu
	while (menu == 0) {
		cout << "\n1. Enter Surgery\n2. Enter Medicine\n3. Check out patient\nInput:" << endl;
		cin >> input;
		switch (input) {
		case '1':
			//surgury sub menu
			cout << "\nPlease select which surgery!" << endl;
			surg.displaySurgery();
			do {
				cout << "Input:" << endl;
				cin >> input;
				switch (input) {
				case '1':
					surg.updateCharges(surg.getSurgery1(), account);
					loop = 1;
					break;
				case '2':
					surg.updateCharges(surg.getSurgery2(), account);
					loop = 1;
					break;
				case '3':
					surg.updateCharges(surg.getSurgery3(), account);
					loop = 1;
					break;
				case '4':
					surg.updateCharges(surg.getSurgery4(), account);
					loop = 1;
					break;
				case '5':
					surg.updateCharges(surg.getSurgery5(), account);
					loop = 1;
					break;
				default:
					cout << "Invalid input, try again!!\n" << endl;

				}

			} while (loop == 0);
			break;
		case '2':
			//pharmacy submenu
			loop = 0;
			//pharmacy drug type
			cout << "\nPlease select which medicine!" << endl;
			pharm.displayPharmacy();
			do {
				cout << "Input:" << endl;
				cin >> input;
				switch (input) {
				case '1':
					pharm.updatePatientAccount(pharm.getMed1(), account);
					loop = 1;
					break;
				case '2':
					pharm.updatePatientAccount(pharm.getMed2(), account);
					loop = 1;
					break;
				case '3':
					pharm.updatePatientAccount(pharm.getMed3(), account);
					loop = 1;
					break;
				case '4':
					pharm.updatePatientAccount(pharm.getMed4(), account);
					loop = 1;
					break;
				case '5':
					pharm.updatePatientAccount(pharm.getMed5(), account);
					loop = 1;
					break;
				default:
					cout << "Invalid input, try again!!\n" << endl;

				}

			} while (loop == 0);

			break;
		case '3':

			//check out menu
			//patients days
			do {
				cout << "Please enter the total days for patient." << endl;
				cin >> in;

			} while (in < 0);
			account.setDays(in);

			//add all the charges
			account.setCharges(account.getCharges() + account.getDays()*account.getDaily());

			//all charges added display the total

			cout << "The total charges: $" << account.getCharges() << endl;
			menu = 1;
			break;

		default:
			cout << "Invalid response....." << endl;
				break;
		}
	}



	return 0;
}
