#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize);



int main()
{
    

    getchar();
    return 0;
}

int leetcode_input(int* nums)
{
    int *nums, i, numsSize;
    char *ori_nums;
    nums = (int*)malloc(30000*sizeof(int));
    ori_nums = (char*)malloc(2*sizeof(char));
    i = 0;
    numsSize = 0;
    
    while(1)
    {
        scanf("%c",&ori_nums[i]);
        if(ori_nums[i]=='['||ori_nums[i]==',')
        {
            ori_nums[i] = '\0';
            i = 0;
            continue;
        }
        else if(ori_nums[i]==']')
        {
            break;
        }
        else if(ori_nums[i]=='-')
        {
            i++;
            scanf("%c",&ori_nums[i]);
            nums[numsSize] = -1 * (ori_nums[i] - '0');
            numsSize++;
            i = 0;
            continue;
            
        }
        else
        {
            nums[numsSize] = (ori_nums[i] - '0');
            numsSize++;
            i = 0;
            continue;
        }


    }
    
    printf("%d\n",numsSize);
    for(i=0;i<numsSize;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int maxSubArray(int* nums, int numsSize)
{

}