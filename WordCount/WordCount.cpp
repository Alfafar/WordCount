#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void c(char* file,int n) {
    printf("\n字符数：%d\n",n);
}
void w(char* file,int n) {
    int number = 0;
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (file[i] == ' ' || file[i] == ',') {
            flag = 1;
            number++;
        }

    }

    if (flag == 1)number++;
    printf("\n单词数：%d\n", number);

}
int main(int argc, char* argv[]) {


        char* parameter = argv[1];
        char* input_file_name = argv[2];
        FILE* f;
        if ((f = fopen(input_file_name, "rt")) == NULL) {
            printf("\nCannot open file!\n");
            exit(1);
        }


        char file[100] ;
        int len = 0;
        while (!feof(f))//feof 检查是否到文件的结束位置
        {
            file[len] = fgetc(f);

           len++;
        }


        switch (parameter[0]) {
        case '-': {
           
            switch (parameter[1]) {
            case 'c'://统计字符数
                c(file,len);
                fclose(f);

                break;
            case 'w'://统计单词数
                w(file,len);
                fclose(f);
                break;

            default://无法识别的选项
                printf("未识别指令\n");
                fclose(f);
            }
            break;
        }
        default://不以'-'开头，是文件名
            printf("指令错误！\n");
            break;
        }
    
   

}

