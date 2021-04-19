#include <stdio.h>

#include <stdlib.h>

#include "interval.h"

/* interval kütüphanesi test programı.
 *  int,double,float,char tiplerinde ağaç oluşturma, sıralama ve overlap tespiti fonksiyonlarını 
 *  test eder. 
 *  11.grup programlamada özel konular dersi 2021 yaz dönemi.
 *  Sabri Başoğlu 16060428
 */
int main(void) {
  //int test bölümü
  node * root = NULL;
  printf("ilk node eklendikten sonra ağaç[15,20]: \n");
  root = insert(root, createInterval(15, 20));
  inorder(root);
  printf(" 2.node eklendikten sonra ağaç[10,30]\n");
 root = insert(root, createInterval(10, 30));
  inorder(root);
  printf(" 3.node eklendikten sonra ağaç[17,19]\n");
  root = insert(root, createInterval(17, 19));
  inorder(root);
  printf(" 4.node eklendikten sonra ağaç[5,20]\n");
  root = insert(root, createInterval(5, 20));
  inorder(root);
  printf(" 5.node eklendikten sonra ağaç[12,15]\n");
  root = insert(root, createInterval(12, 15));
  inorder(root);
  printf(" 5.node eklendikten sonra ağaç[30,40]\n");
  root = insert(root, createInterval(30, 40));

  inorder(root); //in order sırası ile yazdır.

  interval temp_inter = createInterval(6, 7);

  printf("overlap aranıyor:");
  printInterval(temp_inter);
  checkOverLap(root, temp_inter);

  printf("-------------\n");
  //double test bölümü
  node * root1 = NULL;
  root1 = insert(root1, createInterval(15.1, 20.1));
  root1 = insert(root1, createInterval(10.1, 30.1));
  root1 = insert(root1, createInterval(17.1, 19.1));
  root1 = insert(root1, createInterval(5.1, 20.1));
  root1 = insert(root1, createInterval(12.1, 15.1));
  root1 = insert(root1, createInterval(30.1, 40.1));
  inorder(root1);

  interval temp_inter1 = createInterval(5.9, 6.9);

  printf("overlap aranıyor:");
  printInterval(temp_inter1);
  checkOverLap(root1, temp_inter1);

  printf("-------------\n");

  //float test bölümü.
  node * root2 = NULL;
  root2 = insert(root2, createInterval( 15.0f,  20.0f));
  root2 = insert(root2, createInterval( 10.0f,  30.0f));
  root2 = insert(root2, createInterval( 17.0f,  19.0f));
  root2 = insert(root2, createInterval( 5.0f,  20.0f));
  root2 = insert(root2, createInterval( 12.0f,  15.0f));
  root2 = insert(root2, createInterval(30.0f,  40.0f));
  inorder(root2);

  interval temp_inter2 = createInterval(11.3f, 16.5f);

  printf("overlap aranıyor:");
  printInterval(temp_inter2);
  checkOverLap(root2, temp_inter2);

  printf("-------------\n");

  //double test bölümü
  node * root3 = NULL;

  char a = 'a', b = 'b', c = 'c' ,d = 'd' , s = 's' , z = 'z', x = 'x';
  root3 = insert(root3, createInterval(c,z));
  root3 = insert(root3, createInterval(a,b));
  root3 = insert(root3, createInterval(c,d));
  root3 = insert(root3, createInterval(s,z));
  root3 = insert(root3, createInterval(a,x));

  inorder(root3);

  interval temp_inter3 = createInterval(b, d);

  printf("overlap aranıyor:");
  printInterval(temp_inter3);
  checkOverLap(root3, temp_inter3);

  

}