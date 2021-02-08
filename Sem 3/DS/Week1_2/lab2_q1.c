
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct DOB{
	int day;
	char mth[20];
	int year;
};

struct STU_INFO{
	int reg_no;
	char name[20];
	char adrs[30];
};
struct COLLEGE{
	char clg_name[20];
	char univ_name[20];
};

struct STUDENT{
	struct DOB dob;
	struct STU_INFO stu_info;
	struct COLLEGE clg;
};

int main(){
	struct STUDENT student;
	printf("Enter DOB:\n");
	scanf("%d %d %s", &student.dob.day, &student.dob.year, (student.dob.mth));

	printf("Enter info(reg no, name, address):\n");
	scanf("%d %s %s", &student.stu_info.reg_no, student.stu_info.name, student.stu_info.adrs);

	printf("Enter college name(college, university):\n");
	scanf("%s %s", student.clg.clg_name, student.clg.univ_name);

	printf("DOB: %d/%s/%d\n", student.dob.day, student.dob.mth, student.dob.year);
	printf("Info: %d\n%s\n%s\n", student.stu_info.reg_no, student.stu_info.name, student.stu_info.adrs);
	printf("College: %s, %s\n", student.clg.clg_name, student.clg.univ_name);
	
	return 0;
}