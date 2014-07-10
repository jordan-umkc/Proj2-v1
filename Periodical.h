/*
Periodical class header
*/

#ifndef __PERIODICAL_H__
#define __PERIODICAL_H__
#include "Date.h"
#include "Employee.h"
#include <queue>


class Periodical {
    //default constructor
    Periodical() : isCheckedOut(), name(""), barcode(), checkedOutDate(), returnedDate(), maxCheckoutDuration(7) {}

	Periodical(string aName, int aBarCode) 
		: isCheckedOut(), name(aName), barcode(aBarCode), checkedOutDate(), returnedDate(), maxCheckoutDuration() {}

    //full-argument constructor
	Periodical(bool checkedOut, std::string aName, int aBarcode, Date theOutDate, Date theReturnDate, int theMaxDur)
		: isCheckedOut(checkedOut), name(aName), barcode(aBarcode), checkedOutDate(theOutDate), returnedDate(theReturnDate), maxCheckoutDuration(theMaxDur) {}

    //destructor
   // ~Periodical();

    //copy constructor
    Periodical(const Periodical& p) : isCheckedOut(p.isCheckedOut), name(p.name), barcode(p.barcode), checkedOutDate(p.checkedOutDate),
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
    int getBarcode() const {return barcode;}
    
    priority_queue<Employee> empQueue;
private:
    string name;
    int barcode;
    bool isCheckedOut;
    Date checkedOutDate;
    Date returnedDate;
    int maxCheckoutDuration;
};

#endif