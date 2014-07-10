#include "Library.h"
#include <fstream>
#include <string>

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
		Periodical temp; // stiil need to fix this
		string line;
		string aName;
		string aBarCode;
		while (getline(fin, line))
		{
			String_Tokenizer st(line, ",");
			aName = trim(st.next_token());
			aBarCode = stoi(trim(st.next_token(aBarCode)))// and this
		}
	}
}

/** Function to remove the leading and trailing spaces from a string */
string trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}

void Library::ArchivePeriodical(Periodical& p)
{

}