//
// Created by GG on 2020/7/27.
//

#include "file_incise.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int getFileSize(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        return 0;
    }

    fseek(file, 0, SEEK_END);

    int size = ftell(file);

    fclose(file);

    return size;

}


void incise() {
    char *file_name = "C:\\Users\\GG\\CLionProjects\\NDK_Day10\\day10\\image.jpg";

    FILE *file = fopen(file_name, "rb");

    //计算大小
    int file_size = getFileSize(file_name);

    int file_number = 3;
    //每个文件大致需要多少空间
    int pre_file_size = file_size / file_number;
    //构造分割文件需要的二维数组
    char **file_names = static_cast<char **>(malloc(sizeof(char *) * file_number));
    //对二维数组中的元素取名
    for (int i = 0; i < file_number; i++) {
        file_names[i] = static_cast<char *>(malloc(sizeof(char) * 300));
        sprintf(file_names[i], "C:\\Users\\GG\\CLionProjects\\NDK_Day10\\day10\\image_%d.jpg", i);
//        printf("%s\n", file_names[i]);
    }

    for (int j = 0; j < file_number; j++) {
        //构造相应文件，设置为二进制写模式
        FILE *cur_file = fopen(file_names[j], "wb");
        //从哪个位置开始写
        int start = j * pre_file_size;
        //写到哪里
        int end;

        if (j == file_number - 1) {
            end = file_size;
        } else {
            end = (j + 1) * pre_file_size;
        }

        for (int k = start; k < end; k++) {
            fputc(fgetc(file), cur_file);
        }
        fclose(cur_file);
        free(file_names[j]);
    }


    fclose(file);
    free(file_names);

    printf("----complete----");
}
