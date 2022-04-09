//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 EMC Corp.
//
//	@filename:
//		CJobGroupImplementation.cpp
//
//	@doc:
//		Implementation of group implementation job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupImplementation.h"

#include "gpopt/base/CQueryContext.h"
#include "gpopt/engine/CEngine.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CGroupProxy.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupExploration.h"
#include "gpopt/search/CJobGroupExpressionImplementation.h"
#include "gpopt/search/CJobQueue.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"
#include "naucrates/traceflags/traceflags.h"

using namespace gpopt;


// State transition diagram for group implementation job state machine;
//
// +---------------------------+   eevExploring
// |      estInitialized:      | ------------------+
// | EevtStartImplementation() |                   |
// |                           | <-----------------+
// +---------------------------+
//   |
//   | eevExplored
//   v
// +---------------------------+   eevImplementing
// | estImplementingChildren:  | ------------------+
// |  EevtImplementChildren()  |                   |
// |                           | <-----------------+
// +---------------------------+
//   |
//   | eevImplemented
//   v
// +---------------------------+
// |       estCompleted        |
// +---------------------------+
//
const CJobGroupImplementation::EEvent
	rgeev[CJobGroupImplementation::estSentinel]
		 [CJobGroupImplementation::estSentinel] = {{}

};

#ifdef GPOS_DEBUG

// names for states
const WCHAR
	rgwszStates[CJobGroupImplementation::estSentinel][GPOPT_FSM_NAME_LENGTH] = {
		GPOS_WSZ_LIT("initialized"), GPOS_WSZ_LIT("implementing children"),
		GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR
	rgwszEvents[CJobGroupImplementation::eevSentinel][GPOPT_FSM_NAME_LENGTH] = {
		GPOS_WSZ_LIT("ongoing exploration"), GPOS_WSZ_LIT("done exploration"),
		GPOS_WSZ_LIT("ongoing implementation"), GPOS_WSZ_LIT("finalizing")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::CJobGroupImplementation
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupImplementation::CJobGroupImplementation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::~CJobGroupImplementation
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupImplementation::~CJobGroupImplementation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupImplementation::Init(CGroup *pgroup)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::FScheduleGroupExpressions
//
//	@doc:
//		Schedule implementation jobs for all unimplemented group expressions;
//		the function returns true if it could schedule any new jobs
//
//---------------------------------------------------------------------------
BOOL
CJobGroupImplementation::FScheduleGroupExpressions(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::EevtStartImplementation
//
//	@doc:
//		Start group implementation
//
//---------------------------------------------------------------------------
CJobGroupImplementation::EEvent
CJobGroupImplementation::EevtStartImplementation(CSchedulerContext *psc,
												 CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::EevtImplementChildren
//
//	@doc:
//		Implement child group expressions
//
//---------------------------------------------------------------------------
CJobGroupImplementation::EEvent
CJobGroupImplementation::EevtImplementChildren(CSchedulerContext *psc,
											   CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupImplementation::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::ScheduleJob
//
//	@doc:
//		Schedule a new group implementation job
//
//---------------------------------------------------------------------------
void
CJobGroupImplementation::ScheduleJob(CSchedulerContext *psc, CGroup *pgroup,
									 CJob *pjParent)
{
}


#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupImplementation::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupImplementation::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
