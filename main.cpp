#include <QCoreApplication>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <QThread>

void Write(char *fname);
void Read(char *fname);
//void StarsRead(char *fname);

const int size = 50;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char *fname = "D:\\tmp_own\\data.dat";
    Write(fname);

    return a.exec();
}

void Write(char *fname)
{
    FILE *numsinf;
    if ((numsinf = fopen(fname, "wb")) == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    int arr[size];
    qsrand(time(NULL) | clock());
    for (int i = 0; i < size; ++i)
    {
        arr[i] = qrand() % 200 + 10;
    }

    fwrite(arr, sizeof(int), size, numsinf);


    fclose(numsinf);
}

void Read(char *fname)
{
    FILE *numsinf;
    if ((numsinf = fopen(fname, "rb")) == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    rewind(numsinf);

    int arr[size];
    fread(arr, sizeof(int), size, numsinf);

    for (int j = 0; j < size; ++j)
    {
        printf("%d  ", arr[j]);
    }
    printf("\n");

    fclose(numsinf);
}

//void StarsRead(char *fname)
//{
//    FILE *numsinf;
//    if ((numsinf = fopen(fname, "rb")) == NULL)
//    {
//        printf("Error\n");
//        exit(EXIT_FAILURE);
//    }

//    rewind(numsinf);

//    int arr[20];
//    fread(arr, sizeof(int), 20, numsinf);

//    for (int k = 0; k < 20; ++k)
//    {
//        int stars = arr[k];
//        for (int i = 0; i < stars; ++i)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }

//    fclose(numsinf);
//}
