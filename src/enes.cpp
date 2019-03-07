#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(){
	int length = 80000;
	
	ofstream myfile("output1.txt");
	
	myfile << length << endl;
	
	for(int i = length-1; i > 0; i = i - 2){
		myfile << p[i].photoId << endl;
	}
	for(int i = 0; i < length; i = i + 2){
		myfile << p[i].photoId << endl;
	}
	
	
	
}
