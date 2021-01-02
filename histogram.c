
// Homework 1 
// -HistogramA histogram is a representation ofnumerical data which groups data into binsof equal width. 
// Each bin is plotted as a bar whose height corresponds to how many data points are in that bin. 
// Bins are also sometimes called "intervals" or "buckets". Write a program, which will draw a histogram with 
// a given number of bins, for a dataset taken from a file. You have to deliver/generate your own dataset, ie. 
// by random number generation.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int generate (int number, int *random, int columns);

int main () {

	int number_of_values, number_of_columns;
	int *values;

	values = malloc(number_of_values * sizeof(int));

	printf("how many values would you like to be sorted\nnumber of values: ");
	scanf("%d", &number_of_values);
	printf("how many columns would you like\nnumber of columns: ");
	scanf("%d", &number_of_columns);

	generate(number_of_values, values, number_of_columns);
	printf(".....................................................\n");

	for(int i = 0; i < number_of_values; i++ ) {
		printf("%d\t", values[i]);
	}
	free(values);
}

int generate (int number, int *random, int columns) {

  random = malloc(number * sizeof(int));

	srand(time(NULL));

	for (int i = 0; i < number ; ++i) {
		
		random[i] = (double)rand()/RAND_MAX * (columns + 1);
		printf("%d\n", (int)random[i]);
	}
}

int write_to_file() {

	FILE *file;
	file = fopen("data.dat", "w");
	for(int i = 0; i < number; ++i) {
		fprintf(stderr, "%s\n", );
	}
	fclose(file)

}

int sort_by_value (int number_of_values, int divider, int values[]) {
	
	int count = 0;

	for(int i = 0; i < number_of_values; i++) {
		if( values[i] % divider == 0 )
			count ++;
	}
	return count;
}