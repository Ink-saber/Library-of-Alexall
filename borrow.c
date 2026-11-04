#include <stdio.h>
#include <string.h>
#include <time.h>
#include "books.h"

extern char name[100];
void borrow_book() {
    char book_id[10];
    int i=0;
    
    printf("请输入您想要借阅的图书的对应编号: ");
    scanf("%s",&book_id);
    getchar(); 

    for (i = 0; i < 100; i++) {
        if (strcmp(book[i].id, book_id) == 0) {
            if (book[i].num > 0) {
                book[i].num--;
                save_books();
                time_t Time=time(NULL);
                struct tm *realtime=localtime(&Time);
                printf("本次借阅信息已被记录，请于两周内归还哟~\n");
                FILE *fp = fopen("books_borrow_records.txt", "a");
                fprintf(fp, "%s已于%04d-%02d-%02d %02d:%02d:%02d借阅%s\n",name,realtime->tm_year+1900,
                realtime->tm_mon+1,realtime->tm_mday,realtime->tm_hour,realtime->tm_min,
            realtime->tm_sec,book[i].title);//这一串是时间信息，精确到了秒，还记录了借阅者姓名及书名
            fclose(fp);
            return ;
            } else {
                printf("该书已经被借完啦~请下次再来，或是您可尝试借阅其他书籍呢~\n");
            } 
        }
    }
    if(i==100){
        printf("未找到该图书，请检查一下您输入的编号是否正确呢~\n");
            } 
}