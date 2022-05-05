/*******************************************************************
*
*  DESCRIPTION: ControlEncendido
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#ifndef CONTROLENCENDIDO_H
#define CONTROLENCENDIDO_H

#include "atomic.h"

class ControlEncendido : public Atomic
{
public:
	ControlEncendido( const string &name = "ControlEncendido" );
	~ControlEncendido();

	virtual string className() const { return "ControlEncendido"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &m_inOn, &m_inOff;
	const Port &m_outOn, &m_outOff;
	typedef enum { ON, OFF } eStates;
	eStates m_state;
};

#endif   //CONTROLENCENDIDO_H
