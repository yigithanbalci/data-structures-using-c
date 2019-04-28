#include <stdio.h>

/*
 * Linked lists are like arrays but they are not stored consecutively.
 * simply they are structures which have pointer to the next one.
 *
 * Size of LinkedLists is not needed whilst declaring them.
 * Because simply we create them one by one and the address of the new one is used in 
 * the next pointer of last one.
 *
 * Because of the structure they have, individual data of them can not be accessed randomly.
 * We need to travel across the list by simply doing "element.next" to find the location
 * that we want to access. 
 *
 * It seems like a bad con. But Linked Lists have pros too. Which are flexibility and
 * expandability.  
 *
 * We don't need to specify the size of it and when we need to extend them,
 * we do not need to create a new one and copy elements of it, which is opposite in arrays.
 *
 * So, in a short sentence we can say that if we do not want random access, 
 * linked lists are good choices.
 */

/*
 * linked lists are like linear trains, they have number of data fields and a pointer
 * to the next node.
 *
 * They can be used as building block to implement data structures like stacks, queues
 * and their variations.
 *
 * The last node will have no next node connected to it, so it will store NULL as next.
 * (We usually define NULL as -1)
 *
 * Since in a linked list, every node contains a pointer to the next one, it is also called 
 * a self-referential data type.
 */
typedef struct node{
	int data;
	struct node *next;
}node;

/*
 *   Value     Next
 * -------------------
 * -    8   -    2   - 
 * -------------------
 * -    9   -   -1   -
 * -------------------
 *
 * They are independent of each other and in memory there may be some element of a list 
 * can come right after another unlike arrays. 
 *
 * The only important thing is the address of the next node. 
 */

/*
 * Linked lists are a linear collection of data elements. But unlike arrays they are not 
 * stored consecutively in memory. 
 * But like an array, insertions and deletions can be done at any point in the list in a
 * constant time.
 *
 * One advantage is we can add any number of elements to lists. 
 * If we use arrays and declare them as arr[5] then maximum elements this array is 
 * capable of storing will be 5 there is no such restriction in case of a linked list.
 * 
 * Even if it has pros and cons mentioned before, there is another disadvantage which is
 * need for additional space for storing the address of next nodes.
 */

/*
 *
int main(){
	
	return 0;
}
