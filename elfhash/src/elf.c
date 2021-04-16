#include "elf.h"

/*  elfHash kütüphanesi  
 *   ELF hash fonksiyonu PJW Hash fonksiyonuna benzer bir özetleme fonksiyonudur.32 bit işlemciler için tasarlanmıştır. 
 *   UNIX  tabanlı işletim sistemlerinde kullanılır.
 *   Bu kütüphane elf hash oluşturma ve kıyaslama fonksiyonlarını içerir.
 *   11.grup Programlamada özel konular dersi 2021 yaz dönemi.
 */

int elfHashSTR(char * str, long length) {
  printf("haslenecek icerik (String):%s\n", str);

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++str, ++index) {

    result = (result << 4) + ( * str); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  return result;
}

int elfHashINT(int str, long length) {

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  // int değeri stringe çevirir.
  char * converted = malloc(length + 1); // yer alma işlemi. kaçış işareti için +1
  snprintf(converted, length + 1, "%d", str);

  printf("haslenecek icerik (int):%s\n", converted);

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++converted, ++index) {

    result = (result << 4) + ( * converted); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  return result;
}

int elfHashFLOAT(float str, long length) {

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  // float değeri stringe çevirir.
  char * converted = malloc(length + 1); // yer alma işlemi. kaçış işareti için +1
  snprintf(converted, length + 1, "%f", str);

  // float da uzunluğun yanlış belirlenmesinin önüne geçmek için. 

  printf("haslenecek icerik (float):%s \n", converted);

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++converted, ++index) {

    result = (result << 4) + ( * converted); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  return result;
}

int elfHashDOUBLE(double str, long length) {

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  // double değeri stringe çevirir.
  char * converted = malloc(length + 1); // yer alma işlemi. kaçış işareti için +1
  snprintf(converted, length + 1, "%lf", str);

  // float da uzunluğun yanlış belirlenmesinin önüne geçmek için. 

  printf("haslenecek icerik (double):%s \n", converted);

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++converted, ++index) {

    result = (result << 4) + ( * converted); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  return result;
}

int elfHashLONGINT(long int str, long length) {

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  // long int değeri stringe çevirir.
  char * converted = malloc(length + 1); // yer alma işlemi. kaçış işareti için +1
  snprintf(converted, length + 1, "%li", str);

  // float da uzunluğun yanlış belirlenmesinin önüne geçmek için. 

  printf("haslenecek icerik (long int):%s \n", converted);

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++converted, ++index) {

    result = (result << 4) + ( * converted); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  return result;
}

int elfHashCUSTOM(Elfnode * str, long length) {

  int result = 0; //hash sonucudur.
  long holder = 0;
  long index = 0; //döngü için index değeridir.girdi uzunluğu kadar artar.

  char * converted = str -> data;

  printf("haslenecek icerik (CUSTOM):%s \n", converted);

  // 0 dan uzunluğa kadar 1 artan döngü. sırayla tüm indisleri gezerek hashleme işlemini gerçekleştirir. length kadar çalışır.

  for (index = 0; index < length; ++converted, ++index) {

    result = (result << 4) + ( * converted); // result değerini 4 kez sola kaydır ve girdinin indexdeki değerini topla çıkan sonucu resulta eşitle

    // eğer result ile  4026531840(11110000000000000000000000000000)32 bit uzunluğundaki  değerinin ve işlemi sonucu 0 çıkmıyorsa yap 
    //
    if ((holder = result & 0xF0000000L) != 0) {

      result ^= (holder >> 24); // holderi 24 bit sağa kaydır ve oluşan sonucu result değeri ile bit düzeyinde xorla.
    }

    result &= ~holder; // bit bazında ve işlemi. holder in tersi ile result bit düzeyinde ve lenir.

  }

  str -> hash_result = result;

  return result;
}

int errorMessage() {
  printf("Parametre tip uyusmazligi. islem tamamlanamadi \n");
  return -1;
}

Elfnode * create_node(char * data) {

  // ramden yer alma 
  Elfnode * node = (Elfnode * ) malloc(sizeof(Elfnode));

  node -> data = data; // veriyi ekleme
  node -> length = strlen(data); // uzunluğu atama
  printf("%d\n", elfHash(node, node -> length)); // hash sonucunu oluşturup ekleme. elfHash fonksiyonu kendisi node a sonucu yazar.

  return node;
}

// verilen girdi ile verilen  hashin uyuşup uyuşmadığını kontrol eden fonksiyon.
int checkHash(char * str1, int hash) {

  if (elfHash(str1, strlen(str1)) == hash) { // verilen metni hashle ve verilen hash ile kıyasla
    printf("\nhashler eslesiyor.\n");
    return basarili;
  } else {
    printf("\nhashler eslesmiyor.\n");
    return basarisiz;
  }

}