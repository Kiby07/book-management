#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<fstream>
#include<windows.h>
using namespace std;

typedef struct bookinf
{
    string ISBN;
    string name;
    string author;
    string press;
    string date;
    double price;
}bookinf;
extern vector<bookinf> books;
const string FILENAME = "D:\\cprograms\\book\\bin\\Debug\\books.txt";
bool istext(const string &s);
bool isISBN(const string &s);
bool isdate(const string &s);
bool isprice(const string &s);
bool issearch(const string &s);
void loadbooks();
void savebooks();
void addbooks();
void putbooks(bookinf b);
void xiugaibooks();
void deletebooks();
void findbooks();
void exactsearch();
void mouhusearch();
void tongji();
void presssearch();
void authorsearch();
void datesearch();
#endif // BOOK_H
