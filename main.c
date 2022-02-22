/* file main.c
 * author A.Lvov
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <math.h>

#include "area.h"

int main(int argc, char *argv[])
{

        int arg = 0;
        opterr = 0;

        struct config_t conf;
        conf.opt_abscissa = false;
        conf.opt_iterations = false;
        conf.eps = 0.001;

        float area = 0.0;
        float xleft = -10;
        float xright = 10;

        float roots[3];
        float integrals[4];

        while ((arg = getopt(argc, argv, "ahip:v")) != -1) {
                switch (arg) {
                case 'a':
                        conf.opt_abscissa = true;
                        break;
                case 'h':
                        print_help();
                        return 0;
                        break;
                case 'v':
                        print_version();
                        return 0;
                        break;
                case 'i':
                        conf.opt_iterations = true;
                        break;
                case 'p':
                        conf.eps = atof(optarg);
                        printf("Установлена точность эпсилон %f\n", conf.eps);
                        break;
                case '?':
                        print_error(ERROR " Не верный(е) аргументы.\n");
                        print_error("\tДля получения помощи используйте -h.\n");
                        exit(1);
                        break;
                default:
                        printf("default case\n");
                        break;
                }
        }
#if 0
        for (float i = 0.001; i < 100; i += 0.0001) {
                if (fabs(func_one(i) - func_thr(i)) < conf.eps){
                        printf("f1-f2 %f\n", i);
                        break;
                }
        }
#endif
        printf("Вычисление корней функций:\n1. 0.6x+3.\n2. (x-2)^3-1.\n3. 3/x.\n");
        roots[0] = root(conf, xleft, xright, conf.eps, func_one, func_two);
        roots[1] = root(conf, xleft, xright, conf.eps, func_two, func_thr);
        /* roots[2] = root(conf, xleft, xright, conf.eps, func_thr, func_one); */
        roots[2] = root(conf, xleft, 1, conf.eps, func_thr, func_one);

        printf("\nВычисление интегралов:\n");
        integrals[0] = integral(func_one, roots[0], roots[1], 1000);
        integrals[1] = integral(func_two, roots[1], roots[2], 1000);
        integrals[2] = integral(func_thr, roots[1], roots[2], 1000);
        /* integrals[0] = integral(func_one, roots[1], roots[2], conf.eps); */
        /* integrals[1] = integral(func_two, roots[1], roots[2], conf.eps); */
        /* integrals[2] = integral(func_thr, roots[0], roots[2], conf.eps); */
        for (size_t i = 0; i < 3; ++i) {
                printf("Интегралl %li is %f\n", i + 1, integrals[i]);
                area += integrals[i];

        }
        printf("\nВычисление площади:\n");
        printf("Площадь: %f\n", area);
        return 0;
}
