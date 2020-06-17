#ifndef MY_STRING
#define MY_STRING

#include <string.h>

#define FILE_NOT_FOUND_STRING "Input file not found!"
#define REPEATED_DIMENSION_STRING "Repeated DIMENSION section in input file"
#define EDGE_WEIGHT_TYPE_ERROR_STRING "Format error: only EDGE_WEIGHT_TYPE == EUC_2D implemented so far!"
#define DIMENSION_ERROR_STRING "... DIMENSION section should appear before NODE_COORD_SECTION section"
#define NODE_ERROR_STRING "...Unknown node in NODE_COORD_SECTION section"
#define WRONG_FORMAT_ERROR "...Wrong format for the current simplified parser!"
#define TIME_LIMIT_NOT_FOUND_STRING "Time limit not defined"

#define NN_INIT_STRING "Nearest Neighborhood initialization\n"
#define GRASP_INIT_STRING "Random GRASP initialization\n"

//Error
#define ERROR_PLOT_VALUE_STRING "Wrong plot value"
#define ERROR_INIT_VALUE_STRING "Wrong initialization value"
#define ERROR_DISTANCE_STRING "Distance not computed!"
#define ERROR_SOLVER_TYPE_STRING "Wrong Solver Value"

//GNUPlot
#define GNUPLOT_OPEN_COMMAND "gnuplot -persistent"

//VERBOSE
#define VERBOSE_LITTLE_OUTPUT 20
#define VERBOSE_TO_PLOT 80
#endif /* MY_STRING */
