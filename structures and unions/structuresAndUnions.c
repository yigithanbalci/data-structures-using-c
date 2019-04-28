#include <stdio.h>
#include <string.h>
/*
 * Structures are basically user-defined data type.
 * They can store different types of related data. 
 * If you are familiar with object oriented programming,
 * you can simply imagine structures as objects without methods.
 */

struct Example{
	int dummyInt;
};

/*
 * Structure declaration does not allocate any memory or consume storage space.
 * It just gives template to C Compiler. 
 * Memory will be consumed only and only when a variable created from this type.
 */

/*
 * typedef is used for defining a custom type from existing type.
 * it is used to define struct student as student here.
 */
typedef struct student2 {
	int r_no;
	char name[20];
	char course[20];
	float fees;
}student2;

/*
 * Structs can be passed by value or reference and with pointers.
 * student->r_no is the way you use element of student.
 * self-referential structures contains a reference of its same type.
 * it contains a pointer to a data is the same type of structure.
 */
struct node {
	int val;
	struct node * next;
};

/* i skipped simple exercises because i believe main point of structures are 
 * other data structures and being foundation of objects.
 */

/*
 * Unions are similar to structures. 
 * They hold different datas related each other. 
 * The only difference between structures and unions is 
 * that in case of unions, you can only store information in one field at any time.
 * when a new value is assigned to one of the fields of union,
 * the existing data is replaced with the new data.
 */
typedef struct POINT1{
	int x, y;
}POINT1;

typedef union POINT2{
	int x;
	int y;
}POINT2;

void dummyUnionMethod(){
	POINT1 P1 = {2,3};
	// POINT2 P2 = {4,5}; is illegal in case of unions.
	POINT2 P2;
	P2.x = 4;
	P2.y = 5;
	// printing P2.x will be shown in console as "5"
	// because unions override old data.
}

/*
 * The size of a union is equal to the size of its largest member.
 */

/*
 * arrays of unions and structures can be used as well.
 */
void foolishMethod(){
	POINT1 pArr[5];
}

/*
 * Structures can be coded nestedly and unions can be used inside structures.
 */
struct student{
	union{
		char name[20];
		int roll_no;
	};
	int marks;
};
void nestedEx(){
	struct student stud;
	strcpy(stud.name, "Ufuk");

}
/*
 * I have skipped lots of points because i find them exhausting and 
 * not helpfull. 
 * Instead of making an effort on practicing basics of structures,
 * i chose to examine linked lists and other data structures deeply.
 */
int main(){

	return 0;
}
