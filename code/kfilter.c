#include <stdbool.h>

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

double kfilter(double measurement, double motion, double measure_sig, double motion_sig, double mu, double sig, bool mean){

	mu = update_mean(mu, sig, measurement, measure_sig);
	sig = update_variance(sig, measure_sig);

	if(mean == true){
		mu = predict_mean(mu, motion);
		return mu;
	}
	else{
		sig = predict_variance(sig, motion_sig);
		return sig;
	}
}
