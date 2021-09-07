#include <stdio.h>
#include <stdlib.h>
int input(int **nums, int *target);
int find_hash(int *hashtable, int hsize, int target);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int display(int returnSize, int *ans);

int main()
{
    int *nums, target, numsSize, i, returnSize, *ans;
    nums = (int*)malloc(10000*sizeof(int));
    ans = (int*)malloc(2*sizeof(int));
    returnSize = 0;
    numsSize = input(&nums,&target);
    
    
    /*printf("%d\n",numsSize);
    for(i=0;i<numsSize;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\ntarget = %d\n",target);*/

    ans = twoSum(nums,numsSize,target,&returnSize);
    
    display(returnSize,ans);

    
    getchar();
    return 0;
}

int input(int **nums, int *target)
{
    int i, numsSize;
    char endchar;
    i = 0;
    numsSize = 0;
    do
    {
        scanf("%c",&endchar);
        //printf("endchar %c numsSize %d\n",endchar, numsSize);
        switch (endchar)
        {
        
        case '[':
            
            scanf("%d",&(*nums)[numsSize]);
            //printf("nums %d\n",(*nums)[numsSize]);
            numsSize++;
            break;
        case ',':
            
            scanf("%d",&(*nums)[numsSize]);
            //printf("nums %d\n",(*nums)[numsSize]);
            numsSize++;
            break;
        
        case'-':
            scanf("%d",&(*nums)[numsSize]);
            //printf("nums %d\n",(*nums)[numsSize]);
            numsSize++;
            break;
        default:
            //printf("Error\n");
            break;
        }

    }while(endchar!=']');
    scanf("%d",target);
    
    return numsSize;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, pos1, pos2, *ans_pos, *hashtable, hsize, cmpnum;
    ans_pos = (int*)malloc(2*sizeof(int));
    hashtable = (int*)malloc(numsSize*sizeof(int));
    
    for(i=0;i<numsSize;i++)
    {

        if(nums[i]==target && target!=0)
        {
            pos1 = i;
            *returnSize = 1;
            ans_pos[0] = pos1;
            return ans_pos;
            
        }
        else
        {
            cmpnum = target - nums[i];
            //printf("cmpnum %d\n",cmpnum);
            pos1 = find_hash(hashtable,i,cmpnum);
            if(pos1==-1)
            {
                //printf("hash miss\n");
                hashtable[i] = nums[i];
                continue;
            }
            else
            {
                //printf("hash hit\n");
                pos2 = i;
                *returnSize = 2;
                ans_pos[0] = pos1;
                ans_pos[1] = pos2;
                //printf("%d %d\n",ans_pos[0],ans_pos[1]);
                return ans_pos;

            }
        }
        
        
        
    }
    
}

int find_hash(int *hashtable, int hsize, int target)
{
    int i;
    for(i=0;i<hsize;i++)
    {
        
        if(hashtable[i]==target)
        {
            return i;
        }
        
    }
    return -1;
}

int display(int returnSize, int *ans)
{
    if(returnSize==1)
    {
        printf("[%d]",ans[0]);
    }
    else
    {
        printf("[%d,%d]",ans[0],ans[1]);
    }
}