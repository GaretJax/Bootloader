/**
 * @file storage/persistent.h
 *
 * Interface to read/write/erase operations on a persistent storage device.
 *
 * The prototypes contained in this file can be implemented multiple times to be
 * adapted to different storage devices such as Hard Disk Drives, Flash memory
 * devices or RAMs (i.e. for development and testing purposes).
 */


#pragma once


/**
 * Reads some data from the permanent storage handler compiled with this
 * function.
 *
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[out] buffer   The pointer to a char buffer where the read data has to
 *                      be written.
 * @param[in]  block    Block from which to start to read from the storage
 *                      device.
 * @param[in]  length   The number of bytes to read from the storage device,
 *                      starting at the given address.
 *
 * @return  The number of bytes read, a negative number if an error occurred.
 */
int pstorage_read(char * buffer, int block, int length);


/**
 * Writes some data to the permanent storage handler compiled with this
 * function.
 *
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[out] buffer   The pointer to a char buffer from where the data to
 *                      write has to be read.
 * @param[in]  block    Block from which to start to write to the storage
 *                      device.
 * @param[in]  length   The number of bytes to write to the storage device,
 *                      starting at the given address.
 *
 * @return  The number of bytes written, a negative number if an error occurred.
 */
int pstorage_write(const char * buffer, int block, int length);


/**
 * Deletes some data from the permanent storage handler compiled with this
 * function.
 *
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[in]  address  The address from which to start to delete the data from
 *                      the storage device.
 * @param[in]  length   The number of bytes to delete from the storage device,
 *                      starting at the given address.
 *
 * @return  The number of bytes deleted, a negative number if an error occurred.
 */
int pstorage_erase(void * address, int length);

