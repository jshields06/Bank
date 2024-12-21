//Given account number 123456, the user is able to access the bank and choose from options.
//The menu prompts the user to either withdraw, deposit, see balance, or exit.

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <conio.h> 
using namespace std;

//initialize variables
float accnum;
int cash;
int cash2;
int opt{};
string yesno;
string yesnoo;
string noyes;
string line;

void options() { // creates menu 
	cout << "PLEASE CHOOSE AN OPTION BELOW.\n\n";
	cout << "       " << "DIRECTORY       \n" << "       ---------\n";
	cout << "[1] WITHDRAW\n" << "[2] DEPOSIT\n" << "[3] SEE BALANCE\n" << "[4] EXIT\n";
	cin >> opt;
}

void withdraw() { // subtracts amount of cash inputted
	int negcash;
	int x;

	ifstream myfile;
	myfile.open("money.txt"); // opens file for reading
	getline(myfile, line); // reads file
	if (line == "0") {
		cout << "CANNONT WITHDRAW WHEN CURRENT BALANCE IS ZERO.\n\n"; // checks if 0
		goto end;
	}
	redraw:	cout << "HOW MUCH WOULD YOU LIKE TO WITHDRAW?: ";
	cin >> negcash; // get value
	cout << "\n";
	x = stoi(line);
	if (negcash > x) {
		cout << "NOT ENOUGH FUNDS. CURRENT FUNDS ARE: $" << line << "\n\n"; // checks if number is able to be subtracted
		goto redraw;
	}
	else {
		cash = x - negcash;
		ofstream myfile;
		myfile.open("money.txt", ios::out | ios::trunc); // opens file for writing
		myfile << cash;
		myfile.close(); // close file
		cout << "SUCCESSFULLY WITHDRAWN CASH. WOULD YOU LIKE TO CHOOSE ANOTHER OPTION? \n" // prompts user to either stay in menu or exit
			<< "Y OR N: ";
	yn: cin >> yesno;
		cout << "\n";
		while (true) {
			if (yesno == "Y")
			{
				break;

			}
			else if (yesno == "N") {
				exit(0);
			}
			else {
				cout << "\nPLEASE INPUT Y OR N: ";
				goto yn;
			}
		}
			
		
	}
	end: cout <<"";
}

void deposit() {
	int poscash;
	int y;
	ifstream myfile;
	myfile.open("money.txt"); // opens file for reading
	getline(myfile, line); // reads file
	y = stoi(line);
	cout << "HOW MUCH WOULD YOU LIKE TO DEPOSIT?: ";
	reposit: cin >> poscash;
	cout << "\n";
	cout << "IS THE AMOUNT $" << poscash << " CORRECT? (SELECT Y OR N): "; // verifies amount to deposit
		ny:cin >> noyes;


		if (noyes == "Y")
		{
			cash2 = poscash + y;
			myfile.close();
			ofstream myfile;
			myfile.open("money.txt", ios::out | ios::trunc); //opens file for writing
			myfile << cash2;
			cout << "DEPOSIT SUCCESSFUL. YOUR CURRENT BALANCE IS: $" << cash2 << "\n\n" // prompts user to stay in menu or exit
				<< "WOULD YOU LIKE TO CHOOSE ANOTHER OPTION? (SELECT Y OR N): ";
			myfile.close(); // closes file
		yn:	cin >> yesnoo;
			cout << "\n";
			while (true)
			{
				if (yesnoo == "Y")
				{

					break;

				}
				else if (yesnoo == "N") {
					exit(0);
				}
				else {
					cout << "\nPLEASE INPUT Y OR N: ";
					goto yn;
				}
			}
			
		}
		
		else if (noyes == "N") {
			cout << "PLEASE INPUT CORRECT AMOUNT TO DEPOSIT: "; // verifies correct amount and takes value
			goto reposit;
		}
		else {
			cout << "\nPLEASE INPUT Y OR N: ";
			goto ny;
		}
	

}


void account(float) {
	string line;
	ifstream myfile;

if (accnum == 123456) { // verifies account number is correct
		myfile.open("money.txt"); // opens file for reading
		
		if (getline(myfile, line))
		{
			cout << "YOUR CURRENT BALANCE IS $" << line << "." << '\n' << '\n'; // reads current value
			options(); // display menu
			myfile.close();
		}
		while (true) {
			if (opt == 1) {


				withdraw();
				options();
				

			}

			else if (opt == 2) {


				deposit();
				options();

			}

			else if (opt == 3) {
				myfile.open("money.txt"); // opens file for reading
				getline(myfile, line);
				cout << "YOUR CURRENT BALANCE IS $" << line << "." << '\n' << '\n'; // displays current value
				options();
				myfile.close(); // closes file

			}

			else if (opt == 4) {
				exit(0);
			}

			else if (opt != (1 | 2 | 3 | 4)) { // verifies numerical option in menu
				cout << "INVALID NUMBER. CHOOSE FROM DIRECTORY.\n\n ";
				cout << "       " << "DIRECTORY       \n" << "        ---------\n";
				cout << "[1] WITHDRAW\n" << "[2] DEPOSIT\n" << "[3] SEE BALANCE\n" << "[4] EXIT\n";
				cin >> opt;
			}

		}

	}
	else cout << "INVALID NUMBER. ";

}


int main() {
	cout << "WELCOME TO THE BANK! \n";
mylabel: cout << "PLEASE ENTER YOUR ACCOUNT NUMBER: "; // prompts user to input account number
	cin >> accnum;
	account(accnum);
	goto mylabel; // jumps to mylabel
}