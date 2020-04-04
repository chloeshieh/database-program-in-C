#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "readfile.h" 

//function prototype
// void display(struct employee *e){
//     int length = sizeof(e)/sizeof(e[0]);
//     printf("%d\n",length);
// }

int main(int argc, char *argv[]) 
{
    if (argc < 2){
        printf("Pass filename to read from...\n");
        return 0; 
    }
    char *fname = argv[1], name[MAXNAME], surname[MAXNAME];
    struct person employee[MAXNAME];
    int option, emp_id, key, salary, confirm; 

    int n_emp = 0, list[MAXEMP];;
    if(open_file(fname) == -1){
        printf("Error reading file");
        return -1;
    }
    FILE *fp = fopen(fname, "r");
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d\n", &employee[n_emp].id, &employee[n_emp].name, &employee[n_emp].surname, &employee[n_emp].salary);
        list[n_emp] = employee[n_emp].id;
        n_emp++;
    }
    fclose(fp);

    while(1){
        printf("**********************************\n");
        printf("Employee DB Menu:\n");
        printf("**********************************\n");
        printf(" (1) Print the Database\n");
        printf(" (2) Lookup by ID\n");
        printf(" (3) Lookup by Last Name\n");
        printf(" (4) Add an Employee\n");
        printf(" (5) Quit\n");
        printf("**********************************\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        if(option == 1){
            printf("----------------------------------------------\n");
            printf(" NAME                       SALARY      ID\n");
            printf("----------------------------------------------\n");
            for(int i=0; i<n_emp; i++)
                printf(" %-10s %-10s %10d %10d \n", employee[i].name, employee[i].surname, employee[i].salary, employee[i].id) ;
            printf("----------------------------------------------\n");
            //break;   
        }
        else if(option == 2){
            printf("Enter a 6 digit employee id: ");
            scanf(" %d", &emp_id);
            key = binary_search(list, 0, n_emp, emp_id);
            if(key == -1)
                printf("Employee with id %d not found in DB\n", emp_id);
            else
                print_by_key(employee, key);
            //break;
        }
        else if(option == 3){
            printf("Enter Employee's last name (no extra spaces): ");
            scanf(" %s", &surname);
            key = search_lname(employee, n_emp, surname);
            if(key == -1)
                printf("Employee with last name %s not found in DB\n", surname);
            else
                print_by_key(employee, key);
        }
        else if(option == 4){
            printf("Enter the first name of the employee: ");
            scanf("%s", name);
            printf("Enter the last name of the employee: ");
            scanf("%s", surname);
            printf("Enter employee's salary (30000 to 150000): ");
            scanf(" %d", &salary);
            printf("do you want to add the following employee to the DB? \n");
	        printf("%s %s, salary: %d \n",name, surname, salary);
            printf("Enter 1 for yes, 0 for no: ");
            scanf("%d", &confirm);
            if (confirm == 1){
                if((salary >= 30000) && (salary <= 150000)){
                    int cur_id = employee[n_emp-1].id;
                    int new_id = cur_id+1;
                    strcpy(employee[n_emp].name, name);
                    strcpy(employee[n_emp].surname, surname);
                    employee[n_emp].salary = salary;
                    employee[n_emp].id = new_id;
                    list[n_emp] = employee[n_emp].id;
                    n_emp++;
                } else {
                    printf("Salary range invalid. Please enter a value between 30000 and 150000\n");
                }
            }
        }
        else if(option == 5){
            printf("goodbye!\n");
            break;
        }
        else{
            printf("Hey, %d is not between 1 and 5, try again...\n", option);
            continue;
        }
    }
}