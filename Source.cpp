#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include <stdio.h>
#include<windows.h>
#include<dos.h>
#include<vector>
#include<string.h>
#include<ctype.h>
int userinputvalidation(int, int);
void skeleton();
void dbat();
void dban();
void confirm();
void print_table();
void das();
using namespace std;
int main()
{
    skeleton();
    return 0;
}
void skeleton()
{

    system("CLS");
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); int ch, ch1;
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 20;
    cfi.dwFontSize.Y = 30;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = 900;
    wcscpy_s(cfi.FaceName, L"Calibri");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetConsoleTextAttribute(console_color, 1);
    cout << "\t\t      DIGITAL PERIODIC TABLE\n\n";
    cfi.dwFontSize.X = 0; cfi.dwFontSize.Y = 0; SetConsoleTextAttribute(console_color, 2);
    cout << "CHOOSE ANY OPERATION\n";
    cout << "1)Retrive Data by atomic number\n";
    cout << "2)Retrive Data by element name\n3)Sort elements acc to your choice\n4)Edit the data\n5)Data by symbol\n6)Exit\n";
    SetConsoleTextAttribute(console_color, 15);
    printf("Enter your choice\n");
    ch = userinputvalidation(1, 10); ch1 = ch;
    switch (ch1)
    {
    case 1:
        system("CLS");
        dbat();
        break;
    case 2:
        system("CLS");
        dban();
        break;
    case 3:
        system("CLS");
        printf("Sorry this part isnt ready\n"); Sleep(2000); skeleton(); break;
    case 4:
        system("CLS");
        printf("Sorry this part isnt ready\n"); Sleep(2000);skeleton(); break;
    case 5:

        system("CLS");
        das(); break;
    
    
    
    case 6:
        system("CLS");
        exit(1);
        break;
    }
    return;
}


int userinputvalidation(int l, int h)
{


    int ch;

    scanf_s("%d", &ch);
    if (ch <= h && ch >= l)
    {
        return ch;
    }
    else
    {
        cout << "Your have entered a wrong choice\nenter again\n";
        userinputvalidation(l, h);
    }
}

void dbat()
{
    int atn; FILE* fp1, * fp2, * fp3, * fp4, * fp5, * fp6; char  name[10], an, state[7]; int ch, ec[100], s[5]; float am;
    system("CLS");
    print_table();   HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 12);
    printf("Enter atomic number \n");
    atn = userinputvalidation(1, 118);
    fp1 = fopen("atn.txt", "r");
    fp2 = fopen("atname.txt", "r");
    fp3 = fopen("ele.txt", "r"); fp4 = fopen("symbols.txt", "r"); fp5 = fopen("atomicmass.txt", "r"); fp6 = fopen("standardstate.txt", "r");
    while (fscanf(fp1, "%d", &an) != EOF && fscanf(fp2, "%s", name) != EOF && fscanf(fp3, "%s", ec) != EOF && fscanf(fp4, "%s", s) != EOF&&fscanf(fp5,"%f",&am)!=EOF&&fscanf(fp6,"%s",state)!=EOF)
    {
        if (an == atn)
        {
            printf("atomic number=%d\nElement name=%s\nElectronic configuration=%s\nSymbol=%s ", atn, name, ec, s);
            printf("Standard state=%s\nAtomic mass=%f\n", state, am);
        }

    }
    fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6);
    SetConsoleTextAttribute(console_color, 1);
    printf("Press 0 to continue\n"); scanf("%d", &ch);
    if (ch == 0)
        dbat();
    confirm();
    return;
}
void dban()
{
    system("CLS"); HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    print_table(); FILE* fp1, * fp2, * fp3, * fp4, * fp5, * fp6; char name[10], name1[10], ec[100], s[5],state[7]; int atn = 0, r, ch; float am;
    printf("Enter the element name \n");
    scanf("%s", name);
    fp1 = fopen("atname.txt", "r"); fp2 = fopen("atn.txt", "r"); fp3 = fopen("ele.txt", "r"); fp4 = fopen("symbols.txt", "r");
    fp5 = fopen("atomicmass.txt", "r"); fp6 = fopen("standardstate.txt", "r");
    while (fscanf(fp1, "%s\0", name1) != EOF && fscanf(fp2, "%d", &atn) != EOF && fscanf(fp3, "%s", ec) != EOF && fscanf(fp4, "%s", s) != EOF&&fscanf(fp5,"%f",&am)!=EOF&&fscanf(fp6,"%s",state)!=EOF)
    {
        name[0] = toupper(name[0]);
        if (strcmp(name, name1) == 0)
        {
            SetConsoleTextAttribute(console_color, 12);
            printf("Element name=%s\natomic number=%d\n", name1, atn); 
            printf("Electronic configuration=%s\nSymbol=%s\n", ec, s);
            printf("Atomic mass=%f\nStandard state=%s", am, state);

        }

    }
    fclose(fp1), fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6);
    SetConsoleTextAttribute(console_color, 1);
    cout << "\nPress 0 to continue\n"; cin >> ch;
    if (ch == 0)
    {
        dban();
    }
    confirm();
    return;
}
void addd()
{
    system("CLS");
    print_table();
    confirm();
    return;
}
void confirm()
{
    int ex = 0;
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 1);
    printf("Press 1 to exit\nPress any other key for MAIN MENU\n");
    cin >> ex;
    if (ex == 1)
        exit(1);
    else
        skeleton();
}
void print_table()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    FILE* fp1;
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 10);
    char ch;
    fp1 = fopen("table.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp1);
    }
    return;
}
void das()
{
    system("CLS"); HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    print_table(); FILE* fp1, * fp2, * fp3, * fp4, * fp5, * fp6; char s1[3], s2[3], ec[100], name[10], state[7]; int atn = 0, r, ch; float am;
    printf("Enter the element symbol \n");
    scanf("%s", s1);
    fp1 = fopen("atname.txt", "r"); fp2 = fopen("atn.txt", "r"); fp3 = fopen("ele.txt", "r"); fp4 = fopen("symbols.txt", "r");
    fp5 = fopen("atomicmass.txt", "r"); fp6 = fopen("standardstate.txt", "r");
    while (fscanf(fp4, "%s\0", s2) != EOF && fscanf(fp2, "%d", &atn) != EOF && fscanf(fp3, "%s", ec) != EOF && fscanf(fp1, "%s", name) != EOF && fscanf(fp5, "%f", &am) != EOF && fscanf(fp6, "%s", state) != EOF)
    {
        s1[0] = toupper(s1[0]); s1[1] = toupper(s1[1]); s2[0] = toupper(s2[0]); s1[1] = toupper(s2[1]);
        if (strcmp(s1,s2) == 0)
        {
            SetConsoleTextAttribute(console_color, 12);
            printf("Element name=%s\natomic number=%d\n", name, atn);
            printf("Electronic configuration=%s\nSymbol=%s\n", ec, s2);
            printf("Atomic mass=%f\nStandard state=%s", am, state);

        }

    }
    fclose(fp1), fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6);
    SetConsoleTextAttribute(console_color, 1);
    cout << "\nPress 0 to continue\n"; cin >> ch;
    if (ch == 0)
    {
        das();
    }
    confirm();
    return;
}

