//
// Created by Blanche Janice Pinto on 2/28/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct Page{
    int vpn;
    int vb = 1; //valid bit, assume all pages are valid.
    int pb = 0; //present bit
    int db = 0; //dirty bit
    int lru_cnt;
};

void populate_page(FILE *file, Page *page);

void lru(char *argv[], FILE *tFile);
void fifo(char *argv[], FILE *tFile);
void vms(char *argv[], FILE *tFile);

int main(int argc, char *argv[]){

    // Checking that the proper number of arguments are given
    if (argc!= 5){

        printf("Proper amount of arguments not given \n");
        return -1;

    }else{
        // Checking that the file can be opened
        FILE *traceFile = fopen(argv[1], "r");

        if (traceFile == NULL){
            printf("File cannot be opened");
            return -1;
        }
        else{

            int nframes; //number of frames
            char algorithm[]; //lru or fifo or vms
            char dq; //debug or quiet

            //getting all arguments
            nframes = atoi(argv[2]);

            if (argv[3]!= NULL){
                algorithm = argv[3];
            }else{
                algorithm = "fifo"; //default algorithm is fifo
            }

            if(argv[1]!=NULL){
                dq = argv[4][1];
            }else{
                dq = 'q'; //default mode is quiet
            }

        }

        printf("\n------File Name: %s, Number of Frames: %d, Algorithm: %c, Debug/Quiet: %c------\n", argv[1], nframes, algorithm, dq);

        // Checking which algorithm has been chosen from the arguments. If it hasn't an
        // error will show. When an algorithm is chosen it'll pass the trace file, and the quiet or
        // debug selection to the algorithm.
        if(strcmp(argv[3],"LRU") == 0 || strcmp(argv[3],"lru") == 0){
            lru(argv, traceFile);
        }else if(strcmp(argv[3],"FIFO") == 0 || strcmp(argv[3],"fifo") == 0){
            fifo(argv, traceFile);
        }else if(strcmp(argv[3],"VMS") == 0 || strcmp(argv[3],"vms") == 0){
            vms(argv, traceFile);
        }else printf("Algorithm LRU, FIFO, or VMS has not been chosen.");


        fclose(traceFile);

    }



    return 0;
}

void lru(char *argv[], FILE *tFile){


}

void fifo(char *argv[], FILE *tFile){


}

void vms(char *argv[], FILE *tFile){


}

void populate_page(FILE *file, Page *page){
    //checking if file is valid
    if (file==0){
        return false;
    }
    else
    {

        unsigned int addr;
        char rw;
        int i;

        for(i = 0; fscanf(file, "%x %c", &addr, &rw) != EOF; i++)
        {
            Page[i].vpn = addr >> 12; 	//Grabs the first bits - virtual page #
            Page[i].d = rw;			//Grabs the R/W char
        }

        fclose(file);
        return true;

    }
}


