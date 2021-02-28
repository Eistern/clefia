CLEFIA-128. 18 rounds implementation
-
This repository contains an implementation of 128 bits version of CLEFIA algorithm (https://tools.ietf.org/html/rfc6114) 
with minimal examples

Note: all memory blocks have to be allocated outside of function calls; decoded data will be aligned by 16 bits using nulls

Structure 
-
* clefia.h - Header file of library. Comes with minimal comments needed for usage
* clefia.c - Implementation of library. 18-round process used with lookup tables for multiplication
* codec.c -  First example of library usage. Takes input file, key file and mode (c-code/d-decode) as input parameters
* hash.c - Second example of library usage. Implements basic hashcode function. Requires only input file

Results of the examples will be placed in the "results" file

Feel free to use it in any way and in case of usage in git projects please consider adding it as a git submodule 
