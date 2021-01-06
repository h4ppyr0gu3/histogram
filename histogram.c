/* David Rogers
X-1983
Histogram using gnuplot
https://github.com/h4ppyr0gu3/histogram  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *generate (int number, int columns);
int sort_by_value (int number_of_values, int divider, int *values);
int write_to_file(int number, int *columns);

int main () {

	char * commandsForGnuplot[] = {"set title \"TITLEEEEE\"", "plot 'data.temp'"};

	int number_of_values, number_of_columns, random;
	int *values, *columns;

	values = malloc((number_of_values + 1)* 4 *sizeof(int));
	columns = malloc((number_of_columns + 1) * 4 *sizeof(int));

	printf("how many values would you like to be sorted\nnumber of values: ");
	scanf("%d", &number_of_values);
	printf("how many columns would you like\nnumber of columns: ");
	scanf("%d", &number_of_columns);

	values = generate(number_of_values, number_of_columns);

	for(int i = 0; i < number_of_values; i++ ) {
		// printf("%d\t", values[i]);
	}

	for (int i = 0; i <= number_of_columns; ++i)	{
		int count = 0;
		for (int j = 0; j <= (number_of_values - 1); ++j)	{
			random = values[j];
			// printf("random value = %d\n", random);
			if(random == i) {
				count++;
				columns[i] = count;
				// printf("%d\n", columns[i]);
			}
		}
	}

	for (int i = 0; i < number_of_columns; ++i)	{
		// printf("index = %d,   %d\n",i, columns[i]);
	}

	write_to_file(number_of_columns, columns);

	free(columns);
	free(values);

	system("sh histogram.sh");
}

int *generate (int number, int columns) {
  int *random = malloc((number + 1) * 4 * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < number ; i++) {
		random[i] = (double)rand()/RAND_MAX * (columns );
		// printf("%d\n", (int)random[i]);
	}

	return random;
}

int write_to_file(int number, int *columns) {
	FILE *ptr;
	ptr = fopen("data.dat", "w");
	fprintf(ptr, "column index value\n");
	for(int i = 0; i < number; ++i) {
		fprintf(ptr, "column%d %d %d \n", (i + 1), (i + 1), columns[i]);
		printf("%d %d\n", i , columns[i]);
	}
	fclose(ptr);
	return 0;
}

int sort_by_value (int number_of_values, int divider, int *values) {
	
	int count = 0;

	for(int i = 0; i < number_of_values; i++) {
		if( values[i] % divider == 0 )
			count ++;
		else continue;
	}
	return count;
}