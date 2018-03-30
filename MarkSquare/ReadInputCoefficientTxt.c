#include <stdio.h>
#include <stdlib.h>
#include "PointDataStructure.h"
#include "BMP_Structure.h"
#include "MarkedSquare.h"

void Read_Input_Coefficient(char *filename, char Input_LeftBMP_Name[],
                            char *PointSetName, char Output_BMP_Name[],
                            MarkRegion *MarkRegion_Ptr)
{
    int i, j;
    char temp[200];
    FILE *fin=fopen(filename,"r");
    while(fin == NULL){
         printf("%s is no such file\n",filename); 
         printf("Please input IOPathCoefficient file name:\n"); 
         scanf("%s",&filename);
         fin = fopen(filename,"r");
    }
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Input_LeftBMP_Name);
    //輸入BMP圖檔檔名 
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", PointSetName);
    //輸入特徵點文字檔檔名 
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Output_BMP_Name);
    //輸出BMP圖檔檔名 
    fgets(temp, 200, fin);
    fscanf(fin,"%d\n", &MarkRegion_Ptr->RegionWidth);
    //標註方框之寬度
    fgets(temp, 200, fin);
    fscanf(fin,"%d\n", &MarkRegion_Ptr->RegionHeight);
    //標註方框之高度
    fgets(temp, 200, fin);
    fscanf(fin,"%d,%d,%d\n", &MarkRegion_Ptr->Color_B, &MarkRegion_Ptr->Color_G, &MarkRegion_Ptr->Color_R);
    //標註方框之BGR值 
}
