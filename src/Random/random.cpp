//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "random.h"

double randDouble() {
    int max = 1e8;
    int rnd = rand() % max;

    return (double)rnd / max;
}