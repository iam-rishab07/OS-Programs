/*
Q.33. Write a program to simulate Indexed file allocation method. Assumedisk with n number of blocks. Give value of n as input. Randomlymarksome block as allocated andaccordingly maintain the list of freeblocksWrite menu driver program with menu options as mentionedaboveandimplement each option. 
 Show Bit Vector
 Show Directory
 Delete Already File
 Exit
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    int bit[n]; // 0 = free, 1 = occupied
    char fname[10][20];
    int indexBlock[10];
    int fileCount = 0;

    for (int i = 0; i < n; i++) bit[i] = 0;

    int choice;
    do {
        printf("\n--- Indexed File Allocation ---\n");
        printf("1. Create File\n2. Show Bit Vector\n3. Show Directory\n4. Delete File\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Create File
            if (fileCount >= 10) {
                printf("Directory full!\n");
                break;
            }
            printf("Enter file name: ");
            scanf("%s", fname[fileCount]);
            
            int ib;
            printf("Enter index block: ");
            scanf("%d", &ib);

            if (ib < n && bit[ib] == 0) {
                bit[ib] = 1;
                indexBlock[fileCount] = ib;
                fileCount++;
                printf("File created successfully.\n");
            } else {
                printf("Block already allocated or invalid!\n");
            }
            break;

        case 2: // Show Bit Vector
            printf("Bit Vector: ");
            for (int i = 0; i < n; i++) printf("%d ", bit[i]);
            printf("\n");
            break;

        case 3: // Show Directory
            printf("\nFile\tIndex Block\n");
            for (int i = 0; i < fileCount; i++)
                printf("%s\t%d\n", fname[i], indexBlock[i]);
            break;

        case 4: // Delete File
            {
                char del[20];
                int found = 0;
                printf("Enter file name to delete: ");
                scanf("%s", del);
                for (int i = 0; i < fileCount; i++) {
                    if (strcmp(fname[i], del) == 0) {
                        bit[indexBlock[i]] = 0; // Free the block
                        // Shift array to fill the gap
                        for(int j = i; j < fileCount - 1; j++) {
                            strcpy(fname[j], fname[j+1]);
                            indexBlock[j] = indexBlock[j+1];
                        }
                        fileCount--;
                        found = 1;
                        printf("File deleted.\n");
                        break;
                    }
                }
                if(!found) printf("File not found.\n");
            }
            break;
        }
    } while (choice != 5);

    return 0;
}