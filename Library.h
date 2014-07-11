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
    void ReturnToLibrary(Periodical& p, Employee& e);
    void ExchangePeriodical(Periodical& p, Employee& e1, Employee& e2);
    void ReadPeriodicalsFromFile();
	void ReadEmployeesFromFile();
    void ArchivePeriodical(Periodical& p);

private:
    map<int,Periodical> archivedPeriodicals;
    map<int,Periodical> circulatingPeriodicals;
	map<string,Employee> employees;
};

#endif