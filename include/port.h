#ifndef INCLUDE_PORT_H
#define INCLUDE_PORT_H

/* outb 
 * Sends a byte to an IO port
 * 
 * @param port The IO port
 * @param data The data to send
 */
void outb(unsigned short port, unsigned char data);

#endif /* INCLUDE_PORT_H */