//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CJobGroup.cpp
//
//	@doc:
//		Implementation of group job superclass
//---------------------------------------------------------------------------

#include "gpopt/search/CJobGroup.h"

#include "gpopt/search/CGroupProxy.h"
#include "gpopt/search/CJobFactory.h"
#include "gpopt/search/CJobGroupExpressionExploration.h"
#include "gpopt/search/CJobGroupExpressionImplementation.h"

using namespace gpopt;


//---------------------------------------------------------------------------
//	@function:
//		CJobGroup::Init
//
//	@doc:
//		Initialize job
//
//---------------------------------------------------------------------------
void
CJobGroup::Init(CGroup *pgroup)
{
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroup::PgexprFirstUnschedNonLogical
//
//	@doc:
//		Get first non-logical group expression with an unscheduled job
//
//---------------------------------------------------------------------------
CGroupExpression *
CJobGroup::PgexprFirstUnschedNonLogical()
{
	return NULL;
}


//---------------------------------------------------------------------------
//	@function:
//		CJobGroup::PgexprFirstUnschedLogical
//
//	@doc:
//		Get first logical group expression with an unscheduled job
//
//---------------------------------------------------------------------------
CGroupExpression *
CJobGroup::PgexprFirstUnschedLogical()
{
	return NULL;
}

// EOF
