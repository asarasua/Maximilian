//
//  maxiFreeverb.cpp
//  maximEffects
//
//  Created by Álvaro Sarasúa Berodia on 11/8/16.
//
//

#include "maxiFreeverb.h"

maxiAllpass::maxiAllpass()
{
    bufidx = 0;
}

void maxiAllpass::setbuffer(float *buf, int size)
{
    buffer = buf;
    bufsize = size;
}

void maxiAllpass::mute()
{
    for (int i=0; i<bufsize; i++)
        buffer[i]=0;
}

void maxiAllpass::setfeedback(float val)
{
    feedback = val;
}

float maxiAllpass::getfeedback()
{
    return feedback;
}

maxiComb::maxiComb()
{
    filterstore = 0;
    bufidx = 0;
}

void maxiComb::setbuffer(float *buf, int size)
{
    buffer = buf;
    bufsize = size;
}

void maxiComb::mute()
{
    for (int i=0; i<bufsize; i++)
        buffer[i]=0;
}

void maxiComb::setdamp(float val)
{
    damp1 = val;
    damp2 = 1-val;
}

float maxiComb::getdamp()
{
    return damp1;
}

void maxiComb::setfeedback(float val)
{
    feedback = val;
}

float maxiComb::getfeedback()
{
    return feedback;
}

