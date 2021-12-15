/*
 * @Author: Joao Agricio 
 * @Date: 2021-11-24 17:00:11 
 * @Last Modified by: Joao Agicio
 * @Last Modified time: 2021-11-25 10:47:48
 */

#include <stdint.h>

#define RANGE1_TRANSFORMATION_FACTOR        1       // in tmA/mA
#define RANGE1_INV_TRANSFORMATION_FACTOR    1       // in mA/tmA
#define RANGE1_WIDTH_mA     200                     // in mA
#define RANGE1_WIDTH_tmA    200                     // in tmA

#define RANGE2_TRANSFORMATION_FACTOR        0.5     // in tmA/mA
#define RANGE2_INV_TRANSFORMATION_FACTOR    2       // in mA/tmA
#define RANGE2_WIDTH_mA     800                     // in mA
#define RANGE2_WIDTH_tmA    400                     // in tmA

#define RANGE3_TRANSFORMATION_FACTOR        0.1     // in tmA/mA
#define RANGE3_INV_TRANSFORMATION_FACTOR    10      // in mA/tmA
#define RANGE3_WIDTH_mA     4000                    // in mA
#define RANGE3_WIDTH_tmA    400                     // in mA

#define END_OF_SCALE_mA     5000                    // mA
#define END_OF_SCALE_tmA    1000                    // tmA


/*
    Name: CSTransform  | CS meaning Current Sendable (Sendable current value)
    
    Summary: Function used to accommodate measured current precision to transmission

    INPUT: current value in mili ampers (mA)
    OUTPUT: current value in transformed mili ampers (tmA)
*/
uint16_t CSTransform(uint16_t current);         

/*
    Name: InverseCSTransform  | CS meaning Current Sendable (Sendable current value)
    
    Summary: Function used to transform back a sendable current value tmA in a current value
    in mA

    INPUT: current value in transformed mili ampers (tmA)
    OUTPUT: current value in mili ampers (mA)
*/
uint16_t InverseCSTransform(uint16_t current);  
