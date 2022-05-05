/*******************************************************************
*
*  DESCRIPTION: Pendulo
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#ifndef PENDULO_H
#define PENDULO_H

#include "atomic.h"

class Pendulo : public Atomic
{
public:
	Pendulo( const string &name = "Pendulo" );
	~Pendulo();

	virtual string className() const { return "Pendulo"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &m_inTurnOn, &m_inTurnOff;
	const Port &m_outTic;
	Time m_aSecond;
	typedef enum { OFF, RIGHT, LEFT } eStates;
	eStates m_state;
};

#endif   //PENDULO_H

