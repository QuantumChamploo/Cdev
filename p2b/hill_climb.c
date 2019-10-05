///////////////////////////////////////////////////////////////////////////////
//
// Copyright 2019 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
//
///////////////////////////////////////////////////////////////////////////////
// Main File:        (name of file with main function)
// This File:        (name of this file)
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Fall 2019
//
// Author:           (your name)
// Email:            (your wisc email address)
// CS Login:         (your CS login name)
//
/////////////////////////// OTHER SOURCES OF HELP /////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>   
#include <stdlib.h>     
#include <string.h>  

/*
 * USE THIS:
 * Structure representing the Matrix
 * numRows: number of rows
 * numCols: number of columns
 * matrix: 2D heap allocated array of integers
 */
typedef struct {    
    int numRows;
    int numCols;
    int **matrix;
} Matrix;

/* TODO:
 * Get the dimensions of the matrix that are on
 * the first line of the input file.
 * 
 * infp: file pointer for input file
 * nRows: pointer to number of rows in the matrix   
 * nCols: pointer to number of columns in the matrix
 */
void get_dimensions(FILE *infp, int *nRows, int *nCols) {         
    // Read the dimensions on the first line from infp
}            

/* TODO:
 * Continually find and print the largest neighbor
 * that is also larger than the current position
 * until nothing larger is found.       
 * 
 * outfp: file pointer for output file  
 * mstruct: pointer to the Matrix structure
 */
void hill_climb(FILE *outfp, Matrix *mstruct) {  
    // Write the intial starting number to outfp
    // Find the largest neighbor that is also larger than the current position
    // Move to that position  
    // Write that number to outfp
    // Repeat until you can't find anything larger (you may use any loop)
}    

/* TODO:
 * This program reads an m by n matrix from the input file
 * and outputs to a file the path determined from the
 * hill climb algorithm.    
 *
 * argc: CLA count
 * argv: CLA values
 */
int main(int argc, char *argv[]) {
    // Check if number of command-line arguments is correct
    // Open the input file and check if it opened successfully
    // Declare local variables including the Matrix structure 
    // Call the function get_dimensions
    // Dynamically allocate a 2D array in the Matrix structure
    // Read the file line by line base on the number of rows
    // Tokenize each line wrt comma to store the values in the matrix
    // Open the output file  
    // Call the function hill_climb
    // Free the dynamically allocated memory
    // Close the input file  
    // Close the output file

    return 0; 
}   
