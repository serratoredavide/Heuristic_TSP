#include "heuristic_solver_TSP.h"
#include "mystring.h"
#include "tsp.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s -help for help\n", argv[0]);
        return 0;
    }
    //struct initialization
    instance inst;

    //read commands and input
    parse_command_line(argc, argv, &inst);
    read_input(&inst);
    printf("Numbers of node: %d\n", inst.nnodes);

    init_heuristic_inst(&inst);

    //solve problem
    switch (inst.solver_type) {
        case OPT2:
            printf("Solving problem using 2-Opt\n");
            //init
            if (inst.initialization == 0)
                nearest_neighborhood(&inst);
            else
                random_GRASP(&inst);
            opt_2(&inst, inst.nodes_tour, 1);
            break;
        case VNS_OPT:
            printf("Solving problem using Variable Neighborhood Search\n");
            VNS(&inst, inst.initialization);
            break;
        case SA_OPT:
            printf("Solving problem using Simulated Annealing\n");
            simulated_annealing(&inst, inst.initialization);
            break;
        default:
            printf("Solver Type is not define correctly");
            return 0;
            break;
    }

    //free instance struct
    free_instance(&inst);

    return 0;
}
