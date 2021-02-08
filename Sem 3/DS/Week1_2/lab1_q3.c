// Samuel wants to store the data of his employees, which includes the following fields: (i) Name of the employee (ii) Date of birth which is a collection of {day, month, year} (iii) Address which is a collection of {house number, zip code and state}. Write a 'C' program  to  read  and  display  the  data  of  N  employees  using  pointers  to  array  of structures.
#include <stdlib.h>
#include <stdio.h>

struct DOB {
	int day, month, year;
};

struct ADRS {
	int house_no;
	long zipcode;
	char state[20];
};
	
struct EMPLOYEE {
	char name[20];
	struct DOB dob;
	struct ADRS address;
};

struct EMPLOYEE emp[10];
struct EMPLOYEE *ptr = emp;

int main(){
	

	int n;
	printf("Enter number of employees\n");
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		printf("Name: \n");
		scanf("%s", ptr[i].name);
		// printf("%s\n", ptr[i].name);
		printf("DOB: ");
		scanf("%d %d %d", &ptr[i].dob.day, &ptr[i].dob.month, &ptr[i].dob.year);

		
		printf("Address: ");
		scanf("%d %li %s", &ptr[i].address.house_no, &ptr[i].address.zipcode, ptr[i].address.state);
	}
	printf("-----------------------------------------------\n\n");
	// Displaying information
	for(int i = 0; i < n; i++){
		printf("Employee %d: \n", i+1);
		printf("%s\n", ptr[i].name);
		// printf("%s\n", ptr[i].name);
		printf("DOB: ");
		printf("%d/%d/%d\n", ptr[i].dob.day, ptr[i].dob.month, ptr[i].dob.year);

		
		printf("Enter address: ");
		printf("%d, %li, %s\n", ptr[i].address.house_no, ptr[i].address.zipcode, ptr[i].address.state);
	}
	return 0;
}