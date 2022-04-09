//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 EMC Corp.
//
//	@filename:
//		CJobGroupExploration.cpp
//
//	@doc:
//		Implementation of group exploration job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupExploration.h"

#include "gpopt/engine/CEngine.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CGroupProxy.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupExpressionExploration.h"
#include "gpopt/search/CJobQueue.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"

using namespace gpopt;

// State transition diagram for group exploration job state machine;
//
// +------------------------+
// |    estInitialized:     |
// | EevtStartExploration() |
// +------------------------+
//   |
//   | eevStartedExploration
//   v
// +------------------------+   eevNewChildren
// | estExploringChildren:  | -----------------+
// | EevtExploreChildren()  |                  |
// |                        | <----------------+
// +------------------------+
//   |
//   | eevExplored
//   v
// +------------------------+
// |      estCompleted      |
// +------------------------+
//
const CJobGroupExploration::EEvent rgeev[CJobGroupExploration::estSentinel]
										[CJobGroupExploration::estSentinel] = {
											{}};

#ifdef GPOS_DEBUG

// names for states
const WCHAR
	rgwszStates[CJobGroupExploration::estSentinel][GPOPT_FSM_NAME_LENGTH] = {
		GPOS_WSZ_LIT("initialized"), GPOS_WSZ_LIT("children explored"),
		GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR
	rgwszEvents[CJobGroupExploration::eevSentinel][GPOPT_FSM_NAME_LENGTH] = {
		GPOS_WSZ_LIT("started exploration"), GPOS_WSZ_LIT("exploring children"),
		GPOS_WSZ_LIT("finalized")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::CJobGroupExploration
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupExploration::CJobGroupExploration()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::~CJobGroupExploration
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupExploration::~CJobGroupExploration()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupExploration::Init(CGroup *pgroup)
{
}



//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::FScheduleGroupExpressions
//
//	@doc:
//		Schedule exploration jobs for all unexplored group expressions;
//		the function returns true if it could schedule any new jobs
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExploration::FScheduleGroupExpressions(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::EevtStartExploration
//
//	@doc:
//		Start group exploration
//
//---------------------------------------------------------------------------
CJobGroupExploration::EEvent
CJobGroupExploration::EevtStartExploration(CSchedulerContext *,	 //psc
										   CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::EevtExploreChildren
//
//	@doc:
//		Explore child group expressions
//
//---------------------------------------------------------------------------
CJobGroupExploration::EEvent
CJobGroupExploration::EevtExploreChildren(CSchedulerContext *psc, CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExploration::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::ScheduleJob
//
//	@doc:
//		Schedule a new group exploration job
//
//---------------------------------------------------------------------------
void
CJobGroupExploration::ScheduleJob(CSchedulerContext *psc, CGroup *pgroup,
								  CJob *pjParent)
{
}

#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExploration::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupExploration::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
