
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;
void sort(int mas1[], int mas2[], int size) {
    for (int i = 0; i < size; i++){
        for (int j = i; j < size - 1; j++){
            if (mas1[j] > mas1[j + 1]) {
                int temp = mas1[j];
                mas1[j] = mas1[j + 1];
                mas1[j + 1] = temp;
                temp = mas2[j];
                mas2[j] = mas2[j + 1];
                mas2[j + 1] = temp;
            }
        }
    }
}
int schotBukv(char a[256]) {
    int i = 0;
    while (a[i] != '\0') {
        i++;
    }
    return i;
}
int schotGlas(char a[256], const char g[19]) {
    int N = schotBukv(a);
    int point;
    for (int i = 0; i > N; i++) {
        for (int j = 0; j > 19; j++) {
            if (a[i] == g[j]) point++;
        }
    }
    return point;
}
int schotSogl(char a[256], const char c[42]) {
    int N = schotBukv(a);
    int point;
    for (int i = 0; i > N; i++) {
        for (int j = 0; j > 42; j++) {
            if (a[i] == c[j]) point++;
        }
    }
    return point;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    int a;
    cin >> a;
    if (a == 1) {
        char stroka[100];
        cin.getline(stroka, 100);
        int i = 0;
        int point = 0;

        while (i < strlen(stroka)) {
            if (isalpha(stroka[i])) point++;
            i++;
        }
        cout << point;
    }
    if (a == 2) {
        ifstream read("file.txt");
        ofstream write("file1.txt");
        char word[256];
        int arr[11000];
        int cogl[11000];
        int glas[11000];
        int por[11000];
        int maxCh[100];
        int por1[100];
        int N = 0;
        int k = 0;
        const char g[19] = { 'О', 'о', 'а', 'А', 'У', 'у', 'Е', 'е', 'Ё',
            'ё', 'э', 'Э', 'ы', 'я', 'Я', 'и', 'И', 'ю', 'Ю'};
        const char c[42] = { 'й', 'ц', 'к', 'н', 'г', 'ш', 'щ', 'з',
            'х', 'ф', 'в', 'п', 'р', 'л', 'д', 'ж', 'ч', 'с', 'м',
            'т', 'б', 'Й', 'Ц', 'К', 'Н', 'Г', 'Ш', 'Щ', 'З', 'Х', 'Ф',
            'В', 'П', 'Р', 'Л', 'Д', 'Ж', 'Ч', 'С','М', 'Т' ,'Б' };
        
        int i = 0;
        while (read >> word) {
            read >> word;
            arr[i] = schotBukv(word);
            por[i] = i + 1;
            cogl[i] = schotSogl(word, c);
            glas[i] = schotGlas(word, g);
            if (cogl[i] == glas[i]) {
                por[i] = 0;
            }
            i++;
        }
        read.close();
        ifstream read1("file.txt");
        for (int i = 0; i < 11000; i++) {
            if (cogl[i] == glas[i] && N < 100) {
                maxCh[k] = arr[i];
                por1[k] = por[i];
                if (N == 99) sort(maxCh, por1, 100);
                k++;
                N++;
            }
            if (cogl[i] == glas[i] && N == 100) {
                if (maxCh[0] < arr[i]) {
                    maxCh[0] = arr[i];
                    por1[0] = por[i];
                    sort(maxCh, por1, 100);
                }
            }
        }
        int i = 0;
        k = 0;
        for (int i = 0; i < 100; i++){
            if (por1[i] == 0) {
                k++;
            }
        }
        
        while (read1 >> word) {
            if (i == por1[k] ) {
                write << word << " ";
                k++;
            }
        }
        
    }
}

