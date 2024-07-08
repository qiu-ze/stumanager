#include <windows.h>
#include <stdio.h>
#include "student.h"

STU students[N];
int studentCount = 0;

int main(void) {
    SetConsoleOutputCP(65001);
    printf("*******************************************************\n");
    printf("|              欢迎使用基于数组的学生信息管理系统        |\n");
    printf("|       1.Append record                               |\n");
    printf("|       2.List record                                 |\n");
    printf("|       3.Delete record                               |\n");
    printf("|       4.Modify record                               |\n");
    printf("|       5.Search record                               |\n");
    printf("|       6.Sort Score in descending order by sum       |\n");
    printf("|       7.Sort Score in ascending order by sum        |\n");
    printf("|       8.Sort Score in descending order by num       |\n");
    printf("|       9.Sort Score in ascending order by num        |\n");
    printf("|      10.Write to a File                             |\n");
    printf("|      11.Read from a File                            |\n");
    printf("|      12.Insert                                      |\n");
    printf("|      13.Exit                                        |\n");
    printf("*******************************************************\n");
    int aa;
    while (1) {
        printf("选择你要使用的功能\n");
        if(scanf("%d", &aa)!=1) {
            while (getchar()!='\n');
            printf("无效的输入，请输入数字。\n");
            continue;
        };
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
            case 4:
                modify_Record();
                break;
            case 5:
                search_Record();
                break;
            case 6:
                sort_Score_In_Descending_Order_By_Sum();
                break;
            case 7:
                sort_Score_In_Ascending_Order_By_Sum();
                break;
            case 8:
                sort_Score_In_Descending_Order_By_Num();
                break;
            case 9:
                sort_Score_In_Ascending_Order_By_Num();
                break;
            case 10:
                write_To_File();
                break;
            case 11:
            read_From_A_File();
                break;
            case 12:
            Insert();
                break;
            case 13:
                Exit();
                break;
            default: printf("无此功能\n");
        }
    }
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
    STU *s = &students[studentCount];
    scanf("%s",s->num);
    scanf("%s",s->name);
    scanf("%s",s->major);
    scanf("%d",&s->classNo);
    for (int i = 0;i < M;i++) {
        scanf("%d",&s->score[i]);
    }
    studentCount++;
    printf("学生信息添加成功\n");
}

void list_Record() {
    if (studentCount == 0) {
        printf("无学生记录\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        STU *s = &students[i];
        printf("学号: %s\n", s->num);
        printf("  姓名: %s\n",s->name );
        printf("  专业: %s\n",s->major);
        printf("  班级: %d\n",s->classNo);
        for (int j = 0; j < M; j++) {
            printf("  第%d门课程成绩: %d\n", j + 1, s->score[j]);
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

void modify_Record() {
    if (studentCount == 0) {
        printf("没有学生记录可以修改。\n");
        return;
    }

    char searchNumName[15];
    int found = 0;

    printf("请输入要修改的学生学号或姓名: ");
    scanf("%s", searchNumName);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].num, searchNumName) == 0 || strcmp(students[i].name, searchNumName) == 0) {
            found = 1;
            STU *s = &students[i];
            printf("输入新的学号: ");
            scanf("%s", s->num);
            printf("输入新的姓名: ");
            scanf("%s",s->name );
            printf("输入新的专业: ");
            scanf("%s", s->major);
            printf("输入新的班级: ");
            scanf("%d", &s->classNo);
            for (int j = 0; j < M; j++) {
                printf("输入新的第%d门课程成绩: ", j + 1);
                scanf("%f", &s ->score[j]);
            }
            printf("学生信息修改成功。\n");
            break;
        }
    }

    if (!found) {
        printf("没有找到学号或姓名为 %s 的学生信息。\n", searchNumName);
    }
}

void search_Record() {
    if (studentCount == 0) {
        printf("没有可查找的学生记录。\n");
        return;
    }

    char searchNumName[15];
    int found = 0;

    printf("请输入要查找的学生学号或姓名");
    scanf("%s",searchNumName);

    for (int i = 0;i < studentCount;i++) {
        if (strcmp(students[i].num, searchNumName) == 0 || strcmp(students[i].name, searchNumName) == 0) {
            found = 1;
            printf("他的学号是:%s\n",students[i].num);
            printf("他的姓名是:%s\n",students[i].name);
            printf("他的专业是:%s\n",students[i].major);
            printf("他所在的班级是:%d\n",students[i].classNo);
            for (int j = 0; j < M; j++) {
                printf("他的第%d门成绩是:%d\n", j + 1,students[i].score[j]);
            }
            printf("查找成功\n");
            break;
        }
    }
    if (!found) {
        printf("没有找到学号或姓名为 %s 的学生信息。\n", searchNumName);
    }
}

int CalculateTotalScore(STU *s) {
    int total = 0;
    for (int i = 0; i < M; i++) {
        total += s->score[i];
    }
    return total;
}

void sort_Score_In_Descending_Order_By_Sum() {
    if (studentCount < 2) {
        printf("学生记录不足以排序。\n");
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - 1 - i; j++) {
            if (CalculateTotalScore(&students[j]) < CalculateTotalScore(&students[j + 1])) {
                STU temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("学生记录已按总分降序排序。\n");
}

void sort_Score_In_Ascending_Order_By_Sum(){
    if (studentCount == 0) {
        printf("没有学生记录可以排序。\n");
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < studentCount; j++) {
            if (CalculateTotalScore(&students[j]) < CalculateTotalScore(&students[minIndex])) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            STU temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
    printf("按照总分升序排序完成。\n");
}

void sort_Score_In_Descending_Order_By_Num() {
    if (studentCount == 0) {
        printf("没有学生记录可以排序。\n");
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(students[j].num, students[j + 1].num) < 0) {
                STU temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("按学号降序排序完成。\n");
}

void sort_Score_In_Ascending_Order_By_Num() {
    if (studentCount == 0) {
        printf("没有学生记录可以排序。\n");
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < studentCount; j++) {
            if (strcmp(students[j].num, students[minIndex].num) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            STU temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
    printf("按照学号升序排序完成。\n");
}

void write_To_File() {
    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        printf("无法打开文件 student.dat\n");
        return;
    }

    fwrite(&studentCount, sizeof(int), 1, fp);

    for (int i = 0; i < studentCount; i++) {
        fwrite(&students[i], sizeof(STU), 1, fp);
    }

    fclose(fp);
    printf("学生信息已成功保存到 student.dat 文件中。\n");
}

void read_From_A_File() {
    printf("想要读取全部学生的数据请按1。\n");
    printf("想要根据学号和姓名读取单个学生的数据请按2。\n");
    int ll;
    scanf("%d", &ll);
    while (1) {
        switch (ll) {
            case 1:
                read_All_From_File();
                break;
            case 2:
                read_One_From_File();
                break;
            default:printf("请输入1或2\n");
        }
        break;
    }
}

void read_All_From_File() {
    FILE *fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("无法打开文件 student.dat\n");
        return;
    }

    int count;
    fread(&count, sizeof(int), 1, fp);


    for (int i = 0; i < count; i++) {
        fread(&students[i], sizeof(STU), 1, fp);
    }

    fclose(fp);
    studentCount = count;

    printf("从文件 student.dat 中读取了 %d 条学生信息。\n", count);
}

void read_One_From_File(){
    FILE *fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("无法打开文件 student.dat\n");
        return;
    }

    int count;
    fread(&count, sizeof(int), 1, fp);

    char searchNumName[15];
    int found = 0;

    printf("请输入要查找的学生学号或姓名: ");
    scanf("%s", searchNumName);

    for (int i = 0; i < count; i++) {
        fread(&students[i], sizeof(STU), 1, fp);
        if (strcmp(students[i].num, searchNumName) == 0 || strcmp(students[i].name, searchNumName) == 0) {
            found = 1;
            printf("找到了匹配的学生信息:\n");
            printf("学号: %s\n", students[i].num);
            printf("姓名: %s\n", students[i].name);
            printf("专业: %s\n", students[i].major);
            printf("班级: %d\n", students[i].classNo);
            for (int j = 0; j < M; j++) {
                printf("第%d门课程成绩: %d\n", j + 1, students[i].score[j]);
            }
            break;
        }
    }

    if (!found) {
        printf("未找到学号或姓名为 %s 的学生信息。\n", searchNumName);
    }

    fclose(fp);
}

void Insert(){
     if (studentCount == 0) {
        printf("没有学生记录可以排序。\n");
        return;
    }

    for(int i = 0;i < studentCount;i++){
        for(int j = i-1;j >= 0 &&j < i; j--){
            if (CalculateTotalScore(&students[j]) < CalculateTotalScore(&students[i])){
                STU temp = students[j];
                students[j] = students[i];
                students[i] = temp;
            }
        }
    }

    printf("学生记录已按总分降序排序。\n");
}