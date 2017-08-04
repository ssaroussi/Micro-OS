#ifndef INCLUDE_PORT_H
#define INCLUDE_PORT_H

/** outb 
 *  Sends a byte to an IO port
 * 
 *  @param port The IO port
 *  @param data The data to send
 */
void outb(unsigned short port, unsigned char data);

/** inb
 *  Reads a byte from an IO port
 *
 *  @param port The IO port
 *  @return The read byte
 */
unsigned char inb(unsigned short port);


#endif /* INCLUDE_PORT_H */
