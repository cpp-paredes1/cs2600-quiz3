#include <string.h>
#include "Employee.h"

// function detaiils
// return PtrToEmployee
// args:
//	- ptrtoconstemployee -- pointer to the employee
//	- int -- size of table
//	- char * -- phone number to search for (string)
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char * phoneNumber){

	// specify address of the end of the table
	const PtrToConstEmployee endPtr = ptr + tableSize;
	// increment thru table of employees
	for(; ptr < endPtr; ptr++){
		// if the phone # is equal to the target phone #
		if(strcmp(ptr->phone,phoneNumber) == 0){
			// return reference to the employee
			return (PtrToEmployee) ptr;
		}
	}
	// return nothing if not fount
	return NULL;
}
// function details
// same as above
// last arg is a double which represents the target salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){
	PtrToConstEmployee endPtr = ptr + tableSize;
	for(; ptr < endPtr; ptr++){
		if(ptr->salary == targetSalary){
			return (PtrToEmployee) ptr;
		}
	}
	return NULL;
}