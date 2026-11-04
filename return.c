#include <stdio.h>
#include <string.h>
#include <time.h>
#include "books.h"

void return_book(){
    char book_id[10];
    extern char name[100];
    int i=0;
    int a=0;

    printf("请输入您想归还的书的编号呢~\n");
    scanf("%s",book_id);
    getchar();

    for(i=0;i<100;i++){
        if (strcmp(book[i].id, book_id) == 0){
            if(book[i].num<10){
            book[i].num++;
            save_books();
            time_t theTime=time(NULL);
                struct tm *facttime=localtime(&theTime);
            printf("常言道：“有借有还，再借不难。”感谢您的配合，期待与您下次相遇！\n");
            FILE *fpp = fopen("books_return_records.txt", "a");
                fprintf(fpp, "%s已于%04d-%02d-%02d %02d:%02d:%02d归还%s\n",name,facttime->tm_year+1900,
                facttime->tm_mon+1,facttime->tm_mday,facttime->tm_hour,facttime->tm_min,
            facttime->tm_sec,book[i].title);
            fclose(fpp);
            a=1;
            break;
                }
            else{
                printf("您确定是要还这本书吗？请再检查一下罢~\n");
            }
        }//先写的borrow，这很大一段都是从那边改过来的，条件艰苦，缝缝补补又三年~
        if(a==1){
            return;
        }
        if(i==100){
            printf("您要不再检查一下编号是否有异常呢~\n");
        }
    }
}