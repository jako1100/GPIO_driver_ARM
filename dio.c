/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../../mcal/mcu_hw.h"

/*DONE*/

#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    switch (PortId)
    {
    case Dio_Port_A :
        if( GET_BIT(PORTA_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
        {
           ret=STD_high;
        }
      else
       {
           ret=STD_low;
       }
    break ;
    case Dio_Port_B :
        if( GET_BIT(PORTB_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
               {
                  ret=STD_high;
               }
             else
              {
                  ret=STD_low;
              }
           break ;
    case Dio_Port_C :
        if( GET_BIT(PORTC_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
               {
                  ret=STD_high;
               }
             else
              {
                  ret=STD_low;
              }
           break ;
    case Dio_Port_D :
        if( GET_BIT(PORTD_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
               {
                  ret=STD_high;
               }
             else
              {
                  ret=STD_low;
              }
              break ;
    case Dio_Port_E :
        if( GET_BIT(PORTE_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
               {
                  ret=STD_high;
               }
             else
              {
                  ret=STD_low;
              }
       break ;
    case Dio_Port_F :
        if( GET_BIT(PORTF_REG.GPIODATA,ChannelPos)== 1U)   // get bit does not use bit band as it 's read and read is one instruction
                     {
                        ret=STD_high;
                     }
                   else
                    {
                        ret=STD_low;
                    }
        break ;
    }

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{

    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    switch (PortId)
       {

       case Dio_Port_A :
           if(Level==STD_high)   SET_BIT(PORTA_REG.GPIODATA,ChannelPos);
           else  CLR_BIT(PORTA_REG.GPIODATA,ChannelPos);
           break ;
       case Dio_Port_B :
           if(Level==STD_high)   SET_BIT(PORTB_REG.GPIODATA,ChannelPos);
            else  CLR_BIT(PORTB_REG.GPIODATA,ChannelPos);
           break ;
       case Dio_Port_C :
           if(Level==STD_high)   SET_BIT(PORTC_REG.GPIODATA,ChannelPos);
           else  CLR_BIT(PORTC_REG.GPIODATA,ChannelPos);
           break ;
       case Dio_Port_D :
           if(Level==STD_high)   SET_BIT(PORTD_REG.GPIODATA,ChannelPos);
           else  CLR_BIT(PORTD_REG.GPIODATA,ChannelPos);
           break ;
       case Dio_Port_E :
                 if(Level==STD_high)   SET_BIT(PORTE_REG.GPIODATA,ChannelPos);
                 else  CLR_BIT(PORTE_REG.GPIODATA,ChannelPos);
                 break ;
       case Dio_Port_F :
                 if(Level==STD_high)   SET_BIT(PORTF_REG.GPIODATA,ChannelPos);
                 else  CLR_BIT(PORTF_REG.GPIODATA,ChannelPos);
                 break ;
       }

   }

    /*DONE: Write the input value in the corresponding ChannelId */

uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    switch(PortId)
    {
    case Dio_Port_A:
        ret=GET_REG(PORTA_REG.GPIODATA,uint8,0);
        break;
    case Dio_Port_B:
        ret=GET_REG(PORTB_REG.GPIODATA,uint8,0);
           break;
    case Dio_Port_C:
        ret=GET_REG(PORTC_REG.GPIODATA,uint8,0);
           break;
    case Dio_Port_D:
        ret=GET_REG(PORTD_REG.GPIODATA,uint8,0);
           break;
    case Dio_Port_E:
        ret=GET_REG(PORTE_REG.GPIODATA,uint8,0);
           break;
    case Dio_Port_F:
        ret=GET_REG(PORTF_REG.GPIODATA,uint8,0);
           break;
    }
        return ret;
}

void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*DONE */
    switch(PortId)
       {
       case Dio_Port_A:
           PORTA_REG.GPIODATA=value;
           break;
       case Dio_Port_B:
           PORTB_REG.GPIODATA=value;
              break;
       case Dio_Port_C:
           PORTC_REG.GPIODATA=value;
              break;
       case Dio_Port_D:
           PORTD_REG.GPIODATA=value;
              break;
       case Dio_Port_E:
           PORTE_REG.GPIODATA=value;
              break;
       case Dio_Port_F:
           PORTF_REG.GPIODATA=value;
              break;
       }


}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* DONE */

      Dio_PortType PortId = ChannelId / 8;
      Dio_ChannelType ChannelPos = ChannelId % 8;
      switch (PortId)
         {

         case Dio_Port_A :
               TOGGLE_BIT(PORTA_REG.GPIODATA,ChannelPos);
             break ;
         case Dio_Port_B :
             TOGGLE_BIT(PORTB_REG.GPIODATA,ChannelPos);
             break ;
         case Dio_Port_C :
             TOGGLE_BIT(PORTC_REG.GPIODATA,ChannelPos);
             break ;
         case Dio_Port_D :
             TOGGLE_BIT(PORTD_REG.GPIODATA,ChannelPos);
             break ;
         case Dio_Port_E :
             TOGGLE_BIT(PORTE_REG.GPIODATA,ChannelPos);
                   break ;
         case Dio_Port_F :
             TOGGLE_BIT(PORTF_REG.GPIODATA,ChannelPos);
                   break ;
         }

}
void Dio_FlipPort(Dio_PortType PortId)
{
    switch(PortId)
          {
          case Dio_Port_A:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTA_REG.GPIODATA,uint8,0));
              break;
          case Dio_Port_B:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTB_REG.GPIODATA,uint8,0));
                 break;
          case Dio_Port_C:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTC_REG.GPIODATA,uint8,0));
                 break;
          case Dio_Port_D:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTD_REG.GPIODATA,uint8,0));
                 break;
          case Dio_Port_E:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTE_REG.GPIODATA,uint8,0));
                 break;
          case Dio_Port_F:
              PORTA_REG.GPIODATA= ~(GET_REG(PORTF_REG.GPIODATA,uint8,0));
                 break;
          }

}



