/* file area.h
 * author A.Lvov
 */

#include <stdbool.h>

#ifndef AREA_H
#define AREA_H

#define VERSION "0.1"
#define APP_NAME "area"
#define DEBUG "[DEBUG]"
#define ERROR "[ERROR]"

/* function prototype */
typedef float(*func_t)(float);

struct config_t {
        _Bool opt_abscissa;
        _Bool opt_iterations;
        float eps;
};

float func_one(float x);
float func_two(float x);
float func_thr(float x);

void print_help();
void print_version();
void print_error(char *str);
float root(struct config_t conf, float xleft, float xright, float eps, func_t func1, func_t func2);
float integral(float xl, float xr, float eps, func_t func);

#endif /* AREA_H */
