/*
Employee class header
*/

#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <string>
#include <iostream>
#include <vector>
#include "Periodical.h"
#include "Date.h"
using namespace std;

class Employee {
public:
    //default constructor
    Employee(): reliability(), empname(), vacationStart(Date()), vacationEnd(Date()), waiting_time() {}
    
	/*
    //full-argument constructor
    Employee(int aPriority, int aReliability, string aName, Date aVacStart, Date aVacEnd, int aWaitTime) :
        priority(aPriority), reliability(aReliability), empname(aName), vacationStart(aVacStart),
        vacationEnd(aVacEnd), waiting_time(aWaitTime) {}
	*/

	Employee(int aReliability, string aName, Date aVacStart, Date aVacEnd, int aWaitTime) 
		: reliability(aReliability), empname(aName), vacationStart(aVacStart), vacationEnd(aVacEnd), waiting_time(aWaitTime){}

    //copy constructor
    Employee(const Employee& e) : reliability(e.reliability), empname(e.empname), 
        vacationStart(e.vacationStart), vacationEnd(e.vacationEnd), waiting_time(e.waiting_time) {}


    void setReliability(const int& r) {reliability = r;}
    void setVacationStart(const Date& d) {vacationStart = d;}
    void setVacationEnd(const Date& d) {vacationEnd = d;}
    void setWaitingTime(const int& t) {waiting_time = t;}
    void addBookToList(const int& b) {BookListByID.push_back(b);}

    //getters
    Date getVacationStart() const {return vacationStart;}
    Date getVacationEnd() const {return vacationEnd;}
    int getReliability() const {return reliability;}
    string getEmpname() const {return empname;}
    int getWaitingTime() const {return waiting_time;}
    
private:
    string empname;
    int reliability;
    Date vacationStart;
    Date vacationEnd;
    vector<int> BookListByID;
    int waiting_time; // # of days
};

#endif