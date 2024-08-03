#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define LEISHU 10
#define ROWS ROW+2
#define COLS COL+2
void init(char str[ROWS][COLS],int rows, int cols,char set);
void Display(char str[ROWS][COLS], int rows, int cols);
void Setlei(char str[ROWS][COLS], int rows, int cols);
void play(char str[ROWS][COLS],char str1[ROWS][COLS], int rows, int cols);
int  find(char str[ROWS][COLS], int a, int b);
void DfsMine(char str[ROWS][COLS], char str1[ROWS][COLS], int a, int b);
int juge(char str[ROWS][COLS], char str1[ROWS][COLS], int a, int b);
