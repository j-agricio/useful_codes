/*
 * @Author: Joao Agricio 
 * @Date: 2021-11-25 09:07:02 
 * @Last Modified by: Joao Agicio
 * @Last Modified time: 2021-11-25 10:49:05
 */
#include "current_transform.h"

// Summary: Function used to accommodate measured current precision to transmission
uint16_t CSTransform(uint16_t current_ma)
{
    uint16_t accumulated = 0;
    
    if(current_ma < RANGE1_WIDTH_mA)
        return current_ma*RANGE1_TRANSFORMATION_FACTOR;

    accumulated += RANGE1_WIDTH_mA * RANGE1_TRANSFORMATION_FACTOR;      // Results in Maximum range 1 value in tmA
    current_ma -= RANGE1_WIDTH_mA;

    if(current_ma < RANGE2_WIDTH_mA)
        return current_ma*RANGE2_TRANSFORMATION_FACTOR + accumulated;

    accumulated += RANGE2_WIDTH_mA * RANGE2_TRANSFORMATION_FACTOR;
    current_ma -= RANGE2_WIDTH_mA;

    if(current_ma < RANGE3_WIDTH_mA)    
        return current_ma*RANGE3_TRANSFORMATION_FACTOR + accumulated;    

    return END_OF_SCALE_tmA;    

}   

// Summary: Function used to transform back a sendable current value tmA in a current value in mA
uint16_t InverseCSTransform(uint16_t current_tma)
{
    uint16_t accumulated = 0;
    
    if(current_tma < RANGE1_WIDTH_tmA)
        return current_tma*RANGE1_INV_TRANSFORMATION_FACTOR;    
    
    accumulated += RANGE1_WIDTH_tmA * RANGE1_INV_TRANSFORMATION_FACTOR;      // Results in Maximum range 1 value in mA
    current_tma -= RANGE1_WIDTH_tmA;

    if(current_tma < RANGE2_WIDTH_tmA)
        return current_tma*RANGE2_INV_TRANSFORMATION_FACTOR + accumulated;

    accumulated += RANGE2_WIDTH_tmA * RANGE2_INV_TRANSFORMATION_FACTOR;
    current_tma -= RANGE2_WIDTH_tmA;

    if(current_tma < RANGE3_WIDTH_mA)
        return current_tma*RANGE3_INV_TRANSFORMATION_FACTOR + accumulated;

    return END_OF_SCALE_mA;    
}  

