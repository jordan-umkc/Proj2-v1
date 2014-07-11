/*
Library class header
*/

#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include "Periodical.h"
#include "Employee.h"
#include <map>
#include <vector>

class Library {
public:
    void ReturnToLibrary(Periodical& p, Employee& e, Date currentDate);
	void checkoutPeriodical(Periodical& p, Employee& e, Date currentDate);
	void ExchangePeriodical(Periodical& p, Employee& e1, Employee& e2, Date currentDate);
    void ReadPeriodicalsFromFile();
	void ReadEmployeesFromFile();
	void ReadActionsFromFile();
	void buildPriorityQueues();
    void ArchivePeriodical(Periodical& p);
	void removeArchivedPeriodical(Periodical& p);
	void CirculatePeriodical(Periodical& p);
	void removeCirculatingPeriodical(Periodical& p);
	
private:
    map<int,Periodical> archivedPeriodicals;
    map<int,Periodical> circulatingPeriodicals;
	map<string,Employee> employees;
};

#endif