/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GNSS_PARSER_H
#define GNSS_PARSER_H

/* Includes ------------------------------------------------------------------*/
#include "NMEA_parser.h"
#include "gnss_geofence.h"
#include "gnss_datalog.h"


/**
 * @brief Enumeration structure that contains the two states of a parsing dispatcher process
 */

typedef enum
{
  GNSS_PARSER_OK = 0,
  GNSS_PARSER_ERROR
} GNSSParser_Status_t;

/**
 * @brief Enumeration structure that contains the NMEA messages types
 */
typedef enum
{
  GPGGA,
  GNS,
  GPGST,
  GPRMC,
  GSA,
  GSV,
  PSTMVER,
  PSTMPASSRTN,
  PSTMAGPSSTATUS,
  PSTMGEOFENCE,
  PSTMODO,
  PSTMDATALOG,
  PSTMSGL,
  PSTMSAVEPAR
} eNMEAMsg;



typedef struct
{

  GPGGA_Info_t gpgga_data; /**< $GPGGA Data holder */
  GNS_Info_t   gns_data;   /**< $--GNS Data holder */
  GPGST_Info_t gpgst_data; /**< $GPGST Data holder */
  GPRMC_Info_t gprmc_data; /**< $GPRMC Data holder */
  GSA_Info_t   gsa_data;   /**< $--GSA Data holder */
  GSV_Info_t   gsv_data;   /**< $--GSV Data holder */

} GNSSParser_Data_t;



/**	
 * @brief  This function initializes the agent handling parsed GNSS data
 * @param  pGNSSParser_Data The agent
 * @retval GNSS_PARSER_OK on success GNSS_PARSER_ERROR otherwise
 */
GNSSParser_Status_t GNSS_PARSER_Init(GNSSParser_Data_t *pGNSSParser_Data);




/**	
 * @brief  This function computes the checksum and checks the sanity of a GNSS sentence
 * @param  pGNSSParser_Data The agent
 * @param  msg The message type that you want to be checked
 * @retval GNSS_PARSER_OK on success GNSS_PARSER_ERROR otherwise
 */
GNSSParser_Status_t GNSS_PARSER_CheckSanity(GNSSParser_Data_t *pGNSSParser_Data, uint8_t msg);





/**	
 * @brief  This function dispatches a GNSS sentence to be parsed
 * @param  pGNSSParser_Data The agent
 * @param  msg The message type that you want to be parsed
 * @retval GNSS_PARSER_OK on success GNSS_PARSER_ERROR otherwise
 */
GNSSParser_Status_t GNSS_PARSER_ParseMsg(GNSSParser_Data_t *pGNSSParser_Data, uint8_t msg);

/**	
 * @brief  This function prints on the screen the corrispondent message
 * @param  pGNSSParser_Data The agent
 * @param  msg The message type that you want to be printed
 * @retval GNSS_PARSER_OK on success GNSS_PARSER_ERROR otherwise
 */
GNSSParser_Status_t GNSS_PARSER_Print(GNSSParser_Data_t *pGNSSParser_Data, uint8_t msg);



#endif /* GNSS_PARSER_H */