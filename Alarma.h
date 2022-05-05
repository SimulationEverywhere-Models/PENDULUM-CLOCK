/*******************************************************************
*
*  DESCRIPTION: Alarma
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#ifndef ALARMA_H
#define ALARMA_H

#include "atomic.h"

class Alarma : public Atomic
{
public:
	Alarma( const string &name = "Alarma" );
	~Alarma();

	virtual string className() const { return "Alarma"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &m_inHour, &m_inMin, &m_inAlarmHour, &m_inAlarmaMin, &m_inActivate, &m_inDeactivate;
	const Port &m_outSound, &m_outAlarnOn, &m_outAlarmOff;
	typedef enum { ACTIVE, INACTIVE } eStates;
	eStates m_state;
	bool m_bOutputState;
	int m_hour, m_min, m_alarmHour, m_alarmMin;
};

#endif   //ALARMA_H

