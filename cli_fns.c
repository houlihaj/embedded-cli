/*
 * MIT License
 *
 * Copyright (c) 2026 John Houlihan
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
 * File        cli_fns.c
 * Created by  John Houlihan
 * Version     1.0
 *
 */

/*! @file cli_fns.c
 * @brief Implementation of command-line interface.
 */
#include <stdlib.h>  /* atoi */
#include <string.h>  /* strcmp */
#include "cli_fns.h"

cmd_t cmd_tbl[] = {
    {.cmd = "help", .func = help_func},
    {.cmd = "blink", .func = blink_func}
};

/**
  * @brief  Summary of the function
  * @note   In-depth description of the function
  *
  * @param  cli  an instance of the cli_t object
  * @retval
  */
uint8_t cli_set_cmd_members(cli_t* cli)
{
    cli->cmd_tbl = cmd_tbl;
    cli->cmd_cnt = sizeof(cmd_tbl) / sizeof(cmd_t);
    return 0;
}

/**
  * @brief  Summary of the function
  * @note   In-depth description of the function
  *
  * @param  cli  an instance of the cli_t object
  * @retval cli_status_t
  */
static cli_status_t help_func(cli_t* cli, int argc, char** argv)
{
    cli->println("HELP function executed\r\n");
    return CLI_OK;
}

/**
  * @brief  Summary of the function
  * @note   In-depth description of the function
  *
  * @param  cli  an instance of the cli_t object
  * @retval cli_status_t
  */
static cli_status_t blink_func(cli_t* cli, int argc, char** argv)
{
    if (argc > 0)
    {
        if (strcmp(argv[1], "-H") == 0 || strcmp(argv[1], "--help") == 0)
        {
            cli->println("BLINK help menu\r\n");
        }
        else
        {
            return CLI_E_INVALID_ARGS;
        }
    }
    else
    {
        cli->println("BLINK function executed\r\n");
    }
    return CLI_OK;
}
