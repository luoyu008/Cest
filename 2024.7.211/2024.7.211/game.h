#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

void game();
void Initqipan(char qipan[ROW][COL], int row, int col);
void Displayqipan(char qipan[ROW][COL], int row, int col);
void Player(char qipan[ROW][COL], int row, int col);
void Computer(char qipan[ROW][COL], int row, int col);
char Judge(char qipan[ROW][COL], int row, int col);
int Full(char qipan[ROW][COL], int row, int col);
void menu();
