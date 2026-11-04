#include <stdio.h>
//这个头文件用来存放这个结构体变量和一些会用到的函数的声明
struct Books {
    char id[10];
    char title[100];
    char author[100];
    int num;
};

extern struct Books book[100];

void search_book();
void borrow_book();
void return_book();
void load_books(); 
void save_books();

extern char name[100];