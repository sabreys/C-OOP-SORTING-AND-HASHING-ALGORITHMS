#ifndef __ELF_H__
#define __ELF_H__

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define elfHash(X, Y) _Generic((X), \
  char *: elfHashSTR, \
  int: elfHashINT, \
  float: elfHashFLOAT, \
  double: elfHashDOUBLE, \
  long int: elfHashLONGINT, \
  Elfnode *: elfHashCUSTOM, \
  default: errorMessage)((X), (Y))

// örnek struct modeli. veri,uzunluğu ve hash sonucunu içinde barındırır.
typedef struct ElfModel {
  char * data;
  long length;
  int hash_result;
}
Elfnode;

// hash karşılaştırma fonksiyonu için sonuç değerleri. başarısız 0, başarılı 1 
enum sonuc {
  basarisiz,
  basarili
};

// Stringler için elf hash fonksiyonu
int elfHashSTR(char * str, long length);
// int için elf hash fonksiyonu
int elfHashINT(int str, long length);
// float için elf hash fonksiyonu
int elfHashFLOAT(float str, long length);
//double için elf hash fonksiyonu
int elfHashDOUBLE(double str, long length);
// long int için elf hash fonksiyonu
int elfHashLONGINT(long int str, long length);
// custom struct için elf hash fonksiyonu
int elfHashCUSTOM(Elfnode * str, long length);

// verilen data ile node oluşturur,verinin uzunluğunu veriler ve hashleme işlemi yapıp node un içine kaydeder.
Elfnode * create_node(char * data);

// verilen metinin verilen hashle uyumuna bakar.
int checkHash(char * str1, int hash);

// hata mesajı döndürür. -1 döner.
int errorMessage();

#endif