reset
set arrow from -1.6,-7.2 to -1.6,5.8 lw 2
set label '{{/=20 E}{/=12(eV)}}' at -1.3,5.8
unset tics
set xr[-2.5:4.5]
set yr[-7.3:6.2]
unset key

set label '{-6.144}' at -.85, -6.144
set label '{-5.204}' at -.85, -5.204
set label '{-2.496}' at -.85, -2.496
set label '{0.512}'  at -.85, 0.512
set label '{1.787}'  at -.85, 1.787
set label '{4.045}'  at -.85, 4.045

plot "energ.dat" using 1:2:($3-$1):($4-$2) with vectors nohead lt 8 lw 2

set term eps
set output 'energ.eps'
replot
unset term
