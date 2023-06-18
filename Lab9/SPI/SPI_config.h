/******************************************************************************/
/* Author   : Ezzat Hegazy						      */
/* Date     : 30 MAY 2023						      */
/* Version  : V02	                                                      */
/******************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


                /* Master or Slave */
#define MASTER_OR_SLAVE           1
/*      SPI_SLAVE  --> 0
        SPI_MASTER --> 1          */


                /* Clock Polarity */
#define     CPOL            0
/*          SPI_IDLE_LOW    0
            SPI_IDLE_HIGH   1       */


                /* Clock Phase */
#define     CPHA            1      
/*          SPI_SAMPLE_FIRST_TRANSITION     0       // Read or Capture on first transition
            SPI_SAMPLE_SECOND_TRANSITION    1*/

#endif