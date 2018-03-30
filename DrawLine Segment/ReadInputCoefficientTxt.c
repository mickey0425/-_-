#include <stdio.h>
#include <stdlib.h>
#include "PointDataStructure.h"
#include "BMP_Structure.h"

void Read_Input_Coefficient(char *filename, char Input_LeftBMP_Name[], char Input_RightBMP_Name[],  //��J����BMP�����ɦW�B��J�k��BMP�����ɦW 
                            char Input_MPPS_Name[], char Output_BMP_Name[],   //�t��S�x�I��r�ɡB��XBMP�����ɦW 
							Point2D *StartingPoint, ColorDegreeSet *ColorDegreeSet_Ptr)   //�k�ϰ_�l�I�y�СB�C�⵲�c(�u�q�C��BGR) 
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
    //��J����BMP�����ɦW 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Input_RightBMP_Name);
    //��J�k��BMP�����ɦW 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Input_MPPS_Name);
    //�I�ﶰ�X��r���ɦW 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%s\n", Output_BMP_Name);
    //��XBMP�����ɦW 
    
    fgets(temp, 200, fin);
    fscanf(fin,"%d,%d\n", &StartingPoint->x, &StartingPoint->y);
    //�k�ϰ_�l�y��     
    
    fgets(temp, 200, fin);
    fscanf(fin, "%d,%d,%d\n", &ColorDegreeSet_Ptr->LineColor_B, &ColorDegreeSet_Ptr->LineColor_G, &ColorDegreeSet_Ptr->LineColor_R);
    //�u�q�C��BGR 
}
