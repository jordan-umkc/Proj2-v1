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
	Periodical() : isCheckedOut(false), name(""), barcode(), checkOutDate(Date()), returnDate(Date()), maxCheckoutDuration(7) {}
	
	//two-argument constructor
	Periodical(string aName, int aBarCode)
		: isCheckedOut(false), name(aName), barcode(aBarCode), checkOutDate(Date()), returnDate(Date()), maxCheckoutDuration(7) {}

    //full-argument constructor
	Periodical(bool checkedOut, std::string aName, int aBarcode, Date theOutDate, Date theReturnDate, int theMaxDur)
		: isCheckedOut(checkedOut), name(aName), barcode(aBarcode), checkOutDate(theOutDate), maxCheckoutDuration(theMaxDur)
	{
		setReturnDate();
	}

    //copy constructor
    Periodical(const Periodical& p) : isCheckedOut(p.isCheckedOut), name(p.name), barcode(p.barcode), checkOutDate(p.checkOutDate),
        returnDate(p.returnDate), maxCheckoutDuration(p.maxCheckoutDuration) {}

    //setters
    void setCheckedBool(bool isItChecked) {isCheckedOut = isItChecked;}
    void setCheckOutDate(Date& aDate) {checkOutDate = aDate;}
	void setReturnDate()
	{
		Date temp = checkOutDate;
		temp.add_days(maxCheckoutDuration);
		returnDate = checkOutDate;
	}
    void setMaxCheckoutDur(int& dur) {maxCheckoutDuration = dur;}

    //getters
    Date getCheckedOutDate() const {return checkOutDate;}
    Date getReturnedDate() const {return returnDate;}
    string getName() const {return name;}
	bool getCheckOutStatus() { return isCheckedOut; }
    int getBarcode() const {return barcode;}

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
    int barcode;
    bool isCheckedOut;
    Date checkOutDate;
    Date returnDate;
    int maxCheckoutDuration;
};

#endif