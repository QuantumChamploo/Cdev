///////////////////////////////////////////////////////////////////////////////
// Main File:        hill_climb.c
// This File:        hill_climb.c
// Other Files:      None
// Semester:         CS 354 Fall 2019
//
// Author:           Neil Leonard
// Email:            nleonard5@wisc.edu
// CS Login:         nleonard
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

char *COMMA = ",";

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

/* Done:
 * Get the dimensions of the matrix that are on
 * the first line of the input file.
 * 
 * infp: file pointer for input file
 * nRows: pointer to number of rows in the matrix   
 * nCols: pointer to number of columns in the matrix
 */
void get_dimensions(FILE *infp, int *nRows, int *nCols) {         
    // Read the dimensions on the first line from infp

    char *line = NULL;
    size_t len = 0;
    if(getline(&line, &len,infp) == -1){
        printf("Error in reading the file\n");
        exit(1);
    }
    char *token1 = NULL;
    token1 = strtok(line, COMMA);
    *nRows = atoi(token1);

    token1 = strtok(NULL, COMMA);
    *nCols = atoi(token1);

} 

// helper function that will look at a structure and will ask
// 8 questions (for the potential 8 neighboring points) and return
// the indices for the highest neighboring square
int find_next(Matrix *mstruct, int *row, int *col){
    int **mat = mstruct->matrix;
    int matRows = mstruct->numRows;
    int matCols = mstruct->numCols;
    int cur_high = *(*(mat + *row) + *col);

    int rtrn_row = *row;
    int rtrn_col = *col;

    // top left 

    if(*row != 0){
        if(*col != 0){
            if(*(*(mat + *row - 1)+ *col - 1) > cur_high){
                cur_high = *(*(mat + *row - 1)+ *col - 1);
                rtrn_row = *row - 1;
                rtrn_col = *col - 1;
            }
        }
    }
    // directly above
    if(*row != 0){
        if(*(*(mat + *row - 1) + *col) > cur_high){
            cur_high = *(*(mat + *row - 1) + *col);
            rtrn_row = *row -1;
            rtrn_col = *col;
        }
    }
    // top right
    if(*row != 0){
        if(*col < matCols -1){
            if(*(*(mat + *row - 1) + *col + 1) > cur_high){
                cur_high = *(*(mat + *row - 1) + *col + 1);
                rtrn_row = *row - 1;
                rtrn_col = *col + 1;
            }
        }
    }

    // directly right
    if(*col < matCols - 1){
        if(*(*(mat + *row ) + *col + 1) > cur_high){
            cur_high = *(*(mat + *row ) + *col + 1);
            rtrn_row = *row;
            rtrn_col = *col + 1;

        }
    }

    //lower left
    if(*col < matCols - 1){
        if(*row < matRows - 1){
            if(*(*(mat + *row + 1) + *col + 1) > cur_high){
                cur_high = *(*(mat + *row + 1) + *col + 1);
                rtrn_row = *row + 1;
                rtrn_col = *col + 1;

            }
        }
    }
    // directly below
    if(*row < matRows - 1){
        if(*(*(mat + *row +1) + *col) > cur_high){
            cur_high = *(*(mat + *row +1) + *col);
            rtrn_row = *row +1;
            rtrn_col = *col;

        }

    }
    //bottom left
    if( *row < matRows - 1){
        if(*col != 0){
            if(*(*(mat + *row + 1) + *col - 1) > cur_high){
                cur_high = *(*(mat + *row + 1) + *col - 1);
                rtrn_row = *row + 1;
                rtrn_col = *col - 1;

            }
        }
    }
    // directly left
    if(*col != 0){
        if(*(*(mat + *row) + *col - 1) > cur_high){
            cur_high = *(*(mat + *row) + *col - 1);
            rtrn_row = *row;
            rtrn_col = *col - 1;

        }
    }
    


    *row = rtrn_row;
    *col = rtrn_col;

    return 0;
}           

/* Done:
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
    int **mat = mstruct->matrix;
    // the highest row and col
    int highRow = 0;
    int highCol = 0;
    // dummie row and col variables to compare with 
    int *hldRow = malloc(sizeof(int));
    int *hldCol = malloc(sizeof(int));

    *hldRow = 0;
    *hldCol = 0;

    fprintf(outfp,"%d ", **mat);
    // not the best implemetaton, but almost all have the ability to create
    // infinite loops
    while(0 == 0){
    	// find next highest
        find_next(mstruct,hldRow, hldCol);
        // see if its different
        if((*hldRow != highRow) | (*hldCol != highCol)){
            highRow = *hldRow;
            highCol = *hldCol;
            // write into the output file *(*(mat + highRow ) + highCol)
            fprintf(outfp,"%d ", *(*(mat + highRow ) + highCol));
        }
        else{
        	// free the allocated mem
        	free(hldRow);
        	free(hldCol);
        	// couldnt find another so lets leave the loop
            break;
        }
    }

}    

/* Done:
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
    FILE *infp = fopen(*(argv + 1), "r");
    if(infp == NULL){
        printf("Cannot open file for reading\n");
        exit(1);
    }
    // Declare local variables including the Matrix structure 
    int nRows, nCols;
    int **m;
    // Call the function get_dimensions
    get_dimensions(infp, &nRows, &nCols);

    // Dynamically allocate a 2D array in the Matrix structure
    m = malloc(sizeof(int*)*nRows);
    for(int i = 0; i < nRows; i++){
        *(m + i) = malloc(sizeof(int)*nCols);
    }
    // Read the file line by line base on the number of rows
    char *line = NULL;
    size_t len = 0;
    char *token = NULL;
    for(int i = 0; i < nRows; i++){
        if(getline(&line,&len,infp) == -1){
            printf("Error while reading the file\n");
            exit(1);
        }
        token = strtok(line, COMMA);
        for(int j = 0; j < nCols; j++){
            *(*(m +i) + j) = atoi(token);
            token = strtok(NULL, COMMA);
        }
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){

        }
    }

    Matrix mat;
    mat.numRows = nRows;
    mat.numCols = nCols;
    mat.matrix = m;


    // Tokenize each line wrt comma to store the values in the matrix
    // Open the output file  
    // Note about implementation. I used "a" to let me write as I go. This 
    // assumes a blank or absent file. This should be fine by the definitions
    // in the specifications
    FILE *outfp = fopen(*(argv + 2), "a");
    if(outfp == NULL){
        printf("Cannot open file for writing\n");
        exit(1);
    }
    // Call the function hill_climb
    hill_climb(outfp, &mat);
    // Free the dynamically allocated memory
    for(int i = 0; i < nRows; i++){
        free(*(m + i));
        *(m + i) = NULL;
    }
    free(m);
    m = NULL;

    // Close the input file  
    fclose(infp);
    // Close the output file
    fclose(outfp);

    return 0; 
}   
