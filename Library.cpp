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
		String_Tokenizer st(line, ",");
		while (getline(fin, line))
		{
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

void Library::ReadActionsFromFile() // Evan
{
	ifstream fin("Actions.txt");
	if (fin)
	{ 
		string line, empName1, empName2;
		int aBarcode, action;
		String_Tokenizer st(line, ",");
		Date currentDate = trim(st.next_token());
		while (getline(fin, line))
		{
			empName1 = trim(st.next_token());
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
			case 3: // give periodical to 
				empName2 = trim(st.next_token());
				ExchangePeriodical(circulatingPeriodicals[aBarcode], employees[empName1], employees[empName2], currentDate);
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