/*  CSC A48 - Winter 2020
*
*   Exercise 6 - The Resistant Strain
*
*   Please read the comments below carefully, they
*  describe your task in detail. Any clarifications
*  and corrections will be posted to Piazza so please
*  keep an eye on the forum!
*
*  Starter code: Joe Armitage & William Song, 2020
*/


#include <stdbool.h>            // Note this is needed to use the bool type
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TISSUE_SIZE (10)

typedef enum tissueType
{
    _ = '_',  // Uninfected cell
    I = 'I',  // Infected cell
    S = 'S',  // Good bacterium: Sakinacoccus
    C = 'C',  // Good bacterium: Charlestridium tetani
} TissueType;

typedef struct cell
{
    TissueType type;  // Indicates if good bacterium, infected cell or uninfected cell
    int health;  // For good bacteria: the multiple the range is extended by, for infected cells,
                 // number of lives
} Cell;

typedef Cell Tissue[TISSUE_SIZE][TISSUE_SIZE];  // A nice name for a 2D Cell array -> Tissue

/**
 * CRUNCHY: Use this helper helper function to implement Charles AND Sakina
 * HINT: I would implement numberOfCharlesInRange like this:
 *      Pattern charles_patterns[4] = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};
 *      return numberOfBacteriaInRange(tissue_sample, x, y, charles_patterns, 4, C);
 */
typedef int Pattern[2];
int numberOfBacteriaInRange(Tissue tissue, int x, int y, Pattern pattern[], int num_patterns,
                            TissueType type)
{
    /** CRUNCHIER: do this without looping over all the cells (again) (attacks are symmetric!) */
    int counter = 0;

    return counter;
}

/**
 * Return the number of Charlestridium tetani within tissue_sample that can attack position x, y.
 *
 * Legal attacks are limited to the pattern (where X is a legal attack and C is the bacterium):
 *      _ _ X _ _
 *      _ _ _ _ _
 *      X _ C _ X
 *      _ _ _ _ _
 *      _ _ X _ _
 * where each Charlestridium tetani can attack in any one direction in this pattern for a certain
 * number of attacks. For example, if one had 2 health, its pattern would be limited to:
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      X _ X _ C _ X _ X
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN: the number of Charlestridium tetani that can make a legal attack to position x, y
 */
int numberOfCharlesInRange(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */
	int col = 0, row = 0, attack = 0; 
	// goes thru each of the entries of the sample
	for (row = 0; row < TISSUE_SIZE; row++){
		for(col = 0; col < TISSUE_SIZE; col++){
			// checks if it is a LEO
			if (tissue_sample[row][col].type == 'C'){
				//printf("%d \n", tissue_sample[row][col].health);
				for (int h = 1; h <= tissue_sample[row][col].health; h++){
					//printf("%d \n", h);
					if (col + 2*(h) == x && row == y){
						//printf("right \n");
						attack++;
					}else if (col - 2*(h) == x && row == y){
						//printf("left \n");
						attack++;
					}else if (col == x && row + 2*(h) == y){
						//printf("down \n");
						attack++;
					}else if (col == x && row - 2*(h) == y){
						//printf("up \n");
						attack++;
				
					}
				}
			}
		}
	}
    return attack;  // replace this with your implementation
}
	


/**
 * Return the number of Sakinacoccus within tissue_sample that can attack position x, y.
 *
 * Legal attacks are limited to the pattern (where X is a legal attack and S is the bacterium):
 *      _ _ _ _ _
 *      _ X _ X _
 *      _ _ S _ _
 *      _ X _ X _
 *      _ _ _ _ _
 * where each Sakinacoccus can attack in any one direction in this pattern for a certain
 * number of attacks. For example, if one had 2 health, its pattern would be limited to:
 *      X _ _ _ X
 *      _ X _ X _
 *      _ _ S _ _
 *      _ X _ X _
 *      X _ _ _ X
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN: the number of Sakinacoccus that can make a legal attack to position x, y
 */
int numberOfSakinaInRange(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */
	int col = 0, row = 0, attack = 0; 
	// goes thru each of the entries of the sample
	for (row = 0; row < TISSUE_SIZE; row++){
		for(col = 0; col < TISSUE_SIZE; col++){
			// checks if it is a LEO
			if (tissue_sample[row][col].type == 'S'){
				//printf("%d \n", tissue_sample[row][col].health);
					for (int h = 1; h <= tissue_sample[row][col].health; h++){
						if (col + h == x && row + h== y){
					//printf("right down \n");
							attack++;
						}else if (col - h == x && row + h == y){
					//printf("left down \n");
							attack++;
						}else if (col - h == x && row - h == y){
					//printf("left up \n");
							attack++;
						}else if (col + h == x && row - h == y){
					//printf("right up \n");
							attack++;
						}
				}
			}
		}
	}
	return attack;
	
}

/**
 * Computes the percentage of infected cells in the given tissue sample which can be killed
 * by Sakinacoccus or Charlestridium tetani bacteria in the sample and updates the tissue sample to
 * the state after the attacks.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *      - REQ: there is at least one infected cell
 *
 * OUTPUT:
 *  tissue_sample: - mutated such that:
 *      - All `I` cells have their health reduced by the number of good bacteria that can attack.
 *      - Any `I` cell whose health drops to <= 0 is replaced by a `_` cell, with 0 health.
 *
 * RETURN:
 *  The percentage of infected cells that are killed by the good bacteria (Sakinacoccus and
 * Charlestridium tetani).
 */
double testBacteria(Tissue tissue_sample)
{
    /**
     * TODO: Implement this function, satisfying the description above.
     *
     * CRUNCHY: Can you do this without using a loop in a loop?
     *              -> Think about how this 2D array is stored in memory...
     */
	 
	 
	 // 1 is true, 0 is false
	int col = 0, row = 0, number_of_infected = 0, number_cured = 0, killed = 0;
	for (row = 0; row < TISSUE_SIZE; row++){
		for(col = 0; col < TISSUE_SIZE; col++){
			if (tissue_sample[row][col].type == 'I'){
				//printf("Charles: %d \n", numberOfCharlesInRange(tissue_sample, col, row));
				//printf("Sakina: %d \n", numberOfSakinaInRange(tissue_sample, col, row));
				if (numberOfCharlesInRange(tissue_sample, col, row) >=0 || numberOfSakinaInRange(tissue_sample, col, row) >=0){
					tissue_sample[row][col].health -= numberOfCharlesInRange(tissue_sample, col, row) + numberOfSakinaInRange(tissue_sample, col, row); 
				}
				

			}
		}
	}
	
	for (row = 0; row < TISSUE_SIZE; row++){
		for(col = 0; col < TISSUE_SIZE; col++){
			if (tissue_sample[row][col].type == 'I'){
				number_of_infected++;
				tissue_sample[row][col].health -= number_cured;
				if (tissue_sample[row][col].health <= 0){
					tissue_sample[row][col].type = _;
					killed++;
				}
					
				
			}
		}
	}
	
	
	
	//printf("infections: %d cured: %d \n", number_of_infected, number_cured );
    /**
     * TODO: Implement this function, satisfying the description above.
     *
     * CRUNCHY: Can you do this without using a loop in a loop?
     *              -> Think about how this 2D array is stored in memory...
     */
	/* float percent = (((float)number_cured / (float)number_of_infected ) * 100);
	//printf("percent %f \n", percent );
    return round(percent); */

    return (((double)killed / (double)number_of_infected)*100);
}

/**
 * Prints the tissue sample in a human readable format.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *
 * NOTE: The displayed indices do not match the implementation.
 * That is, they start at 1 (when we know array indices start at 0).
 * This is more obvious for the column indices, which are A - J.
 */
void printTissueSample(Tissue tissue_sample)
{
    printf("   A B C D E F G H I J\n");
    for (int x = 0; x < TISSUE_SIZE; x++)
    {
        printf("%2d ", x + 1);
        for (int y = 0; y < TISSUE_SIZE; y++) printf("%c ", tissue_sample[x][y].type);
        printf("\n");
    }
}

// We NEED this compiler directive to test your code with our own main(). Don't break it.
#ifndef __TESTING  // this compiler directive
int main()
{
    // Please note that these are JUST EXAMPLES! You will be tested on a wide range of data.

    printf("====Jackson's Sample====\n");
    Tissue jackson_sample = {
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {C, 1}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 3}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 2}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {S, 2}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}}};
    printTissueSample(jackson_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(jackson_sample));
    printf("  Expected: Killed 066.67%% of bacteria\n");
    printTissueSample(jackson_sample);

    // Feel free to add your own examples/tests here
    printf("====Silviu's Sample====\n");
    Tissue silviu_sample = {
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {I, 1}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}},
        {{_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {S, 2}},
        {{_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {C, 3}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {C, 2}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {I, 1}, {I, 1}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}}};
    printTissueSample(silviu_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(silviu_sample));
    printf("  Expected: Killed 036.36%% of bacteria\n");
    printTissueSample(silviu_sample);
}
#endif  // and this compiler directive
