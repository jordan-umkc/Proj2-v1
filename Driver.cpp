#include "Library.h"

int main()
{
	Library myLib;
	myLib.ReadPeriodicalsFromFile();
	myLib.ReadEmployeesFromFile();
	myLib.buildPriorityQueues();
	
	Date currentDate = Date("7/11/2014");

	Periodical pTest;

	myLib.CirculatePeriodical(pTest);
 	myLib.ArchivePeriodical(pTest);
	myLib.removeCirculatingPeriodical(pTest);
	myLib.removeArchivedPeriodical(pTest);

	Employee eTest;
	myLib.checkoutPeriodical(pTest, eTest, currentDate);




    return 0;
}
