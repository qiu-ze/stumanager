#include <windows.h>
#include <stdio.h>
#include "student.h"

STU students[N];
int studentCount = 0;

void Exit();
void append_Record();
void list_Record();
void delete_Record();

int main(void) {
    SetConsoleOutputCP(65001);
    printf("*****************************\n");
    printf("|欢迎使用基于数组的学生信息管理系统|\n");
    printf("|       1.Append record     |\n");
    printf("|       2.List record       |\n");
    printf("|       3.Delete record     |\n");
    printf("|       4.Modify record     |\n");
    printf("|       5.                  |\n");
    printf("|       6.                  |\n");
    printf("|       7.                  |\n");
    printf("|       8.                  |\n");
    printf("|       9.                  |\n");
    printf("|      10.                  |\n");
    printf("|      11.                  |\n");
    printf("|      12.                  |\n");
    printf("|      13.                  |\n");
    printf("*****************************\n");
    int aa;
    while (1) {
        printf("choose u method\n");
        scanf("%d", &aa);
        switch (aa) {
            case 1:
                printf("你选择的功能是Append record\n");
                append_Record();
                break;
            case 2:
                list_Record();
                break;
            case 3:
                delete_Record();
                break;
            case 13:
                Exit();
                break;
            default: printf("无此功能\n");
        }
    }
    return 0;
}

void Exit() {
    printf("退出程序\n");
    printf("谢谢您的使用\n");
    exit(0);
}

void append_Record() {
    if (studentCount >= N) {
        printf("学生数量满了，无法记录");
        return;
    }
    printf("\n请依次输入学生信息：\n\n学号 姓名 专业 班级 第一门课成绩 第二门课成绩 第三门课成绩\n");
    STU s;
    scanf("%s",&s.num);
    scanf("%s",&s.name);
    scanf("%s",&s.major);
    scanf("%d",&s.classNo);
    for (int i = 0;i < M;i++) {
        scanf("%d",&s.score[i]);
    }
    students[studentCount++] = s;
    printf("学生信息添加成功\n");
}

void list_Record() {
    if (studentCount == 0) {
        printf("无学生记录\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        printf("学号: %s\n", students[i].num);
        printf("  姓名: %s\n", students[i].name);
        printf("  专业: %s\n", students[i].major);
        printf("  班级: %d\n", students[i].classNo);
        for (int j = 0; j < M; j++) {
            printf("  第%d门课程成绩: %d\n", j + 1, students[i].score[j]);
        }
    }
}

void delete_Record() {
    if (studentCount == 0) {
        printf("没有学生记录可以删除。\n");
        return;
    }

    char searchNumName[15];
    int found = 0;

    printf("请输入要删除的学生学号或姓名: ");
    scanf("%s", searchNumName);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].num, searchNumName) == 0 || strcmp(students[i].name, searchNumName) == 0) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("学生信息删除成功。\n");
            break;
        }
    }

    if (!found) {
        printf("没有找到学号或姓名为 %s 的学生信息。\n", searchNumName);
    }
}