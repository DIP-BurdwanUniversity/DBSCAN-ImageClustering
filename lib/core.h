#ifndef CORE_H
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma once
#define DEBUG 0
#define MAX_INTENSITY 256
#define MAX_IMAGE_HEIGHT 512
#define MAX_IMAGE_WIDTH 512
#define MAX_CLUSTER_SIZE 100
#define MAX_COORD_SIZE 100000

// Globally accessible image array filled up in Kmeans.c >> processing 
int image_arr[MAX_IMAGE_HEIGHT+1][MAX_IMAGE_WIDTH+1];
int nbd_dist[MAX_IMAGE_HEIGHT+1][MAX_IMAGE_WIDTH+1];

/*Structure for BMP Header*/
struct bmpheader {
    unsigned char id1;                 // first 2-bytes for BM ID field [1-byte]
    unsigned char id2;                 //                  ;;           [1-byte]
    unsigned int size;                 // Size of the BMP file
    unsigned short int app_spec_1;     // Application specific
    unsigned short int app_spec_2;     // Application specific
    unsigned int offset;               // Offset where the pixel array (bitmap data) can be found
};

/*Structure for DIB [Device Independent Bitmap] Header*/
struct dibheader {
    unsigned int size;                  // Number of bytes in the DIB header (from this point)
    int width;                          // Width of the bitmap in pixels
    int height;                         // Height of the bitmap in pixels. Positive for bottom to top pixel order
    unsigned short int color_planes;    // Number of color planes being used
    unsigned short int bits_per_pixel;  // Number of bits per pixel
    unsigned int compression;           // BI_RGB, pixel array compression used
    unsigned int size_with_padding;     // Size of the raw bitmap data (including padding)
    unsigned int resolution_horizontal; // resolution of the image (horizontal)
    unsigned int resolution_vertical;   // resolution of the image (vertical)
    unsigned int color_palette;         // Number of colors in the palette
    unsigned int important_colors;      // Number of important colors; 0 means all colors are important
};

// Structure for image color plane
struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif