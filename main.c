# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

struct dessert {
  int price;
  char name [256];
};

struct dessert randomStruct() {
  char *arr[3] = {"cookie", "chocolate", "cupcake"};
  struct dessert s0;
  srand(time(NULL));
  s0.price = rand() % 100;
  strcpy(s0.name, arr[rand() % 3]);
  return s0;
}

int printVar(struct dessert test) {
  printf("Name of Dessert: %s\n", test.name);
  printf("Price of Dessert: $%d\n", test.price);
  return 0;
}

int editStruct(struct dessert * test, int p, char n []) {
  (*test).price = p;
  strcpy((*test).name, n);
  return 0;
}

int editStructBoth(struct dessert * test){
	//struct dessert * pointa = &test;
	test -> price += 2;
	strcpy(test -> name,"ytb");
		////strcpy(,"YATA");
		return 0;
	}



int increment(struct dessert * test) {
  (*test).price++;
  int i;
  for(i = 0; i < strlen((*test).name); i++) {
    (*test).name[i]++;
  }
  return 0;
}

int main() {
  struct dessert test0 = randomStruct();
  struct dessert test2 = randomStruct();
  printf("first test \n");
  printVar(test0);
  // printf("%p\n", &test0);
  editStruct(&test0, 50, "cake");
  editStructBoth(&test0);
 // printVar(test0);
  increment(&test0);
  printf("first test after changes \n");
  printVar(test0);

  printf("second test \n");
  printVar(test2);
  editStructBoth(&test2);
  printf("second test after changes \n");
  printVar(test2);
  return 0;
}