#ifndef UTIL_H
#pragma once
#include "core.h"

void printNBDArray(int height, int width) {
    int i,j;
    for(i=1; i<=height; i++) {
        for(j=1; j<=width; j++) {
            printf("%d ", nbd_dist[i][j]);
        }
        printf("\n");
    }
}

void scale_density_to_image(int height, int width) {
    int i,j;
    for(i=1; i<=height; i++) {
        for(j=1; j<width; j++) {
            nbd_dist[i][j] = (nbd_dist[i][j]*10) + 15;
        }
    }
}

#endif