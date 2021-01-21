#ifndef __HEADER_H__
#define __HEADER_H__

// 다른 헤더파일 include
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>

// 상수 및 매크로 정의부
#define FALSE 0
#define TRUE 1

#define AMPERSAND 0
#define EOL 1
#define ARG 2

// 사용자 정의 type정의부
typedef struct
{

}

// 전역 변수 선언
char input[SIZE];
char tokens[SIZE];
char *ptr;
char *tok;

// 함수 선언부
int parse(void);
int get_token(char **arg);
void change_directory(char **arg, int index);
bool is_pipe(char **arg, int size);
bool is_redirection(char **arg, int size);
bool command_line(void);

#endif