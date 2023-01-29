//Wutthiphong khiaokham 65543206079-7 sec 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodetest {
	
    int num;
    struct nodetest *next;
};
	
struct nodetest *AddNode ( struct nodetest **walk , int num ) {
    while ( *walk != NULL ) {
    	walk = &( *walk ) -> next;
    }//End while
    *walk = new struct nodetest;
    ( *walk ) -> num = num;
    ( *walk ) -> next = NULL;
    return *walk;
}//End function AddNode

void showAll ( struct nodetest *walk ) {
    struct nodetest *current = walk;
    while ( current != NULL ) {
        printf( " %d " , current -> num );
        current = current -> next;
    }//End while
    printf( "\n" );
}//End function ShowAll

void updateNode ( struct nodetest *walk , int num1 , int num2 ) {
    nodetest *current = walk;
    while ( current != NULL ) {
        if (current -> num == num1) {
            current -> num = num2;
        }//End if
        current = current -> next;
    }//End while
}//End function UpdateNode

void showBack ( struct nodetest *walk ) {
    if ( walk == NULL ) return;
    showBack (walk -> next );
    printf( " %d " , walk -> num );//End if
}//End function ShowBack

void swapNode ( struct nodetest *walk, int a , int b ) {
    struct nodetest *node1 = NULL;
    struct nodetest *node2 = NULL;
    struct nodetest *current = walk;
    while ( current != NULL ) {
        if ( current -> num == a ) {
            node1 = current;
        }//End if
		else if ( current -> num == b ) {
            node2 = current;
        }//End elif
		current = current -> next;
    }//End while
    if ( a == NULL || b == NULL );
    int temp = node1 -> num;
    node1 -> num = node2 -> num;
    node2 -> num = temp;//End if
}//End function SwapNode

int main ( ) {
	printf("\n   +-----------------------+\n   | Wutthiphong Khiaokham |\n   | 65543206079-7         | \n   | Sec. 3                |\n   +-----------------------+\n");
    struct nodetest *start = NULL;
	   
    printf("\n________ [ Update Node ] ______\n");
    
    AddNode( &start , 10 );
    AddNode( &start , 20 );
    AddNode( &start , 30 );
    AddNode( &start , 40 );
    
    printf( "\nShowAll    : " );
    showAll( start );
    
	printf( "\nUpdateNode : " );
    updateNode( start , 10 , 99 ); 
    showAll( start ); 
    updateNode( start , 99 , 10 );
	printf( "UpdateNode : " );
    updateNode( start , 10 , 98 ); 
    showAll( start );
    updateNode( start , 98 , 10 ); 
    
	printf("\n________ [ Show Back ] ________\n");
    printf( "\nShowAll    : " );
    showAll( start );
	              
    printf( "\nShowBack   : " );
    showBack( start );             
    
	printf("\n\n________ [ Swap Node ] ________\n");
    
    printf( "\nShowAll    : " );
    showAll( start );              
    
    printf( "\nSwapNode   : " );
    swapNode( start , 20 , 30 );   
    showAll( start ); 
    
    
    return 0;
}//End function main
