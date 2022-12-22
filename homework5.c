//Nikole Solano
//"Homework 5" homework5.c
//COP3223C Section 1, Fall 2020

#include <stdio.h>
#include <string.h>
#define MAX_PAY_RECS_NO 10000 

//this was given
struct payroll {
unsigned long long int internal_id;
char first_name[50];
char last_name[50];
char department[100];
unsigned char dob_day;
unsigned char dob_month;
unsigned short dob_year;
double monthly_salary;
}; 

size_t pay_recs_no; 
struct payroll pay_recs[MAX_PAY_RECS_NO]; 

//this is going to print out all the employees in the department we specify 
void PrintDeptPayrollRecords(char* dept_name)
{
    //if the department we entered and the departments in the structure match, the count is added by one
    int count = 0;
    for(int i = 0; i < pay_recs_no; i++)
    {
        if(strcmp(pay_recs[i].department, dept_name) == 0)
        {
            count++;
        }
    }
    //if there are no matches, the count is zero and the table is not printed
    if(count == 0)
    {
        printf("Department %s has no paroll records.\n", dept_name);
    }
    else
    {
        //these print statments will print out the chart
        printf("Employees of the %s department\n", dept_name);
        printf("Last Name \t First Name \t Date of Birth \t Monthly Salary\n");
        printf("-------------------------------------------------------------\n");
        //this iterates through the structure
        for(int i = 0; i < pay_recs_no; i++)
        {
            //if the strings are the same (a match) strcmp will output 0
            if(strcmp(pay_recs[i].department, dept_name)==0)
            {
                printf("%s \t %s \t %u-%u-%u \t %.2f \t \n", pay_recs[i].last_name, pay_recs[i].first_name, pay_recs[i].dob_year, pay_recs[i].dob_month,pay_recs[i].dob_day, pay_recs[i].monthly_salary);
            }
        }
    }

    //if the table is printed, then it calculates the total number of employees in the specified department
    if(count != 0)
    {
        int sum_employees = 0;
        //iterates through the structure
        for(int i = 0; i < pay_recs_no; i++)
        {
            //each time a line has a matching department to what we entered,
            //sum of employees gets added by 1
            if(strcmp(pay_recs[i].department, dept_name) == 0)
            {
                sum_employees++;
            }
        }
        //prints out the total number of employees in the department
        printf("Total Number of Employees in the Department: %d\n", sum_employees);
    }

    //if the table is printed, then it calculates the sum of the salaries of the employees in the specified department
    if(count != 0)
    {
        float sum_salary = 0;
        //iterates through the structure
        for(int i = 0; i < pay_recs_no; i++)
        {
            //if the string matches it will output 0
            if(strcmp(pay_recs[i].department, dept_name)==0)
            {
                //this will add the salary to sum_salary each time there is a match in the structure
                sum_salary+=pay_recs[i].monthly_salary;
            }
        }
        //prints salary sum to two decimal digits
        printf("Aggregated Salary of the Department: %.2f\n", sum_salary);
    }
}


void SaveDeptPayrollRecordsToFile(char* dept_name, char* file_name)
{
    //opening the file
    FILE* file_ptr = fopen(file_name, "w");
    if(file_ptr == NULL)
        return;
  
    //working with the file
    int count = 0;
    for(int i = 0; i < pay_recs_no; i++)
    {
        if(strcmp(pay_recs[i].department, dept_name) == 0)
            {
                count++;
            }
    }

    if(count == 0)
    {
        fprintf(file_ptr,"Department %s has no paroll records.\n", dept_name);
    }
    else
    {
        fprintf(file_ptr,"Employees of the %s department\n", dept_name);
        fprintf(file_ptr,"Last Name \t First Name \t Date of Birth \t Monthly Salary\n");
        fprintf(file_ptr,"-------------------------------------------------------------\n");
        for(int i = 0; i < pay_recs_no; i++)
        {
            if(strcmp(pay_recs[i].department, dept_name)==0)
            {
                fprintf(file_ptr,"%s \t %s \t %u-%u-%u \t %.2f \t \n", pay_recs[i].last_name, pay_recs[i].first_name, pay_recs[i].dob_year, pay_recs[i].dob_month,pay_recs[i].dob_day, pay_recs[i].monthly_salary);

            }
        }
    }

    if(count != 0)
    {
        int sum_employees = 0;
        for(int i = 0; i < pay_recs_no; i++)
        {
            if(strcmp(pay_recs[i].department, dept_name) == 0)
            {
                sum_employees++;
            }
        }
        fprintf(file_ptr,"Total Number of Employees in the Department: %d\n", sum_employees);
    }

    if(count != 0)
    {
        float sum_salary = 0;
        for(int i = 0; i < pay_recs_no; i++)
        {
            if(strcmp(pay_recs[i].department, dept_name) == 0)
            {
                sum_salary += pay_recs[i].monthly_salary;
            }
        }
        fprintf(file_ptr,"Aggregated Salary of the Department: %.2f\n", sum_salary);
    }
 
    //closing the file
    fclose(file_ptr);
    return;
}

int main(void) 
{
  
    struct payroll r1= {111, "Nikole", "Solano", "Production", 17, 02, 2002, 7500.00};
    pay_recs[0]=r1;
    struct payroll r2={112, "Teresa", "Brodman", "Production", 19, 07, 2001, 7500.00};
    pay_recs[1]=r2;
    struct payroll r3={113, "Stefan", "Michura","R&D", 25, 02, 2002, 7600.00};
    pay_recs[2]=r3;
    struct payroll r4={114, "Abby", "McGrath", "R&D", 13, 02, 2002, 7600.00};
    pay_recs[3]=r4;
    struct payroll r5={115, "Grace", "Buckley","Purchasing", 30, 04, 2002, 7400.00};
    pay_recs[4]=r5;
    struct payroll r6={116, "Olivia", "Jimeno", "Purchasing", 30, 11, 2001, 7400.00};
    pay_recs[5]=r5;
    struct payroll r7={117, "Michelle", "Fanelli", "HR", 24, 10, 2001, 7500.00};
    pay_recs[6]=r7;
    struct payroll r8={118, "Courtney", "Lee", "HR", 13,  04, 1998, 7500.00};
    pay_recs[7]=r8;
    struct payroll r9={119, "Claire", "Montgomery", "Accounting", 04, 12, 1997, 7300.00};
    pay_recs[8]=r9;
    struct payroll r10={120, "Ariana", "Solano", "Accounting", 28, 01 ,1998, 7300.00};
    pay_recs[9]=r10;
  
    pay_recs_no=10;
    PrintDeptPayrollRecords("Production");

    char* file_name;
    printf("Enter the file name of the file for storing the payroll records in: ");
    scanf("%s", file_name);
    SaveDeptPayrollRecordsToFile("Production", file_name);

    return 0;
}
