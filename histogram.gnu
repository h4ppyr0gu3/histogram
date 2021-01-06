set term x11 persist
set title "Histogram"
set ylabel "Number of points"
set style fill solid border
set yrange [0:*]
set style data histogram
set style histogram 
set style line 1 lc rgb '#0060ad' 
set grid ytics linestyle 1
plot for [COL=3:3] "data.dat" using COL:xticlabels(1)  title columnheader linecolor rgb "#00FF00"