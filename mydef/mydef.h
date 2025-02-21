/*
	mydef.h

	general definition for my own C programs

					05/09/86	Masami Noro
                                        20240913 rev.   Masami Noro
                                        20241204 rev.   Masami Noro   */

#ifndef MYDEF_H
#define MYDEF_H

#define coerce(XTYPE, OBJECT) (XTYPE) OBJECT

#define NULL_POINTER_ACCESS -77
#define TABLE_OVERFLOW -78
static const int null_Pointer_Access = -77;

typedef enum {NO, YES} boolean;
typedef enum {FAIL,  SUCCESS} result;
typedef enum {FALSE, TRUE} bool;

typedef char *string;

#ifndef NULL
#define NULL 0
static const int null = 0;
#endif

#ifndef NULLS
#define NULLS coerce(string, 0)
static const string err_String = (string) -1;
static const string null_String = (string) 0;
#endif

#ifndef NULLV
#define NULLV coerce(void *, 0)
static const void *null_Value = NULLV;
#endif

#ifndef NULLC
#define NULLC coerce(char, 0)
static const char null_Char = NULLC;
#endif

#define	NULLIF coerce(int (*)(), 0)
#define BS coerce(char, 0x08)
static const char back_Space = BS;

#define CR coerce(char, 0x0d)
static const char carriage_Return = CR;

#define LF coerce(char, 0x0a)
static const char line_Feed = LF;

#define NL '\n'
static const char new_Line = NL;

#ifndef BLANK
#define BLANK coerce(char, 0x20)
static const char space = BLANK;
static const char blank = BLANK;
#endif

#define TABC '\011'
static const char tab = TABC;

#define ESC coerce(char, 0x1b)
static const char escaep = ESC;

#define FF  coerce(char, 0x0c)
static const char form_Feed = FF;

#define BLANKS "                                                                                                 "
static const string blank_String = BLANKS;

#include <stdio.h>
#define NULL_FILE (FILE *)0
static const FILE *null_FILE;

#ifdef NT
#define READMODE "rb"
#define WRITEMODE "wb"
#define APPENDMODE "ab"
#else
#define READMODE "r"
#define WRITEMODE "w"
#define APPENDMODE "a"
#endif
static const string read_Mode = READMODE;
static const string write_Mode = WRITEMODE;
static const string append_Mode = APPENDMODE;

#define _DEC 10
#define _HEX 16
#define _BIN 2
#define _OCT 8
static const int _Dec = _DEC;
static const int _Hex = _HEX;
static const int _Bin = _BIN;
static const int _Oct = _OCT;

#ifndef ERROR
#define ERROR -1
static const int error = ERROR;
#endif

#define NONERROR 0
static const int non_Error = ERROR;

#define STRFMT "%s\n"


#ifndef OFF
typedef int flag;

#define OFF	0
#define ON	1
#endif

typedef void *any_type;

#endif
