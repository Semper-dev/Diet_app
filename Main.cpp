#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;



class person {

private:

	string lytis;
	double svoris;
	int amzius, aktyvumas, ugis, counter, baltymai, angliavandeniai, riebalai;
	int bmr; //Kaloriju kiekis per diena
	vector<vector<string>> food;

public:

	person()
	{
		cout << "Iveskite savo lyti (vyras ar moteris) :" << endl;
		cin >> this->lytis;
		cout << "Iveskite savo amziu (pvz. 35) :" << endl;
		cin >> this->amzius;
		cout << "Iveskite savo ugi centimetrais (pvz 182):" << endl;
		cin >> this->ugis;
		cout << "Iveskite savo svori (pvz 85):" << endl;
		cin >> this->svoris;
		cout << "Aktyvumo lygiai:" << endl;
		cout << "1. Mazas - maziau nei viena treniruote per savaite. " << endl;
		cout << "2. vidutinis - nuo 1 iki 3 treniruociu per savaite. " << endl;
		cout << "3. didelis - nuo 3 iki 5 treniruociu per savaite. " << endl;
		cout << "\nPasirinkite savo aktyvumo lygi (pvz 3): " << endl;
		cin >> this->aktyvumas;
		bmr = 0;
	}

	void reikalingosKalorijos()
	{
		double mazas = 1.2, vidutinis = 1.375, didelis = 1.55;
		string temp = "vyras";
		if (lytis.compare(temp) != 0) {
			bmr = 447.593 + (9.247 * svoris) + (3.098 * ugis) - (4.33 * amzius);
			if (aktyvumas == 1) { bmr *= mazas; }
			else { if (aktyvumas == 2) { bmr *= vidutinis; } else { bmr *= didelis; } }
		}
		else {
			bmr = 88.362 + (13.397 * svoris) + (4.799 * ugis) - (5.677 * amzius);
			if (aktyvumas == 1) { bmr *= mazas; }
			else { if (aktyvumas == 2) { bmr *= vidutinis; } else { bmr *= didelis; } }
		}
	}

	void show()
	{
		reikalingosKalorijos();
		cout << "Jums dienai reikalinga mazdaug " << bmr << " kaloriju." << endl;
	}

	void skirstymas()
	{
		reikalingosKalorijos();

		angliavandeniai = bmr * 55 / 100;
		riebalai = bmr * 30 / 100;
		baltymai = bmr * 15 / 100;

		cout << "Per diena jums reiketu suvartoti : " << endl
			<< "Angliavandeniu : " << angliavandeniai << endl
			<< "Riebalu : " << riebalai << endl
			<< "Baltymu : " << baltymai << endl;

	}
	void nuskaitymas()
	{
		string file_name = "test.txt";
		ifstream myFile(file_name);
		vector<string> tempVector;

		if (myFile.is_open())
		{
			for (int i = 0; i < 999; i++) {

				if (counter % 5 == 0 && counter != 0) {
					food.push_back(tempVector);
					for (int i = 0; i < 5; i++) {
						tempVector.pop_back();
					}
				}
				string l;
				myFile >> l;
				tempVector.push_back(l);
				if (myFile.eof()) {
					tempVector.pop_back();
					break;
				}
				counter++;
			}
		}
		else { cout << "Unable to open file"; }
		myFile.close();
	}

	void foodPerDay() {
		int number;
		int
			srand(time(NULL));
		vector<string> temp;

		for (int i = 0; i < 999; i++) {
			number = rand() % counter - 1;
			for (int k = 0; k < temp.size(); k++) {
				if (food[0][number].compare(temp[k])) {
					break;
				}
				else {
					if ()
				}
			}
			food[number][0];

		}

	}

};

int main()
{
	person user;
	//int choice;

	//user.show();
	//user.skirstymas();
	user.nuskaitymas();



	/*do {


		switch (choice)
		{
		default:
			break;
		}
	} while (choice != 0);*/


}