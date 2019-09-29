#include <stdio.h>  
#include <stdlib.h>
#include <string.h>     

char *COMMA = ","; 
/* COMPLETED:       
 * Retrieves from the first line of the input file,
 * the size of the board (number of rows and columns).
 * 
 * fp: file pointer for input file
 * size: pointer to size
 */
void get_dimensions(FILE *fp, int *size) {      
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1) {
        printf("Error in reading the file\n");
        exit(1);
    }

    char *token = NULL;
    token = strtok(line, COMMA);
    *size = atoi(token);
}   
/* Helper function that will look at an array, and see if there 
a winner. Outputs 0 for no winner, 1 for x is a winner, 2 for o 
is the winner
*/
int check_array(int* arr, int size){
    // if the begining is empty, it cant be a winner
	if(*arr == 0){
		return 0;
	}
    //now loop through and see if everything is the same
	for(int i = 1; i < size; i++){
		if(*(arr + i) != *(arr + (i -1))){
			return 0;
		}
	}
    // if we got here then its a filled array. look at the first entry
    // and return the appopriate type
	if(*arr == 1){
		return 1;
	}
	if(*arr == 2){
		return 2;
	}
    return 0;
}

/* TODO:
 * Returns 1 if and only if the board is in a valid state.
 * Otherwise returns 0.
 * 
 * board: heap allocated 2D board
 * size: number of rows and columns
 */
int n_in_a_row(int **board, int size) {
    // we will use these to count later
	int x = 0;
	int o = 0;
    // count the wins, and for which team
    int x_win = 0;
    int o_win = 0;
    /* these will designate whether it is a row win or a col win. No 
    need to distinguish betweeen o and x, as if both have a win
    then it will be a fail anyway. Set to negative one as 0 will
    designate a row */
    int row_win = -1;
    int col_win = -1;
    // Now loop through each row and see if we have a winner. 
	for(int i = 0; i < size; i++){
        // note we will always check for a win on the other side 
        // before awarding a point
        // check x
		if(check_array(*(board + i), size) == 1){
            if(o_win == 0){
                if(row_win != -1){
                    x_win++;
                    row_win = i;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
		}
        // check o
        if(check_array(*(board + i), size) == 2){
            if(x_win == 0){
                if(row_win != -1){
                    o_win++;
                    row_win = i;
                }            
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
	}
    // now go through the column
	for(int i = 0; i < size; i++){
        // we need to make the row arrays
		int* hld = malloc(sizeof(int)*size);
		for(int j = 0; j < size; j++){
			*(hld + j) = *(*(board + j)+i);
		}
		if(check_array(hld, size) == 1){
            if(o_win == 0){
                if(col_win != -1){
                    x_win++;
                    col_win = i;

                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }

			
		}
        if(check_array(hld, size) == 2){
            if(x_win == 0){
                if(col_win != -1){
                    o_win++;
                    col_win = i;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
            
        }
	}
    // now we make the diagonal arrays
    // from top left to bottom right
	int* hld = malloc(sizeof(int)*size);
    // bottom left to top right
	int* hld2 = malloc(sizeof(int)*size);
    // fill them up
	for(int i = 0; i < size; i++){
		//hld[i] = board[i][i];
        *(hld + i) = *(*(board + i) +i);
        *(hld2 + i) = *(*(board + size - 1 - i) +i);
		//hld2[i] = board[size - 1 - i][i];

	}
    // check if they have a winner, with some extra logic
    // to make sure that we are adding a valid winner
	if(check_array(hld, size) == 1){
        if(o_win == 0){

            if(row_win == -1 | col_win == -1){

                x_win++;
                
            }
            else{
                if(row_win == col_win){
                    x_win++;
                }
                else{
                    free(hld);
                    free(hld2);
                    hld = NULL;
                    hld2 = NULL;
                    return 0;
                }
            }
        }
        else{
            free(hld);
            free(hld2);
            hld = NULL;
            hld2 = NULL;
            return 0;
        }
		
	}
    if(check_array(hld, size) == 2){
        if(x_win == 0){

            if(row_win == -1 | col_win == -1){

                o_win++;
                
            }
            else{
                if(row_win == col_win){
                    o_win++;
                }
                else{
                    free(hld);
                    free(hld2);
                    hld = NULL;
                    hld2 = NULL;
                    return 0;
                }
            }
        }
        else{
            free(hld);
            free(hld2);
            hld = NULL;
            hld2 = NULL;
            return 0;
        }
        
    }
    if(check_array(hld2, size) == 1){
        if(o_win == 0){

            if(row_win == -1 | col_win == -1){

                x_win++;
                
            }
            else{
                if(row_win == (size - 1 - col_win)){
                    x_win++;
                }
                else{
                    free(hld);
                    free(hld2);
                    hld = NULL;
                    hld2 = NULL;
                    return 0;
                }
            }
        }
        else{
            free(hld);
            free(hld2);
            hld = NULL;
            hld2 = NULL;
            return 0;
        }
        
    }
    if(check_array(hld2, size) == 2){
        if(x_win == 0){

            if(row_win == -1 | col_win == -1){

                o_win++;
                
            }
            else{
                if(row_win == (size - 1 - col_win)){
                    o_win++;
                }
                else{
                    free(hld);
                    free(hld2);
                    hld = NULL;
                    hld2 = NULL;
                    return 0;
                }
            }
        }
        else{
            free(hld);
            free(hld2);
            hld = NULL;
            hld2 = NULL;
            return 0;
        }
        
    }   
    free(hld);
    free(hld2);
    hld = NULL;
    hld2 = NULL; 
    // now lets add up how many of each x's and o's there
    // are so we know its valid 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(*(*(board + i) + j) == 1){
                x++;
            }
            if(*(*(board + i) + j) == 2){
                o++;
            }
        }
    }
    // make a total
    int total = (x - o);
    // if both equal then its fine
    if(total == 0){
        return 1;
    }
    // only an x can win with more files
    else if(total == 1){
        if(o_win > 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }


}
    



/* PARTIALLY COMPLETED:
 * This program prints Valid if the input file contains
 * a game board with either 1 or no winners; and where
 * there is at most 1 more X than O.
 * 
 * argc: CLA count
 * argv: CLA value
 */
int main(int argc, char *argv[]) {              

    //TODO: Check if number of command-line arguments is correct.
    if(argc != 2){
        exit(1);
    }

    //Open the file and check if it opened successfully.
    FILE *fp = fopen(*(argv + 1), "r");
    if (fp == NULL) {
        printf("Cannot open file for reading\n");
        exit(1);
    }


    //Declare local variables.
    int size;

	//TODO: Call get_dimensions to retrieve the board size.
    get_dimensions(fp, &size);
    printf("the size is %d\n", size);


    


    //TODO: Dynamically allocate a 2D array of dimensions retrieved above.
    int** m;
    m = malloc(sizeof(int*)*size);
    for(int i = 0; i < size; i++){
    	*(m + i) = malloc(sizeof(int)*size);
    }

    //Read the file line by line.
    //Tokenize each line wrt comma to store the values in your 2D array.
    char *line = NULL;
    size_t len = 0;
    char *token = NULL;
    for (int i = 0; i < size; i++) {

        if (getline(&line, &len, fp) == -1) {
            printf("Error while reading the file\n");
            exit(1);
        }

        token = strtok(line, COMMA);
        for (int j = 0; j < size; j++) {
            //TODO: Complete the line of code below
            //to initialize your 2D array.
            /* ADD ARRAY ACCESS CODE HERE */ *(*(m +i) + j) = atoi(token);
            token = strtok(NULL, COMMA);
        }
    }


    //TODO: Call the function n_in_a_row and print the appropriate
    //output depending on the function's return value.

    int hld = n_in_a_row(m, size);
    char *answer = malloc(256);
    if(hld == 0){
        strcpy(answer, "invalid");
    }
    if(hld == 1){
        strcpy(answer, "valid");
    }

    printf("the output is %s\n", answer);



    //TODO: Free all dynamically allocated memory.
    for(int i = 0; i < size; i++){

    	free(m[i]);
    	m[i] = NULL;

    }
    free(m);
    m = NULL;

    //Close the file.
    if (fclose(fp) != 0) {
        printf("Error while closing the file\n");
        exit(1);
    } 

    return 0;       
}       