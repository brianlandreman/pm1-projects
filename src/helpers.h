
#ifndef HELPERS_H
#define HELPERS_H
#include "imageutil.h"
// image resizing function prototypes using stb_image_resize.h with similar function signatures to the image manipulation functions
imatrix* resize_image_to_imatrix(imatrix* input_image, int new_width, int new_height);
imatrix* transpose(imatrix* input_image);
#endif