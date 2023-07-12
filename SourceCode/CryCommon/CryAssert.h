/*************************************************************************
Crytek Source File.
Copyright (C), Crytek Studios, 2001-2005.
-------------------------------------------------------------------------
$Id$
$DateTime$
Description: 
	Assert dialog box

-------------------------------------------------------------------------
History:
- 23:10:2006: Created by Julien Darre

*************************************************************************/
#ifndef __CRYASSERT_H__
#define __CRYASSERT_H__
#pragma once

//-----------------------------------------------------------------------------------------------------
// Just undef this if you want to use the standard assert function
//-----------------------------------------------------------------------------------------------------

#define USE_CRY_ASSERT

#if defined(__SPU__) || defined(JOB_LIB_COMP)

	#if !defined(__SPU__)
		#include <assert.h>
	#endif
	#define CRY_ASSERT(condition) assert(condition)
	#define CRY_ASSERT_MESSAGE(condition,message) assert(condition)
	#define CRY_ASSERT_TRACE(condition,parenthese_message) assert(condition)
	#if defined __CRYCG__
		// FIXME: Find a way to tunnel asserts through CryCG.
		#define assert(cond) ((void)0)
	#endif

#else

//-----------------------------------------------------------------------------------------------------
// Use like this:
// CRY_ASSERT(expression);
// CRY_ASSERT_MESSAGE(expression,"Useful message");
// CRY_ASSERT_TRACE(expression,("This should never happen because parameter n°%d named %s is %f",iParameter,szParam,fValue));
//-----------------------------------------------------------------------------------------------------

#if defined(USE_CRY_ASSERT) && defined(_DEBUG) && defined(WIN32)

	void CryAssertTrace(const char *,...);
	bool CryAssert(const char *,const char *,unsigned int,bool *);

	#define CRY_ASSERT(condition) CRY_ASSERT_MESSAGE(condition,NULL)

	#define CRY_ASSERT_MESSAGE(condition,message) CRY_ASSERT_TRACE(condition,(message))

	#define CRY_ASSERT_TRACE(condition,parenthese_message)							\
		do																																\
		{																																	\
			static bool s_bIgnoreAssert = false;														\
			if(!s_bIgnoreAssert && !(condition))														\
			{																																\
				CryAssertTrace parenthese_message;														\
				if(CryAssert(#condition,__FILE__,__LINE__,&s_bIgnoreAssert))	\
				{																															\
					DEBUG_BREAK;																								\
				}																															\
			}																																\
		} while(0)

#else

	#if defined(PS3) && defined(_DEBUG) && !defined(JOB_LIB_COMP)
		//method logs assert to a log file and enables setting of breakpoints easily
		//implemented in WinBase.cpp
		extern void HandleAssert(const char* cpMessage, const char* cpFunc, const char* cpFile, const int cLine);
		#undef assert
		#define CRY_ASSERT(condition) CRY_ASSERT_MESSAGE(condition,NULL)
		#define CRY_ASSERT_MESSAGE(condition,message) CRY_ASSERT_TRACE(condition,(message))
		#define CRY_ASSERT_TRACE(cond,message) \
		do \
				{ \
					if (!(cond)) \
						HandleAssert(#cond, __func__, __FILE__, __LINE__); \
				} while (false)

		#define assert CRY_ASSERT

	#else

		#include <assert.h>

		#define CRY_ASSERT(condition) assert(condition)
		#define CRY_ASSERT_MESSAGE(condition,message) assert(condition)
		#define CRY_ASSERT_TRACE(condition,parenthese_message) assert(condition)
	#endif
#endif

//-----------------------------------------------------------------------------------------------------

#endif	//JOB_LIB_COMP
#endif

//-----------------------------------------------------------------------------------------------------
