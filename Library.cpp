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

void Library::ReadFromFile()
{
	
	ifstream fin("periodicals.txt");
	if (fin)
	{
		Periodical temp; // still need to fix this
		
		string line;
		string aName;
		string aBarCode;
		
		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			aName = trim("Hello world");
			aBarCode = stoi(trim(st.next_token()));
		}
		
	}
	
}

void Library::ArchivePeriodical(Periodical& p)
{

}