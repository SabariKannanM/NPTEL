/*
Write a program in C++ to implement the String Class functions. 
Given an input string S, find whether it contains only digits or not and replace the whitespaces (if any) with "IIT". 
The length of string S is less than or equal to 100. 

Input: 
The string S in a single line. 

Output: 
In the first line, output "YES" if it only contains digits else output "NO"
In the second line, print the formatted string after replacing the whitespaces by "IIT".

Example:
Input:
Hi my name is Amit

Output:
NO
HiIITmyIITnameIITisIITAmit
*/

#include <iostream>
using namespace std;

#define space ' '
int slength,count = 0;
char str[20];

int main() {
	cin.getline (str, 20); // getting string with spaces
	
	for(slength = 0; str[slength] != '\0'; ++slength); //finding string lenght
	
	for(int j = 0; j<slength; j++){
		int a = (int)str[j];	// char to int conversion gives the ascii value
		if(48<=a && a<=59)
		count++;
	}
	
	if(count == slength)
	cout<< "YES\n";
	else
	cout<< "NO\n";
	
	for(int i = 0; i<slength; i++){
		if(str[i] != space)
		cout<< str[i];
		else
		cout<< "IIT";
	}

	return 0;
}
