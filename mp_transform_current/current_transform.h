/*
 * @Author: Joao Agricio 
 * @Date: 2021-11-24 17:00:11 
 * @Last Modified by: Joao Agicio
 * @Last Modified time: 2021-11-24 17:19:19
 */

#define RANGE1_TRANSFORMATION_FACTOR    1   // in tmA/mA
#define RANGE1_WIDTH_mA    200              // in mA

#define RANGE2_TRANSFORMATION_FACTOR    2   // in tmA/mA
#define RANGE2_MA_WIDTH    800             // in mA

#define RANGE2_TRANSFORMATION_FACTOR    10  // in tmA/mA
#define RANGE3_MA_WIDTH    4000             // in mA
/*
    Function used to accommodate measured current precision to transmission

    INPUT: current value in mili ampers (mA)
    OUTPUT: current value in transformed mili ampers (tmA)
*/
uint16_t agricio_transform(uint16_t current)
{
    if(current >= RANGE1_WIDTH_mA)
    {
        current -= RANGE1_WIDTH_mA;
        if(current >= RANGE2_WIDTH_mA)
        {
            current -= RANGE2_WIDTH_mA;
        }

        return current*RANGE2_TRANSFORMATION_FACTOR;
    }
    return current*RANGE1_TRANSFORMATION_FACTOR;
}   