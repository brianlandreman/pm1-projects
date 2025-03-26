// guard against multiple includes of the same header file
#ifndef IMAGE_UTIL_H
#define IMAGE_UTIL_H

// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



// define the number of color channels as 3
#define CHANNEL_NUM 3

// define a struct to wrap a byte array of pixel data for an image
typedef struct imatrix{
    int width;
    int height;

    uint8_t** r; // array of red pixel values
    uint8_t** g; // array of green pixel values
    uint8_t** b; // array of blue pixel values

    // function pointers to image manipulation functions
    struct imatrix* (*add)(struct imatrix* this, struct imatrix* m2);
    struct imatrix* (*subtract)(struct imatrix* this, struct imatrix* m2);
    struct imatrix* (*dot)(struct imatrix* this, struct imatrix* m2);
    struct imatrix* (*scale)(struct imatrix* this, int width, int height, float alpha);

    // function pointers to image writing functions
    void (*write_image_to_rgb)(struct imatrix* this);
    void (*write_rgb_to_image)(struct imatrix* m);

    // function pointer to set the pixel data for an image
    struct imatrix* (*set_rgb_image)(struct imatrix* this, uint8_t* new_rgb_image, int width, int height, int channels);

    // internal image reference
    uint8_t* rgb_image;
} imatrix;

// function prototypes
imatrix* init_from_file(char* image_path, int* width, int* height, int* channels);
imatrix* init_from_rgb_image(uint8_t* rgb_image, int width, int height);
imatrix* init_blank_rgb_image(int width, int height);
imatrix* set_rgb_image(imatrix* this, uint8_t* new_rgb_image, int height, int width);
void free_imatrix(imatrix* image);

// enumeration for the red, green, and blue color channels
enum RGB {RED, GREEN, BLUE};

// function prototypes
void init_funcptrs(imatrix* this);
void write_rgb_to_image(imatrix* m);
void write_image_to_rgb(imatrix* this);
imatrix* init_rgb(imatrix* this, int width, int height);
imatrix* add(imatrix* m1, imatrix* m2);
imatrix* subtract(imatrix* m1, imatrix* m2);
imatrix* multiply(imatrix* m1, imatrix* m2);
imatrix* scale(imatrix* this, int width, int height, float alpha);

#endif // end of the header guard
