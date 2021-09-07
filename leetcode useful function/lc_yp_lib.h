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
