#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    A = 0,
    C = 1,
    G = 2,
    T = 3,
} Nucleotide;  // these are just the integers 0, 1, 2, 3 with fancy names!
typedef Nucleotide Codon[3];

/**
 * Sort the codons array in place, in ascending order.
 *
 * EX: sort_codons({{A, A, C}, {A, A, A}}, 2) => {{A, A, A}, {A, A, C}}
 *
 * NOTE: The codons should be sorted based on their own value,
 *          NOT the value of their associated amino acids.
 *
 * REQ:
 *  - The "codons" array points to an array of codons with exactly num_codons in it
 *  - Each codon contains exactly 3 Nucleotides
 *  - Each nucleotide can only take on a value in the set {A, C, G, T}
 *
 * INPUT:
 *  - codons: An array of codons, likely unsorted
 *  - num_codons: The number of codons that are in the array
 *
 * OUTPUT:
 *  - codons: The same array of codons, now sorted
 */
void sortCodons(Codon codons[], int num_codons)
{
    /**
     * TODO: Implement this function, with O(num_codons) worst case time complexity.
     *
     * HINTS:
     *  - How many possible codons are there? How many buckets do you need?
     *  - Are any 2 of the same type in the list different in some way? No.
     *      - That is {A, C, G} == {A, C, G}, even if they are not at the same memory location.
     *  - So, copying data is the same as recreating it elsewhere....
     *
     * NOTE: For this exercise, you can assume that:
     *  - there will only ever be 4 nucleotides
     *  - there will always be 3 nucleotides per codon.
     */
	 
	int buckets[64];
	for (int i = 0; i < 64; i++){
		buckets[i] = 0;
	}
	for (int i = 0; i <= num_codons; i++){
		// first is 0
		if (codons[i][0] == 0){
			// second is 0
			if (codons[i][1] == 0){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] == 0){
					buckets[0]++;
				}else if(codons[i][2] == 1){
					buckets[1]++;
				}else if(codons[i][2] == 2){
					buckets[2]++;
				}else if(codons[i][2] == 3){
					buckets[3]++;
				}
			// second is 1
			}else if(codons[i][1] == 1){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] == 0){
					buckets[4]++;
				}else if(codons[i][2] == 1){
					buckets[5]++;
				}else if(codons[i][2] == 2){
					buckets[6]++;
				}else if(codons[i][2] == 3){
					buckets[7]++;
				}
			// second is 2
			}else if(codons[i][1] == 2){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] == 0){
					buckets[8]++;
				}else if(codons[i][2] == 1){
					buckets[9]++;
				}else if(codons[i][2] == 2){
					buckets[10]++;
				}else if(codons[i][2] == 3){
					buckets[11]++;
				}
			// second is 3
			}else if(codons[i][1] == 3){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] == 0){
					buckets[12]++;
				}else if(codons[i][2] == 1){
					buckets[13]++;
				}else if(codons[i][2] == 2){
					buckets[14]++;
				}else if(codons[i][2] == 3){
					buckets[15]++;
				}
			}
		// first is 1
		}else if (codons[i][0] == 1){
			// second is 0
			if (codons[i][1] == 0){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] == 0){
					buckets[16]++;
				}else if(codons[i][2] == 1){
					buckets[17]++;
				}else if(codons[i][2] ==2){
					buckets[18]++;
				}else if(codons[i][2] ==3){
					buckets[19]++;
				}
			// second is 1
			}else if(codons[i][1] ==1){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[20]++;
				}else if(codons[i][2] ==1){
					buckets[21]++;
				}else if(codons[i][2] ==2){
					buckets[22]++;
				}else if(codons[i][2] ==3){
					buckets[23]++;
				}
			// second is 2
			}else if(codons[i][1] ==2){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[24]++;
				}else if(codons[i][2] ==1){
					buckets[25]++;
				}else if(codons[i][2] ==2){
					buckets[26]++;
				}else if(codons[i][2] ==3){
					buckets[27]++;
				}
			// second is 3
			}else if(codons[i][1] ==3){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[28]++;
				}else if(codons[i][2] ==1){
					buckets[29]++;
				}else if(codons[i][2] ==2){
					buckets[30]++;
				}else if(codons[i][2] ==3){
					buckets[31]++;
				}
			}
		// first is 2
		}else if (codons[i][0] == 2){
			// second is 0
			if (codons[i][1] ==0){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[32]++;
				}else if(codons[i][2] ==1){
					buckets[33]++;
				}else if(codons[i][2] ==2){
					buckets[34]++;
				}else if(codons[i][2] ==3){
					buckets[35]++;
				}
			// second is 1
			}else if(codons[i][1] ==1){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[36]++;
				}else if(codons[i][2] ==1){
					buckets[37]++;
				}else if(codons[i][2] ==2){
					buckets[38]++;
				}else if(codons[i][2] ==3){
					buckets[39]++;
				}
			// second is 2
			}else if(codons[i][1] ==2){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[40]++;
				}else if(codons[i][2] ==1){
					buckets[41]++;
				}else if(codons[i][2] ==2){
					buckets[42]++;
				}else if(codons[i][2] ==3){
					buckets[43]++;
				}
			// second is 3
			}else if(codons[i][1] ==3){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[44]++;
				}else if(codons[i][2] ==1){
					buckets[45]++;
				}else if(codons[i][2] ==2){
					buckets[46]++;
				}else if(codons[i][2] ==3){
					buckets[47]++;
				}
			}
		// first is 3
		}else if (codons[i][0] ==3){
			// second is 0
			if (codons[i][1] ==0){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[48]++;
				}else if(codons[i][2] ==1){
					buckets[49]++;
				}else if(codons[i][2] ==2){
					buckets[50]++;
				}else if(codons[i][2] ==3){
					buckets[51]++;
				}
			// second is 1
			}else if(codons[i][1] ==1){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[52]++;
				}else if(codons[i][2] ==1){
					buckets[53]++;
				}else if(codons[i][2] ==2){
					buckets[54]++;
				}else if(codons[i][2] ==3){
					buckets[55]++;
				}
			// second is 2
			}else if(codons[i][1] ==2){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[56]++;
				}else if(codons[i][2] ==1){
					buckets[57]++;
				}else if(codons[i][2] ==2){
					buckets[58]++;
				}else if(codons[i][2] ==3){
					buckets[59]++;
				}
			// second is 3
			}else if(codons[i][1] ==3){
				// 0 1 2 3 in that order for the last
				if (codons[i][2] ==0){
					buckets[60]++;
				}else if(codons[i][2] == 1){
					buckets[61]++;
				}else if(codons[i][2] == 2){
					buckets[62]++;
				}else if(codons[i][2] == 3){
					buckets[63]++;
				}
			}
		}
			
		
	}
	int x = 0;
	for (int i = 0; i < 64; i++){
		if (buckets[i] > 0){
			
			if (i == 0){
				codons[x][0] = 0;
				codons[x][1] = 0;
				codons[x][2] = 0;
				x++;
			}else if(i == 1){
				codons[x][0] = 0;
				codons[x][1] = 0;
				codons[x][2] = 1;
				x++;
			}else if(i == 2){
				codons[x][0] = 0;
				codons[x][1] = 0;
				codons[x][2] = 2;
				x++;
			}else if(i == 3){
				codons[x][0] = 0;
				codons[x][1] = 0;
				codons[x][2] = 3;
				x++;
			}else if(i == 4){
				codons[x][0] = 0;
				codons[x][1] = 1;
				codons[x][2] = 0;
				x++;
			}else if(i == 5){
				codons[x][0] = 0;
				codons[x][1] = 1;
				codons[x][2] = 1;
				x++;
			}else if(i == 6){
				codons[x][0] = 0;
				codons[x][1] = 1;
				codons[x][2] = 2;
				x++;
			}else if(i == 7){
				codons[x][0] = 0;
				codons[x][1] = 1;
				codons[x][2] = 3;
				x++;
			}else if(i == 8){
				codons[x][0] = 0;
				codons[x][1] = 2;
				codons[x][2] = 0;
				x++;
			}else if(i == 9){
				codons[x][0] = 0;
				codons[x][1] = 2;
				codons[x][2] = 1;
				x++;
			}else if(i == 10){
				codons[x][0] = 0;
				codons[x][1] = 2;
				codons[x][2] = 2;
				x++;
			}else if(i == 11){
				codons[x][0] = 0;
				codons[x][1] = 2;
				codons[x][2] = 3;
				x++;
			}else if(i == 12){
				codons[x][0] = 0;
				codons[x][1] = 3;
				codons[x][2] = 0;
				x++;
			}else if(i == 13){
				codons[x][0] = 0;
				codons[x][1] = 3;
				codons[x][2] = 1;
				x++;
			}else if(i == 14){
				codons[x][0] = 0;
				codons[x][1] = 3;
				codons[x][2] = 2;
				x++;
			}else if(i == 15){
				codons[x][0] = 0;
				codons[x][1] = 3;
				codons[x][2] = 3;
				x++;
			}else if(i == 16){
				codons[x][0] = 1;
				codons[x][1] = 0;
				codons[x][2] = 0;
				x++;
			}else if(i == 17){
				codons[x][0] = 1;
				codons[x][1] = 0;
				codons[x][2] = 1;
				x++;
			}else if(i == 18){
				codons[x][0] = 1;
				codons[x][1] = 0;
				codons[x][2] = 2;
				x++;
			}else if(i == 19){
				codons[x][0] = 1;
				codons[x][1] = 0;
				codons[x][2] = 3;
				x++;
			}else if(i == 20){
				codons[x][0] = 1;
				codons[x][1] = 0;
				codons[x][2] = 1;
				x++;
			}else if(i == 21){
				codons[x][0] = 1;
				codons[x][1] = 1;
				codons[x][2] = 1;
				x++;
			}else if(i == 22){
				codons[x][0] = 1;
				codons[x][1] = 1;
				codons[x][2] = 2;
				x++;
			}else if(i == 23){
				codons[x][0] = 1;
				codons[x][1] = 1;
				codons[x][2] = 3;
				x++;
			}else if(i == 24){
				codons[x][0] = 1;
				codons[x][1] = 2;
				codons[x][2] = 0;
				x++;
			}else if(i == 25){
				codons[x][0] = 1;
				codons[x][1] = 2;
				codons[x][2] = 1;
				x++;
			}else if(i == 26){
				codons[x][0] = 1;
				codons[x][1] = 2;
				codons[x][2] = 2;
				x++;
			}else if(i == 27){
				codons[x][0] = 1;
				codons[x][1] = 2;
				codons[x][2] = 3;
				x++;
			}else if(i == 28){
				codons[x][0] = 1;
				codons[x][1] = 3;
				codons[x][2] = 0;
				x++;
			}else if(i == 29){
				codons[x][0] = 1;
				codons[x][1] = 3;
				codons[x][2] = 1;
				x++;
			}else if(i == 30){
				codons[x][0] = 1;
				codons[x][1] = 3;
				codons[x][2] = 2;
				x++;
			}else if(i == 31){
				codons[x][0] = 1;
				codons[x][1] = 3;
				codons[x][2] = 3;
				x++;
			}else if(i == 32){
				codons[x][0] = 2;
				codons[x][1] = 0;
				codons[x][2] = 0;
				x++;
			}else if(i == 33){
				codons[x][0] = 2;
				codons[x][1] = 0;
				codons[x][2] = 1;
				x++;
			}else if(i == 34){
				codons[x][0] = 2;
				codons[x][1] = 0;
				codons[x][2] = 2;
				x++;
			}else if(i == 35){
				codons[x][0] = 2;
				codons[x][1] = 0;
				codons[x][2] = 3;
				x++;
			}else if(i == 36){
				codons[x][0] = 2;
				codons[x][1] = 1;
				codons[x][2] = 0;
				x++;
			}else if(i == 37){
				codons[x][0] = 2;
				codons[x][1] = 1;
				codons[x][2] = 1;
				x++;
			}else if(i == 38){
				codons[x][0] = 2;
				codons[x][1] = 1;
				codons[x][2] = 2;
				x++;
			}else if(i == 39){
				codons[x][0] = 2;
				codons[x][1] = 1;
				codons[x][2] = 3;
				x++;
			}else if(i == 40){
				codons[x][0] = 2;
				codons[x][1] = 2;
				codons[x][2] = 0;
				x++;
			}else if(i == 41){
				codons[x][0] = 2;
				codons[x][1] = 2;
				codons[x][2] = 1;
				x++;
			}else if(i == 42){
				codons[x][0] = 2;
				codons[x][1] = 2;
				codons[x][2] = 2;
				x++;
			}else if(i == 43){
				codons[x][0] = 2;
				codons[x][1] = 2;
				codons[x][2] = 3;
				x++;
			}else if(i == 44){
				codons[x][0] = 2;
				codons[x][1] = 3;
				codons[x][2] = 0;
				x++;
			}else if(i == 45){
				codons[x][0] = 2;
				codons[x][1] = 3;
				codons[x][2] = 1;
				x++;
			}else if(i == 46){
				codons[x][0] = 2;
				codons[x][1] = 3;
				codons[x][2] = 2;
				x++;
			}else if(i == 47){
				codons[x][0] = 2;
				codons[x][1] = 3;
				codons[x][2] = 3;
				x++;
			}else if(i == 48){
				codons[x][0] = 3;
				codons[x][1] = 0;
				codons[x][2] = 0;
				x++;
			}else if(i == 49){
				codons[x][0] = 3;
				codons[x][1] = 0;
				codons[x][2] = 1;
				x++;
			}else if(i == 50){
				codons[x][0] = 3;
				codons[x][1] = 0;
				codons[x][2] = 2;
				x++;
			}else if(i == 51){
				codons[x][0] = 3;
				codons[x][1] = 0;
				codons[x][2] = 3;
				x++;
			}else if(i == 52){
				codons[x][0] = 3;
				codons[x][1] = 1;
				codons[x][2] = 0;
				x++;
			}else if(i == 53){
				codons[x][0] = 3;
				codons[x][1] = 1;
				codons[x][2] = 1;
				x++;
			}else if(i == 54){
				codons[x][0] = 3;
				codons[x][1] = 1;
				codons[x][2] = 2;
				x++;
			}else if(i == 55){
				codons[x][0] = 3;
				codons[x][1] = 1;
				codons[x][2] = 3;
				x++;
			}else if(i == 56){
				codons[x][0] = 3;
				codons[x][1] = 2;
				codons[x][2] = 0;
				x++;
			}else if(i == 57){
				codons[x][0] = 3;
				codons[x][1] = 2;
				codons[x][2] = 1;
				x++;
			}else if(i == 58){
				codons[x][0] = 3;
				codons[x][1] = 2;
				codons[x][2] = 2;
				x++;
			}else if(i == 59){
				codons[x][0] = 3;
				codons[x][1] = 2;
				codons[x][2] = 3;
				x++;
			}else if(i == 60){
				codons[x][0] = 3;
				codons[x][1] = 3;
				codons[x][2] = 0;
				x++;
			}else if(i == 61){
				codons[x][0] = 3;
				codons[x][1] = 3;
				codons[x][2] = 1;
				x++;
			}else if(i == 62){
				codons[x][0] = 3;
				codons[x][1] = 3;
				codons[x][2] = 2;
				x++;
			}else if(i == 63){
				codons[x][0] = 3;
				codons[x][1] = 3;
				codons[x][2] = 3;
				x++;
			}
		}
		//printf("The number in buckets %d is %d \n",i,buckets[i]);
	}
	
	// go through the bucket list
		// if the bucket is greater than 1, add it to the list until it is no longer 1
		
	
	// int x = 0;
	// for (int i = 0; i < 4; i++){
		// for (int y = 0; y < 4; y++){
			// for (int z = 0; z < 4; z++){
				
				
				// printf("x:%d codon: %d %d %d\n", x,i,y,z);
				
				// x++;
			// }
			
			
		// }
	// } 
	
	/* for (int i = 0; i < num_codons; i++){
		for (int y = 0; y < 3; y++){
			printf("%d \n", codons[i][y]);
			
		}
	} */
	
	 
}

/**
 * Prints the amino acid coded for by each codon. This just makes them more readable.
 *
 * EX: printCodon({A, T, G}) => Methionine
 *
 * INPUT:
 *  - codons: A codon whose associated amino acid is to be printed
 *
 * OUTPUT:
 *  - To the terminal: The amino acid associated with the given codon
 */
void printCodon(Codon codon)
{  // Ignore this whole implementation if you like.
    switch (codon[0])
    {
    case A:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tLysine");
                break;
            case C:
                printf("\tAsparganine");
                break;
            case G:
                printf("\tLysine");
                break;
            case T:
                printf("\tAsparganine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tThreonine");
            break;
        case G:
            switch (codon[2])
            {
            case A:
                printf("\tArginine");
                break;
            case C:
                printf("\tSerine");
                break;
            case G:
                printf("\tArginine");
                break;
            case T:
                printf("\tSerine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case T:
            switch (codon[2])
            {
            case A:
                printf("\tIsoleucine");
                break;
            case C:
                printf("\tIsoleucine");
                break;
            case G:
                printf("\tMethionine");
                break;
            case T:
                printf("\tIsoleucine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case C:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tGlutamine");
                break;
            case C:
                printf("\tHistidine");
                break;
            case G:
                printf("\tGlutamine");
                break;
            case T:
                printf("\tHistidine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tProline");
            break;
        case G:
            printf("\tArginine");
            break;
        case T:
            printf("\tLeucine");
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case G:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tGlutamic Acid");
                break;
            case C:
                printf("\tAspartic Acid");
                break;
            case G:
                printf("\tGlutamic Acid");
                break;
            case T:
                printf("\tAspartic Acid");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tAlanine");
            break;
        case G:
            printf("\tGlycine");
            break;
        case T:
            printf("\tValine");
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case T:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tSTOP");
                break;
            case C:
                printf("\tTyrosine");
                break;
            case G:
                printf("\tSTOP");
                break;
            case T:
                printf("\tTyrosine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tSerine");
            break;
        case G:
            switch (codon[2])
            {
            case A:
                printf("\tSTOP");
                break;
            case C:
                printf("\tCysteine");
                break;
            case G:
                printf("\tTryptophan");
                break;
            case T:
                printf("\tCysteine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case T:
            switch (codon[2])
            {
            case A:
                printf("\tLeucine");
                break;
            case C:
                printf("\tPhenylalanine");
                break;
            case G:
                printf("\tLeucine");
                break;
            case T:
                printf("\tPhenylalanine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    default:
        printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
        exit(1);
    }
}

/**
 * Prints the amino acids associated with each codon in the given array.
 *
 * REQ:
 *  - The "codons" array points to an array of codons with exactly num_codons in it
 *  - Each codon contains exactly 3 Nucleotides
 *  - Each nucleotide can only take on a value in the set {A, C, G, T}
 *
 * INPUT:
 *  - codons: An array of codons
 *  - num_codons: The number of codons that are in the array
 *
 * OUTPUT:
 *  - To the terminal: The amino acids associated with each codon in the list, in order.
 */
void printCodons(Codon codons[], int num_codons)
{
    for (int index = 0; index < num_codons; index++) printCodon(codons[index]);
    printf("\n");
}

// We NEED this compiler directive to test your code with our own main(). Don't break it.
#ifndef __TESTING  // this compiler directive
int main()
{
    Codon test_codons[3] = {
        {A, T, G}, // 0 3 2 14
        {A, A, C}, // 0 0 1 1
        {T, A, A}, // 3 0 0 48
    };

    printf("Before sorting:\n");
    printCodons(test_codons, 3);

    sortCodons(test_codons, 3);  // calls your sorting code

    printf("After sorting:\n");
    // Now should print:
    //     Asparganine    Glutamic Acid    STOP
    printCodons(test_codons, 3);
}
#endif  // and this compiler directive