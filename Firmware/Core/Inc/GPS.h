#ifndef _GPS_H_
#define _GPS_H_

#include <stdint.h>

//##################################################################################################################

typedef struct
{
	uint8_t			UTC_Hour;
	uint8_t			UTC_Min;
	uint8_t			UTC_Sec;
	uint16_t		UTC_MicroSec;
	
	float			Latitude;
	double			LatitudeDecimal;
	char			NS_Indicator;
	float			Longitude;
	double			LongitudeDecimal;
	char			EW_Indicator;
	
	uint8_t			PositionFixIndicator;
	uint8_t			SatellitesUsed;
	float			HDOP;
	float			MSL_Altitude;
	char			MSL_Units;
	float			Geoid_Separation;
	char			Geoid_Units;
	float			Speed_KTS;
	float			Speed_KMH;
	
	uint16_t		AgeofDiffCorr;
	char			DiffRefStationID[4];
	char			CheckSum[2];
	
	float			HHMMSS;
	uint8_t			UTC_Day;
	uint8_t			UTC_Month;
	uint16_t		UTC_Year;
	uint32_t		YYMMDD;


}GPGGA_t;

typedef struct 
{
	uint8_t		rxBuffer[512];
	uint16_t	rxIndex;
	uint8_t		rxTmp;	
	uint32_t	LastTime;	
	
	GPGGA_t		GPGGA;
	
}GPS_t;

extern GPS_t GPS;
//##################################################################################################################
void	GPS_Init(void);
void	GPS_CallBack(void);
void	GPS_Process(void);
//##################################################################################################################

#endif
