/*
 * MIT License
 *
 * Copyright (c) 2019 Sean Farrelly
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * File        cli.h
 * Created by  Sean Farrelly
 * Version     1.1
 *
 */

#ifndef _CLI_DEFS_H_
#define _CLI_DEFS_H_

#include <stddef.h>

#ifndef MAX_BUF_SIZE
#define MAX_BUF_SIZE 128  /* Maximum size of CLI Rx buffer */
#endif

#ifndef CMD_TERMINATOR
#define CMD_TERMINATOR '\r'  /* Delimiter denoting end of cmd from user */
#endif

typedef struct cmd_s cmd_t;
typedef struct cli_s cli_t;

typedef enum {
    CLI_OK,               /* API execution successful.                */
    CLI_E_NULL_PTR,       /* Null pointer error.                      */
    CLI_E_IO,
    CLI_E_CMD_NOT_FOUND,  /* Command name not found in command table. */
    CLI_E_INVALID_ARGS,   /* Invalid function parameters/arguments.   */
    CLI_E_BUF_FULL,       /* CLI buffer full.                         */
    CLI_IDLE              /* No command to execute at the moment      */
} cli_status_t;

/*!
 * @brief Function type declarations.
 */
typedef cli_status_t (*cmd_func_ptr_t)(cli_t* cli, int argc, char** argv);
typedef void (*println_func_ptr_t)(char* string);

/*!
 * @brief Command structure, consisting of a name and function pointer.
 */
struct cmd_s {
    char* cmd;            /* Command name.                            */
    cmd_func_ptr_t func;  /* Function pointer to associated function. */
};

/*!
 * @brief Command-line interface handle structure.
 */
struct cli_s {
    println_func_ptr_t println;  /* Function pointer to user defined println function.      */
    cmd_t* cmd_tbl;              /* Pointer to series of commands which are to be accepted. */
    size_t cmd_cnt;              /* Number of commands in cmd_tbl.                          */
};

#endif
