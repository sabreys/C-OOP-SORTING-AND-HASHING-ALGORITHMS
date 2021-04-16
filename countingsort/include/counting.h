#ifndef __COUNTING_H__
#define __COUNTING_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RANGE 255 //char değerler için max aralık


#define countingSort(X,Y) _Generic((X), \
  char *: countingSortCHAR, \
  int*: countingSortINT, \
  long int*: countingSortLONGINT, \
  unsigned int*: countingSortUNSIGNEDINT,\
  short int*:countingSortSHORTINT,\
  long long int*:countingSortLONGLONGINT,\
  CustomModel*: countingSortCUSTOM, \
  default: errorMessage)((X),(Y))


#define findRange(X,Y)_Generic((X), \
  char *: returnCharRange, \
  int*: findRangeINT, \
  unsigned int*:findRangeUNSIGNEDINT,\
  short int*:findRangeSHORTINT,\
  long int*: findRangeLONGINT, \
  long long int*: findRangeLONGLONGINT,\
  CustomModel*: findRangeCUSTOM, \
  default: errorMessage) ((X),(Y))

#define printArray(X,Y)_Generic((X), \
  char *: printArrayCHAR, \
  int*: printArrayINT, \
  unsigned int*:printArrayUNSIGNEDINT,\
  short int*:printArraySHORTINT,\
  long int*: printArrayLONGINT, \
  long long int*: printArrayLONGLONGINT,\
  CustomModel*: printArrayCUSTOM, \
  default: errorMessage) ((X),(Y))


typedef struct CustomModel {
  void* data;
  int max;
  int size;
  int modelTip;
}CustomModel;

enum modelType{charModel,intModel,longIntModel,shortModel,unsignedModel,longLongModel};



void countingSortCHAR(char input[],int size);

void countingSortINT(int input[],int size);

void countingSortLONGINT(long int input[],int size);

void countingSortSHORTINT(short int input[],int size);

void countingSortUNSIGNEDINT(unsigned int input[],int size);

void countingSortLONGLONGINT(long long int input[],int size);

void countingSortCUSTOM(CustomModel* model,int size );



CustomModel* createModel(void* data,int max,int size,int modelTip);

int findRangeINT(int arr[],int size);

long int findRangeLONGINT(long int arr[],int size);


short int findRangeSHORTINT(short int arr[],int size);


unsigned int findRangeUNSIGNEDINT(unsigned int arr[],int size);

long long int findRangeLONGLONGINT(long long int arr[],int size);


long long int  findRangeCUSTOM(CustomModel* model,int size);

int returnCharRange();

// hata mesajı döndürür. -1 döner.
int errorMessage();

void printArrayCHAR(char input[],int size);

void printArrayINT(int input[],int size);

void printArrayLONGINT(long int input[],int size);

void printArraySHORTINT(short int input[],int size);

void printArrayUNSIGNEDINT(unsigned int input[],int size);

void printArrayLONGLONGINT(long long int input[],int size);

void printArrayCUSTOM(CustomModel* model,int size);




#endif