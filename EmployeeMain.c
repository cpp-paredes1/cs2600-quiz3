//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

 

#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 

int main(void){ 

    //defined in EmployeeSearch.c

    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneToFind);

    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
 

    //defined in employeeTable.c 

    extern Employee EmployeeTable[];     

    extern const int EmployeeTableEntries;      

 

    PtrToEmployee matchPtr;  //Declaration 

    // TESTING EmployeeSearch.c
    // Test 1
    // Expected: pointer to Employee Dorris Perl
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if(matchPtr != NULL){
        printf("Test 1: Found Employee %s, with phone number %s.\n", matchPtr->name, matchPtr->phone);
    } else {
        printf("Test 1: Employee not found.\n");
    }
    
    // Test 2
    // Expected: NULL
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "111-111-1201");
    if(matchPtr != NULL){
        printf("Found Employee %s, with phone number %s.\n", matchPtr->name, matchPtr->phone);
    } else {
        printf("Test 2: Employee not found.\n");
    }

    // Test 3
    // Expected: pointer to Employee Tammy Franklin
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL){
        printf("Test 3: Found Employee %s, with salary %f.\n", matchPtr->name, matchPtr->salary);
    } else {
        printf("Test 3: Employee not found.\n");
    }

    // Test 4
    // Expected: NULL
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 12.12);
    if(matchPtr != NULL){
        printf("Test 4: Found Employee %s, with salary %f.\n", matchPtr->name, matchPtr->salary);
    } else {
        printf("Test 4: Employee not found.\n");
    }
    
    return EXIT_SUCCESS; 

} 