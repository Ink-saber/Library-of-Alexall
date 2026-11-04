#include <stdio.h>
#include <string.h>
#include "books.h"

void search_book() {
    char book_id[10];
    
    for(int i=0;i<100;i++){
        if(book[i].num==0){
            break;
        }
        printf("图书编号: %s ", book[i].id);
        printf("图书名称: %s ", book[i].title);
        printf("作者: %s ", book[i].author);
        printf("库存数量: %d\n", book[i].num);
    }//本来的版本是输入编号查找，后来发现如果没有查找也不知道编号
    

}