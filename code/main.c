#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


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

double update_mean(double m1, double var1, double m2, double var2){
	double new_mean;

	new_mean = (m1 * var2 + m2 * var1) / (var1 + var2);
	
	return new_mean;
}

double update_variance(double var1, double var2){
	double new_variance;

	new_variance = 1 / ((1 / var1) + (1 / var2));
	
	return new_variance;
}

double predict_mean(double m1, double m2){
	double new_mean;

	new_mean = m1 + m2;

	return new_mean;
}


double predict_variance(double var1, double var2){
	double new_variance;

	new_variance = var1 + var2;

	return new_variance;
}

double kalmanfilter(double measurements[], int count_measurements, double motions[], double measure_sig, double motion_sig, double mu, double sig){
	for(int i = 0; i < count_measurements; i++){
		mu = update_mean(mu, sig, measurements[i], measure_sig);
		sig = update_variance(sig, measure_sig);
		printf("Update: mean = %.15f, sigma = %.15f\n", mu, sig);
		mu = predict_mean(mu, motions[i]); 	
		sig = predict_variance(sig, motion_sig);
		printf("Prediction: mean = %.15f, sigma = %.15f\n", mu, sig);
	}
	return 0;

}


double step(double measurement, double motion, double measure_sig, double motion_sig, double mu, double sig, bool mean){

	mu = update_mean(mu, sig, measurement, measure_sig);
	sig = update_variance(sig, measure_sig);
	printf("Update: mean = %.15f, sigma = %.15f\n", mu, sig);

	if(mean == true){
		mu = predict_mean(mu, motion);
		return mu;
	}
	else{
		sig = predict_variance(sig, motion_sig);
		return sig;
	}
}

int main(void) {
  double measurements[] = {5, 6, 7, 9, 10};
  double motions[] = {1, 1, 2, 1, 1};
  double mu = 0;
  double sig = 10000;
  double new_mu, new_sig;

  /*kalmanfilter(measurements, 5, motions, 4, 2, 0, 10000);*/


  for(int i = 0; i < 5; i++){
	  new_mu = step(measurements[i], motions[i], 4, 2, mu, sig, true);
	  new_sig = step(measurements[i], motions[i], 4, 2, mu, sig, false);
	  mu = new_mu;
	  sig = new_sig;
  }


  printf("Final Prediction: mean = %.15f, sigma = %.15f\n", mu, sig);
  

  system("pause");


  return 0;
}
