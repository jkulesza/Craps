Craps
-----

This is a simple program (inspired by Bryan Hayden) written to perform
simulations of the dice-based game, Craps.  It was written in serial (at a time
when multi-core consumer processors didn't exist).  However, this may allow it to
serve as a tool for learning how to parallelize a serial computer code.

Compilation
-----------

```g++ craps.cpp```

Execution
---------

./a.out TOTALGAMES FILENAME

This will append the output statistics to the end of the FILENAME specified.

If no such file exists, it will be created.

Results Processing
------------------

A GNUPlot input file is provided to work with an output file produced by this 
application. 

One can simply execute ```gnuplot results.gnuplot``` if the output file is 
named ```craps.out```.  Otherwise, some modification of the 
```results.gnuplot``` will be necessary.
 
