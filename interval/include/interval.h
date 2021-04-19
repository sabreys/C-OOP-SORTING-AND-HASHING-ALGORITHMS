#ifndef interval_h
#define interval_h

#include <stdio.h>

#include <stdlib.h>

/* INTERVAL AĞACI KÜTÜPHANESİ
* interval ağacı aralıkları tutmak için geliştirilmiş bir ağaç türüdür.  
* çoğunlukla pencereleme sorguları için kullanılır.
* int,float,char,double tiplerini tutabilir.
*  11.grup programlamada özel konular dersi 2021 yaz dönemi.
*  Sabri Başoğlu 16060428
*/

// generic olarak interval oluşturma macrosu
#define createInterval(X, Y) _Generic((X), \
  int: createIntervalINT, \
  float: createIntervalFLOAT, \
  char: createIntervalCHAR, \
  double: createIntervalDOUBLE, \
  default: errorMessage)(X, Y)

//intervalin tuttuğu void* pointerın gösterdiği veri tipini ifade eder 
enum intervalTypes {
  intInterval,
  floatInterval,
  charInterval,
  doubleInterval
};


// interval veri yapısı. farklı tipleri tutabilmek için void* kullanır
typedef struct interval {
  void * low;
  void * high;
  int * intervalTip;
}
interval;

// ağacın düğümlerinin veri yapısı modeli. her node maximum değer pointerı,değerin tipi, 1 adet interval ve sağ ve sol pointerları içerir.
typedef struct node {
  void * max;
  interval * i;
  struct node * left;
  struct node * right;
  int * intervalTip;
}
node;


//node yaratma fonksiyonu. intervalin intervalTipine göre uygun node u yaratır.
node * createNode(interval i);
// int değer için interval yaratma fonksiyonu. dinamik olarak yer ayırarak bu işlemi gerçekleştirir.
interval createIntervalINT(int low, int high);
// float değer için interval yaratma fonksiyonu. dinamik olarak yer ayırarak bu işlemi gerçekleştirir.
interval createIntervalFLOAT(float low, float high);
// char  değer için interval yaratma fonksiyonu. dinamik olarak yer ayırarak bu işlemi gerçekleştirir.
interval createIntervalCHAR(char low, char high);
//double değer için interval yaratma fonksiyonu. dinamik olarak yer ayırarak bu işlemi gerçekleştirir.
interval createIntervalDOUBLE(double low, double high);
// ekleme fonksiyonu.verilen intervalin tipine göre switch ile uygun tipte ekleme yapar.
node * insert(node * root, interval i);
//aşma tespit fonksiyonu. bool değer yerine int olarak 1 yada 0 döner.
int overlap(interval i1, interval i2);
// aşma araması yapan fonksiyon.
interval * overlapSearch(node * root, interval i);
//inorder sıralaması ile ağacı gezerek yazdırma işlemi yapar.
void inorder(node * root);
// yanlış tip seçiminde hata mesajı yazdırır.
int errorMessage();
// verilen intervali tipine uygun şekilde yazdırır.
void printInterval(interval i);
// overlap search yaptıktan sonra yazdırma işlemini yapan fonksiyon. overlapSearchten gelen interval ile işlem uygulanmayacaksa bu fonksiyon tercih edilmelidir.
void checkOverLap(node * root, interval i);

#endif /* interval_h */