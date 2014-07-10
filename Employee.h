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
    Employee(): priority(), reliability(), empname(""), vacationStart(), vacationEnd(), waiting_time() {}
    
    //full-argument constructor
    Employee(int aPriority, int aReliability, string aName, Date aVacStart, Date aVacEnd, int aWaitTime) :
        priority(aPriority), reliability(aReliability), empname(aName), vacationStart(aVacStart),
        vacationEnd(aVacEnd), waiting_time(aWaitTime) {}

    //copy constructor
    Employee(const Employee& e) : priority(e.priority), reliability(e.reliability), empname(e.empname), 
        vacationStart(e.vacationStart), vacationEnd(e.vacationEnd), waiting_time(e.waiting_time) {}


    //setters
    void setPriority(const int& p) {priority = p;}
    void setReliability(const int& r) {reliability = r;}
    void setVacationStart(const Date& d) {vacationStart = d;}
    void setVacationEnd(const Date& d) {vacationEnd = d;}
    void setWaitingTime(const int& t) {waiting_time = t;}
    void addBookToList(const int& b) {BookListByID.push_back(b);}

    //getters
    Date getVacationStart() const {return vacationStart;}
    Date getVacationEnd() const {return vacationEnd;}
    int getPriority() const {return priority;}
    int getReliability() const {return reliability;}
    string getEmpname() const {return empname;}
    int getWaitingTime() const {return waiting_time;}
    
    //overrided operators
    bool operator > (const Employee& rhs) { //PRIORITY QUEUE should automatically assess employees looking at their priorities
        return priority > rhs.priority;
    }

private:
    string empname;
    int priority;
    int reliability;
    Date vacationStart;
    Date vacationEnd;
    vector<int> BookListByID;
    int waiting_time;
};

#endif