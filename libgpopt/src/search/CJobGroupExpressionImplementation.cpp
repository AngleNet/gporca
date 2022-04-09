//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CJobGroupExpressionImplementation.cpp
//
//	@doc:
//		Implementation of group expression implementation job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupExpressionImplementation.h"

#include "gpopt/engine/CEngine.h"
#include "gpopt/operators/CLogical.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupImplementation.h"
#include "gpopt/search/CJobTransformation.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"
#include "gpopt/xforms/CXformFactory.h"


using namespace gpopt;

// State transition diagram for group expression implementation job state machine;
//
// +-------------------------+   eevImplementingChildren
// |     estInitialized:     | --------------------------+
// | EevtImplementChildren() |                           |
// |                         | <-------------------------+
// +-------------------------+
//   |
//   | eevChildrenImplemented
//   v
// +-------------------------+   eevImplementingSelf
// | estChildrenImplemented: | --------------------------+
// |   EevtImplementSelf()   |                           |
// |                         | <-------------------------+
// +-------------------------+
//   |
//   | eevSelfImplemented
//   v
// +-------------------------+
// |   estSelfImplemented:   |
// |     EevtFinalize()      |
// +-------------------------+
//   |
//   | eevFinalized
//   v
// +-------------------------+
// |      estCompleted       |
// +-------------------------+
//
const CJobGroupExpressionImplementation::EEvent
	rgeev[CJobGroupExpressionImplementation::estSentinel]
		 [CJobGroupExpressionImplementation::estSentinel] = {{}

};

#ifdef GPOS_DEBUG

// names for states
const WCHAR rgwszStates[CJobGroupExpressionImplementation::estSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("initialized"),
						   GPOS_WSZ_LIT("children implemented"),
						   GPOS_WSZ_LIT("self implemented"),
						   GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR rgwszEvents[CJobGroupExpressionImplementation::eevSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("implementing child groups"),
						   GPOS_WSZ_LIT("implemented children groups"),
						   GPOS_WSZ_LIT("applying implementation xforms"),
						   GPOS_WSZ_LIT("applied implementation xforms"),
						   GPOS_WSZ_LIT("finalized")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::CJobGroupExpressionImplementation
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupExpressionImplementation::CJobGroupExpressionImplementation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::~CJobGroupExpressionImplementation
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupExpressionImplementation::~CJobGroupExpressionImplementation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionImplementation::Init(CGroupExpression *pgexpr)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::ScheduleApplicableTransformations
//
//	@doc:
//		Schedule transformation jobs for all applicable xforms
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionImplementation::ScheduleApplicableTransformations(
	CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::ScheduleChildGroupsJobs
//
//	@doc:
//		Schedule implementation jobs for all child groups
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionImplementation::ScheduleChildGroupsJobs(
	CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::EevtImplementChildren
//
//	@doc:
//		Implement child groups
//
//---------------------------------------------------------------------------
CJobGroupExpressionImplementation::EEvent
CJobGroupExpressionImplementation::EevtImplementChildren(CSchedulerContext *psc,
														 CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::EevtImplementSelf
//
//	@doc:
//		Implement group expression
//
//---------------------------------------------------------------------------
CJobGroupExpressionImplementation::EEvent
CJobGroupExpressionImplementation::EevtImplementSelf(CSchedulerContext *psc,
													 CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::EevtFinalize
//
//	@doc:
//		Finalize implementation
//
//---------------------------------------------------------------------------
CJobGroupExpressionImplementation::EEvent
CJobGroupExpressionImplementation::EevtFinalize(CSchedulerContext *,  //psc
												CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExpressionImplementation::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::ScheduleJob
//
//	@doc:
//		Schedule a new group expression implementation job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionImplementation::ScheduleJob(CSchedulerContext *psc,
											   CGroupExpression *pgexpr,
											   CJob *pjParent)
{
}

#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionImplementation::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupExpressionImplementation::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
