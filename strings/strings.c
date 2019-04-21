#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
 * Strings are basically arrays which contain chars.
 * And null-character terminated arrays they are so they end with '\0'.
 */

/* 
 * Finding length of a string is actually quite simple.
 * Just look at the null character '\0'.
 */
int findTheLength(char * str){
	int i = 0;
	while(str[i] != '\0'){
		++i;
	}
	return i;
}

/*
 * I Just skipped upper-lower case conversion because it is so simple
 * and nowadays we do not do it by ourselves.
 *
 * Appending is not being done manually too but it is a good practice.
 *
 * And i suggest to not use pre or post increment like this kind of situations
 * because it may make program execute unexpectedly.
 */
void concanateSTwoToSone(char * s1, char * s2){
	int i = -1, j = -1;
	while(s1[++i] != '\0');
	while(s2[++j] != '\0'){
		s1[i++] = s2[j];
	}
	s1[i] = '\0';
}

/*
 * Comparing two strings is a method that is being used generally.
 */
bool compareTwoStrings(char * s1, char * s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 != len2){
		return false;
	}
	int indexCounter = 0;
	while(indexCounter < len1){
		if (s1[indexCounter] != s2[indexCounter]){
			break;
		}
		++indexCounter;
	}
	return indexCounter == len1 ? true : false;
}

/*
 * There may be several different approaches to reversing a string.
 * But, there is a solution to this problem that i do love so much.
 */
char * reverseString(char * s){
	int firstIndex = 0;
	int lastIndex = strlen(s) - 1;
	char tmp;
	while (firstIndex < lastIndex){
		// there is also a method to swap two variables.
		// which uses adding and substraction.
		// but i believe it is risky to make an overflow occur.
		tmp = s[firstIndex];
		s[firstIndex] = s[lastIndex];
		s[lastIndex] = tmp;
		++firstIndex;
		--lastIndex;
	}
	return s;
}

/*
 * To extract a substring from a string,
 * simply find the position of substring and then copy it to the other string. 
 */
char * extractSubstring(char * s, int location, int size){
	char * s2 = (char*) malloc(sizeof(char) * 100);
	int index1 = location;
	int index2 = 0;
	while(s[index1] != '\0' && size > 0){
		s2[index2++] = s[index1++];
		--size;
	}
	s2[index2] = '\0';
	return s2;	
}

/*
 * Inserting a string into a main string is implemented with two indexes.
 * It is a basic logic. Copy a part of first one then copy other completely 
 * after that just copy the remaining part of the first one.
 */
char * copyString(char * s1, char * s2, int position){
	int length = strlen(s1);
	length = length + strlen(s2);
	// actually minus one could be applied
	// cause of null char is duplicated.
	char * s3 = (char *) malloc(sizeof(char) * length);
	int index1 = 0, index2 = 0, index3 = 0;
	while(s1[index1] != '\0'){
		if (index1 == position){
			while(s2[index2] != '\0'){
				s3[index3] = s2[index2];
				++index3;
				++index2;
			}
		} else {
			s3[index3] = s1[index1];
			++index3;
		}
		++index1;
	}
}

/*
 * Substring search is a exhaustive search problem. 
 * It is really slow like O(n^2). 
 * 
 * Altough there are several algorithms to do it in better complexity,
 * it is a topic that i will handle in algorithms study.
 */
int positionOfSubstr(char * s1, char * s2){
	int index = 0, location1 = 0, location2 = 0;
	int length2 = strlen(s2);
	while(s1[index] != '\0'){
		location1 = index;
		location2 = 0;
		while(s2[location2] != '\0'){
			if (s1[location1] != s2[location2]){
				break;
			}
			++location1;
			++location2;
		}
		if(location2 == length2){
			break;
		}
		++index;
	}
	return index;
}

/*
 * Deleting substring is something like deleting sub array. 
 * Just shift some of them. So i will not implement it.
 *
 * Replacing pattern with another is something like 
 * finding the pattern match then replace it. 
 * after finding the index of a pattern just copy from this location.
 *
 * Concetanetion is just copying too. and pointers work as in an array.
 */


int main(){
	return 0;
}
