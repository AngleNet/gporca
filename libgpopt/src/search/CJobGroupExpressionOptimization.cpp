//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CJobGroupExpressionOptimization.cpp
//
//	@doc:
//		Implementation of group expression optimization job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroupExpressionOptimization.h"

#include "gpopt/base/CCostContext.h"
#include "gpopt/base/CDrvdPropCtxtPlan.h"
#include "gpopt/base/CReqdPropPlan.h"
#include "gpopt/engine/CEngine.h"
#include "gpopt/operators/CExpressionHandle.h"
#include "gpopt/operators/CLogical.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupImplementation.h"
#include "gpopt/search/CJobTransformation.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"


using namespace gpopt;

// State transition diagram for group expression optimization job state machine;
//
//                 +------------------------+
//                 |    estInitialized:     |
//  +------------- |    EevtInitialize()    |
//  |              +------------------------+
//  |                |
//  |                | eevOptimizingChildren
//  |                v
//  |              +------------------------+   eevOptimizingChildren
//  |              | estOptimizingChildren: | ------------------------+
//  |              | EevtOptimizeChildren() |                         |
//  +------------- |                        | <-----------------------+
//  |              +------------------------+
//  |                |
//  | eevFinalized   | eevChildrenOptimized
//  |                v
//  |              +------------------------+
//  |              | estChildrenOptimized:  |
//  +------------- |   EevtAddEnforcers()   |
//  |              +------------------------+
//  |                |
//  |                | eevOptimizingSelf
//  |                v
//  |              +------------------------+   eevOptimizingSelf
//  |              |  estEnfdPropsChecked:  | ------------------------+
//  |              |   EevtOptimizeSelf()   |                         |
//  +------------- |                        | <-----------------------+
//  |              +------------------------+
//  |                |
//  |                | eevSelfOptimized
//  |                v
//  |              +------------------------+
//  |              |   estSelfOptimized:    |
//  | eevFinalized |     EevtFinalize()     |
//  |              +------------------------+
//  |                |
//  |                |
//  |                |
//  |                |
//  +----------------+
//                   |
//                   |
//                   | eevFinalized
//                   v
//                 +------------------------+
//                 |      estCompleted      |
//                 +------------------------+
//
const CJobGroupExpressionOptimization::EEvent
	rgeev[CJobGroupExpressionOptimization::estSentinel]
		 [CJobGroupExpressionOptimization::estSentinel] = {{}};

#ifdef GPOS_DEBUG

// names for states
const WCHAR rgwszStates[CJobGroupExpressionOptimization::estSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("initialized"),
						   GPOS_WSZ_LIT("optimizing children"),
						   GPOS_WSZ_LIT("children optimized"),
						   GPOS_WSZ_LIT("enforceable properties checked"),
						   GPOS_WSZ_LIT("self optimized"),
						   GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR rgwszEvents[CJobGroupExpressionOptimization::eevSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {
						   GPOS_WSZ_LIT("optimizing child groups"),
						   GPOS_WSZ_LIT("optimized child groups"),
						   GPOS_WSZ_LIT("checking enforceable properties"),
						   GPOS_WSZ_LIT("computing group expression cost"),
						   GPOS_WSZ_LIT("computed group expression cost"),
						   GPOS_WSZ_LIT("finalized")};

#endif	// GPOS_DEBUG


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::CJobGroupExpressionOptimization
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::CJobGroupExpressionOptimization()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::~CJobGroupExpressionOptimization
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::~CJobGroupExpressionOptimization()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::Init(CGroupExpression *pgexpr,
									  COptimizationContext *poc, ULONG ulOptReq,
									  CReqdPropPlan *prppCTEProducer)
{
}

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::Cleanup
//
//	@doc:
//		Cleanup allocated memory
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::Cleanup()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::InitChildGroupsOptimization
//
//	@doc:
//		Initialization routine for child groups optimization
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::InitChildGroupsOptimization(
	CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::EevtInitialize
//
//	@doc:
//		Initialize internal data structures;
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::EEvent
CJobGroupExpressionOptimization::EevtInitialize(CSchedulerContext *psc,
												CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::DerivePrevChildProps
//
//	@doc:
//		Derive plan properties and stats of the child previous to
//		the one being optimized
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::DerivePrevChildProps(CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::ComputeCurrentChildRequirements
//
//	@doc:
//		Compute required plan properties for current child
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::ComputeCurrentChildRequirements(
	CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::ScheduleChildGroupsJobs
//
//	@doc:
//		Schedule optimization job for the next child group; skip child groups
//		as they do not require optimization
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::ScheduleChildGroupsJobs(CSchedulerContext *psc)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::EevtOptimizeChildren
//
//	@doc:
//		Optimize child groups
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::EEvent
CJobGroupExpressionOptimization::EevtOptimizeChildren(CSchedulerContext *psc,
													  CJob *pjOwner)
{
		return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::EevtAddEnforcers
//
//	@doc:
//		Add required enforcers to owning group
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::EEvent
CJobGroupExpressionOptimization::EevtAddEnforcers(CSchedulerContext *psc,
												  CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::EevtOptimizeSelf
//
//	@doc:
//		Optimize group expression
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::EEvent
CJobGroupExpressionOptimization::EevtOptimizeSelf(CSchedulerContext *psc,
												  CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::EevtFinalize
//
//	@doc:
//		Finalize optimization
//
//---------------------------------------------------------------------------
CJobGroupExpressionOptimization::EEvent
CJobGroupExpressionOptimization::EevtFinalize(CSchedulerContext *,	// psc
											  CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExpressionOptimization::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::ScheduleJob
//
//	@doc:
//		Schedule a new group expression optimization job
//
//---------------------------------------------------------------------------
void
CJobGroupExpressionOptimization::ScheduleJob(CSchedulerContext *psc,
											 CGroupExpression *pgexpr,
											 COptimizationContext *poc,
											 ULONG ulOptReq, CJob *pjParent)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::FScheduleCTEOptimization
//
//	@doc:
//		Schedule a new job for CTE optimization
//
//---------------------------------------------------------------------------
BOOL
CJobGroupExpressionOptimization::FScheduleCTEOptimization(
	CSchedulerContext *psc, CGroupExpression *pgexpr, COptimizationContext *poc,
	ULONG ulOptReq, CJob *pjParent)
{
	return false;
}


#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobGroupExpressionOptimization::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobGroupExpressionOptimization::OsPrint(IOstream &os)
{
	os << "Group expr: ";
	m_pgexpr->OsPrint(os);
	os << std::endl;

	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG

// EOF
