#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double random_n(double, double);

struct ATOMS {
	double rx, ry, rz;
	double vx, vy, vz;
	double m, M;
	double r;
	double kin_energy, pot_energy, tot_energy;
};

int main(){
	int i, n;
	double ra, rb, va, vb, ma, mb;
	double total_energy;
	const double G = 6.67430e-11;
	
	time_t t;
	srand((unsigned) time(&t));
	
	
	//define position interval
	printf("Please enter the position interval: ");
	scanf("%lf", &ra);
	printf("and: ");
	scanf("%lf", &rb);
	
	//define velocity interval
	printf("Please enter the velocity interval: ");
	scanf("%lf", &va);
	printf("and: ");
	scanf("%lf", &vb);
	
	n = 100; //number of atoms
	struct ATOMS atomistic[n];
	total_energy = 0; 
	
	for (i = 0; i<n; i++){
		
		//define position
		atomistic[i].rx = random_n(ra, rb);
		atomistic[i].ry = random_n(ra, rb);
		atomistic[i].rz = random_n(ra, rb);
		
		//define velocity
		atomistic[i].vx = random_n(va, vb);
		atomistic[i].vy = random_n(va, vb);
		atomistic[i].vz = random_n(va, vb);

		//define mass of interacting atoms m, M 
		ma = 1;
		mb = 118;
		atomistic[i].m = random_n(ma, mb);
		atomistic[i].M = random_n(ma, mb);
		
		//calculate kinetic energy
		atomistic[i].kin_energy = 0.5 * atomistic[i].m * (pow(atomistic[i].vx,2) + pow(atomistic[i].vy,2) + pow(atomistic[i].vz,2));
		
		//calculate potential energy
		atomistic[i].pot_energy = -G * atomistic[i].m * atomistic[i].M / sqrt(pow(atomistic[i].rx, 2) + pow(atomistic[i].ry, 2) + pow(atomistic[i].rz, 2));
		
		//calculate total energy
		atomistic[i].tot_energy = atomistic[i].kin_energy + 0.5 * atomistic[i].pot_energy;
		printf("Total energy of atom: %e\n", atomistic[i].tot_energy);
		
		//sum of all atoms' total energy
		total_energy += atomistic[i].tot_energy;
	}
	
	printf("Sum of total energy of %d atoms with random masses is: %e\n", n, total_energy);
	
	return 0;
}




double random_n(double a, double b){

	double HI, LO, n;

	if (a>b){
		HI = a;
		LO = b;
	}else{
		HI = b;
		LO = a;
	}	
	n = LO+(double)(rand())/((double)(RAND_MAX/(HI-LO)));

	return n;
}
