histogram: histogram.c
	gcc -c histogram.c
	gcc -o histogram histogram.o
clean: histogram histogram.o data.dat
	rm histogram histogram.o data.dat
gnuplot: data.dat
	gnuplot 
	plot 'data.dat'