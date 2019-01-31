/**
* \file CTimelineTest.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Timeline.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(EmptyTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(CTimelineTest)
		{
			CTimeline timeline;
			Assert::AreEqual(0.0, timeline.GetCurrentTime());
			timeline.SetCurrentTime(23.4);
			Assert::AreEqual(23.4, timeline.GetCurrentTime());

			Assert::AreEqual(30, timeline.GetFrameRate());
			timeline.SetFrameRate(23);
			Assert::AreEqual(23, timeline.GetFrameRate());

			Assert::AreEqual(300, timeline.GetNumFrames());
			timeline.SetNumFrames(430);
			Assert::AreEqual(430, timeline.GetNumFrames());
		}
		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

			timeline.SetNumFrames(789);
			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());

			// Changed time
			timeline.SetCurrentTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}

	};
}