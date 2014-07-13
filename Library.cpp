#include <fstream>
#include <string>
#include "Library.h"
#include "StringTokenizer.h"
#include "HelperFunctions.h"
using namespace std;

void Library::ReturnToLibrary(Periodical& p, Employee& e, Date currentDate)
{//Jordan
	p.setCheckedBool(false);
	e.removeBookFromList(p.getBarcode());
    UpdateEmployeeReliability(e, p, currentDate);

	if (!p.empQueue.empty())
	{
		checkoutPeriodical(p, p.empQueue.top(), currentDate);
	}
    else
    {
        ArchivePeriodical(p);
    }

}

void Library::UpdateEmployeeReliability(Employee& e, Periodical& p, Date& currentDate)
{//Jordan
    if (currentDate > p.getReturnDate())
	{
		e.setReliability(e.getReliability() + (currentDate - p.getReturnDate()));
	}
	else
	{
		e.setReliability(e.getReliability() - (currentDate - p.getReturnDate()));
        if (e.getReliability() < 0)
        {
            e.setReliability(0);
        }
	}
}

void Library::checkoutPeriodical(Periodical& p, Employee& e, Date currentDate) // Jordan
{
	if (p.getCheckOutStatus() == true)
	{
		p.empQueue.push(e);
		return;
	}
	map<int,Employee> popMap = UpdateQueue(p, currentDate);
    if (!popMap.empty())
    {
        p.empQueue.top().addBookToList(p.getBarcode());
        int dayswaiting = currentDate - p.getReturnDate();
        p.empQueue.top().setWaitingTime(p.empQueue.top().getWaitingTime() + dayswaiting);
        p.empQueue.pop();
        for (int i = 0; i < popMap.size(); i ++)
        {
            p.empQueue.push(popMap.begin()->second);
            popMap.erase(popMap.begin());
        }
        return;
    }
	p.setCheckOutDate(currentDate);
	p.setReturnDate();
	p.setCheckedBool(true);
	e.addBookToList(p.getBarcode());
	removeArchivedPeriodical(p);
	CirculatePeriodical(p);


	/*
	if (p.getCheckOutStatus() == true)
		throw::exception("the periodical you want is currently checked out");
    if (p.empQueue.empty())
    {
		if (currentDate > e.getVacationEnd() || currentDate < e.getVacationStart())
		{
			p.setCheckOutDate(currentDate);
			p.setReturnDate();
			p.setCheckedBool(true);
			e.addBookToList(p.getBarcode());
			Periodical temp = Periodical(p);
			removeArchivedPeriodical(p);
		}
		else
		{
			p.empQueue.push(e);
		}
    }
	*/
}

void Library::ExchangePeriodical(Periodical& p, Employee& e1, Date currentDate)
{//Jordan
	e1.removeBookFromList(p.getBarcode());
    UpdateEmployeeReliability(e1, p, currentDate);
	map<int,Employee> popMap = UpdateQueue(p, currentDate);
    if (!popMap.empty())
    {
        p.empQueue.top().addBookToList(p.getBarcode());
        p.empQueue.pop();
        for (int i = 0; i < popMap.size(); i ++)
        {
            p.empQueue.push(popMap.begin()->second);
            popMap.erase(popMap.begin());
        }
        return;
    }
}

//returns a map of the pops required until we find an employee NOT on vacation
map <int,Employee> Library::UpdateQueue(Periodical& p, Date currentDate)
{//Jordan
    //checks if emp at top of queue is not on vacation. if he/she is on vacation we check the rest of the list
    bool checkDate = (currentDate <= p.empQueue.top().getVacationEnd() || currentDate >= p.empQueue.top().getVacationEnd());
    map <int,Employee> popMap;
    if (checkDate)
    {
        //employee is not on vacation. keep at top of queue
        return popMap;
    }
    else
    {
        
        int numPops = 0;
        while (!p.empQueue.empty() && !checkDate)
        {
            popMap[numPops] = p.empQueue.top();
            p.empQueue.pop(); 
            if (p.empQueue.empty())
            {
                //all employees in queue are on vacation. we will return to archive now
                ArchivePeriodical(p);
                removeCirculatingPeriodical(p);
                popMap.clear();
                return popMap;
            }
            numPops++;
        }
        //returns map of items popped. item at top of queue is item to be affected (not on vacation)
        return popMap;
    }
}

void Library::ReadPeriodicalsFromFile()
{//Evan w/ Brenton debug

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
{//Evan w/ Brenton debug
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
			employees[empName] = Employee(theReliability, empName, Date(startVacation, DateFormat::US), Date(endVacation, DateFormat::US), theWaitingTime);
		}
	}
	fin.close();
}
// Returns Date of next batch of actions
// if end of file has been reached return empty Date
void Library::ReadActionsFromFile() // Evan
{
	ifstream fin("Actions.txt");
	if (fin)
	{
		string line, empName1, currentDate;
		int aBarcode, action;

		getline(fin, currentDate);

		while (getline(fin, line)) 
            if (!line.empty())
            {
		{
			String_Tokenizer st(line, ",");

			empName1 = trim(st.next_token());
			action = stoi(trim(st.next_token()));
			aBarcode = stoi(trim(st.next_token()));

			switch (action)
			{
			case 1: // checking out a periodical?
				break;
			case 2: // return periodical
				ReturnToLibrary(circulatingPeriodicals[aBarcode], employees[empName1], currentDate);
				break;
			case 3: // give periodical to another employee
			{
				string empName2;
				empName2 = trim(st.next_token());
				ExchangePeriodical(circulatingPeriodicals[aBarcode], employees[empName1], currentDate);
			}
				break;
			default:
				throw::exception("Invalid action call from file");
				break;
			}
		}
	}
    }
}

void Library::buildPriorityQueues(){
	//Brenton
    if (!circulatingPeriodicals.empty())
    {
        throw exception ("There are still items in the circulating periodical map.");
    }
	for (map<int, Periodical>::iterator itr = circulatingPeriodicals.begin(); itr != circulatingPeriodicals.end(); itr++){
		itr->second.generateEmpQueue(employees);
        CirculatePeriodical(itr->second);
        cout << "building priority queue for\t" << itr->second.getName() << endl;
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