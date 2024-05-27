#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_POINTS 10000
#define MEAN 0.5

double generate_exponential(double mean) {
    double lambda = 1.0 / mean;
    double u = (double) rand() / RAND_MAX; // Uniform random variable between 0 and 1
    return -log(u) / lambda;
}

int main() {
    int i;
    double data[NUM_POINTS];
    double lambda = 1.0 / MEAN;
    srand(time(NULL));

    // Generate random numbers
    for (i = 0; i < NUM_POINTS; i++) {
        data[i] = generate_exponential(MEAN);
    }

    // Save data to a file
    FILE *fp;
    fp = fopen("exponential_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < NUM_POINTS; i++) {
        fprintf(fp, "%.6f\n", data[i]);
    }

    fclose(fp);
    printf("Data saved to 'exponential_data.txt'.\n");

    return 0;
}
