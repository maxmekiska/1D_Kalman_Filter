#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "onedkalmanfilter.h"
#include "stats.h"

int main(void) {
	  double measurements[] = {5, 6, 7, 9, 10};
	  double motions[] = {1, 1, 2, 1, 1};
	  double mu = 0;
	  double sig = 10000;
	  double new_mu, new_sig;



	  for(int i = 0; i < 5; i++){
		  new_mu = kfilter(measurements[i], motions[i], 4, 2, mu, sig, true);
		  new_sig = kfilter(measurements[i], motions[i], 4, 2, mu, sig, false);
		  mu = new_mu;
		  sig = new_sig;
	  }


	  printf("Final Prediction: mean = %.15f, sigma = %.15f\n", mu, sig);

	  double gdensity;
	  gdensity = gauss(0, 1, 2);

	  printf("Gauss says: %.15f", gdensity);
	  

	  system("pause");


	  return 0;
}
