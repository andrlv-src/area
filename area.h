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

/* структура конфигурации */
struct config_t {
        _Bool opt_abscissa; /* флаг демонстрации абсцисс */
        _Bool opt_iterations; /* флаг демонстрации итераци */
        float eps;
};

float func_one(float x);
float func_two(float x);
float func_thr(float x);


void print_help();
void print_version();
void print_error(char *str);
void test_func(char *str, int len);
float root(struct config_t conf, float xleft, float xright, float eps, func_t func1, func_t func2);
float integral(float xl, float xr, size_t n, func_t f);

#endif /* AREA_H */
