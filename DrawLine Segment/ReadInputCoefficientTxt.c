#include <stdio.h>
#include <stdlib.h>
#include "PointDataStructure.h"
#include "BMP_Structure.h"

void Read_Input_Coefficient(char *filename, char Input_LeftBMP_Name[], char Input_RightBMP_Name[],  //輸入左圖BMP圖檔檔名、輸入右圖BMP圖檔檔名 
                            char Input_MPPS_Name[], char Output_BMP_Name[],   //配對特徵點文字檔、輸出BMP圖檔檔名 
							Point2D *StartingPoint, ColorDegreeSet *ColorDegreeSet_Ptr)   //右圖起始點座標、顏色結構(線段顏色BGR) 
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
    //輸入左圖BMP圖檔檔名 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Input_RightBMP_Name);
    //輸入右圖BMP圖檔檔名 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Input_MPPS_Name);
    //點對集合文字檔檔名 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Output_BMP_Name);
    //輸出BMP圖檔檔名 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%d,%d\n", &StartingPoint->x, &StartingPoint->y);
    //右圖起始座標     
    
    fgets(temp, 200, fin);
    fscanf(fin, "%d,%d,%d\n", &ColorDegreeSet_Ptr->LineColor_B, &ColorDegreeSet_Ptr->LineColor_G, &ColorDegreeSet_Ptr->LineColor_R);
    //線段顏色BGR 
}
