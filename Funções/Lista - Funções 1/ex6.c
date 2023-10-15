#include<stdio.h>
#include<math.h>

int raizes(float af, float bf, float cf, float *x1, float *x2){ 
	
	float delta = pow(bf, 2) - 4*af*cf;
	printf("\nDelta: %.2f\n", delta);
	
	if(delta >= 0){
		*x1 = (-bf + sqrt(delta)) /(2*af);
		*x2 = (-bf - sqrt(delta)) /(2*af);
		return 1;
	}else{
		printf("\nDelta negativo!...\n");
		return 0;
	}
}

main(){
	float x1, x2;
	
	raizes(2, 1, -15, &x1, &x2);
	
	printf("\n- Raizes - \n");
	printf("\n X'  =  %.1f", x1);
	printf("\n X''  =  %.1f", x2);
}
