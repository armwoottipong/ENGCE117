#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name [20] ;
    int   age ;
    char  sex ;
    float gpa ;
    struct studentNode *next;
};

struct studentNode* AddNode (struct studentNode** start, char name[20], int age, char sex, float gpa)
 {
    struct studentNode* newNode = ( struct studentNode* ) malloc ( sizeof ( struct studentNode ) );
    strcpy(newNode -> name, name );
    newNode ->age  = age ;
    newNode ->sex  = sex ;
    newNode ->gpa  = gpa ;
    newNode ->next = NULL;
    if ( *start == NULL ) 
	{
        *start = newNode;
    } else {
        struct studentNode* currentNode = *start;
        while ( currentNode -> next != NULL ) 
		{
            currentNode = currentNode -> next;
        }
        currentNode -> next = newNode;
    }
    return newNode;
}

void InsertNode( struct studentNode* currentNode, char name[20], int age, char sex, float gpa ) 
{
    struct studentNode* newNode = ( struct studentNode* )malloc( sizeof ( struct studentNode ) );
    strcpy( newNode->name, name );
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void DelNode( struct studentNode* currentNode ) {
    if ( currentNode -> next != NULL ) {
        struct studentNode* temp = currentNode->next;
        currentNode -> next = temp -> next;
        free( temp );
    }
}

void ShowAll ( struct studentNode *walk ) 
{
    while ( walk != NULL) {
        printf( "%s ", walk -> name );
        walk = walk -> next;
    }
    printf(" ");
}

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode( &start, "one", 6, 'M', 3.11 );
    ShowAll ( start );
    now = AddNode( &start, "two", 8, 'F', 3.22 );
    ShowAll ( start );
    InsertNode ( now, "three", 10, 'M', 3.33 );
    ShowAll ( start );
    InsertNode ( now, "four", 12, 'F', 3.44);
    ShowAll (start);
    DelNode ( now );
    ShowAll ( start );
    return 0;
}
