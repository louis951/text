#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    
    srand( time( 0 ) );
    clock_t start,end;
    
    start = clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 500 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   end = clock();
   (tortoise==RACE_END)?cout<<"TORTOISE WIN!!! YAY!!!\n":cout<<"Hare WIN. YAY.\n";
   cout << "TIME ELAPSED = "<< (end - start)/1000<< " seconds"<< endl;
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=0;i<7;i++){
		 cout << "---------|";
	}
	cout << endl;
	cout << setw(*bunnyPtr)<< "H"<< endl;
	cout << setw(*snapperPtr)<< "T"<< endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int a = rand()%10+1;
	
	*turtlePtr+= (a<=5)?3:(a<=7)?-6:1;
	*turtlePtr= (*turtlePtr>=70)?70:(*turtlePtr<=1)?1:*turtlePtr;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int a = rand()%10+1;
	
	*rabbitPtr+= (a<=2)?0:(a<=4)?9:(a<=5)?-12:(a<=8)?1:-2;
	*rabbitPtr= (*rabbitPtr>=70)?70:(*rabbitPtr<=1)?1:*rabbitPtr;
}
