//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 EMC Corp.
//
//	@filename:
//		CJobGroupOptimization.cpp
//
//	@doc:
//		Implementation of group optimization job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupOptimization.h"

#include "gpopt/engine/CEngine.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CGroupProxy.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupExpressionOptimization.h"
#include "gpopt/search/CJobGroupImplementation.h"
#include "gpopt/search/CJobQueue.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"
#include "naucrates/traceflags/traceflags.h"

using namespace gpopt;


// State transition diagram for group optimization job state machine:
//
//     eevImplementing   +------------------------------+
//  +------------------ |       estInitialized:        |
//  |                   |   EevtStartOptimization()    |
//  +-----------------> |                              | -+
//                      +------------------------------+  |
//                        |                               |
//                        | eevImplemented                |
//                        v                               |
//                      +------------------------------+  |
//      eevOptimizing   |                              |  |
//  +------------------ |                              |  |
//  |                   |    estOptimizingChildren:    |  |
//  +-----------------> |    EevtOptimizeChildren()    |  |
//                      |                              |  |
//  +-----------------> |                              |  |
//  |                   +------------------------------+  |
//  |                     |                               |
//  | eevOptimizing       | eevOptimizedCurrentLevel      |
//  |                     v                               |
//  |                   +------------------------------+  |
//  |                   | estDampingOptimizationLevel: |  |
//  +------------------ |  EevtCompleteOptimization()  |  |
//                      +------------------------------+  |
//                        |                               |
//                        | eevOptimized                  | eevOptimized
//                        v                               |
//                      +------------------------------+  |
//                      |         estCompleted         | <+
//                      +------------------------------+
//
const CJobGroupOptimization::EEvent rgeev[CJobGroupOptimization::estSentinel]
										 [CJobGroupOptimization::estSentinel] =
											 {{}

};

#ifdef GPOS_DEBUG

// names for states
const WCHAR
	rgwszStates[CJobGroupOptimization::estSentinel][GPOPT_FSM_NAME_LENGTH] = {
		GPOS_WSZ_LIT("initialized"), GPOS_WSZ_LIT("optimizing children"),
		GPOS_WSZ_LIT("damping optimization level"), GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR rgwszEvents[CJobGroupOptimization::eevSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("ongoing implementation"),
						   GPOS_WSZ_LIT("done implementation"),
						   GPOS_WSZ_LIT("ongoing optimization"),
						   GPOS_WSZ_LIT("optimization level complete"),
						   GPOS_WSZ_LIT("finalizing")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::CJobGroupOptimization
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupOptimization::CJobGroupOptimization()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::~CJobGroupOptimization
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupOptimization::~CJobGroupOptimization()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupOptimization::Init(
	CGroup *pgroup,
	CGroupExpression
		*pgexprOrigin,	// group expression that triggered optimization job,
						// NULL if this is the Root group
	COptimizationContext *poc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::FScheduleGroupExpressions
//
//	@doc:
//		Schedule optimization jobs for all unoptimized group expressions with
//		the current optimization priority;
//		the function returns true if it could schedule any new jobs
//
//---------------------------------------------------------------------------
BOOL
CJobGroupOptimization::FScheduleGroupExpressions(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::EevtStartOptimization
//
//	@doc:
//		Start group optimization
//
//---------------------------------------------------------------------------
CJobGroupOptimization::EEvent
CJobGroupOptimization::EevtStartOptimization(CSchedulerContext *psc,
											 CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::EevtOptimizeChildren
//
//	@doc:
//		Optimize child group expressions
//
//---------------------------------------------------------------------------
CJobGroupOptimization::EEvent
CJobGroupOptimization::EevtOptimizeChildren(CSchedulerContext *psc,
											CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::EevtCompleteOptimization
//
//	@doc:
//		Complete optimization action
//
//---------------------------------------------------------------------------
CJobGroupOptimization::EEvent
CJobGroupOptimization::EevtCompleteOptimization(CSchedulerContext *,  // psc
												CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupOptimization::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::ScheduleJob
//
//	@doc:
//		Schedule a new group optimization job
//
//---------------------------------------------------------------------------
void
CJobGroupOptimization::ScheduleJob(CSchedulerContext *psc, CGroup *pgroup,
								   CGroupExpression *pgexprOrigin,
								   COptimizationContext *poc, CJob *pjParent)
{
}

#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupOptimization::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupOptimization::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
