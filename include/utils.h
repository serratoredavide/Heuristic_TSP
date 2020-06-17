#include "tsp.h"

void print_error(const char *err);
void sendCommands(FILE *gnuplotPipe, char *commandsForGnuplot[], int numCommands);
void createPointsFile(const instance *inst, FILE *temp);
void parse_command_line(int argc, char **argv, instance *inst);
void read_input(instance *inst);
