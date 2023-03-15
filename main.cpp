#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void Quicksort(int dizi[],int baslangic,int bitis) {
    int temp,a = baslangic, b = bitis;

    int pivotsayi = dizi[(baslangic+bitis)/2];

    while (a <= b) {

        while (dizi[a] < pivotsayi) {
            a++;
        }
        while (dizi[b] > pivotsayi) {
            b--;
        }
        if (a<=b) {
            temp=dizi[a];
            dizi[a]=dizi[b];
            dizi[b]=temp;
            a++;
            b--;

        }

    }
    if (baslangic<b)
        Quicksort(dizi,baslangic,b);
    if (a<bitis)
        Quicksort(dizi,a,bitis);
}
int main() {
     int Boyut = 10000;
     int dizi[Boyut];
    srand(time(NULL));
    for (int i = 0;i<Boyut; i++) {
        dizi[i]=rand();
    }

    clock_t baslangicadresi = clock();

    Quicksort(dizi,0,Boyut-1);

    clock_t bitisadresi=clock();

    float Quicksortgecensure = (float)(bitisadresi-baslangicadresi)/CLOCKS_PER_SEC;

    cout <<"Quicksort suresi: "<< Quicksortgecensure << " sn" << endl;
     baslangicadresi = clock();


    for (int i = 0;i<Boyut; i++) {
        for (int j=i +1;j< Boyut;j++) {
            if (dizi[j]< dizi[i]) {
                int temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }

        }


    }
    bitisadresi = clock();

    float bruteforcegecensure=(float)(bitisadresi-baslangicadresi)/CLOCKS_PER_SEC;

    cout <<"BruteForce suresi:"<<bruteforcegecensure << " sn" << endl;


    return 0;
}
