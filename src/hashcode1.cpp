#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstring>
#include "photo.cpp"
using namespace std;

int main(){
    ifstream myFile ("b_lovely_landscapes.txt");

    int noOfPhoto;

    myFile >> noOfPhoto;
    photo* photoArray = new photo[noOfPhoto];

    string str;
    getline(myFile, str);

    for(int i = 0; i < noOfPhoto; i++){

        getline(myFile, str);
        istringstream iss(str);
        string token;
        getline(iss,token, ' ');
        if (token == "H")
            (photoArray[i]).position = 0;
        else
            (photoArray[i]).position = 1;
        getline(iss,token, ' ');

        std::stringstream s_str( token );
        s_str >> photoArray[i].notags;

        photoArray[i].tags = new char*[photoArray[i].notags];
        photo* temp = &photoArray[i];
        for(int j = 0; j < photoArray[i].notags; j++) {
            getline(iss,token, ' ');
            (temp->tags[j]) = new char[token.length()+1];
            strcpy(temp->tags[j], token.c_str());
        }

        photoArray[i].photoId = i;
    }

//    photo* vertical = NULL;
//
//	for( int i = 0; i < noOfPhoto; i++ ){
//		if( photoArray[i].position == 1 && vertical == NULL){
//			vertical = &photoArray[i];
//		}
//		else if (photoArray[i].position == 1 && vertical !=  NULL){
//			vertical->photoId = vertical->photoId + photoArray[i].photoId;
//			vertical->mergePhoto(&photoArray[i]);
//			photoArray[i] = photoArray[noOfPhoto-1];
//			noOfPhoto--;
//
//		}
//	}


    int nop = noOfPhoto;
    int index1 = 0, index2 = 0, maks1 = 0, maks2 = 0;
    for( int i = 0; i < nop; i++) {
        int maks, index;
        //cout << i << "\n";
        photo tmp;
        maks = 0;
        index = i;
        for( int j = i; j < nop ; j++){
            if( photoArray[j].notags > maks) {
                maks = photoArray[j].notags;
                index = j;
            }
        }
        tmp = photoArray[i];
        photoArray[i] = photoArray[index];
        photoArray[index] = tmp;
    }
    //cout << "asd";

    for( int i = 1; i < 101; i++){
        int a;
        a = photoArray[0].calculateInterest(&photoArray[i]);
        if( a > maks1) {
            index2 = index1;
            index1 = i;
        }
        else if( a > maks2)
            index2 = i;
    }
    photo tmp;
    tmp = photoArray[1];
    photoArray[1] = photoArray[index1];
    photoArray[index1] = tmp;
    tmp = photoArray[2];
    photoArray[2] = photoArray[index2];
    photoArray[index2] = tmp;
    cout << "check";
    for( int i = 1; i < nop - 4; i++) {
        int maks, index;
        maks = 0;
        index = i + 2;
        for( int j = i + 2; ((j < i + 100) && (j < nop)); j++) {
            int a;
            a = photoArray[i].calculateInterest(&photoArray[j]);
            if( a > maks)
                index  = j;
        }
        //cout << index << "\n";
        if( index != i + 2){
            tmp = photoArray[i + 2];
            photoArray[i + 2] = photoArray[index];
            photoArray[index] = tmp;
        }

    }
    //cout << "asd"

    ofstream myfile("output1.txt");

	myfile << noOfPhoto << endl;

	for(int i = noOfPhoto-1; i > 0; i = i - 2){
		myfile << photoArray[i].photoId << endl;
	}
	for(int i = 0; i < noOfPhoto; i = i + 2){
		myfile << photoArray[i].photoId << endl;
	}
    return 0;

}
