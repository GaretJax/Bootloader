/**
 * @file io/serial.h
 *
 * Interface to a serial interface (wow, an interface of an interface... :-)
 *
 * The prototypes contained in this file can be implemented multiple times to be
 * adapted to different communication interfaces which can simulate a serial
 * port (e.g. a real serial port, a TCP socket, a Unix socket,...).
 */


#pragma once


/**
 * Initializes the serial port using the values contained in the given struct.
 * The type of the struct is not defined to allow each implementation to use
 * a struct containing the values needed to set up its own communication
 * interface.
 *
 * For example, an implementation which connects to a serial port uses a struct
 * which contains values to define the speed, partity and stop bits of the
 * interface, while a testing implementation which simulates a serial port using
 * a TCP socket needs to know the values for the host and port to which
 * establish the connection.
 *
 * @param[in] config_struct  An implementation dependent struct to hold the
 *                           needed configuration settings.
 * @return  0 if the initialization process ended sucessfully, an error code
 *          otherwise.
 */
int serial_init(const void * config_struct);


/**
 * Reads a single char from a serial interface, blocking until some character
 * data is received.
 *
 * @pre   The \c serial_init function was already called and returned
 *        sucessfully.
 * @todo  How can we handle errors of this function? Setting a timeout limit and
 *        a special return code could do the trick.
 *
 * @return  The char read from the communication device.
 */
char serial_readchar();


/**
 * Reads data from the communication device until a newline character is
 * encountered, then saves the data to the buffer and returns the number of
 * bytes read.
 *
 * @pre   The \c serial_init function was already called and returned
 *        sucessfully.
 * @post  The data saved to the buffer does not contain any newline characters
 *        and is \\0 terminated.
 *
 * @todo  Should we set a timeout option? Should we allow to configure the char
 *        sequence to identify a line break (\\n, \\r\\n or \\r)?
 * @todo  Define the possible error numbers and their respective meaning.
 *
 * @param[out] buffer  The pointer to the string buffer to which the read line
 *                     has to be written.
 *
 * @return  The number of characters written to the buffer if the operation
 *          completed successfully, a negative error code otherwise.
 */
int serial_readline(char * buffer);


/**
 * Writes the data contained in the given character buffer to the communication
 * device until the end of the string (\\0).
 *
 * @pre   The \c serial_init function was already called and returned
 *        sucessfully.
 * @pre   The \a buffer string is correctly \\0 terminated.
 *
 * @param[in] buffer  The string to write to the serial interface.
 *
 * @return  The number of characters written if the operation completed
 *          successfully, a negative error code otherwise.
 */
int serial_write(const char * buffer);
