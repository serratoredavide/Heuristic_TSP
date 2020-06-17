#include "tsp.h"

#include <unistd.h>
// #include <time.h>

#include "mystring.h"
#include "utils.h"

//#define DEBUG

/**
 * @brief Memory allocation for heuristic structure
 * 
 * @param inst 
 */
void init_heuristic_inst(instance *inst) {
    int num_nodes = inst->nnodes;
    int num_x_columns = (num_nodes * num_nodes) - num_nodes * (num_nodes + 1) / 2;
    inst->nodes_tour = (int *)malloc(num_nodes * sizeof(int));
    inst->distance = (double *)malloc(num_x_columns * sizeof(double));

    //init distance between nodes
    for (int i = 0; i < num_x_columns; i++) {
        inst->distance[i] = -1.0;
    }
}

/**
 * @brief Free pointer to coord
 * 
 * @param inst Pointer to struct
 */
void free_instance(instance *inst) {
    free(inst->xcoord);
    free(inst->ycoord);
    if (inst->nodes_tour != NULL) free(inst->nodes_tour);
    if (inst->distance != NULL) free(inst->distance);
}

/**
 * @brief Compute the distance using Euclidian distance
 * 
 * @param i First node index
 * @param j Second node index
 * @param inst Pointer to struct
 * @return double : Distance value
 */
double dist(int i, int j, const instance *inst) {
    double dx = inst->xcoord[i] - inst->xcoord[j];
    double dy = inst->ycoord[i] - inst->ycoord[j];
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Compute edge's position in the model
 * 
 * @param i First node
 * @param j Second node
 * @param inst Pointer to struct
 * @return int : Position in the model
 */
int triangle_xpos(int i, int j, const instance *inst) {
    if (i == j) print_error(" i == j in xpos");
    if (i > j) return triangle_xpos(j, i, inst);
    return i * inst->nnodes + j - ((i + 1) * (i + 2)) / 2;
}
