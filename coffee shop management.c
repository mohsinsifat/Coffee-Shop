
#include <stdio.h>
#include <string.h>

struct MenuItem {
  char name[50];
  float price;
};

char adminUsername[50] = "admin";
char adminPassword[50] = "password";

struct MenuItem menu[50];
int numItems = 0;
float sales[50];


void adminLogin() {
  char username[50], password[50];

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

}


void showMenu() {
  int i;
  printf("Menu:\n");
  printf(" 1.Cold coffee\n 2.Hot coffee\n 3.Mocha\n 4.atte\n 5.Flat white\n 6.Doppio\n ");

  for(i=0; i<numItems; i++) {
    printf("%s - $%.2f\n", menu[i].name, menu[i].price);
  }
}


void addItem() {
  printf("Enter item name: ");
  scanf("%s", menu[numItems].name);

  printf("Enter price: ");
  scanf("%f", &menu[numItems].price);

  numItems++;

  printf("Item added to menu.\n");
}


void deleteItem() {
  char name[50];

  printf("Enter delete item: ");
  scanf("%s", name);

  int i;
  for(i=0; i<numItems; i++) {
    if(strcmp(menu[i].name, name) == 0) {
      for(int j=i; j<numItems-1; j++) {
        menu[j] = menu[j+1];
      }
      numItems--;
      printf("Item deleted.\n");
      return;
    }
  }

  printf("Item not found.\n");
}


void sellItem() {
  char name[50];

  printf("Enter the item name: ");
  scanf("%s", name);

  int i;
  for(i=0; i<numItems; i++) {
    if(strcmp(menu[i].name, name) == 0) {
      sales[i] += menu[i].price;
      printf("%s sold\n", name);
      return;
    }
  }
  printf("Item not found!\n");
}


void salesReport() {
  int i;

  printf("Sales Report\n");

  for(i=0; i<numItems; i++) {
    printf("%s: $%.2f\n", menu[i].name, sales[i]);
  }

  float total = 0;
  for(i=0; i<numItems; i++) {
    total += sales[i];
  }

  printf("Total Sales: $%.2f\n", total);
}

int main() {
     adminLogin();

  while(1) {

    int choice;

    while(1) {

      printf("\n1. Display Menu\n");
      printf("2. Add New Item\n");
      printf("3. Delete Item\n");
      printf("4. Sell Item\n");
      printf("5. Sales Report\n");

      printf("Enter choice: ");
      scanf("%d", &choice);


      if(choice == 1) showMenu();
      else if(choice == 2) addItem();
      else if(choice == 3) deleteItem();
      else if(choice == 4) sellItem();
      else if(choice == 5) salesReport();
      break;
    }
  }

  return 0;
}
