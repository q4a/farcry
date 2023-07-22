/*
 * Copyright (C) 2011 Mathieu Turcotte (mathieuturcotte.ca)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

#ifndef FINDFIRST_H_
#define FINDFIRST_H_

#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>
#include <time.h>
#include "Linux64Specific.h"
#include <vector>
#include <string>

/* http://en.wikipedia.org/wiki/Attrib */
#define _A_NORMAL   0x00    /* Normal file.     */
#define _A_RDONLY   0x01    /* Read only file.  */
#define _A_HIDDEN   0x02    /* Hidden file.     */
#define _A_SYSTEM   0x04    /* System file.     */
#define _A_SUBDIR   0x10    /* Subdirectory.    */
#define _A_ARCH     0x20    /* Archive file.    */

struct _finddata_t {
    unsigned attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    off_t size;
    char name[260];
};

typedef struct __finddata64_t
{
	//!< atributes set by find request
	unsigned    int attrib;			//!< attributes, only directory and readonly flag actually set
	__time64_t	time_create;		//!< creation time, cannot parse under linux, last modification time is used instead (game does nowhere makes decision based on this values)
	__time64_t	time_access;		//!< last access time
	__time64_t	time_write;			//!< last modification time
	__time64_t	size;						//!< file size (for a directory it will be the block size)
	char        name[256];			//!< file/directory name

private:
	int									m_LastIndex;					//!< last index for findnext
	char								m_DirectoryName[260];			//!< directory name, needed when getting file attributes on the fly
	char								m_ToMatch[260];						//!< pattern to match with
	DIR*								m_Dir;									//!< directory handle
	std::vector<std::string>	m_Entries;						//!< all file entries in the current directories
public:

	inline __finddata64_t():
	  attrib(0), time_create(0), time_access(0), time_write(0),
		size(0), m_LastIndex(-1), m_Dir(NULL)
	{
		memset(name, '0', 256);	
	}
	~__finddata64_t();
	
	//!< copies and retrieves the data for an actual match (to not waste any effort retrioeving data for unused files)
	void CopyFoundData(const char * rMatchedFileName);

public:
	//!< global _findfirst64 function using struct above, can't be a member function due to required semantic match
	friend intptr_t _findfirst64(const char *pFileName, __finddata64_t *pFindData);
	//!< global _findnext64 function using struct above, can't be a member function due to required semantic match
	friend int _findnext64(intptr_t last, __finddata64_t *pFindData);
}__finddata64_t;

/*
 * Returns a unique search handle identifying the file or group of
 * files matching the filespec specification, which can be used in
 * a subsequent call to findnext or to findclose. Otherwise, findfirst
 * returns NULL and sets errno to EINVAL if filespec or fileinfo
 * was NULL or if the operating system returned an unexpected error
 * and ENOENT if the file specification could not be matched.
 */
intptr_t _findfirst(const char* filespec, struct _finddata_t* fileinfo);
intptr_t _findfirst64(const char* filespec, struct __finddata64_t* fileinfo);

/*
 * Find the next entry, if any, that matches the filespec argument
 * of a previous call to findfirst, and then alter the fileinfo
 * structure contents accordingly. If successful, returns 0. Otherwise,
 * returns -1 and sets errno to EINVAL if handle or fileinfo was NULL
 * or if the operating system returned an unexpected error and ENOENT
 * if no more matching files could be found.
 */
int _findnext(intptr_t handle, struct _finddata_t* fileinfo);
int _findnext64(intptr_t handle, struct __finddata64_t* fileinfo);

/*
 * Closes the specified search handle and releases associated
 * resources. If successful, findclose returns 0. Otherwise, it
 * returns -1 and sets errno to ENOENT, indicating that no more
 * matching files could be found.
 */
int _findclose(intptr_t handle);

#endif /* FINDFIRST_H_ */
