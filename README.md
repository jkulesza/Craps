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
 
