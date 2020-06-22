# Heuristic_TSP_Approach

### Sistemi Intelligenti's project report
University of Padua | Computer Engineering Department


#### Authors
Serratore Davide - M.1207660 | Vesco Omar - M.1197699

---

## Repository content

	Report.pdf                    \\ Project report
	data/*.tsp                    \\ TspLib instances used in the report http://elib.zib.de/pub/mp-testdata/tsp/tsplib/tsp/index.html

	Makefile                      \\ Makefile to compile code
	src/tsp.c                     \\ General structure of the problem and some useful function
	src/heuristic_solver_TSP.c    \\ Heuristic algorithms
	src/utils.c                   \\ Function utility
	include/*.h                   \\ headers



## Compile and Execution

To compile:

	make 

To execute code. Some parameters are needed:

	./exec_tsp -file data/xxxxx.tsp 

Parameters:

	-help | --help          \\ for help
	-file | -f | -input     \\ input instances
	-timelimit              \\ Needed for VNS (number of iterations) and SA (time in seconds)
	-solver_type            \\ 0 for 2-Opt, 1 for VNS, 2 for SA
	-init                   \\ 0 for Nearest Neighborhood, 1 for Random GRASP


VERBOSE is also defined in tsp.h. To plot tour: VERBOSE >= 80

`make clean` to clean up executable files
