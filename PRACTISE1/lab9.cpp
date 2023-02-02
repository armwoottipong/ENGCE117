#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList {
 protected :
  struct studentNode *start, **now ;
 public :
  LinkedList() ;
  ~LinkedList() ;
  void InsNode( char n[], int a, char s, float g ) ;
  void DelNode() ;
  void GoNext() ;
  void GoFirst() ;
  void GoLast() ;
  void ShowAll() ;
  int FindNode( char n[] ) ;
  struct studentNode *NowNode() ;
  void EditNode( char n[], int a, char s, float g ) ;
} ; //end class

void EditData(LinkedList *ll) {
  char name[20];
  int age;
  char sex;
  float gpa;

  printf("Enter name: ");
  scanf("%s", name);

  if (ll->FindNode(name) == 1) {
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter sex: ");
    scanf(" %c", &sex);

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    ll->EditNode(name, age, sex, gpa);
  } else {
    printf("Node not found!\n");
  }
}//End function EditData

void AddData(LinkedList *ll) {
  char name[20];
  int age;
  char sex;
  float gpa;

  printf("Enter name: ");
  scanf("%s", name);

  printf("Enter age: ");
  scanf("%d", &age);

  printf("Enter sex: ");
  scanf(" %c", &sex);

  printf("Enter GPA: ");
  scanf("%f", &gpa);

  ll->InsNode(name, age, sex, gpa);
}//End function AddData

void FindData( LinkedList *ll ) {
  char name[20];
  int found = 0;
  printf("Enter name to search: ");
  scanf("%s", name);

  found = ll->FindNode(name);
  if (found == 1) {
    printf("Data found: ");
    ll->NowNode();
  } else {
    printf("Data not found\n");
  }//End if-else
}//End function FindData
void readfile( LinkedList *ll ) {
  FILE *fp;
  char name[20];
  int age;
  char sex;
  float gpa;

  fp = fopen("student.txt", "r");
  if (fp == NULL) {
    printf("Cannot open file\n");
    return;
  }//End if
  while (fscanf(fp, "%s %d %c %f", name, &age, &sex, &gpa) != EOF) {
    ll->InsNode(name, age, sex, gpa);
  }//End while
  fclose(fp);
}//End function readfile
void writefile( LinkedList *ll ) {
  FILE *fp;
  struct studentNode *temp;

  fp = fopen("student.txt", "w");
  if (fp == NULL) {
    printf("Cannot open file\n");
    return;
  }//End if
  ll->GoFirst();
  while ((temp = ll->NowNode()) != NULL) {
    fprintf(fp, "%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
    ll->GoNext();
  }//End while
  fclose(fp);
}//End function writefile

int main() {
 LinkedList listA ;
 int menu ;
 readfile( &listA ) ;
 printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
 scanf( "%d", &menu ) ;
 while( menu != 0 ) {
  switch( menu ) {
   case 1 : AddData( &listA ) ; break ;
   case 2 : EditData( &listA ) ; break ;
   case 3 : listA.DelNode() ; break ;
   case 4 : FindData( &listA ) ; break ;
   case 5 : listA.ShowAll() ; break ;
  }//end switch
  printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
  scanf( "%d", &menu ) ;
 }//end while
 writefile( &listA ) ;
 return 0 ;
}//end function
