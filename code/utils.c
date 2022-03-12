#include <math.h>
#include "stats.h"


double gauss(double mu, double sigma, double x){
	double prob;
  	double term1;
	double term2;
	double sigma_sqrt;

	sigma_sqrt = pow(sigma, 2);

	term1 = pow((2 * M_PI * sigma_sqrt), -0.5);
	term2 = exp(-(pow(x-mu, 2)) / 2 * sigma_sqrt);

	prob = term1 * term2;
	return prob;
}
