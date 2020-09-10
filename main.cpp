#include <QCoreApplication>
#include <stdio.h>
#include <conio.h>
#include <QThread>

void ShowFile(char *fname);
void SortFile(char *fname);
void ShowArr(int arr[], int sz);

const int size = 50;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // prompt
    do
    {
        printf("\nEnter space: ");

    } while(getch() != ' ');

    printf("\nSpace success\n");

    char *fname = "D:\\tmp_own\\data.dat";

//    // show
//    ShowFile(fname);



    // sort
    SortFile(fname);



//    // show after sort
//    ShowFile(fname);

    return a.exec();
}

void ShowFile(char *fname)
{
    // open
    FILE *numsinf;
    if ((numsinf = fopen(fname, "rb")) == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    rewind(numsinf);

    // into arr
    int arr[size];
    fread(arr, sizeof(int), size, numsinf);

    // print content
    for (int j = 0; j < size; ++j)
    {
        printf("%d  ", arr[j]);
    }
    printf("\n");

    // close
    fclose(numsinf);
}

void SortFile(char *fname)
{
    // open
    FILE *numsinf;
    if ((numsinf = fopen(fname, "rb")) == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    rewind(numsinf);

    int arr[size];
    // into arr
    fread(arr, sizeof(int), size, numsinf);
    fclose(numsinf);

    // loop sort
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        numsinf = fopen(fname, "wb");
        fwrite(arr, sizeof(int), size, numsinf);
        fclose(numsinf);
        QThread::msleep(100);
        //ShowFile(fname);
    }

    // show arr
//    printf("Show arr:\n");
//    ShowArr(arr, 20);

//    rewind(numsinf);
//    // into file
//    printf("wr in file\n");
//    fwrite(arr, sizeof(int), 20, numsinf);

//    fclose(numsinf);

}

void ShowArr(int arr[], int sz)
{
    for (int j = 0; j < sz; ++j)
    {
        printf("%d  ", arr[j]);
    }
    printf("\n");
}
