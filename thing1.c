/*
Zepeda, Bryant
Lab# 1B
Due Date: 2015-02-24
Description:

Input 3 positive integers from the terminal, determine if they are valid
sides of a triangle. If the sides do from a valid triangle, output the type
of triangle - equilateral, isosceles, or scalene - and the area of the
triangle. If the three integers are not the valid sides of a triangle,
output an appropriate message and the 3 sides. Be sure to comment and error
check in your program.
*/

#include <stdio.h>
#include <math.h> /* For GCC, use 'gcc <name>.c -lm' */
#define _CRT_SECURE_NO_WARNINGS
double sqrt(double x); /*<math.h> library, square root function prototype*/
void type(void);
int main(void)
{
	type();
	return 0;
}

void type(void)
{
  int a, b, c; char INPUT;
  do {
    printf("Please enter values: \n");
    scanf("%d %d %d", &a, &b, &c);
    
    /*Checking if positive*/
    if(a<=0) { printf ("Error! Value is negative!\n"); break; }
    if(b<=0) { printf ("Error! Value is negative!\n"); break; }
    if(c<=0) { printf ("Error! Value is negative!\n"); break; }

    /*Checking if valid triangle*/
    
    if (!(a + b > c)) {printf ("Error! Invalid triangle input!\n");break;}
    if (!(a + c > b)) {printf ("Error! Invalid triangle input!\n");break;}
    if (!(b + c > a)) {printf ("Error! Invalid triangle input!\n");break;}
    
    /*Formula*/
    float sqt = (a + b + c) / 2.0;
    int area = sqt * ((sqt - a) * (sqt - b) * (sqt - c));
    
    if ((a == b) && (a == c) && (b == a) && (b == c) && (c == a) && (c == b))
      {
	printf("This is an Equilateral Triangle.\n");
	printf("Area: %f\n", sqrt(area));
      }
    else if ((a == b && b == a) || (a == c && c == a)
	     || (b == c && c == b))
      {
	printf("This is an Isosceles Triangle.\n");
	printf("Area: %f\n", sqrt(area));
      }
    else {
      printf("This is a Scalene Triangle.\n");
      printf ("Area: %6.2f\n", sqrt(area));
    }
    
    while(1){
      printf ("Would you like to enter another triangle? [Y//n]: ");
      scanf (" %c", &INPUT);
      
      if (INPUT == 'y' || INPUT == 'Y')
	break;
      else if (INPUT == 'N' || INPUT == 'n')
	return;
    }
  }while(INPUT == 'Y' || INPUT == 'y');
}
