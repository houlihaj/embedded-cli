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
 * File        cli_fns.h
 * Created by  John Houlihan
 * Version     1.0
 *
 */

/*! @file cli_fns.h
 * @brief Command-line interface API definitions.
 */

/*!
 * @defgroup CLI API
 */
#ifndef _CLI_FNS_H_
#define _CLI_FNS_H_

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "cli_defs.h"

uint8_t cli_set_cmd_members(cli_t* cli);

static cli_status_t help_func(cli_t* cli, int argc, char** argv);
static cli_status_t blink_func(cli_t* cli, int argc, char** argv);

#ifdef __cplusplus
}
#endif  /* End of CPP guard */
#endif  /* _CLI_FNS_H_ */
/** @}*/
