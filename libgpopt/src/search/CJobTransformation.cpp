//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CJobTransformation.cpp
//
//	@doc:
//		Implementation of group expression transformation job
//---------------------------------------------------------------------------

#include "gpopt/search/CJobTransformation.h"

#include "gpopt/engine/CEngine.h"
#include "gpopt/operators/CLogical.h"
#include "gpopt/search/CGroup.h"
#include "gpopt/search/CGroupExpression.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CScheduler.h"
#include "gpopt/search/CSchedulerContext.h"


using namespace gpopt;

// State transition diagram for transformation job state machine;
//
// +-----------------+
// | estInitialized: |
// | EevtTransform() |
// +-----------------+
//   |
//   | eevCompleted
//   v
// +-----------------+
// |  estCompleted   |
// +-----------------+
//
const CJobTransformation::EEvent
	rgeev[CJobTransformation::estSentinel][CJobTransformation::estSentinel] = {
		{// estInitialized
		 CJobTransformation::eevSentinel, CJobTransformation::eevCompleted},
		{// estCompleted
		 CJobTransformation::eevSentinel, CJobTransformation::eevSentinel},
};

#ifdef GPOS_DEBUG

// names for states
const WCHAR rgwszStates[CJobTransformation::estSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {GPOS_WSZ_LIT("initialized"),
												  GPOS_WSZ_LIT("completed")};

// names for events
const WCHAR rgwszEvents[CJobTransformation::eevSentinel]
					   [GPOPT_FSM_NAME_LENGTH] = {GPOS_WSZ_LIT("transforming")};

#endif	//GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::CJobTransformation
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CJobTransformation::CJobTransformation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::~CJobTransformation
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CJobTransformation::~CJobTransformation()
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobTransformation::Init(CGroupExpression *pgexpr, CXform *pxform)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::EevtTransform
//
//	@doc:
//		Apply transformation action
//
//---------------------------------------------------------------------------
CJobTransformation::EEvent
CJobTransformation::EevtTransform(CSchedulerContext *psc, CJob *pjOwner)
{
	return eevSentinel;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::FExecute
//
//	@doc:
//		Main job function
//
//---------------------------------------------------------------------------
BOOL
CJobTransformation::FExecute(CSchedulerContext *psc)
{
	return false;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::ScheduleJob
//
//	@doc:
//		Schedule a new transformation job
//
//---------------------------------------------------------------------------
void
CJobTransformation::ScheduleJob(CSchedulerContext *psc,
								CGroupExpression *pgexpr, CXform *pxform,
								CJob *pjParent)
{
}

#ifdef GPOS_DEBUG

//---------------------------------------------------------------------------
//	@function:
//		CJobTransformation::OsPrint
//
//	@doc:
//		Print function
//
//---------------------------------------------------------------------------
IOstream &
CJobTransformation::OsPrint(IOstream &os)
{
	return m_jsm.OsHistory(os);
}

#endif	// GPOS_DEBUG


// EOF
