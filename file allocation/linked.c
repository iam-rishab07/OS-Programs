/*
Q.3. Write a program to simulate Linked file allocation method. Assumediskwith n number of blocks. Give value of n as input. Randomly marksomeblock as allocated andaccordingly maintain the list of free blocksWritemenu driver program with menu options as mentioned belowandimplement each option. 
 Show Bit Vector
 Create New File
 Show Directory
 Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct File {
    char name[20];
    int start, end, size;
    int blocks[50]; 
} f[10];

int main() {
    int n, bit[100], fCount = 0, ch;
    srand(time(NULL));

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    // Randomly allocate ~15% of blocks as "already taken"
    for (int i = 0; i < n; i++) bit[i] = (rand() % 100 < 15) ? 1 : 0;

    while (1) {
        printf("\n1.Bit Vector 2.Create 3.Directory 4.Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            for (int i = 0; i < n; i++) printf("%d ", bit[i]);
            printf("\n");
        } 
        else if (ch == 2) {
            printf("Enter name and size: ");
            scanf("%s %d", f[fCount].name, &f[fCount].size);
            
            int allocated = 0;
            for (int i = 0; i < n && allocated < f[fCount].size; i++) {
                if (bit[i] == 0) {
                    bit[i] = 1;
                    if (allocated == 0) f[fCount].start = i;
                    f[fCount].blocks[allocated++] = i;
                    f[fCount].end = i;
                }
            }
            if (allocated < f[fCount].size) printf("Not enough space!\n");
            else { printf("File Created.\n"); fCount++; }
        } 
        else if (ch == 3) {
            printf("\nFile\tStart\tEnd\tChain\n");
            for (int i = 0; i < fCount; i++) {
                printf("%s\t%d\t%d\t", f[i].name, f[i].start, f[i].end);
                for (int j = 0; j < f[i].size; j++) 
                    printf("%d%s", f[i].blocks[j], (j == f[i].size - 1) ? "" : "->");
                printf("\n");
            }
        } 
        else exit(0);
    }
    return 0;
}