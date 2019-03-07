#include <iostream>
#include <stdio.h>
using namespace std;

class photo{

public:
	photo* prev;
	photo* next;
	int position;
	string photoId;
	int notags;
	int interest;
	char** tags;


	photo(){
		photoId = -1;
		notags = -1;
	}
	photo(int position, int photoId, int notags, char** tagscopy[]){
		tags = new char*[notags];
		for( int i = 0; i < notags; i++ ){
			this->tags[i] = tags[i];
		}

		this->notags = notags;
		this->photoId = photoId;
	}

	addPrev(photo &p){
		prev = &p;
	}

	addNext(photo &p){
		next = &p;
	}
	int calculateInterest(photo* p){
		if( false ){
			interest = 0;
		} else {
			int ortak = 0;
			int bundabulunan = 0;
			int digerindebulunan = 0;

			bool bol = true;
			bool bol2 = false;

			for( int i = 0; i < notags; i++ ){
				for( int k = 0; k < p->notags; k++){
					string str = tags[i];
					string str2 = p->tags[k];
					if( str.compare(str2) == 0 ) {
						ortak++;
					}else{
						bundabulunan++;
					}
				}
			}
			digerindebulunan = notags + p->notags - ortak;

			if( ortak < bundabulunan ){
				if( ortak < digerindebulunan ){
					interest = ortak;
				}
				else{
					interest = digerindebulunan;
				}
			}else{
				if( bundabulunan < digerindebulunan ){
					interest = bundabulunan;
				}
				else {
					interest = digerindebulunan;
				}
			}
		}
		return interest;
	}
	void mergePhoto( photo* p){
		photoId = photoId + " " + p->photoId;
		position = 0;

		char** tagstemp;
		int ortak = ortakhesapla(p);

		notags = notags + p->notags - ortak;
		/**
		tagstemp = new char*[ notags + p->notags - ortak];
		for( int i = 0; i < notags; i++ ){
				for( int k = 0; k < p->notags; k++){
					if( str.compare(str2) != 0 ) {
						tagstemp[i] = tags[i]
					}
			}
		}
		**/

	}

	int ortakhesapla(photo* p){
		int ortak = 0;
		for( int i = 0; i < notags; i++ ){
				for( int k = 0; k < p->notags; k++){
					string str = tags[i];
					string str2 = p->tags[k];
					if( str.compare(str2) == 0 ) {
						ortak++;
					}
				}
		}
		return ortak;
	}
};

