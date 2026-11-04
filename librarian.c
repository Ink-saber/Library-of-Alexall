#include <stdio.h>
#include <windows.h>
#include "books.h" 
#include <string.h>

//这个文件就是我的目的文件了，另外几个模块我都会用makefile来链接起来
struct Books book[100] = {
    {"A001","《周易》","伏羲、姬昌、孔子",10},
    {"A002","《诗经》","孔子",10},
    {"A003","《尚书》","孔子",10},
    {"A004","《礼记》","孔子",10},
    {"A005","《春秋》","孔子",10},
    {"B001","《史记》","司马迁",10},
    {"B002","《资治通鉴》","司马光",10},
    {"B003","《汉书》","班固",10},
    {"B004","《三国志》","陈寿",10},
    {"B005","《左传》","左丘明",10},
    {"C001","《韩非子》","韩非",10},
    {"C002","《孙子兵法》","孙武",10},
    {"C003","《墨子》","墨翟",10},
    {"C004","《道德经》","老子",10},
    {"C005","《庄子》","庄周",10},
    {"D001","《楚辞》","屈原、宋玉等",10},
    {"D002","《文心雕龙》","刘勰",10},
    {"D003","《世说新语》","刘义庆",10},
    {"E001","《共产党宣言》","马克思、恩格斯",10},
    {"E002","《资本论》","马克思",10},
    {"E003","《国家与革命》","列宁",10},
    {"E004","《毛泽东选集》","毛泽东",10},
};//存放的书籍放在这个结构体数组里

char name[100];

//下面这两个函数是为解决程序关闭之后无法保存的问题
void save_books(void)
{
    FILE *fp = fopen("books_data.txt", "w");   
    int i;

    if (fp == NULL) {
        printf("无法写入 books_data.txt，这个文件好像有问题诶~\n");
        return;
    }
    for (i = 0; i < 100; i++) {
        if (book[i].id[0] == '\0') break;      
        fprintf(fp, "%s|%s|%s|%d\n",
                book[i].id, book[i].title, book[i].author, book[i].num);
    }
    fclose(fp);//这块就是循环写入数据
}

void load_books(void)
{
    FILE *fp = fopen("books_data.txt", "r");
    char line[256];
    int n = 0;

    if (fp == NULL) {          //没有文件先生成一个
        save_books();
        return;
    }
    while (n < 100 && fgets(line, sizeof line, fp) != NULL) {
        struct Books tmp;
        line[strcspn(line, "\r\n")] = '\0';//这里是为去除多余回车，替换成空格以便后续筛查
        if (line[0] == '\0') continue;//看到空字符就跳过
        memset(&tmp, 0, sizeof tmp);//清除旧内容，用0填充
        if (sscanf(line, "%9[^|]|%99[^|]|%99[^|]|%d",
                   tmp.id, tmp.title, tmp.author, &tmp.num) == 4) {
            book[n++] = tmp;   
        }
    }
    fclose(fp);
}

int main() {
    int n;
    
    load_books();
    printf("亚历山小图书馆管理系统\n");
    printf("欢迎您来到我们亚历山小图书馆，本馆使用电子查询系统，请依照指示进行操作\n");
    printf("不过，在正式使用本系统之前，还请您先为您自己起一个昵称呢~以便我们记录您的借阅信息\n");
    scanf("%s", name);
    getchar(); // 
    
    
    for(;;){
    printf("请选择操作:\n");
    printf("1.查询图书\n");
    printf("2.归还图书\n");
    printf("3.借阅图书\n");
    printf("4.退出系统\n");
    printf("请输入正确的操作编号: ");
    scanf("%d", &n);
    getchar();
    if(n==4){
        printf("正在退出系统中......\n");
        printf("退出成功！");
        break;
    }
    switch(n) {
        case 1:
            search_book();
            break;
        case 2:
            borrow_book();
            break;
        case 3:
            return_book();
            break;
        default:
            printf("输入错误，请重新输入\n");
    }
}
    return 0;
}