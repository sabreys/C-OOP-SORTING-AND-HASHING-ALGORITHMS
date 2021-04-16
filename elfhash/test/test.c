#include <stdio.h>

#include <string.h>

#include "elf.h"

/* Elf Hash kütüphanesini denemek amaçlı test programı
 * farklı tipte verileri vererek sonuçlarını yazdırır.
 * parametre olarak da veri alıp hashleyebilir.
 * kullanım: test "metin"
 * eğer parametre verilirse verilen veriyi hashler. yoksa örnek verileri işler.
 */
int main(int argc, char * argv[]) {

  if (argc < 2) {

    float b = 2.55;
    long int c = 1234123412341234;
    double d = 2.11;
    printf("Node yaratma ve hashleme :\n");
    Elfnode * test_node1 = create_node("node yaratma denemesi");
    printf("%d\n", test_node1 -> hash_result);
    printf("---------\n");
    Elfnode * test_node2 = (Elfnode * ) malloc(sizeof(Elfnode));
    test_node2 -> data = "bu bir node verisidir.";
    test_node2 -> length = strlen(test_node2 -> data);

    printf("Farklı veri tiplerinde kullanımı:\n");

    printf("%d\n", elfHash(2222, 4));

    printf("%d\n", elfHash(b, 4));

    printf("%d \n", elfHash(c, 16));

    printf("%d \n", elfHash(d, 4));

    printf("%d \n", elfHash(test_node2, test_node2 -> length));

    printf("---------\n");

    printf("Hash kıyaslama :\n");

    checkHash("bu bir node verisi değildir.", test_node1 -> hash_result);

  } else { //bu kısım terminal parametrelerini hashler.

    // girdi metnini atar.
    char * test = argv[1];
    long size = strlen(test);
    int hash_result = elfHash(test, size);
    printf("%d\n", hash_result);

  }

  return 0;

}