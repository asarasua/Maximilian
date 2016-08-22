//
//  maxiFreeverb.h
//  maximEffects
//
//  Created by Álvaro Sarasúa Berodia on 11/8/16.
//
//

#ifndef maxiFreeverb_h
#define maxiFreeverb_h

#define undenormalise(sample) if(((*(unsigned int*)&sample)&0x7f800000)==0) sample=0.0f

class maxiAllpass
{
public:
    maxiAllpass();
    void	setbuffer(float *buf, int size);
    inline  float	process(float inp);
    void	mute();
    void	setfeedback(float val);
    float	getfeedback();
    // private:
    float	feedback;
    float	*buffer;
    int		bufsize;
    int		bufidx;
};


// Big to inline - but crucial for speed

inline float maxiAllpass::process(float input)
{
    float output;
    float bufout;
    
    bufout = buffer[bufidx];
    undenormalise(bufout);
    
    output = -input + bufout;
    buffer[bufidx] = input + (bufout*feedback);
    
    if(++bufidx>=bufsize) bufidx = 0;
    
    return output;
}

class maxiComb
{
public:
    maxiComb();
    void	setbuffer(float *buf, int size);
    inline  float	process(float inp);
    void	mute();
    void	setdamp(float val);
    float	getdamp();
    void	setfeedback(float val);
    float	getfeedback();
private:
    float	feedback;
    float	filterstore;
    float	damp1;
    float	damp2;
    float	*buffer;
    int		bufsize;
    int		bufidx;
};


// Big to inline - but crucial for speed

inline float maxiComb::process(float input)
{
    float output;
    
    output = buffer[bufidx];
    undenormalise(output);
    
    filterstore = (output*damp2) + (filterstore*damp1);
    undenormalise(filterstore);
    
    buffer[bufidx] = input + (filterstore*feedback);
    
    if(++bufidx>=bufsize) bufidx = 0;
    
    return output;
}

const int	numcombs		= 8;
const int	numallpasses	= 4;
const float	muted			= 0;
const float	fixedgain		= 0.015f;
const float scalewet		= 3;
const float scaledry		= 2;
const float scaledamp		= 0.4f;
const float scaleroom		= 0.28f;
const float offsetroom		= 0.7f;
const float initialroom		= 0.5f;
const float initialdamp		= 0.5f;
const float initialwet		= 1/scalewet;
const float initialdry		= 0;
const float initialwidth	= 1;
const float initialmode		= 0;
const float freezemode		= 0.5f;
const int	stereospread	= 23;

// These values assume 44.1KHz sample rate
// they will probably be OK for 48KHz sample rate
// but would need scaling for 96KHz (or other) sample rates.
// The values were obtained by listening tests.
const int combtuningL1		= 1116;
const int combtuningR1		= 1116+stereospread;
const int combtuningL2		= 1188;
const int combtuningR2		= 1188+stereospread;
const int combtuningL3		= 1277;
const int combtuningR3		= 1277+stereospread;
const int combtuningL4		= 1356;
const int combtuningR4		= 1356+stereospread;
const int combtuningL5		= 1422;
const int combtuningR5		= 1422+stereospread;
const int combtuningL6		= 1491;
const int combtuningR6		= 1491+stereospread;
const int combtuningL7		= 1557;
const int combtuningR7		= 1557+stereospread;
const int combtuningL8		= 1617;
const int combtuningR8		= 1617+stereospread;
const int allpasstuningL1	= 556;
const int allpasstuningR1	= 556+stereospread;
const int allpasstuningL2	= 441;
const int allpasstuningR2	= 441+stereospread;
const int allpasstuningL3	= 341;
const int allpasstuningR3	= 341+stereospread;
const int allpasstuningL4	= 225;
const int allpasstuningR4	= 225+stereospread;

#endif /* maxiFreeverb_h */
