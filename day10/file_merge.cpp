//
// Created by GG on 2020/7/27.
//

#include "file_merge.h"
#include <stdio.h>
#include "file_incise.h"

/**
 *文件合并
 */
void merge() {

    char *file_names[] = {"C:\\Users\\GG\\CLionProjects\\NDK_Day10\\day10\\image_0.jpg",
                          "C:\\Users\\GG\\CLionProjects\\NDK_Day10\\day10\\image_1.jpg",
                          "C:\\Users\\GG\\CLionProjects\\NDK_Day10\\day10\\image_2.jpg"};
    char *file_name = "C:\\Users\\GG\\CLionProjects\\NDK_Day10\\image_merge.jpg";
    FILE *merge_file = fopen(file_name, "wb");

    for (int i = 0; i < 3; i++) {
        FILE *file = fopen(file_names[i], "rb");

        int size = getFileSize(file_names[i]);
        for (int j = 0; j < size; j++) {
            fputc(fgetc(file), merge_file);

        }
        fclose(file);
    }

    fclose(merge_file);

    printf("----合并完成----");

}