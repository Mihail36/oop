#pragma once

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	bool IsTurnedOn() const;
	int GetChannel() const;

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousChannel = m_selectedChannel;
};

const int MIN_CHANNEL = 1;
const int MAX_CHANNEL = 99;