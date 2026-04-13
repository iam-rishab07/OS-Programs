/*
Q.1 Write a program to simulate Contiguous file allocation method. Assume disk with n

number of blocks. Give value of n as input. Randomly mark some block as allocated and

accordingly maintain the list of free blocks Write menu driver program with menu options

as mentioned above and implement each option.

• Show Bit Vector

• Create New File

• Show Directory

• Exit
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, i, j, bit[50], start[10], len[10], f_cnt = 0, ch;
    char names[10][20];

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    // Initialize and randomly allocate some blocks
    for (i = 0; i < n; i++) bit[i] = (rand() % 2)? 1:0; 

    do {
        printf("\n1.Bit Vector 2.Create File 3.Show Directory 4.Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            for (i = 0; i < n; i++) printf("%d ", bit[i]);
            printf("\n");
        } 
        else if (ch == 2) {
            int s, l, free = 1;
            printf("Enter Name, Start, Length: ");
            scanf("%s %d %d", names[f_cnt], &s, &l);

            for (i = s; i < s + l; i++) 
                if (i >= n || bit[i] == 1) { free = 0; break; }

            if (free) {
                for (i = s; i < s + l; i++) bit[i] = 1;
                start[f_cnt] = s; len[f_cnt++] = l;
                printf("Allocated.\n");
            } else printf("Error: Blocks busy or out of range.\n");
        } 
        else if (ch == 3) {
            printf("\nFile\tStart\tLength\n");
            for (i = 0; i < f_cnt; i++)
                printf("%s\t%d\t%d\n", names[i], start[i], len[i]);
        }else if(ch!=4){
            printf("Invalid choice !, try again...");
            break;
        }
    } while (ch != 4);
    return 0;
}