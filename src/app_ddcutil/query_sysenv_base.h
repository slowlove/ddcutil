/* query_sysenv_base.h
 *
 * <copyright>
 * Copyright (C) 2014-2017 Sanford Rockowitz <rockowitz@minsoft.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * </endcopyright>
 */

#ifndef QUERY_SYSENV_BASE_H_
#define QUERY_SYSENV_BASE_H_

#include <stdbool.h>



char ** get_known_video_driver_modules();
char ** get_prefix_matches();
char ** get_other_driver_modules();


void report_file_first_line(char * fn, char * title, int depth);
bool show_one_file(char * dir_name, char * simple_fn, bool verbose, int depth);

// Linked list of driver names
// struct driver_name_node;
struct driver_name_node {
   char * driver_name;
   struct driver_name_node * next;
};



void free_driver_name_list(struct driver_name_node * driver_list);



// Collects information relevant to later tests
typedef struct {
   char * architecture;
   char * distributor_id;
   bool   is_raspbian;
   bool   is_arm;
   Byte_Value_Array i2c_device_numbers;
   struct driver_name_node * driver_list;
} Env_Accumulator;

void free_env_accumulator(Env_Accumulator * accum);

#endif /* QUERY_SYSENV_BASE_H_ */
