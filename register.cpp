/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "Pendulo.h"
#include "AgujaMin.h"
#include "AgujaHour.h"
#include "Alarma.h"
#include "ControlEncendido.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Pendulo>() , "Pendulo" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AgujaMin>() , "AgujaMin" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AgujaHour>() , "AgujaHour" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Alarma>() , "Alarma" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ControlEncendido>() , "ControlEncendido" ) ;
}
