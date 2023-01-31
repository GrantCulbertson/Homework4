#include <iostream>
using namespace std;
// Grant Culbertson , 11/30/2021. This program calculates a paycheck for an employee given their hours worked and # of dependents.
int main() {
cout.precision(2);
cout.setf(ios::fixed, ios::floatfield);
  //Intialize variable to start while loop
  char y = 'y';

  cout << "This program will ask you how many hours you worked, and calculate your taxes, dues, gross pay, and net pay. \n";
  //Intialize while loop so the program can be run multiple times without stopping and starting
  while (y == 'y'){
  //Intialize Pay Constants
  double otPayC = 25.02;
  double regPayC = 16.68;
  //Initalize all variables regarding hours worked
  double hoursWorked;
  double overtimeHours = 0.00;
  double totalHours;
  //Get user input for how many hours they worked
  cout <<"\nHow many hours did you work? ";
  cin >> hoursWorked;
  totalHours = hoursWorked;

  int dependents;
  //Get user input for how many dependents they have
  cout <<"How many dependents do you have? ";
  cin >> dependents;
  //If more than 40 hours are worked than overtimeHours is given an appropiate value (not zero)
  if(hoursWorked > 40){
    overtimeHours = hoursWorked - 40;
    hoursWorked = 40;
  }

  //Calculates all the parts that go into the final paycheck
  double regPay = hoursWorked * regPayC;
  double otPay = overtimeHours * otPayC;
  double grossPay = regPay + otPay;
  double socialSecurity = grossPay *.06;
  double federalIncomeTax = grossPay * .14;
  double stateIncomeTax = grossPay * .05;
  double unionDues = 10;
  double familyHealthInsurance = 35;

  //Adds the insurance premium if the user has 3 or more dependents
  if (dependents >= 3){
    familyHealthInsurance = 35;
  }

  //Calculates the final Paycheck and total deductions
  double totalPay = grossPay - socialSecurity - federalIncomeTax - stateIncomeTax - unionDues - familyHealthInsurance;
  double totalDeductions = grossPay - totalPay;
  //Prints all the info for the individual parts of the paycheck out
  cout << "\nRegular hours: " << hoursWorked << " (at $16.68 an hour)";
  cout << "\nOvertime hours: " << overtimeHours << " (at $25.02 an hour)";
  cout << "\nTotal Hours: " << totalHours;
  cout <<"\nGross pay is " << "$" << grossPay;
  cout<< "\nSocial Security tax: " << "$" << socialSecurity;
  cout<<"\nFederal taxes: " <<"$"<< federalIncomeTax;
  cout<<"\nState taxes: " << "$" <<stateIncomeTax;
  cout<<"\nUnion Dues: $" << unionDues;
  if(dependents >= 3){
    cout<<"\nFamily Health Insurance: $" << familyHealthInsurance << " (additional insurance premiums for your family)";
  }
  cout<<"\nTotal Deductions: $" << totalDeductions;

  //Checks if total pay is negative or positive. If positive it just prints net pay, if negative it gives the extra message.
  if(totalPay >=0){
      cout<<"\nNet Pay: $" << totalPay << ".";
  }
  if(totalPay <0){
    cout<<"\n\nYour dues and insurance obligations outstripped your pay by $" << totalPay;
  }

  cout<< "\n\nWould you like to calculate another week's pay? (y or n) ";
  cin>> y;


  }
cout<< "\nThank you for using this program.";





}