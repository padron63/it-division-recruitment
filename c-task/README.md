# C Task

This task is a simplified version of a real GPS project addressed last year in our department. The project is based on the use of two electronic boards: an ST board F446RE and a GNSS2A1 core, along with a FreeRTOS operating system, which features two main threads: a Parser that analyzes messages received from the antenna via the NMEA protocol, and a Consumer that processes them.

In the repository, there is an interface file `gnss_parser.h` that provides the necessary functions for message analysis. Ignore the corresponding `.c` file and use these functions in `app_gnss.c`. The behavior of the Parser functions is described in the comments within the `gnss_parser.h` file.

## Implementation Instructions

Implement the necessary instructions in the `app_gnss.c` file to (Insert all the implementation inside the comments denoted as /* USER CODE ... */):

1. Initialize the variable `GNSSParser_Data` in the function `void task(void *args);`
2. Implement `uint32_t getValue(void *args);` to return an 8-bit unsigned integer randomly generated between 0 and the maximum representable by an 8-bit integer (Assume a Big Endian representation and store the 8 bits in the least significant byte).
3. Implement the following action inside the infinite loop: based on the value of `value`, analyze messages of type GPGGA if the third bit equals 1, otherwise analyze GNS messages if the second bit equals 1, and finally GPRMC messages if the last bit equals 1. Specifically, use the function `GNSSParser_Status_t GNSS_PARSER_ParseMsg(GNSSParser_Data_t *pGNSSParser_Data, uint8_t msg)` for analysis, and then print the result with the function `GNSSParser_Status_t GNSS_PARSER_Print(GNSSParser_Data_t *pGNSSParser_Data, uint8_t msg);`.

## Bonus

Implement a circular queue as an First-Class ADT through the files `queue.h` and `queue.c`, and instantiate 3 queues for each message of size 10. In addition to printing, store the data in the corresponding queues. In order to get the size of GPGGA_Info_t, GNS_Info_t and GPRMC_Info_t (they are structs), use the function size(). Assume that you can use the heap, so you can use the malloc, free ecc.






_Note: your code cannot be tested, but it will be subject of discussion at the
interview, if you'll pass the task selection._
