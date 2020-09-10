#include <QCoreApplication>
#include <stdio.h>
#include <QThread>
#include <windows.h>

void ShowStars(int arr[], int sz);

const int size = 50;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char *fname = "D:\\tmp_own\\data.dat";

    for (int i = 0; i < 200; ++i)
    {
        QThread::msleep(50);
        FILE *fstars = fopen(fname, "rb");
        rewind(fstars);

        int arr[size];
        fread(arr, sizeof(int), size, fstars);
        fclose(fstars);

        ShowStars(arr, size);
        printf("\n\n\n");
        QThread::msleep(50);
        system("cls");
    }

    return a.exec();
}

void ShowStars(int arr[], int sz)
{
    for (int j = 0; j < sz; ++j)
    {
        for (int k = 0; k < arr[j]; ++k)
        {
            printf("*");
        }
        printf("\n");
    }
}
