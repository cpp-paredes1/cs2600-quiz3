//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

 

#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 

int main(void){ 

    //defined in employeeSearchOne.c 

    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 

    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 

    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneToFind);

    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
 

    //defined in employeeTable.c 

    extern Employee EmployeeTable[];     

    extern const int EmployeeTableEntries;      

 

    PtrToEmployee matchPtr;  //Declaration 

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

 

    //Example not found 

    if (matchPtr != NULL) 

        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee ID is NOT found in the record\n"); 

 

    //Example found 

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if (matchPtr != NULL) 

        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 

    else 

        printf("Employee Tony Bobcat is NOT found in the record\n"); 

    

    // TESTING EmployeeSearch.c
    // Test 1
    // Expected: pointer to Employee Dorris Perl
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if(matchPtr != NULL){
        printf("Found Employee %s, with phone number %s.", matchPtr->name, matchPtr->phone);
    } else {
        printf("Test 1: employee not found.");
    }
    
    // Test 2
    // Expected: NULL
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "111-111-1201");
    if(matchPtr != NULL){
        printf("Found Employee %s, with phone number %s.", matchPtr->name, matchPtr->phone);
    } else {
        printf("Test 2: employee not found.");
    }

    // Test 3
    // Expected: pointer to Employee Tammy Franklin
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL){
        printf("Found Employee %s, with salary %s.", matchPtr->name, matchPtr->salary);
    } else {
        printf("Test 3: employee not found.");
    }

    // Test 4
    // Expected: NULL
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 12.12);
    if(matchPtr != NULL){
        printf("Found Employee %s, with salary %s.", matchPtr->name, matchPtr->salary);
    } else {
        printf("Test 3: employee not found.");
    }
    
    
    


    return EXIT_SUCCESS; 

} 