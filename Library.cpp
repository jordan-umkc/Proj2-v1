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
	
	ifstream fin("periodicals.txt");
	if (fin)
	{
		string line, aName;
		int aBarCode;
		
		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			aName = trim(st.next_token());
			aBarCode = stoi(trim(st.next_token()));
			circulatingPeriodicals[aBarCode] = Periodical(aName,aBarCode);
		}
	}
}

void Library::ArchivePeriodical(Periodical& p)
{

}

