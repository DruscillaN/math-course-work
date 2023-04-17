#include <stdio.h>
int main(){
	float a;
	a=3000.00;
	for (a*=1.5;a<1500000;a+=a*2){
		printf ("%.1f\n",a);
	};
	//try it out
	
}
