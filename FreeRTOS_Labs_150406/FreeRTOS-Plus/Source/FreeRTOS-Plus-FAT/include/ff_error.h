/*
 * FreeRTOS+FAT Labs Build 150406 (C) 2015 Real Time Engineers ltd.
 * Authors include James Walmsley, Hein Tibosch and Richard Barry
 *
 *******************************************************************************
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 ***                                                                         ***
 ***                                                                         ***
 ***   FREERTOS+FAT IS STILL IN THE LAB:                                     ***
 ***                                                                         ***
 ***   This product is functional and is already being used in commercial    ***
 ***   products.  Be aware however that we are still refining its design,    ***
 ***   the source code does not yet fully conform to the strict coding and   ***
 ***   style standards mandated by Real Time Engineers ltd., and the         ***
 ***   documentation and testing is not necessarily complete.                ***
 ***                                                                         ***
 ***   PLEASE REPORT EXPERIENCES USING THE SUPPORT RESOURCES FOUND ON THE    ***
 ***   URL: http://www.FreeRTOS.org/contact  Active early adopters may, at   ***
 ***   the sole discretion of Real Time Engineers Ltd., be offered versions  ***
 ***   under a license other than that described below.                      ***
 ***                                                                         ***
 ***                                                                         ***
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 *******************************************************************************
 *
 * - Open source licensing -
 * While FreeRTOS+FAT is in the lab it is provided only under version two of the
 * GNU General Public License (GPL) (which is different to the standard FreeRTOS
 * license).  FreeRTOS+FAT is free to download, use and distribute under the
 * terms of that license provided the copyright notice and this text are not
 * altered or removed from the source files.  The GPL V2 text is available on
 * the gnu.org web site, and on the following
 * URL: http://www.FreeRTOS.org/gpl-2.0.txt.  Active early adopters may, and
 * solely at the discretion of Real Time Engineers Ltd., be offered versions
 * under a license other then the GPL.
 *
 * FreeRTOS+FAT is distributed in the hope that it will be useful.  You cannot
 * use FreeRTOS+FAT unless you agree that you use the software 'as is'.
 * FreeRTOS+FAT is provided WITHOUT ANY WARRANTY; without even the implied
 * warranties of NON-INFRINGEMENT, MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. Real Time Engineers Ltd. disclaims all conditions and terms, be they
 * implied, expressed, or statutory.
 *
 * 1 tab == 4 spaces!
 *
 * http://www.FreeRTOS.org
 * http://www.FreeRTOS.org/plus
 * http://www.FreeRTOS.org/labs
 *
 */

#ifndef _FF_ERROR_H_
#define _FF_ERROR_H_

/**
 *	@file		ff_error.h
 *	@ingroup	ERROR
 **/

/**
 * Error codes are 32-bit numbers, and consist of three items:
 *    1Bit     7Bits      8Bits           16Bits
 *     .     ........   ........    ........  ........
 * [ErrFlag][ModuleID][FunctionID][--   ERROR CODE   --]
 *
 * Error Codes should always have the ErrFlag set, this is the reason why all module
 * codes include it.
 *
 * When returning an error simply return the defined Error Code, OR'd with the function
 * name (capitalised) in which the error has occurred.
 *
 * When receiving an Error code from another layer, do not modify the code, as this will
 * prevent the error code from containing the origin of the error, simply pass it to the
 * next layer.
 *
 * Some API's have been defined to provide, useful and meaningful Error messages to the
 * the 'userspace' application layer.
 *
 **/

#define FF_MODULE_SHIFT				24
#define FF_FUNCTION_SHIFT			16

#define FF_GETERROR( x )			( ( ( unsigned ) x ) & 0xFFFF )
#define FF_GETMODULE( x )			( ( ( ( unsigned ) x ) >> FF_MODULE_SHIFT ) & 0x7F )
#define FF_GETFUNCTION( x )			( ( ( ( unsigned ) x ) >> FF_FUNCTION_SHIFT ) & 0xFF )
#define FF_GETMOD_FUNC( x )			( ( ( ( unsigned ) x ) >> FF_FUNCTION_SHIFT ) & 0xFFFF )
#define FF_ERRFLAG					0x80000000
#define FF_isERR( x )				( ( ( x ) & FF_ERRFLAG ) != 0 )

/*----- FreeRTOS+FAT Module Identifiers */
#define FF_MODULE_IOMAN				( (  1		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_DIR				( (  2		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_FILE				( (  3		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_FAT				( (  4		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_CRC				( (  5		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_FORMAT			( (  6		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_MEMORY			( (  7		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_STRING			( (  8		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_LOCKING			( (  9		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_TIME				( ( 10		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_DRIVER			( ( 11		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )
#define FF_MODULE_STDIO				( ( 12		<< FF_MODULE_SHIFT ) | FF_ERRFLAG )

/*----- FreeRTOS+FAT Function Identifiers (In Modular Order) */
/*----- FF_IOManager_t - The FreeRTOS+FAT I/O Manager. */
#define FF_CREATEIOMAN				( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_DESTROYIOMAN				( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_REGISTERBLKDEVICE		( ( 3		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_UNREGISTERBLKDEVICE		( ( 4		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_MOUNTPARTITION			( ( 5		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_UNMOUNTPARTITION			( ( 6		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_FLUSHCACHE				( ( 7		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_GETPARTITIONBLOCKSIZE	( ( 8		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_BLOCKREAD				( ( 9		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_BLOCKWRITE				( ( 10		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_DETERMINEFATTYPE			( ( 11		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_GETEFIPARTITIONENTRY		( ( 12		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_USERDRIVER				( ( 13		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_DECREASEFREECLUSTERS		( ( 14		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_INCREASEFREECLUSTERS		( ( 15		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_PARTITIONSEARCH			( ( 16		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )
#define FF_PARSEEXTENDED			( ( 17		<< FF_FUNCTION_SHIFT ) | FF_MODULE_IOMAN )


/*----- FreeRTOS+FAT Return codes for user Rd/Wr routines */
#define FF_ERR_DRIVER_BUSY			( FF_ERR_IOMAN_DRIVER_BUSY 		  | FF_USERDRIVER | FF_MODULE_DRIVER )
#define FF_ERR_DRIVER_FATAL_ERROR 	( FF_ERR_IOMAN_DRIVER_FATAL_ERROR  | FF_USERDRIVER | FF_MODULE_DRIVER )

/*----- FF_DIR - The FreeRTOS+FAT directory handling routines. */
#define FF_FETCHENTRYWITHCONTEXT 	( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_PUSHENTRYWITHCONTEXT		( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_GETENTRY					( ( 3		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_FINDFIRST				( ( 4		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_FINDNEXT					( ( 5		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_REWINDFIND				( ( 6		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_FINDFREEDIRENT			( ( 7		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_PUTENTRY					( ( 8		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_CREATESHORTNAME			( ( 9 		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_CREATELFNS				( ( 10 		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_EXTENDDIRECTORY			( ( 11 		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_MKDIR					( ( 12		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_TRAVERSE					( ( 13		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )
#define FF_FINDDIR					( ( 14		<< FF_FUNCTION_SHIFT ) | FF_MODULE_DIR )

/*----- FF_FILE - The FreeRTOS+FAT file handling routines. */
#define FF_GETMODEBITS				( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_OPEN						( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_ISDIREMPTY				( ( 3		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_RMDIR					( ( 4		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_RMFILE					( ( 5		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_MOVE						( ( 6		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_ISEOF					( ( 7		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_GETSEQUENTIALCLUSTERS 	( ( 8		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_READCLUSTERS				( ( 9		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_EXTENDFILE				( ( 10		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_WRITECLUSTERS			( ( 11		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_READ						( ( 12		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_GETC						( ( 13		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_GETLINE					( ( 14		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_TELL						( ( 15		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_WRITE					( ( 16		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_PUTC						( ( 17		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_SEEK						( ( 18		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_INVALIDATE				( ( 19		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_CHECKVALID				( ( 20		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_CLOSE					( ( 21		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_SETTIME					( ( 22		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_BYTESLEFT				( ( 23		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_SETFILETIME				( ( 24		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_INITBUF					( ( 25		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )
#define FF_SETEOF					( ( 26		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FILE )

/*----- FF_FAT - The FreeRTOS+FAT FAT handling routines. */
#define FF_GETFATENTRY				( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FAT )
#define FF_CLEARCLUSTER				( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FAT )
#define FF_PUTFATENTRY				( ( 3		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FAT )
#define FF_FINDFREECLUSTER			( ( 4		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FAT )
#define FF_COUNTFREECLUSTERS		( ( 5		<< FF_FUNCTION_SHIFT ) | FF_MODULE_FAT )

/*----- FF_FORMAT - The FreeRTOS+FAT format routine */
#define FF_FORMATPARTITION			( ( 1			<< FF_FUNCTION_SHIFT ) | FF_MODULE_FORMAT )

/*----- FF_UNICODE - The FreeRTOS+FAT unicode routines. */
#define FF_UTF8CTOUTF16C			( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STRING )
#define FF_UTF16CTOUTF8C			( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STRING )
#define FF_UTF32CTOUTF16C			( ( 3		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STRING )
#define FF_UTF16CTOUTF32C			( ( 4		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STRING )


/*----- FF_STDIO - The stdio-interface to FreeRTOS+FAT. */
#define FF_CHMOD					( ( 1		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STDIO )
#define FF_STAT_FUNC				( ( 2		<< FF_FUNCTION_SHIFT ) | FF_MODULE_STDIO )

/*	FreeRTOS+FAT defines different Error-Code spaces for each module. This ensures
	that all error codes remain unique, and their meaning can be quickly identified.
*/
/* Global Error Codes */
#define FF_ERR_NONE							 0	/* No Error */
/*#define FF_ERR_GENERIC					 1*/ /* BAD NEVER USE THIS! -- Therefore commented out. */
#define FF_ERR_NULL_POINTER					 2	/* Parameter was NULL. */
#define FF_ERR_NOT_ENOUGH_MEMORY			 3	/* malloc() failed! - Could not allocate handle memory. */
#define FF_ERR_DEVICE_DRIVER_FAILED			 4	/* The Block Device driver reported a FATAL error, cannot continue. */

/* User return codes for Rd/Wr functions: */
#define FF_ERR_IOMAN_DRIVER_BUSY			 9
#define FF_ERR_IOMAN_DRIVER_FATAL_ERROR		10

/* IOMAN Error Codes */
#define	FF_ERR_IOMAN_BAD_BLKSIZE			11	/* The provided blocksize was not a multiple of 512. */
#define FF_ERR_IOMAN_BAD_MEMSIZE			12	/* The memory size was not a multiple of the blocksize. */
#define FF_ERR_IOMAN_DEV_ALREADY_REGD		13	/* Device was already registered. Use FF_UnRegister() to re-use this IOMAN with another device. */
#define FF_ERR_IOMAN_NO_MOUNTABLE_PARTITION	14	/* A mountable partition could not be found on the device. */
#define FF_ERR_IOMAN_INVALID_FORMAT			15	
#define FF_ERR_IOMAN_INVALID_PARTITION_NUM	16	/* The partition number provided was out of range. */
#define FF_ERR_IOMAN_NOT_FAT_FORMATTED		17	/* The partition did not look like a FAT partition. */
#define FF_ERR_IOMAN_DEV_INVALID_BLKSIZE	18	/* IOMAN object BlkSize is not compatible with the blocksize of this device driver. */
#define FF_ERR_IOMAN_PARTITION_MOUNTED		19	/* Device is in use by an actively mounted partition. Unmount the partition first. */
#define FF_ERR_IOMAN_ACTIVE_HANDLES			20	/* The partition cannot be unmounted until all active file handles are closed. (There may also be active handles on the cache). */
#define FF_ERR_IOMAN_GPT_HEADER_CORRUPT		21	/* The GPT partition table appears to be corrupt, refusing to mount. */
#define FF_ERR_IOMAN_NOT_ENOUGH_FREE_SPACE	22
#define FF_ERR_IOMAN_OUT_OF_BOUNDS_READ		23
#define FF_ERR_IOMAN_OUT_OF_BOUNDS_WRITE	24

/* File Error Codes                         30 + */
#define FF_ERR_FILE_ALREADY_OPEN			30	/* File is in use. */
#define FF_ERR_FILE_NOT_FOUND				31	/* File was not found. */
#define FF_ERR_FILE_OBJECT_IS_A_DIR			32	/* Tried to FF_Open() a Directory. */
#define FF_ERR_FILE_IS_READ_ONLY			33	/* Tried to FF_Open() a file marked read only. */
#define FF_ERR_FILE_INVALID_PATH			34	/* The path of the file was not found. */
#define FF_ERR_FILE_NOT_OPENED_IN_WRITE_MODE 35
#define FF_ERR_FILE_NOT_OPENED_IN_READ_MODE	36
#define FF_ERR_FILE_EXTEND_FAILED			37	/* Could not extend the file. */
#define FF_ERR_FILE_DESTINATION_EXISTS		38
#define FF_ERR_FILE_SOURCE_NOT_FOUND		39
#define FF_ERR_FILE_DIR_NOT_FOUND			40
#define FF_ERR_FILE_COULD_NOT_CREATE_DIRENT	41
#define FF_ERR_FILE_BAD_HANDLE				42	/* A file handle was invalid */
#define FF_ERR_FILE_MEDIA_REMOVED			43	/* File handle got invalid because media was removed */
#define FF_ERR_FILE_READ_ZERO				44	/* Used internally. */
#define FF_ERR_FILE_SEEK_INVALID_ORIGIN		45	/* Seeking beyond end of file. */
#define FF_ERR_FILE_SEEK_INVALID_POSITION	46	/* Bad value for the 'whence' parameter. */

/* Directory Error Codes                    50 + */
#define FF_ERR_DIR_OBJECT_EXISTS			50	/* A file or folder of the same name already exists in the current directory. */
#define FF_ERR_DIR_DIRECTORY_FULL			51	/* No more items could be added to the directory. */
#define FF_ERR_DIR_END_OF_DIR				52	/*/ */
#define FF_ERR_DIR_NOT_EMPTY				53	/* Cannot delete a directory that contains files or folders. */
#define FF_ERR_DIR_INVALID_PATH				54	/* Could not find the directory specified by the path. */
#define FF_ERR_DIR_INVALID_PARAMETER		55	/* Could not find the directory specified by the path. */
#define FF_ERR_DIR_CANT_EXTEND_ROOT_DIR		56	/* Can't extend the root dir. */
#define FF_ERR_DIR_EXTEND_FAILED			57	/* Not enough space to extend the directory. */
#define FF_ERR_DIR_NAME_TOO_LONG			58	/* Name exceeds the number of allowed characters for a filename. */

/* Fat Error Codes                                                              70 + */
#define FF_ERR_FAT_NO_FREE_CLUSTERS			70	/* No more free space is available on the disk. */

/* UNICODE Error Codes                      100 + */
#define FF_ERR_UNICODE_INVALID_CODE			100	/* An invalid Unicode character was provided! */
#define FF_ERR_UNICODE_DEST_TOO_SMALL		101	/* Not enough space in the UTF-16 buffer to encode the entire sequence as UTF-16. */
#define FF_ERR_UNICODE_INVALID_SEQUENCE		102	/* An invalid UTF-16 sequence was encountered. */
#define FF_ERR_UNICODE_CONVERSION_EXCEEDED	103	/* Filename exceeds MAX long-filename length when converted to UTF-16. */

typedef int32_t FF_Error_t;

#if( ffconfigDEBUG != 0 )
	const char *FF_GetErrMessage( FF_Error_t iErrorCode );
	const char *FF_GetErrModule( FF_Error_t iErrorCode );
	const char *FF_GetErrFunction( FF_Error_t iErrorCode );
	const char *FF_GetErrDescription( FF_Error_t iErrorCode, char *pcBuffer, int iMaxLength );	/* Get the complete description */
#else	/* ffconfigDEBUG */
	#define FF_GetErrMessage( X )				""	/* A special MACRO in case FF_GetErrMessage() isn't gated with ffconfigDEBUG */
	#define FF_GetErrModule( X )				""
	#define FF_GetErrFunction( X )				""
	static portINLINE const char *FF_GetErrDescription( FF_Error_t iErrorCode, char *pcBuffer, int iMaxLength )
	{
		( void ) iErrorCode;
		( void ) iMaxLength;
		strcpy( pcBuffer, "unknown" );
		return pcBuffer;
	}
#endif										/* Function call is safely replaced with a NULL string. */

#endif	/* INCLUDE GUARD END */
