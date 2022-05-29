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
    	//system("xdg-open latex_results.pdf");
    //cout<<result<<endl;
}
