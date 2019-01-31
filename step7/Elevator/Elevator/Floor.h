#pragma once


///Forward reference
class CController;

class CFloor
{
public:
	CFloor();
	virtual ~CFloor();
	void SetUp(bool s);
	void SetPanel(bool p);
	void SetDown(bool s);
	void SetFloor(int floor) { mFloor = floor; }
	void SetController(CController *cntrl) { mController = cntrl; }
	bool IsUp() { return mUp; }
	bool IsDown() { return mDown; }
	bool IsPanel() { return mPanel; }
private:
	bool mUp = false;
	bool mDown = false;
	bool mPanel = false;
	int mFloor = 0;

	CController *mController;   ///< Controller for this object
};

