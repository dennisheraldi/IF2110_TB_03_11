#include "listdin.h"
#include "stdio.h"

int main(void)
{
    ListDin l1;
    CreateListDin(&l1,5);
    if (isIdxValidLD(l1,2))
    {
        printf("valid\n");
    }
    if (!isFullLD(l1))
    {
        printf("masih ada tempat\n");
        printf("Kapasitas list %d\n",lengthLD(l1));
    }
    if (isEmptyLD(l1))
    {
        printf("ListDin masih kosong\n");
    }
    growList(&l1,3);
    printf("sekarang kapasitas list menjadi %d\n",lengthLD(l1));

}