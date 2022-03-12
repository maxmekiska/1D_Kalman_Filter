#ifndef   ONEDKALMANFITLER_HEADER
#define   ONEDKALMANFILTER_HEADER


double kfilter(double measurement, double motion, double measure_sig, double motion_sig, double mu, double sig, bool mean);

#endif
