/*******************************************************************
*
*  DESCRIPTION: AgujaMin
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#ifndef AGUJAMIN_H
#define AGUJAMIN_H

#include "atomic.h"

class AgujaMin : public Atomic
{
public:
	AgujaMin( const string &name = "AgujaMin" );
	~AgujaMin();

	virtual string className() const { return "AgujaMin"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const int m_maxMins, m_maxTics;
	const Port &m_inInc, &m_inDec, &m_inTic;
	const Port &m_outInc, &m_outDec, &m_outValue ;
	int m_minCounter, m_ticCounter;
	typedef enum { INC, DEC } eOutEvent;
	eOutEvent m_outEvent;
};

#endif   //AGUJAMIN_H

