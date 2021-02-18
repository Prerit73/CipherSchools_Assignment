
#include <iostream> 
using namespace std; 

int numberOfPaths(int a, int b) 
{ 
	int path = 1; 
	for (int i = b; i < (a + b - 1); i++) { 
		path *= i; 
		path /= (i - b + 1); 
	} 
	return path; 
} 


int main() 
{ 
	cout << numberOfPaths(2, 3); 
	return 0; 
} 

