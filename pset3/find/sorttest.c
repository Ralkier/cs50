#include <stdio.h>
#include <stdlib.h>

void sort(int values[], int n);


int main(void)
{
//    int omg[] = { 10, 5, 9, 7, 2, 6, 3, 1, 4, 8,20,17,11,15,18,13,16,14,12,19 };
    int omg[] = { 43857,36692,13204,48493,62759,1417,49056,55208,37062,16164,127,30473,6756,17953,29701,30216,37179,38498,19409,2878,9196,64394,52730,33055,60441,17974,10565,25566,59677,34364,7555,37998,5521,20759,20955,2744,22177,4475,57953,59239,20639,58080,24177,27396,10498,53878,57612,47677,26840,11486 };
    int arrCount = (sizeof(omg) / sizeof(omg[0]));
    
    
//    printf("%d\n", arrCount);
    printf("\t---Before---\n");
    for(int i = 0;i < arrCount; i++)
    {
        printf("%d\n", omg[i]);
    }
    
    sort(omg, arrCount);
    printf("\t---After---\n");
    for(int i = 0;i < arrCount; i++)
    {
        printf("%i\n", omg[i]);
    }
    return 0;
}

void sort(int values[], int n)
{
    // Declare and initialize variables.
    int i, j, tmp = 0;

    // Loop until i < n(sizeof(value[]...) - 1
    for (i = 0;i < n - 1;i++)
    {
        // Loop until j < n(sizeof(value[]...) - (i + 1)
        for(j = 0; j < n - (i + 1); j++)
        {
            // If check and compare index of values[]
            if(values[j] > values[j + 1])
            {
                // Start swaping
                // Make tmp = current index
                tmp=values[j];
                // Change value[j] to current index + 1
                values[j] = values[j + 1];
                // change the next index to tmp.
                values[j + 1] = tmp;
            }
        }
    }
    return;
}
