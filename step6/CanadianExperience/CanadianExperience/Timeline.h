/** This class implements a timeline that manages the animation
*
* A timeline consists of animation channels for different parts of our
* actors, each with keyframes that set the position, orientation, etc
* at that point in time. */

#pragma once
class CTimeline
{
public:
	CTimeline();
	virtual ~CTimeline();

	/// Copy Constructor (Disabled)
	CTimeline(const CTimeline &) = delete;
	/// Assignment Operator (Disabled)
	CTimeline &operator=(const CTimeline &) = delete;

	/** Get the number of frames in the animation
	* \returns Number of frames in the animation
	*/
	int GetNumFrames() const { return mNumFrames; }

	/** Set the number of frames in the animation
	* \param numFrames Number of frames in the animation
	*/
	void SetNumFrames(int numFrames) { mNumFrames = numFrames; }

	/** Get the frame rate
	* \returns Animation frame rate in frames per second
	*/
	int GetFrameRate() const { return mFrameRate; }

	/** Set the frame rate
	* \param frameRate Animation frame rate in frames per second
	*/
	void SetFrameRate(int frameRate) { mFrameRate = frameRate; }

	/** Get the current time
	* \returns Current animation time in seconds
	*/
	double GetCurrentTime() const { return mCurrentTime; }

	/** Set the current time
	* \param currentTime new current animation time in seconds
	*/
	void SetCurrentTime(double currentTime) { mCurrentTime = currentTime; }

	/** Get the current frame.
	*
	* This is the frame associated with the current time
	* \returns Current frame
	*/
	int GetCurrentFrame() const { return floor(mCurrentTime*mFrameRate); }

	/** Get the animation duration
	* \returns Animation duration in seconds
	*/
	double GetDuration() const { return (double)mNumFrames / mFrameRate; }

private:
	/// frame
	int mFrameRate = 30;
	/// frame time
	double mCurrentTime = 0;
	/// framesss
	int mNumFrames = 300;
};

