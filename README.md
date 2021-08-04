# Libido - \<libido/\>
A C math library.

[what the fucj]()

[Installation](#installation)
[Documentation](#documentation)
# Installation:
1. Copy everything to /usr/include/libido, or run install.sh to do it for you.
2. Compile using ./compile.
# Documentation:
## Vector - <libido/vector.h>
| Variable Type: | Members: | Description:<img width=1000/> |
| - | - | - |
| `vec` | `double *val` - vector contents.<br> `int size` - vector size. | This is the vector struct. All functions in vector.h operate on `vec`. It is identical to the struct `set` from `<libido/set.h>`. |

| Macro: | Description: <img width=1000/> |
| - | - |
| `NULL` | Null pointer. |

| Function : | Arguments: | Description:<img width=1000/> |
| - | - | - |
| `vec_init` | `double *arr` - source array.<br> `int size` - source array size. | Initialize a vector from a double array. |
| `vec_print` | `vec vec` - vector to print. | Print a vector in mathematical notation. |
| `vec_print_padded` | `vec vec` - vector to print.<br> `int padding` - padding width | Print a vector in mathematical notation, with desired padding around values. |
| `vec_gen` | `double min` - first coefficient. <br> `double max` - last coefficient. <br> `double inc` - coefficient increment <br> `double (*function)(double)` - function on coefficient | Generating function, used to iteratively populate a vector. |
| `vec_fill` | `vec vec` - vector to fill. <br> `double val` - filler value. | Populate a vector with identical values. |
| `vec_add` | `vec vec0` - first addend. <br> `vec vec1` - second addend. | Compute the sum of two vectors. |
| `vec_sub` | `vec vec0` - minuend. <br> `vec vec1` - subtrahend. | Compute the difference of two vectors. |
| `hada_prod` | `vec vec0` - first factor. <br> `vec vec1` - second factor. | Compute the Hadamard product of two vectors. |
| `vec_mag` | `vec vec` - target vector. | Compute the magnitude of a vector. |
| `double dot_prod` | `vec vec0` - first factor. <br> `vec vec1` - second factor. | Compute the dot product of two vectors. |
| `double cross_prod_mag` | `vec vec0` - first factor. <br> `vec vec1` - second factor. | Compute the magnitude of the cross product of two vectors. |
| `vec cross_prod` | `vec vec0` - first factor. <br> `vec vec1` - second factor. | Compute the cross product of two vectors. |
