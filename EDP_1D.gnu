reset
set ylabel "t (s)"
set xlabel "x (m)"

set term png size 1200, 900
set output "resultat1D.png"

set palette rgbformulae 22,13,-31

set pm3d map interpolate 0,0

splot "EDP_1D.txt" u 2:1:3 title ""
