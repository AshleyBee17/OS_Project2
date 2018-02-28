//
// Created by Blanche Janice Pinto on 2/28/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct Page{
    int vpn;
    time_t timeAccessed;
    bool dirty;
};

void printToConsole(char *output);

void fifo();

void lru();

void vms();

bool DEBUG = false;
char *fileName;
int framesCount;

int main(int argc, char *argv[]) {
    char* algorithmLetter;


    if(argc < 5){
        return 0; // Print error message
    }

    // Read trace File
    fileName = argv[1];

    // Intialize frames amount
    framesCount = atoi(argv[2]);

    // Switch case for which algorithm to use
    switch(argv[3][0]) { // Grabs first letter of algorithmn (L F or V)
        default:
        case 'l':
        case 'L':
            lru();
            break;
        case 'f':
        case 'F':
            fifo();
            break;
        case 'v':
        case 'V':
            vms();
            break;
    }

    // Set debug or not
    if(argv[4][0] == 'd' || argv[4][0] == 'D' ) {
        DEBUG = true;
    }




    return 0;
}

void vms() {

}

void lru() {
    int read;
    FILE *fp;

    struct PageTable lruTable;
    lruTable.size = framesCount;

    fp = fopen(fileName, "r");

    unsigned addr;char rw;
    while(read != EOF) {
        struct Page page;
        read = fscanf(fp,"%x %c",&addr,&rw);


        if(rw == 'W') {

        }
        page.timeAccessed = time(0);
        page.vpn = addr/ 4096;


    }
}

void fifo() {

}


void printToConsole(char *output) {
    if(DEBUG) {
        printf("%s\n", output);
    }
}


bool lruPagePrevLoaded(struct PageTable pageTable, char * vpn) {
    int i;
    for(i=0;i< pageTable.size;i++) {
        if(pageTable.pages[i].vpn == vpn) {
            return true;
        }
    }
    return false;
}



struct Page leastUsedPage(struct PageTable pageTable) {
    unsigned int i, smallestValue = (unsigned int) -1; // Forcing smallest value to be the largest possible int value.
    for(i=0;i< pageTable.size;i++) {
        if(pageTable.pages[i].timeAccessed < smallestValue) {
            smallestValue = (unsigned int) pageTable.pages[i].timeAccessed;
        }
    }

    return pageTable.pages[i];
};