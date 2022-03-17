#include <stdbool.h>
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

double variance(double num[], int size, bool population) {
  double squared_sum = 0.0;
  double mean = 0.0;
  double result;
  
  for(int i = 0; i < size; ++i){
    mean += num[i];
  } 
  
  mean = mean/size;

  for(int i = 0; i < size; ++i) {
    squared_sum += pow((num[i] - mean), 2);
  }
  
  if(population == true){
    result = squared_sum / size;
  }
  
  else{
    result = squared_sum / (size - 1); 
    
  }
  return result; 
}
