/*
 * The Decoders
 * Joseph Murray
 * Jonathan Carreon
 * CIS 17A
 * Project 1B
 */

/*************************************************************************************
 * This program is to be used by a gym that needs to streamline their memberships.   *
 * It will allow users to choose from different membership and latter allow them     *
 * to add training sessions to their account.  They will also be able to add people  *
 * to their account.                                                                 *
*************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <stdlib.h> 

using namespace std;

// Global constants
/**********************************************************/

// Vector to hold months

vector<string> Months{ "Three Months",
					   "Six Months",
					   "Nine Months",
					   "Twelve Months" };

// Vector to hold activity

vector<string> Activity{ "Weight Training",
						 "Spinning",
						 "Yoga",
						 "Zumba",
						 "Crossfit" };

// Array to hold prices

double MemberPrices[4] = { 17.00, 15.00, 13.00, 11.00 };
double TrainingPrices[5] = { 4.00, 4.25, 4.50, 5.50, 6.75 };

// Variables for user choices

int trainingOption, Weeks, memberOption;
double FinalPrice;
char choice,
LockIn,
addTraining;

// Holds customer information

string custFirstName,
	   custLasttName,
	   custBirthMonth,
	   custBirthDay,
	   custBirtYear,
	   custEmail;

// Vector to hold days and times

vector<string> Days{ "Monday & Wednesday @ 09:00 AM",
					 "Monday & Wednesday @ 12:00 PM",
					 "Tuesday & Thursday @ 07:00 AM",
					 "Tuesday & Thursday @ 06:00 PM",
					 "Tuesday & Thursday @ 06:00 AM" };

double MemberCost;		// Holds membership cost
double TrainingCost;	// Holds training cost
const int NUM_EMP = 3;	// The number of products produced

// Arrays to hold employee data

int ValidEmpNum[NUM_EMP] = { 101, 102, 103 };
string ValidEmpName[NUM_EMP] = { "Jonathan Carreon", 
								 "Joseph Murray", 
								 "Kasey Nguyen" };

/**********************************************************/

// Function prototypes
/**********************************************************/

int EmployeeSearch(const int[], int, int);
void CustomerPortal();
void EmployeePortal();
void SelectionTableMembership();
void SelectionTableTraining();
void showMemTotal(int memberOption);
void TrainingOutput(int trainingOption, int Weeks);
void SummaryofServices();
void Receipt();
void employeeIDoutput(int employeeID);
void selectionSort(int[], int);
void swap(int &, int &);
void editMemberPrices();
void editTrainingPrices();
void SetDefaultMember();

/**********************************************************/

// Main Function

int main()
{
	char choice;

	// Introduction (DONE)

	cout << "\n Welcome to Visual Studios Fitness Club!\n\n";
	cout << " Are you a customer or employee?\n";
	cout << " (Enter \"1\" for customer or \"2\" for employee) ====> ";
	cin >> choice;
	if (choice == '1') // Customer Portal
		CustomerPortal();
	else if (choice == '2') // Employee Portal
		EmployeePortal();
}

// Employee Portal

void EmployeePortal()
{
	int EmpNum;
	int employeeOption;
	int index;
	int count = 0;
	bool validity = false;

	const int MemberPrices = 1,
		TrainingPrice = 2,
		MemberIDs = 3,
		Exit = 4;

	cout << "\n\n\tEMPLOYEE PORTAL\n";
	cout << "------------------------------\n\n";
	cout << " Enter employee number ====> ";
	cin >> EmpNum;
	index = EmployeeSearch(ValidEmpNum, NUM_EMP, EmpNum);

	// Display the results of the search

	if (index == -1)
	{
		do
		{
			cout << "\nSorry, that employee number was not found.\n";
			cout << " Please enter a valid employee number ====> ";
			cin >> EmpNum;
			index = EmployeeSearch(ValidEmpNum, NUM_EMP, EmpNum);
			if (index == -1)
			{
				count++;
				cout << endl << endl;
			}
			else
				validity = true;
			if (count == 2)
			{
				cout << "\t\t!!!EXCEEDED NUMBER OF INVALID TRIES. EXITING THE PROGRAM!!!\n\n";
				validity = true;
			}

		} while (validity == false);
	}

	if (index != -1)
	{
		cout << "\nHello " << ValidEmpName[index] << ".\n\n";
		cout << " What would you like to do?\n\n";
		cout << "\t1.  Update membership prices\n";
		cout << "\t2.  Update training prices\n";
		cout << "\t3.  Check registered IDs\n";
		cout << "\t4.  Exit program.\n";
		cout << "\n\t====> ";

		do
		{
			cin >> employeeOption;

			switch (employeeOption)
			{
			case MemberPrices:
				editMemberPrices();
				cout << " Keep up the good work and have a nice day!!!\n\n";
				break;
			case TrainingPrice:
				editTrainingPrices();
				cout << " Keep up the good work and have a nice day!!!\n\n";
				break;
			case MemberIDs:
				employeeIDoutput(employeeOption);
				cout << " Keep up the good work and have a nice day!!!\n\n";
				break;
			case Exit:
				main();
				cout << " Keep up the good work and have a nice day!!!\n\n";
				break;
			default:
				cout << " Sorry, " << employeeOption << " is not an option.\n";
				break;
			}
		} while (memberOption > 4);
	}
}

// Customer Portal

void CustomerPortal()
{
	// Constants for menu choices (DONE)

	const int Weight_Training = 1,
		Spinning = 2,
		Yoga = 3,
		Zumba = 4,
		Crossfit = 5;

	const int Three_Months = 1,
		Six_Months = 2,
		Nine_Months = 3,
		Twelve_Months = 4;

	// Gets user information and allows user to validate (DONE) - New

	cout << "\nYou have selected the \"Customer Option.\" Please enter the following information\n";

	do
	{
		cout << "\n\tFirst name ====> ";
		cin >> custFirstName;
		cout << "\tLast name ====> ";
		cin >> custLasttName;
		cout << "\tBirth month [i.e. Aug or August] ====> ";
		cin >> custBirthMonth;
		cout << "\t2 digit birth day ====> ";
		cin >> custBirthDay;
		cout << "\t4 digit birth year ====> ";
		cin >> custBirtYear;
		cout << "\tValid email ====> ";
		cin >> custEmail;

		cout << "\nIs the information on the screen correct?\n\n"
			<< "\tName: " << custFirstName << " " << custLasttName << endl
			<< "\tDate of birth: " << custBirthMonth << " " << custBirthDay
			<< ", " << custBirtYear << endl << "\tEmail: " << custEmail;
		cout << "\n\nType \"Y\" for yes of \"N\" for no and press [ENTER]. ====> ";
		cin >> choice;

	} while (choice == 'n' || choice == 'N');

	cout << endl << "\n\nHello " << custFirstName
		<< ", please select from the list of membership packages below\n";

	SelectionTableMembership();

	// Swtich statement to allow for user selection (DONE)

	do
	{
		cout << "What membership would you like to have [1-4] ====> ";
		cin >> memberOption;

		switch (memberOption)
		{
		case Three_Months:
			--memberOption;
			showMemTotal(memberOption);
			break;
		case Six_Months:
			--memberOption;
			showMemTotal(memberOption);
			break;
		case Nine_Months:
			--memberOption;
			showMemTotal(memberOption);
			break;
		case Twelve_Months:
			--memberOption;
			showMemTotal(memberOption);
			break;
		default:
			cout << "Sorry, " << memberOption << " is not an option.\n";
			break;
		}
	} while (memberOption > 3);

	// Allow user to select a training program

	cout << "Would you like to add training: (Type 'Y' for yes and 'N' for no.) ====>  ";
	cin >> addTraining;

	if (addTraining == 'y' || addTraining == 'Y')
	{
		// Displays the selection table 

		SelectionTableTraining();

		// Allows user to choose training session

		cout << "\n\n----------------------------------------------------------------------\n\n";
		cout << "Which training session would you like to add to your account [1-5] ====> ";
		cin >> trainingOption;

		if (trainingOption > 0)
		{
			do
			{
				if (trainingOption < 6)
				{
					cout << "How many weeks would you like to purchase ====> ";
					cin >> Weeks;

					switch (trainingOption)
					{
					case Weight_Training:
						--trainingOption;
						TrainingOutput(trainingOption, Weeks);
						break;
					case Spinning:
						--trainingOption;
						TrainingOutput(trainingOption, Weeks);
						break;
					case Yoga:
						--trainingOption;
						TrainingOutput(trainingOption, Weeks);
						break;
					case Zumba:
						--trainingOption;
						TrainingOutput(trainingOption, Weeks);
						break;
					case Crossfit:
						--trainingOption;
						TrainingOutput(trainingOption, Weeks);
						break;
					default:
						cout << "Sorry, " << trainingOption << " is not an option.\n";
						break;
					}

					cout << "Would you want to lock in this rate "
						<< "(Type 'Y' for yes and 'N' for no.) ====> ";
					cin >> LockIn;

					// Will allow user to lock in price to be added to membership price

					if (LockIn == 'n' || LockIn == 'N')
					{
						cout << "Would you like to make another selection "
							<< "(Type 'Y' for yes and 'N' for no.) ====>  ";
						cin >> choice;
						if (choice == 'Y' || choice == 'y')
						{
							cout << "Which training session would you like to "
								<< "add to your account [1-5] ====> ";
							cin >> trainingOption;
						}
					}
					else
					{
						cout << "Type the letter M and press [ENTER] to go back to the main menu. "
							<< " ====> ";
						cin >> choice;
					}
				}

				// Will display error message selection is out of range

				else
				{
					cout << "Sorry " << trainingOption << " is not an available choice.\n";
					cout << "Would you like to make another choice "
						<< "(Type 'Y' for yes and 'N' for no.) ====> ";
					cin >> choice;
					if (choice == 'Y' || choice == 'y')
					{
						cout << "Which training session would you like to "
							<< "add to your account [1-5] ====> ";
						cin >> trainingOption;
					}
				}

			} while (choice == 'Y' || choice == 'y');
		}
	}

	// Adds membership price to training cost for a final total (DONE)

	FinalPrice = MemberCost + TrainingCost;

	// Summary of selections

	cout << "Here are details of services you have selected\n\n";

	SummaryofServices();

	// Output to receipt (DONE)

	Receipt();

	cout << "\n\nHave a wonderful day."
		<< " Details have been outputted to a receipt.\n"
		<< "Thank you for choosing our Gym!\n\n";
}

// Displays Membership Options table

void SelectionTableMembership()
{
	int Counter = 1;
	const int SIZE = 4;

	cout << endl << setw(40) << "Membership Selection Menu\n\n";
	cout << setw(21) << "No. of Months" << setw(30) << "Prices (per month)\n";
	cout << setw(21) << "-------------";
	cout << setw(30) << "------------------\n";
	cout << fixed << showpoint << setprecision(2);

	for (int count = 0; count < SIZE; count++)
	{
		cout << left;
		cout << Counter++ << ".\t" << setw(18) << Months[count]
			<< right << setw(16) << *(MemberPrices + count) << endl;
	}

	cout << endl;
}

// Displays Training Options table

void SelectionTableTraining()
{
	int dayCounter = 1;
	const int SIZE = 5;

	cout << endl << endl << setw(60) << "Training Selection Menu\n\n";
	cout << setw(20) << "Activity" << setw(30) << "Day & Time" << setw(28) << "Price per week\n";
	cout << "\t---------------"
		<< setw(35) << "-----------------------------"
		<< setw(20) << "--------------\n";
	cout << fixed << showpoint << setprecision(2);

	for (int count = 0; count < SIZE; count++)
	{
		cout << left;
		cout << dayCounter++ << ".\t" << setw(18) << Activity[count]
			<< right << setw(32) << Days[count]
			<< right << setw(10) << "$" << *(TrainingPrices + count) << endl;
	}
	cout << "\n6.\t" << setw(18) << "Type \"-1\" to exit Training Selection Menu\n\n";
}

// Output chosen membership option

void showMemTotal(int memberOption)
{
	// Calculate the amount of Membership price times Months (Stub)

	MemberCost = MemberPrices[memberOption] * ((memberOption + 1) * 3);
	cout << "The showMemTotal function was called with "
		<< "the following argument:\n"
		<< "Total for Membership: " << MemberCost << "\n" << endl;
}

// Ouput chosen training option

void TrainingOutput(int trainingOption, int Weeks)
{
	// Calculate the cost of weeks chosen times price

	TrainingCost = Weeks * TrainingPrices[trainingOption];

	// Output to screen

	cout << "\n\t" << Activity[trainingOption]
		<< "\t" << Days[trainingOption]
		<< "\tRate: $" << TrainingPrices[trainingOption] << endl
		<< "\tWeeks: " << Weeks << endl << endl
		<< "\tFinal training cost: $" << TrainingCost
		<< endl << endl;
}

// Shows summary of services

void SummaryofServices()
{
	cout << fixed << setprecision(2) << showpoint;
	cout << "\tSummary of Services\n\n";
	cout << "\tMember Info: " << endl;
	cout << "\t\tName: " << custFirstName << " " << custLasttName << endl;
	cout << "\t\tDate of birth: " << custBirthMonth << " " << custBirthDay;
	cout << ", " << custBirtYear << endl << "\t\tEmail: " << custEmail;
	cout << "\n\tSubscription: " << Months[memberOption];
	cout << "\t$" << MemberPrices[memberOption] << " per month";

	// Will only print if training was added (DONE)

	if (addTraining == 'y' || addTraining == 'Y')
	{
		// Adds membership price to training cost for a final total (DONE)

		FinalPrice = MemberCost + TrainingCost;

		cout << "\n\tTraining Sessions: Y\n";
		cout << "\n\t" << Activity[trainingOption];
		cout << "\t" << Days[trainingOption];
		cout << "\tRate: $" << TrainingPrices[trainingOption] << endl;
		cout << "\tWeeks: " << Weeks << endl << endl;
		cout << "\tFinal training cost: $" << TrainingCost;
	}
	else
	{
		FinalPrice = MemberCost;
		cout << "\n\tTraining Sessions: N\n";
	}

	cout << "\n\tTotal cost of membership: $" << FinalPrice;
}

// Receipt output

void Receipt()
{
	ofstream outputFile;
	outputFile.open("CustomerReceipt.txt");

	// Generic output to file (DONE) - Updated

	outputFile << fixed << setprecision(2) << showpoint;
	outputFile << "\tSummary of Services\n\n";
	outputFile << "\tMember Info: " << endl;
	outputFile << "\t\tName: " << custFirstName << " " << custLasttName << endl;
	outputFile << "\t\tDate of birth: " << custBirthMonth << " " << custBirthDay;
	outputFile << ", " << custBirtYear << endl << "\t\tEmail: " << custEmail;
	outputFile << "\n\tSubscription: " << Months[memberOption];
	outputFile << "\t$" << MemberPrices[memberOption] << " per month";

	// Will only print if training was added (DONE)

	if (addTraining == 'y' || addTraining == 'Y')
	{
		// Adds membership price to training cost for a final total (DONE)

		FinalPrice = MemberCost + TrainingCost;

		outputFile << "\n\tTraining Sessions: Y\n";
		outputFile << "\n\t" << Activity[trainingOption];
		outputFile << "\t" << Days[trainingOption];
		outputFile << "\tRate: $" << TrainingPrices[trainingOption] << endl;
		outputFile << "\tWeeks: " << Weeks << endl << endl;
		outputFile << "\tFinal training cost: $" << TrainingCost;
	}
	else
	{
		FinalPrice = MemberCost;
		outputFile << "\n\tTraining Sessions: N\n";
	}

	outputFile << "\n\tTotal cost of membership: $" << FinalPrice;
	outputFile << "\n\n\tEnjoy working out here at the Gym.";

	// Close the file (DONE)

	outputFile.close();
}

// Searches employee via employee ID

int EmployeeSearch(const int array[], int numElems, int value)
{
	int first = 0,			 // First array element
		last = numElems - 1, // Last array element
		middle,				 // Midpoint of search
		position = -1;		 // Position of search value
	bool found = false;		 // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;  // Calculate midpoint
		if (array[middle] == value)	  // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half
	}
	return position;
}

// Output of option 3 under 'Employee' choice

void employeeIDoutput(int employeeID)
{
	const int NUM_EMP = 3;

	int ValidEmpNum[NUM_EMP] = { 101, 103, 102 };

	selectionSort(ValidEmpNum, NUM_EMP);

	cout << " Sorted employee IDs\n";
	cout << " -------------------\n\n";
	for (auto element : ValidEmpNum)
		cout << element << " ";
	cout << endl << endl;
}

// Sorts employee IDs

void selectionSort(int array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

// Swaps a and b in memory

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Displays arrays with Member Prices in function editMemberPrices

void DisplayMemberArray()
{
	cout << "\n\tArray\t    = Prices\n";
	cout << "\t-------------------\n\n";

	for (int i = 0; i < 4; i++)
		cout << "\tArray [ " << i << " ] = $" << setprecision(2) << fixed 
			 << MemberPrices[i] << endl;
}

// Displays arrays with Trainer Prices in function editTrainingPrices

void DisplayTrainingArray()
{
	cout << "\n\tArray\t    = Prices\n";
	cout << "\t-------------------\n\n";

	for (int i = 0; i < 5; i++)
		cout << "\tArray [ " << i << " ] = $" << setprecision(2) << fixed
		<< TrainingPrices[i] << endl;
}

// Contains default Member Prices

void SetDefaultMember()
{
	double MemberPrices[4] = { 17.00, 15.00, 13.00, 11.00 };
}

// Contains default Trainer Prices

void SetDefaultTrainer()
{
	double TrainingPrices[5] = { 4.00, 4.25, 4.50, 5.50, 6.75 };
}

// Updates the Member Prices

void UpdateMember()
{
	DisplayMemberArray();

	cout << "\n Enter Index Number to Update Value :";
	int index;
	cin >> index;

	if (index > 3 || index < 0)
	{
		cout << "\n ERROR! Invalid Index Entered ----> Valid Range(0-3)\n\n";
		UpdateMember();// Recall The Function it self
	}
	else
	{
		cout << "\n Enter the New Value For Index array[ " << index << " ] = ";
		cin >> MemberPrices[index];
		cout << "\n Array Updated!\n\n";
	}
}

// Updates the Trainer Prices

void UpdateTrainer()
{
	int index;
	
	cout << "\n Enter Index Number to Update Value ====> ";	
	cin >> index;

	if (index > 4 || index < 0)
	{
		cout << "\n ERROR! Invalid Index Entered ----> Valid Range(0 - 4)\n\n";
		UpdateTrainer();// Recall The Function it self
	}
	else
	{
		cout << "\n Enter the New Value For Index array[ " << index << " ] ====> ";
		cin >> TrainingPrices[index];
		cout << "\n Array Updated\n\n";
	}
}

// Displays new Member Prices

void editMemberPrices()
{
	char option;

	do
	{
		SetDefaultMember();
		UpdateMember();

		cout << "\n Updated Array:\n\n";

		DisplayMemberArray();

		cout << "\n\n Would you like to make more changes to this array? 'Y' or 'N' ====> ";
		cin >> option;
	} while (option == 'Y' || option == 'y');
}

// Displays new Trainer Prices

void editTrainingPrices()
{
	char option;

	do
	{
		SetDefaultTrainer();
		UpdateTrainer();

		cout << "\n Updated Array\n\n";

		DisplayTrainingArray();


		cout << "\n\n Would you like to make more changes to this array? 'Y' or 'N' ====> ";
		cin >> option;
	} while (option == 'Y' || option == 'y');
}