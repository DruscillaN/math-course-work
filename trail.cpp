#include <stdio.h>
#include <math.h>
/* SIGN function definition as a macro */
#define sign(x) (x > 0) ? 1 : ((x < 0) ? -1 : 0)

/* functions prototype */
float f (float x);
int f_disp (int i, float a, float b, float c);

int main(void){
 float a = 0; /* left point */
 float b = 1; /* right point */
 float TOL = 1E-2; /* tolerance */
 float NMAX = 11; /* maximum number of iterations */
 float c = 0; /* estimated root */
 int i = 0; /* index */
 
 c = (a + b)/2; /* calculate the midpoint */
 
 /* Display the table header and initial data */
 printf("i\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\n");
 f_disp(i, a, b, c);
 
 /* Evaluate loop until the result is less than the tolerance
 * maximum number of iterations is not yet reached*/
 
 if (f(c) == 0){
  /* If the first midpoint gives f(c) = 0, c is the root */
  printf("Root is: %f \n", c);}
  else{
   while ((fabs(f(c)) > TOL) && (i<=NMAX)){
    if (f(c)*f(a)>0){
     /* f(c) has same sign as f(a) */
    a= c;}
    else{
     /* f(c) has same sign as f(b) */
    b = c;} 
    c = (a+b)/2; /* midpoint update */
    f_disp(i+1, a, b, c); /* display current data */
   i++; /* index increment */}}
 
 /* Display results */
printf("\nRoot is c=%.7f found after %d iterations\n", c, i);
 printf("The value of the function f(c) is: %.10f\n", f(c));
 return 0;}

/* function definition */
float f (float x){
 float y;
 y = sqrt(x)-cos(x);
 return y;} 

/* display function definition */
int f_disp (int i, float a, float b, float c){
 printf("%d\t%.7f\t%.7f\t%.7f\t", i, a, b, c);
 printf("%.7f\t%.7f\t%.7f\n", f(a), f(b), f(c));
 return 0;} 
 
 /*For a given function f(x),the Bisection Method algorithm works as follows:

two values a and b are chosen for which f(a) > 0 and f(b) < 0 (or the other way around)
interval halving: a midpoint c is calculated as the arithmetic mean between a and b, c = (a + b) / 2
the function f is evaluated for the value of c
if f(c) = 0 means that we found the root of the function, which is c
if f(c) ? 0 we check the sign of f(c):
if f(c) has the same sign as f(a) we replace a with c and we keep the same value for b
if f(c) has the same sign as f(b), we replace b with c and we keep the same value for a
we go back to step 2. and recalculate c with the new value of a or b
The algorithm ends when the values of f(c) is less than a defined tolerance (e.g. 0.001). In this case we say that c is close enough to be the root of the function for which f(c) ~= 0.

In order to avoid too many iterations, we can set a maximum number of iterations (e.g. 1000) and even if we are above the defined tolerance, we keep the last value of c as the root of our function*/

