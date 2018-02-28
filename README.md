# OS Project 2
# Measuring the Performance of Page Replacement Algorithms on Real Traces		 	 	 		

This program tests three page replacement algorithms: First-In First-Out(FIFO), Last Recently Used(LRU), and Virtual Machine placement(VMS). This project uses a memory simulator to assess the memory performance of each algorithm using traces from real world applications taken from SPEC benchmarks. 
				
# Set Up and Running

To run memsim.c, run the makefile included in the zip file to compile the code. Once compiled use the memsim command (./memsim) to run the code. Along with the command, 4 additional arguments in the following order must be taken in the format:

./memsim <tracefile> <nframes> <lru|fifo|vms> <debug|quiet>

The second argument, tracefile, will contain one of the tracefiles included in the zip file. Each .trace file will contain one million memory accesses in HEX followed by either an R or W for reading or writing.

The third argument, nframes, will be the number of page frames in the simulated memory. 

The fourth argument has three options for each of the three page replacement algorithms.

The fifth argument can be used to have a quiet output or a debugging output. The quiet output will run the program and display statistics about the trace including the number of memory frames, events, total disk reads, and writes. The debug output will display the trace’s events.

# Contributors 

Ashley Benjamin-Shallow and Blanche Pinto


