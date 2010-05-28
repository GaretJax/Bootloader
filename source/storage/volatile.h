/** 
 * @file storage/volatile.h
 *
 * Interface to read/write operations on a volatile storage devices or
 * interfaces.
 *
 * The prototypes contained in this file can be implemented multiple times to be
 * adapted to different storage devices such as RAMs, Cache chips or Hard Disk
 * Drives (i.e. for development/testing purposes).
 */


#pragma once


/**
 * Reads some data from the volatile storage handler compiled with this
 * function.
 *
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[out] buffer   The pointer to a char buffer where the read data has to
 *                      be written.
 * @param[in]  relADR   The relative address from which to start to read from 
 *                      the storage device.
 * @param[in]  length   The number of bytes to read from the storage device,
 *                      starting at the given address.
 *
 * @return  The number of bytes read, a negative number if an error occurred.
 */
int vstorage_read(char * buffer, const void * relADR, int length);


/**
 * Writes some data to the volatile storage handler compiled with this
 * function.
 *
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[out] buffer   The pointer to a char buffer from where the data to
 *                      write has to be read.
 * @param[in]  relADR   The relative address from which to start to write to 
 *                      the storage device.
 * @param[in]  length   The number of bytes to write to the storage device,
 *                      starting at the given address.
 *
 * @return  The number of bytes written, a negative number if an error occurred.
 */
int vstorage_write(const char * buffer, void * relADR, int length);

