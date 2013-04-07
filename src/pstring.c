/* 
 * 14.01.2011
 * Copyright (C) 2011 Alexander Saprykin <xelfium@gmail.com>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 */

#include <string.h>
#include <ctype.h>

#include "pstring.h"
#include "pmem.h"

P_LIB_API pchar *
p_strdup (const pchar *str)
{
	pchar	*ret;
	psize	len;

	if (str == NULL)
		return NULL;

	len = strlen (str) + 1;
	if ((ret = p_malloc (len)) == NULL)
		return NULL;

	memcpy (ret, str, len);

	return ret;
}

P_LIB_API pchar *
p_strchomp (const pchar *str)
{
	psize		pos_start, pos_end;
	psize		str_len;
	pchar		*ret;
	const pchar	*ptr;

	if (str == NULL)
		return NULL;

	ptr = str;
	pos_start = 0;
	pos_end = strlen (str) - 1;

	while (isspace (* ((const puchar *) ptr++)))
		++pos_start;

	ptr = str + pos_end;

	while (isspace (* ((const puchar *) ptr--)))
		--pos_end;

	if (pos_end <= pos_start)
		return p_strdup ("\0");

	str_len = pos_end - pos_start + 2;

	if ((ret = p_malloc0 (str_len)) == NULL)
		return NULL;

	memcpy (ret, str + pos_start, str_len - 1);
	*(ret + str_len - 1) = '\0';

	return ret;
}