/*
 * This file is part of the Serial Flash Universal Driver Library.
 *
 * Copyright (c) 2016-2018, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: It is an head file for this library. You can see all of the functions which can be called by user.
 * Created on: 2016-04-23
 */

#ifndef _SFUD_H_
#define _SFUD_H_
#include <sfud/inc/sfud_def.h>

#ifdef __cplusplus
extern "C" {
#endif

sfud_err sfud_init(void);

sfud_err sfud_device_init(sfud_flash *flash);

sfud_flash *sfud_get_device(size_t index);

size_t sfud_get_device_num(void);

const sfud_flash *sfud_get_device_table(void);

#ifdef SFUD_USING_QSPI

sfud_err sfud_qspi_fast_read_enable(sfud_flash *flash, uint8_t data_line_width);
#endif /* SFUD_USING_QSPI */

sfud_err sfud_read(const sfud_flash *flash, uint32_t addr, size_t size, uint8_t *data);

sfud_err sfud_erase(const sfud_flash *flash, uint32_t addr, size_t size);

sfud_err sfud_write(const sfud_flash *flash, uint32_t addr, size_t size, const uint8_t *data);

sfud_err sfud_erase_write(const sfud_flash *flash, uint32_t addr, size_t size, const uint8_t *data);

sfud_err sfud_chip_erase(const sfud_flash *flash);

sfud_err sfud_read_status(const sfud_flash *flash, uint8_t *status);

sfud_err sfud_write_status(const sfud_flash *flash, bool is_volatile, uint8_t status);

#ifdef __cplusplus
}
#endif

#endif /* _SFUD_H_ */
