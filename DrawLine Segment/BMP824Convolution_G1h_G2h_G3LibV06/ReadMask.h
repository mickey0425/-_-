//ReadMask.h

typedef struct
{
	char MaskType[50];      //Mask���� 
	int MaskWidth;          //Mask�e 
	int MaskHeight;         //Mask�� 
	float *MaskCoefficient; //Mask���,�@���}�C 
}MaskStructure;

void ReadMask(char filename[],MaskStructure *Maskdata);
//28-18��
void ReadShowMask(char filename[],MaskStructure *Maskdata);
//30-19�� 
void ReadMaskHead(FILE *MaskFilePtr,MaskStructure *Maskdata);
//29-16��
void ReadMaskCoeff(FILE *MaskFilePtr,MaskStructure *Maskdata);
//37-23�� 
void ShowMaskData(MaskStructure *Maskdata);
//15-14��
