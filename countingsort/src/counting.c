#include "counting.h"
 


//verilen char dizisini sayma_dizisiing sort algoritması ile sıralar.
void countingSortCHAR(char input[],int size)
{
    // sıralanmış çıktı dizisi
    char output[strlen(input)];
 
    //tüm elemanların boyutunda sayma dizisi. 
    // bu dizi üzerinde var olan elemanların adetleri tutulur.
    int sayma_dizisi[RANGE + 1], i;
    memset(sayma_dizisi, 0, sizeof(sayma_dizisi));//0 ile dolu dizi oluşturuyoruz.
 
    // input dizisini sayma dizisi üzerinde işaretler
    for (i = 0; input[i]; ++i)
        ++sayma_dizisi[input[i]];
 
   //sayma dizisindeki konumları asıl yerine kaydırır. 0 yerine 1 den başlar
    for (i = 1; i <= RANGE; ++i)
        sayma_dizisi[i] += sayma_dizisi[i - 1];
 
    // sonuc dizisini hazirlar.
    for (i = 0; input[i]; ++i) {
        output[sayma_dizisi[input[i]] - 1] = input[i];
        --sayma_dizisi[input[i]];
    }
 
    // sonuc dizisini asıl diziye geçirir.
    for (i = 0; input[i]; ++i)
        input[i] = output[i];
}
 
int returnCharRange(){
  return RANGE;
}

int findRangeINT(int arr[],int size){

   int biggest=arr[0];
   for(int i=1;i<size;i++){
     if(arr[i]>biggest){
        biggest=arr[i];
     }
   }

   return biggest;

}


long int findRangeLONGINT(long int arr[],int size){
    long int biggest=arr[0];
   for(int i=1;i<size;i++){
     if(arr[i]>biggest){
        biggest=arr[i];
     }
   }

   return biggest;
}


unsigned int findRangeUNSIGNEDINT(unsigned int arr[],int size){
   signed int biggest=arr[0];
   for(int i=1;i<size;i++){
     if(arr[i]>biggest){
        biggest=arr[i];
     }
   }

   return biggest;
}

short int findRangeSHORTINT(short int arr[],int size){
   short int biggest=arr[0];
   for(int i=1;i<size;i++){
     if(arr[i]>biggest){
        biggest=arr[i];
     }
   }

   return biggest;
}


long long int findRangeLONGLONGINT(long long int arr[],int size){
    long long  int biggest=arr[0];
   for(int i=1;i<size;i++){
     if(arr[i]>biggest){
        biggest=arr[i];
     }
   }

   return biggest;
}



long long int  findRangeCUSTOM(CustomModel* model,int size){

  int* arr1;
  long int* arr2;
  short int* arr3;
  unsigned int* arr4;
  long long int* arr5;
  int biggest;
  long  int biggest2;   
  short int biggest3;
  unsigned int biggest4;
  long long int biggest5;

  switch (model-> modelTip){
    case charModel:
       
        return RANGE;
      break;

    case intModel:
        arr1=(int*) model->data;


        biggest= arr1[0];
   for(int i=1;i<model-> size;i++){
     if(arr1[i] >biggest){
        biggest=arr1[i];
     };
   };

     return biggest;
      break;


    case longIntModel:
    arr2=(long int*) model->data;

   biggest2= arr2[0];
   for(int i=1;i<model-> size;i++){
     if(arr2[i] >biggest2){
        biggest2=arr2[i];
     };
   };
 
    return biggest2;


      break;
    
     case shortModel:
       arr3=(short int*) model->data;
      
      biggest3= arr3[0];
   for(int i=1;i<model-> size;i++){
     if(arr3[i] >biggest3){
        biggest3=arr3[i];
     };
   };

     return biggest3;

      break;

 case unsignedModel:
       arr4=(unsigned int*)model->data;
      
     biggest4= arr4[0];
   for(int i=1;i<model-> size;i++){
     if(arr4[i] >biggest4){
        biggest4=arr4[i];
     };
   };
     return biggest4;

      break;

 case longLongModel:

arr5=(long long int*)model->data;
      
 biggest5 = arr5[0];

   for(long long int i=1;i<model-> size;i++){
     if(arr5[i] > biggest5){
        biggest5=arr5[i];
     };
   };
     return biggest5;

      break;


     default: 
      errorMessage();
      return 0;
}


}

int errorMessage(){
    printf("tip hatası\n");
    return -1;
}



void countingSortINT(int input[],int size){
  printf("int counting sort:\n");
  //çıktı dizisi
  int output[size];
  // aralığı kısıtlamak için en büyük elemanı buluyoruz
  int biggest = findRange(input,size);
  // sayma dizisi
  int count[biggest+1];
 // sayma dizisini 0 ile doldur
  for (int i = 0; i <= biggest; ++i) {
    count[i] = 0;
  }
  //count dizisine elemanları saydır
  for (int i = 0; i < size; i++) {
    count[input[i]]++;
  }
  // indis kaydırma
  for (int i = 1; i <= biggest; i++) {
    count[i] += count[i - 1];
  }
  //output dizisini hazırlama. sıralı şekilde dizer
  for (int i = size - 1; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  // çıktıyı ilk verilen diziye aktarır. üzerine yazar
  for (int i = 0; i < size; i++) {
    input[i] = output[i];
  }

}

void countingSortLONGINT(long int input[],int size){
  printf("long int counting sort:\n");
  //çıktı dizisi
  long int output[size];
  // aralığı kısıtlamak için en büyük elemanı buluyoruz
  long int biggest = findRange(input,size);
  // sayma dizisi
  long int count[biggest+1];
 // sayma dizisini 0 ile doldur
  for (long int i = 0; i <= biggest; ++i) {
    count[i] = 0;
  }
  //count dizisine elemanları saydır
  for (long int i = 0; i < size; i++) {
    count[input[i]]++;
  }
  // indis kaydırma
  for (long int i = 1; i <= biggest; i++) {
    count[i] += count[i - 1];
  }
  //output dizisini hazırlama. sıralı şekilde dizer
  for (long int i = size - 1; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  // çıktıyı ilk verilen diziye aktarır. üzerine yazar
  for (long int i = 0; i < size; i++) {
    input[i] = output[i];
  }
}

void countingSortSHORTINT(short int input[],int size){



  printf("short int counting sort:\n");
  //çıktı dizisi
  short int output[size];
  // aralığı kısıtlamak için en büyük elemanı buluyoruz
  short int biggest = findRange(input,size);
  // sayma dizisi
  short int count[biggest+1];
 // sayma dizisini 0 ile doldur
  for (short int i = 0; i <= biggest; ++i) {
    count[i] = 0;
  }
  //count dizisine elemanları saydır
  for (short int i = 0; i < size; i++) {
    count[input[i]]++;
  }
  // indis kaydırma
  for (short int i = 1; i <= biggest; i++) {
    count[i] += count[i - 1];
  }
  //output dizisini hazırlama. sıralı şekilde dizer
  for (short int i = size - 1; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  // çıktıyı ilk verilen diziye aktarır. üzerine yazar
  for (short int i = 0; i < size; i++) {
    input[i] = output[i];
  }
}

void countingSortUNSIGNEDINT(unsigned int input[],int size){
  printf("unsigned int counting sort:\n");
  //çıktı dizisi
  unsigned int output[size];
  // aralığı kısıtlamak için en büyük elemanı buluyoruz
  unsigned int biggest = findRange(input,size);
  // sayma dizisi
  unsigned int count[biggest+1];
 // sayma dizisini 0 ile doldur
  for (int i = 0; i <= biggest; ++i) {
    count[i] = 0;
  }
  //count dizisine elemanları saydır
  for ( int i = 0; i < size; i++) {
    count[input[i]]++;
  }
  // indis kaydırma
  for (int i = 1; i <= biggest; i++) {
    count[i] += count[i - 1];
  }
  //output dizisini hazırlama. sıralı şekilde dizer
  for ( int i = size - 1; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  // çıktıyı ilk verilen diziye aktarır. üzerine yazar
  for (int i = 0; i < size; i++) {
    input[i] = output[i];
  }
}

void countingSortLONGLONGINT(long long int input[],int size){


  printf("long long int counting sort:\n");
  //çıktı dizisi
  long long int output[size];
  // aralığı kısıtlamak için en büyük elemanı buluyoruz
  long long int  biggest = findRange(input,size);
  // sayma dizisi
  long long int  count[biggest+1];
 // sayma dizisini 0 ile doldur
  for (long long int  i = 0; i <= biggest; ++i) {
    count[i] = 0;
  }
  //count dizisine elemanları saydır
  for ( long long int i = 0; i < size; i++) {
    count[input[i]]++;
  }
  // indis kaydırma
  for (long long int  i = 1; i <= biggest; i++) {
    count[i] += count[i - 1];
  }
  //output dizisini hazırlama. sıralı şekilde dizer
  for ( long long int  i = size - 1; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  // çıktıyı ilk verilen diziye aktarır. üzerine yazar
  for (long long int  i = 0; i < size; i++) {
    input[i] = output[i];
  }
}


void countingSortCUSTOM(CustomModel* model,int size ){


  
  switch (model-> modelTip){


    case charModel:
         countingSort((char*)model->data, size);
      break;

    case intModel:

      countingSort((int*)model->data, size);
      break;


    case longIntModel:
  
  countingSort((long int*)model->data, size);
      break;
    
     case shortModel:
   
   countingSort((short*)model->data, size);

      break;

 case unsignedModel:
  
       countingSort((unsigned*)model->data, size);

      break;

 case longLongModel:
 

      
 countingSort((long long int*)model->data, size);

      break;


     default: 
      errorMessage();
   
}

 


}


void printArrayCHAR(char input[],int size){
  printf("%s\n",input);
}

void printArrayINT(int input[],int size){
  for(int i=0; i< size;i++){
    printf("%d,",input[i]);
  }
  printf("\n");
}

void printArrayLONGINT(long int input[],int size){
  for(int i=0; i< size;i++){
    printf("%ld,",input[i]);
  }
  printf("\n");
}

void printArraySHORTINT(short int input[],int size){
  for(int i=0; i< size;i++){
    printf("%d,",input[i]);
  }
  printf("\n");
}

void printArrayUNSIGNEDINT(unsigned int input[],int size){
  for(int i=0; i< size;i++){
    printf("%d,",input[i]);
  }
  printf("\n");
}

void printArrayLONGLONGINT(long long int input[],int size){
  for(int i=0; i< size;i++){
    printf("%lld,",input[i]);
  }
  printf("\n");
}


void printArrayCUSTOM(CustomModel* model,int size){

  printf("%d\n",model->modelTip );

  switch (model-> modelTip) {


    case charModel:
        printArray((char*)model->data , size );
      break;

    case intModel:
         printArray((int*) model->data, size );
      break;

    case longIntModel:
    printArray((long int*) model->data, size );
      break;
    
     case shortModel:
  printArray((short int*) model->data, size );

      break;

 case unsignedModel:

      printArray((unsigned int*)model->data, size );
      break;

 case longLongModel:
 
      
 printArray((long long int*)model->data, size );

      break;


     default: 
      errorMessage();
      break;
   
}

}













