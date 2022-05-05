/*******************************************************************
*
*  DESCRIPTION: AgujaHour
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#ifndef AGUJAHOUR_H
#define AGUJAHOUR_H

#include "atomic.h"

class AgujaHour : public Atomic
{
public:
	AgujaHour( const string &name = "AgujaHour" );
	~AgujaHour();

	virtual string className() const { return "AgujaHour"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const int m_maxHours, m_maxMins;
	const Port &m_inInc, &m_inDec;
	const Port &m_outValue;
	int m_minCounter, m_hourCounter;
};

#endif   //AGUJAHOUR_H

