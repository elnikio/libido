![title](./logo2.png)

# **Libido - \<libido/\>**

A C math library.

1. [Installation](#installation)  
2. [Documentation](#documentation)  
	2.1. [Vector](#vector)
---
# **1. Installation**
1. Run install.sh, which copies the files to your include directory.
2. Compile using ./compile.sh.
---
# **2. Documentation**
---
## 2.1. **Vector** - <libido/vector.h>
### Types:
| Variable Type: | Members: | Description: |
| - | - | - |
| vec  | `double *val` - vector contents. <br> `int size` - vector size. <br>| This is the vector struct. All functions in vector.h operate on `vec`. It is identical to the struct `set` from `<libido/set.h>`. |


### Constructors:
| Function: | Arguments: | Description: |
| - | - | - |
| `vec vec_from_arr `| `double arr[]	` - source array.<br> `int size		` - source array size.<br> | Initialize a vector from a double array. |
| `vec vec_from_const `| `double cons	` - component value.<br> `int size		` - vector size.<br> | Initialize a vector with identical values. |
| `vec vec_gen `| `double min		` - first coefficient.<br> `double max		` - last coefficient.<br> `double inc		` - coefficient increment.<br> `double (*function)(double)	` - function on coefficient.<br> | Vector generating function meant for iteratively populating a vector. |

### Methods:
| Function: | Arguments: | Description: |
| - | - | - |
| `vec vec_fill `| `vec vec		` - target vector.<br> `double val		` - filler value.<br> | Fill a vector with identical values. |
| `vec vec_clear `| `vec vec			` - target vector.<br> | Nullify a vector. |
| `vec vec_mul_const `| `vec vec		` - vector factor.<br> `double mul		` - constant factor.<br> | Multiply a vector by a constant. |
| `vec vec_div_const `| `vec vec		` - vector divident.<br> `double div		` - constant divisor.<br> | Divide a vector by a constant. |
| `vec vec_add_const `| `vec vec		` - vector addend.<br> `double add		` - constant addend.<br> | Add a constant to each component of a vector. |
| `vec vec_sub_const `| `vec vec		` - vector minuend.<br> `double sub		` - constant subtrahend.<br> | Subtract a constant from each component of a vector. |
| `vec vec_unit `| `vec vec			` - target vector.<br> | Compute the unit vector of a select vector. |
| `vec vec_add `| `vec vec0		` - first addend.<br> `vec vec1		` - second addend.<br> | Add two vectors. |
| `vec vec_sub `| `vec vec0		` - minuend.<br> `vec vec1		` - subtrahend.<br> | Subtract two vectors. |
| `vec vec_hada `| `vec vec0		` - first factor.<br> `vec vec1		` - second factor.<br> | Compute the Hadamard product of two vectors. |
| `double vec_mag `| `vec vec			` - target vector.<br> | Compute the magnitude of a vector. |
| `double dot_prod `| `vec vec0		` - first factor.<br> `vec vec1		` - secdond factor.<br> | Compute the dot product of two vectors. |
| `double cross_prod_mag `| `vec vec0		` - first factor.<br> `vec vec1		` - second factor.<br> | Compute the cross product magnitude of two vectors. |

### Printers:
| Function: | Arguments: | Description: |
| - | - | - |
| `void vec_print `| `vec vec			` - target vector.<br> | Print a vector in vector notation. |
| `void vec_print_padded `| `vec vec		` - target vector.<br> `int padding		` - padding width.<br> | Print a vector in vector notation with padding. |
| `void vec_print_labeled `| `vec vec		` - target vector.<br> `char *label	` - vector label.<br> `int padding		` - padding width.<br> | Print a vector in vector notation with padding and a label. |
| `void good_dog `| `int dog			` - dog.<br> | Print the index of a good dog (not to be confused with bad_dog()). |
