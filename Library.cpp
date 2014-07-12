#include <fstream>
#include <string>
#include "Library.h"
#include "StringTokenizer.h"
#include "HelperFunctions.h"
using namespace std;

void Library::ReturnToLibrary(Periodical& p, Employee& e, Date currentDate)
{

}

void Library::checkoutPeriodical(Periodical& p, Employee& e, Date currentDate) // Evan
{
	if (p.getCheckOutStatus() == true)
		throw::exception("the periodical you want is currently checked out");

	p.setCheckOutDate(currentDate);
	p.setReturnDate();
	p.setCheckedBool(true);
	e.addBookToList(p.getBarcode());

	removeArchivedPeriodical(p);
	CirculatePeriodical(p);
}

void Library::ExchangePeriodical(Periodical& p, Employee& e1, Employee& e2, Date currentDate)
{

}

void Library::ReadPeriodicalsFromFile()
{
	
	ifstream fin("Periodicals.txt");
	if (fin)
	{
		string line, aName;
		int aBarCode;
		

		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			aName = trim(st.next_token());
			aBarCode = stoi(trim(st.next_token()));
			archivedPeriodicals[aBarCode] = Periodical(aName, aBarCode);
		}
	}
	fin.close();
}

void Library::ReadEmployeesFromFile()
{
	ifstream fin("Employees.txt");
	if (fin)
	{
		string line, empName, startVacation, endVacation;
		int theReliability, theWaitingTime;
		
		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			empName = trim(st.next_token());
			theReliability = stoi(trim(st.next_token()));
			theWaitingTime = stoi(trim(st.next_token()));
			startVacation = trim(st.next_token());
			endVacation = trim(st.next_token());
			employees[empName] = Employee(theReliability, empName, Date(startVacation), Date(endVacation), theWaitingTime);
		}
	}
	fin.close();
}
// Returns Date of next batch of actions
// if end of file has been reached return empty Date
Date Library::ReadActionsFromFile() // Evan
{
	ifstream fin("Actions.txt");
	if (fin)
	{ 
		string line, empName1,  currentDate, test;
		int aBarcode, action;

		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			test = trim(st.next_token());
			// determine if what was read in was a name or a date
			if (test.find("/"))
			{
				currentDate = test;
				getline(fin, line);
				empName1 = trim(st.next_token());
			}
				
			else
				empName1 = test;

			action = stoi(trim(st.next_token()));
			aBarcode = stoi(trim(st.next_token()));

			switch (action)
			{
			case 1: // checkout periodical
				checkoutPeriodical(archivedPeriodicals[aBarcode], employees[empName1], currentDate);
				break;
			case 2: // return periodical
				ReturnToLibrary(circulatingPeriodicals[aBarcode], employees[empName1], currentDate);
				break;
			case 3: // give periodical to another employee
			{
				string empName2;
				empName2 = trim(st.next_token());
				ExchangePeriodical(circulatingPeriodicals[aBarcode], employees[empName1], employees[empName2], currentDate);
			}
				break;
			default:
				throw::exception("Invalid action call from file");
				break;
			}
		}
	}
	fin.close();
}

void Library::buildPriorityQueues(){

	for (map<int, Periodical>::iterator itr = circulatingPeriodicals.begin(); itr != circulatingPeriodicals.end(); itr++){
		itr->second.generateEmpQueue(employees);
	}
}

void Library::ArchivePeriodical(Periodical& p) // Evan
{
	map<int, Periodical>::iterator iter = archivedPeriodicals.begin();
	archivedPeriodicals.insert(iter, pair <int, Periodical>(p.getBarcode(), p));
}

void Library::removeArchivedPeriodical(Periodical& p) // Evan
{
	archivedPeriodicals.erase(p.getBarcode());
}

void Library::CirculatePeriodical(Periodical& p) // Evan
{
	map<int, Periodical>::iterator iter = circulatingPeriodicals.begin();
	circulatingPeriodicals.insert(iter, pair <int, Periodical>(p.getBarcode(), p));
}

void Library::removeCirculatingPeriodical(Periodical& p) // Evan
{
	circulatingPeriodicals.erase(p.getBarcode());
}