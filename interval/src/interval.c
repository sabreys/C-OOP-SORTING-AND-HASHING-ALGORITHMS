#include "interval.h"

// verilen intervalin tipinde node yaratan fonksiyon.
node * createNode(interval i) {
  //ramden dinamik yer alma.
  node * temp = (node * ) malloc(sizeof(node)); 
  //interval için dinamik yer alma.
  interval * temp_interval = (interval * ) malloc(sizeof(interval));
  // veri tipine göre veriyi tutacak değişkenler.
  int * lowOne;
  int * highOne;
  float * lowOne1;
  float * highOne1;
  char * lowOne2;
  char * highOne2;
  double * lowOne3;
  double * highOne3;
  int * type;

  type = ( int * )malloc(sizeof(int));

  
   // tip  seçici 
  switch (*(int*)i.intervalTip) {
  case intInterval:
     //stack üzerinden veri kaybı olmaması için bu değişkenler dinamik olarak atandı.
    lowOne = (int * ) malloc(sizeof(int));
    highOne = (int * ) malloc(sizeof(int));
    
    * lowOne = * (int * ) i.low;
    * highOne = * (int * ) i.high;

    temp_interval -> low = lowOne;
    temp_interval -> high = highOne;


    *type = intInterval;

    temp_interval -> intervalTip = type;

    temp -> i = temp_interval;
    temp -> intervalTip = type;
    temp -> max = highOne;

    break;
  case floatInterval:

    lowOne1 = (float * ) malloc(sizeof(float));
    highOne1 = (float * ) malloc(sizeof(float));
    * lowOne1 = * (float * ) i.low;
    * highOne1 = * (float * ) i.high;

    temp_interval -> low = lowOne1;
    temp_interval -> high = highOne1;
    
    *type = floatInterval;
    
    temp_interval -> intervalTip = type;

    temp -> i = temp_interval;
    temp -> intervalTip = type;
    temp -> max = highOne1;

    break;
  case charInterval:
    lowOne2 = (char * ) malloc(sizeof(char));
    highOne2 = (char * ) malloc(sizeof(char));
    * lowOne2 = * (char * ) i.low;
    * highOne2 = * (char * ) i.high;

    temp_interval -> low = lowOne2;
    temp_interval -> high = highOne2;
 
    *type = charInterval;

    temp_interval -> intervalTip = type;

    temp -> i = temp_interval;
    temp -> intervalTip = type;
    temp -> max = highOne2;

    break;
  case doubleInterval:
    lowOne3 = (double * ) malloc(sizeof(double));
    highOne3 = (double * ) malloc(sizeof(double));
    * lowOne3 = * (double * ) i.low;
    * highOne3 = * (double * ) i.high;

    temp_interval -> low = lowOne3;
    temp_interval -> high = highOne3;
  
    *type = doubleInterval;

    temp_interval -> intervalTip = type;

    temp -> i = temp_interval;
    temp -> intervalTip = type;
    temp -> max = highOne3;

  };

  temp -> left = NULL;
  temp -> right = NULL;

  return temp;
}

interval createIntervalINT(int low, int high) {
    //dinamik yer alma işlemleri.
  interval * temp_interval = (interval * ) malloc(sizeof(interval));
  int * lowOne = (int * ) malloc(sizeof(int));
  int * highOne = (int * ) malloc(sizeof(int));
  int * type = (int * ) malloc(sizeof(int));
  *type =intInterval;
  * lowOne = low;
  * highOne = high;
  // atama işlemleri
  temp_interval -> low = lowOne;
  temp_interval -> high = highOne;
  temp_interval -> intervalTip = type;
  return *temp_interval;
}
interval createIntervalFLOAT(float low, float high) {
  interval * temp_interval = (interval * ) malloc(sizeof(interval));
  float * lowOne = (float * ) malloc(sizeof(float));
  float * highOne = (float * ) malloc(sizeof(float));
  int * type = (int * ) malloc(sizeof(int));
  *type =floatInterval;
  * lowOne = low;
  * highOne = high;

  temp_interval -> low = lowOne;
  temp_interval -> high = highOne;

  temp_interval -> intervalTip = type;
  return *temp_interval;
}

interval createIntervalCHAR(char low, char high) {
  interval * temp_interval = (interval * ) malloc(sizeof(interval));
  char * lowOne = (char * ) malloc(sizeof(char));
  char * highOne = (char * ) malloc(sizeof(char));
  int * type = (int * ) malloc(sizeof(int));
  *type =charInterval;
  * lowOne = low;
  * highOne = high;

  temp_interval -> low = lowOne;
  temp_interval -> high = highOne;
  temp_interval -> intervalTip = type;


  return *temp_interval;
}

interval createIntervalDOUBLE(double low, double high) {
  interval * temp_interval = (interval * ) malloc(sizeof(interval));
  double * lowOne = (double * ) malloc(sizeof(double));
  double * highOne = (double * ) malloc(sizeof(double));
  int * type = (int * ) malloc(sizeof(int));
  *type =doubleInterval;
  * lowOne = low;
  * highOne = high;

  temp_interval -> low = lowOne;
  temp_interval -> high = highOne;
  temp_interval -> intervalTip = type;
  return *temp_interval;
}

// node ekleme fonksiyonu. verilen  rootun veri tipine göre çalışır.
node * insert(node * root, interval i) {
  // eğer verilen node boşsa bir node yarat.
  if (root == NULL) {
    return createNode(i);
  }

  // veri tiplerine göre veri tutan değişkenler.
  int l;
  float l1;
  char l2;
  double l3;

  switch (*(int*)root -> i -> intervalTip) {
  case intInterval:
    l = * (int * ) root -> i -> low; // kökün intervalinin lowunu l ye ata.

    if ( * (int * ) i.low < l) { // eğer  intervalin lowu l den küçükse sola ekle değilse sağa ekle 
      root -> left = insert(root -> left, i);
    } else {
      root -> right = insert(root -> right, i);
    }

    if ( * (int * ) root -> max < * (int * ) i.high) { // eğer kökün maxı intervalin highın yüksekse rootun maxını bu değere eşitle.
      root -> max = i.high;
    }

    break;

  case floatInterval:
    l1 = * (float * ) root -> i -> low;

    if ( * (float * ) i.low < l1) {
      root -> left = insert(root -> left, i);
    } else {
      root -> right = insert(root -> right, i);
    }

    if ( * (float * ) root -> max < * (float * ) i.high) {
      root -> max = i.high;
    }

    break;
  case charInterval:
    l2 = * (char * ) root -> i -> low;

    if ( * (char * ) i.low < l2) {
      root -> left = insert(root -> left, i);
    } else {
      root -> right = insert(root -> right, i);
    }

    if ( * (char * ) root -> max < * (char * ) i.high) {
      root -> max = i.high;
    }

    break;
  case doubleInterval:
    l3 = * (double * ) root -> i -> low;

    if ( * (double * ) i.low < l3) {
      root -> left = insert(root -> left, i);
    } else {
      root -> right = insert(root -> right, i);
    }

    if ( * (double * ) root -> max < * (double * ) i.high) {
      root -> max = i.high;
    }

  };

  return root;

}
//taşma tespit fonksiyonu. bool yerine 1 ve 0 döner.
int overlap(interval i1, interval i2) {
  //tip seçim bölümü


  switch (*(int*)i1.intervalTip) {
  case intInterval:

    if ( * (int * ) i1.low <= * (int * ) i2.high && * (int * ) i2.low <= * (int * ) i1.high) { // eğer i1 in lovu i2nin highdan küçük eşitse ve i2 nin lowu i1 in highdan küçükse overlap vardır.
      return 1;
    }

    break;
  case floatInterval:

    if ( * (float * ) i1.low <= * (float * ) i2.high && * (float * ) i2.low <= * (float * ) i1.high) {
      return 1;
    }

    break;
  case charInterval:
   
    if ( * (char * ) i1.low <= * (char * ) i2.high && * (char * ) i2.low <= * (char * ) i1.high) {
      return 1;
    }

    break;
  case doubleInterval:

    if ( * (double * ) i1.low <= * (double * ) i2.high && * (double * ) i2.low <= * (double * ) i1.high) {
      return 1;
    }

  };

  return 0;
}

//overlap arama fonksiyonu.
interval * overlapSearch(node * root, interval i) {



  if (root == NULL) { 
    return NULL;
  }

  if (overlap(( * root -> i), i) == 1) { // rootun intervali ile verilen interval taşma yapıyorsa rootun intervalini döndür. overlap yakalandı.
    return root -> i;
  }

  switch (*(int*)i.intervalTip) { // tipe göre yönlendirme.
  case intInterval:

    if (root -> left != NULL && * (int * ) root -> left -> max >= * (int * ) i.low) { //eğer rootun solu varsa ve rootun solunun maxı intervalin lowundan büyükse bu dala kay ve overlap ara.
      return overlapSearch(root -> left, i);
    }

    break;
  case floatInterval:

    if (root -> left != NULL && * (float * ) root -> left -> max >= * (float * ) i.low) {
      return overlapSearch(root -> left, i);
    }

    break;
  case charInterval:

    if (root -> left != NULL && * (char * ) root -> left -> max >= * (char * ) i.low) {
      return overlapSearch(root -> left, i);
    }

    break;
  case doubleInterval:

    if (root -> left != NULL && * (double * ) root -> left -> max >= * (double * ) i.low) {
      return overlapSearch(root -> left, i);
    }

  };

  return overlapSearch(root -> right, i);
}


//inorder şekilde ağaç yazdırma fonksiyonu.
void inorder(node * root) {

  if (root == NULL) {
    return;
  }

  inorder(root -> left); 

  switch (*(int*)root -> intervalTip) { // tipe göre yönlendirme.
  case intInterval:

    printf("int tip interval  [%d,%d] max =%d\n", *(int * ) root -> i -> low, *(int * ) root -> i -> high, *(int * ) root -> max);

    break;
  case floatInterval:

    printf("float tip interval [%f,%f] max =%f\n", *(float * ) root -> i -> low, *(float * ) root -> i -> high, *(float * ) root -> max);

    break;
  case charInterval:

    printf("char  tip interval [%c,%c] max =%c \n", *(char * ) root -> i -> low, *(char * ) root -> i -> high, *(char * ) root -> max);

    break;
  case doubleInterval:

    printf("double tip interval  [%lf,%lf] max =%lf\n", *(double * ) root -> i -> low, *(double * ) root -> i -> high, *(double * ) root -> max);

  };

  inorder(root -> right);

}
 // tipe göre interval yazdırma fonksiyonu.
void printInterval(interval i) {

  switch (*(int*)i.intervalTip) {
  case intInterval:

    printf("int tip interval [%d,%d]\n", *(int * ) i.low, *(int * ) i.high);

    break;
  case floatInterval:

    printf(" float tip interval [%f,%f] \n", *(float * ) i.low, *(float * ) i.high);

    break;
  case charInterval:

    printf("char tip interval [%c,%c] \n", *(char * ) i.low, *(char * ) i.high);

    break;
  case doubleInterval:

    printf("double tip interval [%lf,%lf] \n", *(double * ) i.low, *(double * ) i.high);

  };
}
// overlap bulma ve yazdırma fonksiyonu. overlap işlem sonucu interval ile bir iş yapılmayacaksa overlapSearch yerine kullanılması için eklendi.
void checkOverLap(node * root, interval temp_inter) {

  interval * res = overlapSearch(root, temp_inter); //overlap ara

  if (res == NULL) { //overlap yok
    printf("overlapped interval bulunamadı.\n");

  } else {
    printf("overlapped interval bulundu :"); //bulunan overlap'ı yazdır.

    res -> intervalTip = root -> intervalTip; //stack veri kaybını engellemek için eklendi.

    printInterval( * res);

  }
}

// minumum node u döndürür
node * minValue( node * node){
   if(node == NULL)
        return NULL;

    else if(node->left != NULL) // solda çocuk varsa çocuğun minumumunu çağır
        return minValue(node->left); // sol dalın en küçüğü
    return node;
}


node * deleteIntervalINT( node* root, int key){
    if (root == NULL)
        return root;
 
    // eğer aranan değer kökten küçükse sola kayar.
    if (key < *(int*)root->i->low)
        root->left = deleteInterval(root->left, key);
 

    //eğer aranan değer kökten büyükse sağa kayar.
    else if (key > *(int*)root->i->low)
        root->right = deleteInterval(root->right, key);
 
   // aranan node bukulnmuşsa silme işlemi
    else {
        // node un çocukları yoksa 
        if (root->left==NULL && root->right==NULL){

            return NULL;
        }
       
        // tek çocuğu varsa.
        else if (root->left == NULL) {
             node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
 
        // iki çocuklu  bir dal ise 
        node* temp = minValue(root->right);
 
        // kaydırma işlemi 
        root->i->low = temp->i->low;
        root->right = deleteInterval(root->right, *(int*)temp->i->low);
    }
    return root;
}


node * deleteIntervalFLOAT( node* root, float key){
    if (root == NULL)
        return root;
 
    // eğer aranan değer kökten küçükse sola kayar.
    if (key < *(float *)root->i->low)
        root->left = deleteInterval(root->left, key);
 

    //eğer aranan değer kökten büyükse sağa kayar.
    else if (key > *(float *)root->i->low)
        root->right = deleteInterval(root->right, key);
 
   // aranan node bukulnmuşsa silme işlemi
    else {
        // node un çocukları yoksa 
        if (root->left==NULL && root->right==NULL){

            return NULL;
        }
       
        // tek çocuğu varsa.
        else if (root->left == NULL) {
             node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
 
        // iki çocuklu  bir dal ise 
        node* temp = minValue(root->right);
 
        // kaydırma işlemi 
        root->i->low = temp->i->low;
        root->right = deleteInterval(root->right, *(float *)temp->i->low);
    }
    return root;
}

node * deleteIntervalCHAR( node* root, char key){
    if (root == NULL)
        return root;
 
    // eğer aranan değer kökten küçükse sola kayar.
    if (key < *(char *)root->i->low)
        root->left = deleteInterval(root->left, key);
 

    //eğer aranan değer kökten büyükse sağa kayar.
    else if (key > *(char *)root->i->low)
        root->right = deleteInterval(root->right, key);
 
   // aranan node bukulnmuşsa silme işlemi
    else {
        // node un çocukları yoksa 
        if (root->left==NULL && root->right==NULL){

            return NULL;
        }
       
        // tek çocuğu varsa.
        else if (root->left == NULL) {
             node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
 
        // iki çocuklu  bir dal ise 
        node* temp = minValue(root->right);
 
        // kaydırma işlemi 
        root->i->low = temp->i->low;
        root->right = deleteInterval(root->right, *(char *)temp->i->low);
    }
    return root;
}

node * deleteIntervalDOUBLE( node* root, double key){
    if (root == NULL)
        return root;
 
    // eğer aranan değer kökten küçükse sola kayar.
    if (key < *(double *)root->i->low)
        root->left = deleteInterval(root->left, key);
 

    //eğer aranan değer kökten büyükse sağa kayar.
    else if (key > *(double *)root->i->low)
        root->right = deleteInterval(root->right, key);
 
   // aranan node bukulnmuşsa silme işlemi
    else {
        // node un çocukları yoksa 
        if (root->left==NULL && root->right==NULL){

            return NULL;
        }
       
        // tek çocuğu varsa.
        else if (root->left == NULL) {
             node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
 
        // iki çocuklu  bir dal ise 
        node* temp = minValue(root->right);
 
        // kaydırma işlemi 
        root->i->low = temp->i->low;
        root->right = deleteInterval(root->right, *(double *)temp->i->low);
    }
    return root;
}

