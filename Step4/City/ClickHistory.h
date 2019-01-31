/**
 * \file ClickHistory.h
 *
 * \author Charles Owen
 *
 * Class that keeps track of the history of clicks on city tiles
 */

#pragma once
#include "Click.h"

/**
 * Class that keeps track of the history of clicks on city tiles
 */
class CClickHistory
{
public:
    CClickHistory();
    virtual ~CClickHistory();

    void Add(std::shared_ptr<CTile> tile, time_t time);
    bool Remove(std::shared_ptr<CTile> tile);
    void Clear();

protected:
    /**
     * Nexted class that actually stores the click history items
     */
    class Click : public CClick
    {
    public:
        Click(std::shared_ptr<CTile> tile, time_t time);
        virtual ~Click();

        /**
        * Get the tile we clicked on
        * \returns CTile object pointer
        */
        std::shared_ptr<CTile> GetTile() { return mTile; }

        /**
        * Get the time this click occurred
        * \returns Time as a long long value (seconds since 1970)
        */
        time_t GetTime() { return mTime; }

        /// Pointer to next click in linked list
        std::shared_ptr<Click> mNext;

        /// Pointer to a tile
        std::shared_ptr<CTile> mTile;

        /// Click time
        time_t mTime = 0;
    };

    /// Pointer to head of linked list of clicks
    std::shared_ptr<Click> mHead;


	///Class that makes an iterator for the clicks.
	class Iter
	{
	public:
		/** Constructor
		* \param click The city we are iterating over 
		* \param pos is the position */
		Iter(CClickHistory *click, std::shared_ptr<Click> pos) : mClick(click), mPos(pos) {}

		/** Test for end of the iterator
		* \returns True if we this position equals not equal to the other position 
		* \param other is the position*/
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<Click> operator *() const { return mPos; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos = mPos->mNext;
			return *this;
		}

	private:
		CClickHistory *mClick;   ///< City we are iterating over
		std::shared_ptr<Click> mPos;       ///< Position in the collection
	};

public:


	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */
	Iter begin() { return Iter(this, mHead); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this, nullptr); }

};

