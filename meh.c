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
#include <math.h> /* For GCC, use -lm */
#define _CRT_SECURE_NO_WARNINGS /* Because Windows... */
double sqrt (double x); /*<math.h> library, square root function prototype*/
void type (float, float, float); /*Function Prototype */
void loop (void);
int main (void) /*main function*/
{
  float a, b, c;
  
  printf ("Please enter values: \n");
  scanf ("%f %f %f", &a, &b, &c);
  /*Missing instructions to check for valid triangle inside here because of your dumbass*/
  return 0;
}

void type (float a, float b, float c)
{
  float sqt = (a + b + c) / 2.0;
  float area = sqt * ((sqt-a) * (sqt-b) * (sqt-c));/*Formulas*/
  
  if ((a == b) && (a == c) && (b == a) && (b == c) && (c == a) && (c == b))
    {
      printf ("This is an Equilateral Triangle.\n");
      printf ("Area: %f\n", sqrt(area));
    }
  else if ((a == b && b == a) || (a == c && c == a)
	   || (b == c && c == b)) 
    {
      printf ("This is an Isosceles Triangle.\n");
      printf ("Area: %f\n", sqrt(area));
    }
  else {
    printf ("This is a Scalene Triangle.\n");
  }

  loop(); /*Func to continue running program according to input*/
  return;
}

void loop (void)
{
  char INPUT;

  printf ("Continue [Y//n]: ");
  scanf ("%c", &INPUT);

  if (INPUT == 'Y' || INPUT == 'y')
    main();
  else if (INPUT == 'N' || INPUT == 'n')
    return;
}
  
