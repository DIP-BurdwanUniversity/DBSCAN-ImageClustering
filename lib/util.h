#ifndef UTIL_H
#pragma once
#include "core.h"
#define PAIR_LIMIT 10
#define INIT_CLUSTER_LIM 50

typedef struct pair {
    int x;
    int y;
} pair;

// Structure for image cluster
typedef struct Cluster {
    int freePosCounter;  // Tracks free position in points array 
    pair __centroid;     // Cluster centroid
    pair points[MAX_COORD_SIZE];    // [(x1,y1), (x2,y2), (x3,y3),...]
    void (*add_ptr) (struct Cluster *c, pair point); // function pointer
} Cluster;

// Global cluster array stores array of coordinates falling into a cluster 
Cluster KMeansCluster[MAX_CLUSTER_SIZE];

pair idx[INIT_CLUSTER_LIM];     // initial random indexes

// Compares two pairs for equality
bool pairCompare(pair A, pair B) {
    if(A.x==B.x && A.y==B.y) return true;
    return false;
}

// Similar to pairCompare(): works with arrays
bool pairArrayCompare(pair A[], pair B[]) {
    int i;
    for(i=0; i<PAIR_LIMIT; i++) {
        if(A[i].x!=B[i].x || A[i].y!=B[i].y) return false; 
    }
    return true;
}

// Generates random initial centroid pixel coordinates [max. clusters 50]
void GenerateInitialCentroids(int pts) {
    int i;
    // Some random f(x,y) to generate initial random points...
    for(i=0; i<pts; i++) {
        idx[i].x=pts*i + 2*i + i;
        idx[i].y=pts*i + 2*pts + i;
    }
}

// Wrapper returns gray level for pair
int getGrayLevel(pair p) {
    return image_arr[p.x][p.y];
}

// Function pointer to append points inside a cluster 
void add(Cluster *c, pair point) {
    c->freePosCounter++;
    // printf("\nfree pos. count : %d", c.freePosCounter);
    if(c->freePosCounter < 0) {
        printf("Underflow occured\nExiting...\n");
        return;
    }
    else if(c->freePosCounter >= MAX_COORD_SIZE) {
        printf("Overflow occured\nExiting...\n");
        return;
    }
    c->points[c->freePosCounter] = point;
}

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