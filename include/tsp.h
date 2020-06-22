#ifndef TSP_H_

#define TSP_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VERBOSE 80  // printing level  (=20 little output, =50-60 good, =80 to plot )

//model type
#define OPT2 0
#define VNS_OPT 1
#define SA_OPT 2

//data structures

typedef struct {
    //input data
    int nnodes;
    double *xcoord;
    double *ycoord;

    // parameters
    int solver_type;
    int initialization;
    double timelimit;       // overall time limit, in sec.s
    char input_file[1000];  // input file

    //eurisitc data
    int *nodes_tour;
    double *distance;
} instance;

void init_heuristic_inst(instance *inst);
void free_instance(instance *inst);
double dist(int i, int j, const instance *inst);
int triangle_xpos(int i, int j, const instance *inst);

#endif /* TSP_H_ */
