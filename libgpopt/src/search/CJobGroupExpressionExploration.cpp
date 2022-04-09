//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 EMC Corp.
//
//	@filename:
//		CJobGroupExpressionExploration.cpp
//
//	@doc:
//		Implementation of group expression exploration job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupExpressionExploration.h"

#include "gpopt/engine/CEngine.h"
#include "gpopt/operators/CLogical.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupExploration.h"
#include "gpopt/search/CJobTransformation.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"
#include "gpopt/xforms/CXformFactory.h"


using namespace gpopt;

// State transition diagram for group expression exploration job state machine;
//
// +-----------------------+   eevExploringChildren
// |    estInitialized:    | -----------------------+
// | EevtExploreChildren() |                        |
// |                       | <----------------------+
// +-----------------------+
//   |
//   | eevChildrenExplored
//   v
// +-----------------------+   eevExploringSelf
// | estChildrenExplored:  | -----------------------+
// |   EevtExploreSelf()   |                        |
// |                       | <----------------------+
// +-----------------------+
//   |
//   | eevSelfExplored
//   v
// +-----------------------+
// |   estSelfExplored:    |
// |    EevtFinalize()     |
// +-----------------------+
//   |
//   | eevFinalized
//   v
// +-----------------------+
// |     estCompleted      |
// +-----------------------+
//
const CJobGroupExpressionExploration::EEvent
	rgeev[CJobGroupExpressionExploration::estSentinel]
		 [CJobGroupExpressionExploration::estSentinel] = {{}};

#ifdef GPOS_DEBUG

// names for states
const WCHAR rgwszStates[CJobGroupExpressionExploration::estSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("initialized"),
						   GPOS_WSZ_LIT("children explored"),
						   GPOS_WSZ_LIT("self explored"),
						   GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR rgwszEvents[CJobGroupExpressionExploration::eevSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("exploring children groups"),
						   GPOS_WSZ_LIT("explored children groups"),
						   GPOS_WSZ_LIT("applying exploration xforms"),
						   GPOS_WSZ_LIT("applied exploration xforms"),
						   GPOS_WSZ_LIT("finalized")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::CJobGroupExpressionExploration
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupExpressionExploration::CJobGroupExpressionExploration()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::~CJobGroupExpressionExploration
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupExpressionExploration::~CJobGroupExpressionExploration()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionExploration::Init(CGroupExpression *pgexpr)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::ScheduleApplicableTransformations
//
//	@doc:
//		Schedule transformation jobs for all applicable xforms
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionExploration::ScheduleApplicableTransformations(
	CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::ScheduleChildGroupsJobs
//
//	@doc:
//		Schedule exploration jobs for all child groups
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionExploration::ScheduleChildGroupsJobs(CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::EevtExploreChildren
//
//	@doc:
//		Explore child groups
//
//---------------------------------------------------------------------------
CJobGroupExpressionExploration::EEvent
CJobGroupExpressionExploration::EevtExploreChildren(CSchedulerContext *psc,
													CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::EevtExploreSelf
//
//	@doc:
//		Explore group expression
//
//---------------------------------------------------------------------------
CJobGroupExpressionExploration::EEvent
CJobGroupExpressionExploration::EevtExploreSelf(CSchedulerContext *psc,
												CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::EevtFinalize
//
//	@doc:
//		Finalize exploration
//
//---------------------------------------------------------------------------
CJobGroupExpressionExploration::EEvent
CJobGroupExpressionExploration::EevtFinalize(CSchedulerContext *,  //psc
											 CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExpressionExploration::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::ScheduleJob
//
//	@doc:
//		Schedule a new group expression exploration job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionExploration::ScheduleJob(CSchedulerContext *psc,
											CGroupExpression *pgexpr,
											CJob *pjParent)
{
}

#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionExploration::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupExpressionExploration::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
