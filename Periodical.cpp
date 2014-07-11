#include "Periodical.h"

struct employeeComparer {
	bool operator()(const Employee& emp1, const Employee& emp2){
		return emp1.getReliability() + emp1.getWaitingTime() > emp2.getReliability() + emp2.getWaitingTime();
	}
};
/*
void Periodical::generateEmpQueue(){

}
*/