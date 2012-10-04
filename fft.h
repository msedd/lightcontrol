/*
 * fft.h
 *
 *  Created on: 26.09.2012
 *      Author: mse
 */

#ifndef FFT_H_
#define FFT_H_

 /* fix_fft.c - Fixed-point in-place Fast Fourier Transform  */
 /*
   All data are fixed-point short integers, in which -32768
  to +32768 represent -1.0 to +1.0 respectively. Integer
  arithmetic is used for speed, instead of the more natural
  floating-point.

  Written by:  Tom Roberts  11/8/89
  Made portable:  Malcolm Slaney 12/15/94 malcolm@interval.com
  Enhanced:  Dimitrios P. Bouras  14 Jun 2006 dbouras@ieee.org
  Adapted for Arduino: Anatoly Kuzmenko 6 Feb 2011 k_anatoly@hotmail.com
 */


 //**************************************************************************************************

#include "sinus.h"
#define LOG2_N_WAVE     10      /* log2(N_WAVE) */

 #define FFT_SIZE       64 
 #define log2FFT       6
 #define N             (2 * FFT_SIZE)
 #define log2N         (log2FFT + 1)


 
//**************************************************************************************************
int fix_fft(int fr[], int fi[], int m )
 {
   int mr, nn, i, j, l, k, istep, n, scale, shift;
   int qr, qi, tr, ti, wr, wi;

   n = 1 << m;

   /* max FFT size = N_WAVE */
   if (n > N_WAVE)
     return -1;

   mr = 0;
   nn = n - 1;
   scale = 0;

   /* decimation in time - re-order data */
   for (m=1; m<=nn; ++m) {
     l = n;
     do {
       l >>= 1;
     } 
     while (mr+l > nn);
     mr = (mr & (l-1)) + l;

     if (mr <= m)
       continue;
     tr = fr[m];
     fr[m] = fr[mr];
     fr[mr] = tr;
     ti = fi[m];
     fi[m] = fi[mr];
     fi[mr] = ti;
   }

   l = 1;
   k = LOG2_N_WAVE-1;
   while (l < n) {
     shift = 1;
     istep = l << 1;
     for (m=0; m<l; ++m) {
       j = m << k;
       /* 0 <= j < N_WAVE/2 */
       wr =  pgm_read_word(&Sinewave[j+N_WAVE/4]);
       wi = -pgm_read_word(&Sinewave[j]);

       wr >>= 1;
       wi >>= 1;

       for (i=m; i<n; i+=istep) {
         j = i + l;
         tr = ((long)wr*(long)fr[j] - (long)wi*(long)fi[j])>>15;
         ti = ((long)wr*(long)fi[j] + (long)wi*(long)fr[j])>>15;
         qr = fr[i];
         qi = fi[i];

         qr >>= 1;
         qi >>= 1;

         fr[j] = qr - tr;
         fi[j] = qi - ti;
         fr[i] = qr + tr;
         fi[i] = qi + ti;
       }
     }
     --k;
     l = istep;
   }
   return scale;
 }
//Performing FFT, getting fx[] array, where each element represents
//frequency bin with width 65 Hz.
 int fix_fftr(int f[], int m )
 {
   int Nt = 1<<(m-1),  scale = 0;
   int *fr=f, *fi=&f[Nt];

   scale = fix_fft(fi, fr, m-1 );
   
   return scale;
 }


#endif /* FFT_H_ */
