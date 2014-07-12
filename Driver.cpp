#include "Library.h"

#include <iostream>

int main()
{
	Library myLib;
	myLib.ReadPeriodicalsFromFile();
	myLib.ReadEmployeesFromFile();
	myLib.buildPriorityQueues();
	
	myLib.ReadActionsFromFile();




	/*
	Date currentDate = Date("7/11/2014");

	Date testDate = Date();
	cout << testDate.toString() << endl;

	if (testDate.getDay() < 1 || testDate.getDay() > 31)
	{
		cout << "Empty TestDate Found" << endl;
	}

	
	Periodical pTest;

	myLib.CirculatePeriodical(pTest);
 	myLib.ArchivePeriodical(pTest);
	myLib.removeCirculatingPeriodical(pTest);
	myLib.removeArchivedPeriodical(pTest);

	Employee eTest;
	myLib.checkoutPeriodical(pTest, eTest, currentDate);
	*/

	system("pause");

    return 0;
}
