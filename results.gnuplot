#!/usr/bin/gnuplot

set terminal png size 1024, 768
set output 'craps.png'
set key outside 

set ytics nomirror
set y2tics
set y2label 'Win/Loss Percent' 

set title 'Wins, Losses, and Total Games for Simulated Craps'
set xlabel 'Batch of Games' 
set ylabel 'Result (Wins/Losses/Total Games)'

plot 'craps.out' using 1:2  title 'Wins'            with lines, \
     'craps.out' using 1:3  title 'Losses'          with lines, \
     'craps.out' using 1:17 title 'Total Games'     with lines, \
     'craps.out' using 1:18 title 'Win Percentage'  with lines axis x1y2, \
     'craps.out' using 1:19 title 'Loss Percentage' with lines axis x1y2
