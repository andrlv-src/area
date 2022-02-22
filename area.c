/* file area.c
 * author A.Lvov
 */

#include <stdio.h>
#include <math.h>
#include <float.h>
#include "area.h"

float func_one(float x)
{
        return 0.6 * x + 3;
}

float func_two(float x)
{
        return pow((x - 2), 3) - 1;
}

float func_thr(float x)
{
        if(x == 0)
                return FLT_MAX;
        return 3 / x;
}

float root(struct config_t conf, float xl, float xr, float eps, func_t f1, func_t f2)
{
        static int n = 1;
        int steps = 0;
        while(fabs(f1(xr) - f2(xr)) > eps && fabs(xr-xl) > eps) {
                xl = xr - (xr - xl) * (f1(xr) - f2(xr)) / ((f1(xr) - f2(xr)) - (f1(xl) - f2(xl)));
                xr = xl - (xl - xr) * (f1(xl) - f2(xl)) / ((f1(xl) - f2(xl)) - (f1(xr) - f2(xr)));
                steps++;
        }

        if (conf.opt_abscissa) {
                printf("Корень %d: %f", n++, xr);
                if (conf.opt_iterations)
                        printf(", найден за %d итераций.\n", steps);
                else
                        printf(".\n");
        }
        return xr;
}

/*
float root(float xleft, float xright, float eps, func_t func1, func_t func2) {
        int steps=0;
        float xmid = (xleft + xright) / 2;
        while (fabs(func1(xmid) - func2(xmid)) > eps) {
                xmid = (xleft + xright) / 2;

                if (fabs(func1(xleft) - func2(xleft)) < eps)
                        xmid = xleft;
                else if (fabs(func1(xright) - func2(xleft)) < eps)
                        xmid = xright;

                if ((func1(xleft) - func2(xleft) < 0 ? -1 : 1) != (func1(xmid) - func2(xmid) < 0 ? -1 : 1))
                        xright = xmid;
                else
                        xleft = xmid;

                if((func1(xleft) - func2(xleft) < 0 ? -1 : 1) == (func1(xright) - func2(xright) < 0 ? -1 : 1)) {
                        xmid = NAN;
                        break;
                }
                steps++;
        }
        printf("Корень %f найден за %d итераций\n", xmid, steps);
        return xmid;
}
*/
float integral(func_t f, float xl, float xr, size_t n) {
        float sum = 0;
        float h = (xr - xl) / n;
        for(size_t i = 0; i < n; i++) {
                sum += f(xl);
                xl += h; }
        return sum * h;
}

/*
float integral(func_t func, float xleft, float xright, float eps)
{
        float sum = 0;
        int n = 4;
        float h = (xright - xleft) / n;
        for(float x = xleft + h; x < xright - h; x += h) {
                sum += 0.5 * h *(func(x) + func(x + h));
        }
        return sum;
}
*/

void print_help()
{
        printf("Использование: " APP_NAME " [опции]\n");
        printf("  -a\tВывести абсциссы точек пересечения кривых.\n");
        printf("  -h\tВывести собщение о помощи.\n");
        printf("  -v\tВывести информацию о версии.\n");
        printf("  -i\tВывести количество итераций.\n");
        printf("  -p\tЗадать точность. Точность по умолчанию = 0.001.\n");
}

void print_version()
{
        printf(APP_NAME " version %s\n", VERSION);
        printf("  Copyright (C) 2022 Andrey Lvov.\n");
        /* printf(
           "This is free software: you are free to change and redistribute it.\n");*/
        printf("  There is NO WARRANTY, to the extent permitted by law.\n");
}

void print_error(char *str)
{
        fprintf(stderr, "%s", str);
}
