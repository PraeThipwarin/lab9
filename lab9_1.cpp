#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan,pers,PayM,PerS;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> pers;
	PerS = pers/100;
	cout << "Enter amount you can pay per year: ";
	cin >> PayM;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2);
	int year = 1;
	double PrvB = loan,IntR = loan*PerS,ToT =loan+IntR,NBl = loan+IntR-PayM;
	while (NBl != 0)
	{
		cout << setw(13) << left << year;
		cout << setw(13) << left << PrvB;
		cout << setw(13) << left << IntR;
		cout << setw(13) << left << ToT;
		if(PayM < ToT)
			cout << setw(13) << left << PayM;
		else if(PayM > ToT){
			PayM = ToT;
			cout << setw(13) << left << PayM;}
		else
			cout << "eror";
		if(PayM < ToT){
			NBl = ToT-PayM;
			cout << setw(13) << left << NBl;}
		else if(PayM == ToT){
			NBl = ToT-ToT;
			cout << setw(13) << left << NBl;}
		else
			cout << "eror";
		cout << "\n";
		year++;
		PrvB = PrvB+IntR-PayM;
		IntR = PrvB*PerS;
		ToT = PrvB + IntR;
	}
	return 0;
}
