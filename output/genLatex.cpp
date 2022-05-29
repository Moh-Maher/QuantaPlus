/*******************************************************************************************
 build latex_results file

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
int main(int argc, char* argv[]) {
  
	if (argc < 2) {
		printf("You must specify a file name!\n");
		printf("for example: \"./run.out xxx.tex\"\n");
		return 1;
	}

	const char* run ="pdflatex ";
	char result[100];   // array to hold the result.

	strcpy(result,run); // copy string one into the result.
	strcat(result,argv[1]); // append string two to the result.

	system(result);
	system("clear");
	system("make clean");

}
