#define MAXNAME  64
#define MAXEMP  1024

struct person {
    char name[MAXNAME], surname[MAXNAME];   
    int  id, salary;
};

int open_file(char *fname){
    if(fopen(fname, "r") == NULL)
        return -1;
    return 0;
}

int read_int(int *address){
    if(scanf("%d", address) == 0)
        return -1;
    return 0;
}

int read_float(float *address){
    if(scanf("%f", address) == 0)
        return -1;
    return 0;
}

int read_string(char *address){
    if(scanf("%s", address) == 0)
        return -1;
    return 0;
}

void close_file(FILE *fname){
    fclose(fname);
}

///need help here 
int binary_search(const int arr[], int l, int r, int x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binary_search(arr, l, mid - 1, x); 
        // Else the element can only be present 
        // in right subarray 
        return binary_search(arr, mid + 1, r, x); 
    } 
    // We reach here when element is not 
    // present in array 
    return -1; 
}

void print_by_key(struct person employee[MAXNAME], int key){
    /* Given structure and id, this function prints the employee record
    if it exists */
    printf("----------------------------------------------\n");
    printf(" NAME                       SALARY      ID\n");
    printf(" %-10s %-10s %10d %10d \n", employee[key].name, employee[key].surname, employee[key].salary, employee[key].id) ;
    printf("----------------------------------------------\n");
}

int search_lname(struct person employee[MAXNAME], int n_emp, char surname[]){
    for(int i=0;i<n_emp;i++){
        if(strcmp(employee[i].surname, surname)==0){
            return i;
        }
    }
    return -1;
}

int print_by_name(struct person employee[1024], char emp_name[256]){
    /* Given structure and last name, this function prints the employee record
    if it exists */
    int length = sizeof(employee)/ sizeof(employee[0]);
    for(int i=0;i<length;i++){
        if(employee[i].surname == emp_name){
            printf("NAME\t\t\t\t\t\tSALARY\t\tID\n");
            printf("---------------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%d\t\t%d\n",employee[i].name,employee[i].surname,employee[i].salary,employee[i].id);
            printf("---------------------------------------------------------------\n");
            return 0;
        }
    }
    return 0;
}