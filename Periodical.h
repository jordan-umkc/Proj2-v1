/*
Periodical class header
*/

#ifndef __PERIODICAL_H__
#define __PERIODICAL_H__
#include <map>
#include <queue>
#include "Date.h"
#include "Employee.h"

class Periodical {
public:
    //default constructor
    Periodical() : isCheckedOut(true), name(""), checkedOutDate(Date()), returnedDate(Date()), maxCheckoutDuration(7) {}
	/* these are the constructors that have a barCode variable
	Periodical(string aName, int aBarCode) 
		: isCheckedOut(), name(aName), barcode(aBarCode), checkedOutDate(), returnedDate(), maxCheckoutDuration() {}

    //full-argument constructor
	Periodical(bool checkedOut, std::string aName, int aBarcode, Date theOutDate, Date theReturnDate, int theMaxDur)
		: isCheckedOut(checkedOut), name(aName), barcode(aBarcode), checkedOutDate(theOutDate), returnedDate(theReturnDate), maxCheckoutDuration(theMaxDur) {}

    //copy constructor
    Periodical(const Periodical& p) : isCheckedOut(p.isCheckedOut), name(p.name), barcode(p.barcode), checkedOutDate(p.checkedOutDate),
        returnedDate(p.returnedDate), maxCheckoutDuration(p.maxCheckoutDuration) {}
	*/

	Periodical(string aName)
		: isCheckedOut(), name(aName), checkedOutDate(), returnedDate(), maxCheckoutDuration() {}

	//full-argument constructor
	Periodical(bool checkedOut, std::string aName, Date theOutDate, Date theReturnDate, int theMaxDur)
		: isCheckedOut(checkedOut), name(aName), checkedOutDate(theOutDate), returnedDate(theReturnDate), maxCheckoutDuration(theMaxDur) {}

	//copy constructor
	Periodical(const Periodical& p) : isCheckedOut(p.isCheckedOut), name(p.name), checkedOutDate(p.checkedOutDate),
		returnedDate(p.returnedDate), maxCheckoutDuration(p.maxCheckoutDuration) {}

    //setters
    void setCheckedBool(bool isItChecked) {isCheckedOut = isItChecked;}
    void setCheckedOutDate(Date& aDate) {checkedOutDate = aDate;}
    void setReturnedDate(Date& aDate) {returnedDate = aDate;}
    void setMaxCheckoutDur(int& dur) {maxCheckoutDuration = dur;}

    //getters
    Date getCheckedOutDate() const {return checkedOutDate;}
    Date getReturnedDate() const {return returnedDate;}
    string getName() const {return name;}
    //int getBarcode() const {return barcode;}

	void generateEmpQueue(map<string,Employee>&);

	struct EmployeeComparer{
		bool operator()(const Employee& emp1, const Employee& emp2){
			int emp1priority = emp1.getReliability() + emp1.getWaitingTime();
			int emp2priority = emp2.getReliability() + emp2.getWaitingTime();
			return emp1priority < emp2priority;
		}
	};
    
private:
	priority_queue<Employee,vector<Employee>,EmployeeComparer> empQueue;
	string name;
    //int barcode; // it doesn't make sense to have barcode variable because its already taken care of with the maps in library.cpp
    bool isCheckedOut;
    Date checkedOutDate;
    Date returnedDate;
    int maxCheckoutDuration;
};

#endif