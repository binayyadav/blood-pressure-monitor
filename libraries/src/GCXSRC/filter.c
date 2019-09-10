/******************************************************************************************************
 SOFTWARE COPYRIGHT NOTICE:

 © [2013] Microchip Technology Inc. and its subsidiaries.
 You may use this software and any derivatives exclusively with Microchip products.

 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS,
 COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

 MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS.
******************************************************************************************************/

#include "filter.h"


double convert_range(double value, double in_hi, double in_lo, double out_hi, double out_lo)
{
    double slope = ((out_hi - out_lo)/ (in_hi - in_lo));
    double point = slope * (value - in_lo) + out_lo;
    return point;

}
void filterLowPassInit(filterLowPass *k, double sampleFreq, double cuttoff) {
	int i;
	k->fs = sampleFreq;
	k->fc = cuttoff;



	for ( i = 0; i < 2; i ++ ) {
		k->a[i] = 0.0;
		k->b[i] = 0.0;
		k->x[i] = 0.0;
		k->y[i] = 0.0;
	}

	filterSetCutoff(k,cuttoff);

}
void filterSetSinglePoleX(filterLowPass *k, double x)
{
    k->a[0] = 1 - x;
    k->b[1] = x;
}

double filterGetXDelay(uint32_t d)
{
    return exp((-1)/(double)d);
}

double filterGetFCDelay(double fc)
{
    return exp(-2*3.14159265*fc);
}

double convertHz2Norm(double fs, double f)
{
	double fNyq = fs/2.0;
	double norm = f/fNyq * 0.5;
	return norm;
}
void filterSetDelay(filterLowPass* k, uint32_t d)
{
    double x = filterGetXDelay(d);
    filterSetSinglePoleX(k,x);
}
void filterSetCutoff(filterLowPass* k, double fc)
{
	k->fc = fc;
	double norm = convertHz2Norm(k->fs,fc);
	filterSetSinglePoleX(k,filterGetFCDelay(norm));
}

double filterGetResult(filterLowPass *k)
{
	return k->lastResult;
}
double filterSingle(filterLowPass *k, double x)
{

    k->x[0] = x;
    k->y[0] = k->a[0]*k->x[0] + k->a[1]*k->x[1] + k->b[1]*k->y[1];

    k->lastResult = k->y[1];

    k->y[1] = k->y[0]; 
    k->x[1] = k->x[0]; 
    return k->lastResult;
}

