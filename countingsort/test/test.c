#include <stdio.h>

#include <string.h>

#include "counting.h"

/* Elf Hash kütüphanesini denemek amaçlı test programı
 * farklı tipte verileri vererek sonuçlarını yazdırır.
 * parametre olarak da veri alıp hashleyebilir.
 * kullanım: test "metin"
 * eğer parametre verilirse verilen veriyi hashler. yoksa örnek verileri işler.
 */



int main()
{
    char arr[] = "test metni"; ;
    int arr1[]={1,200,3,4,78};
    long long int  arr2[]={22,234,111,99};


    countingSort(arr,5);
 
    printf("Sorted character array is %s", arr);

    printf("%d",findRange(arr1,5));

  

   countingSort(arr2,4);

    for(int i=0;i<4;i++){
        printf("%lld\n",arr2[i] );
    }




    CustomModel* modelim=(CustomModel*) malloc(sizeof(CustomModel));

    modelim->data = arr1;
    modelim->size = 5;
    modelim->modelTip = intModel;

    printf("%lld,",findRange(modelim,modelim->size));

    countingSort(modelim,modelim->size);

    printArray(modelim,modelim->size);


    return 0;
}