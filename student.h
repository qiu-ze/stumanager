//
// Created by armstrong on 24-7-2.
//

#ifndef STUDENT_H
#define STUDENT_H

#define M 3
#define N 10
struct Student {
    char num[15];
    char name[15];
    char major[10];
    int classNo;
    int score[M];
};
typedef struct Student STU;

#endif //STUDENT_H
