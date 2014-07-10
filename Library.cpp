#include <fstream>
#include <string>
#include "Library.h"
#include "StringTokenizer.h"
#include "HelperFunctions.h"
using namespace std;

void Library::ReturnToLibrary(Periodical& p, Employee& e)
{

}

void Library::ExchangePeriodical(Periodical& p, Employee& e1, Employee& e2)
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
			circulatingPeriodicals[aBarCode] = Periodical(aName);
		}
	}
}

void ReadEmployeesFromFile()
{
	ifstream fin("Employees.txt");
	if (fin)
	{
		string line, aName, startVacation, endVacation;
		int theReliability, theWaitingTime;

		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			aName = trim(st.next_token());
			theReliability = stoi(trim(st.next_token()));
			theWaitingTime = stoi(trim(st.next_token()));
			//String_Tokenizer stDate(line, "/");
			startVacation = trim(st.next_token());
			endVacation = trim(st.next_token());
			// put the employee into the vector
			employees. // why isn't it able to see the employee vector?
		}
	}
}

void Library::ArchivePeriodical(Periodical& p)
{

}

