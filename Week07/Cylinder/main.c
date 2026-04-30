#include <stdio.h>

#define PI 3.14159

typedef struct {
    float radius;
    float height;
    float volume;
} Cylinder;

int main() {

    Cylinder cyl;

    //Option 1: User input (Used)
    printf("Enter radius of cylinder: ");
    scanf("%f", &cyl.radius);

    printf("Enter height of cylinder: ");
    scanf("%f", &cyl.height);

    //Option 2: Read from file (Not used)
    /*
    FILE *fin = fopen("C:/Users/jw2-barnett/CLionProjects/ufmfgt-15-1-portfolio/Week07/Cylinder/Answer/input.txt","r");
    if (fin == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    fscanf(fin, "%f", &cyl.radius);
    fscanf(fin, "%f", &cyl.height);
    fclose(fin);
    */

    cyl.volume = PI * cyl.radius * cyl.radius * cyl.height;

    FILE *fout = fopen("C:/Users/jw2-barnett/CLionProjects/ufmfgt-15-1-portfolio/Week07/Cylinder/Answer/cylinder.txt","w");
    if (fout == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    fprintf(fout, "Radius: %.2f\n", cyl.radius);
    fprintf(fout, "Height: %.2f\n", cyl.height);
    fprintf(fout, "Volume: %.2f\n", cyl.volume);

    fclose(fout);

    printf("Cylinder data written to Answer/cylinder.txt\n");

    return 0;
}