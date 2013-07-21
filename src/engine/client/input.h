/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef ENGINE_CLIENT_INPUT_H
#define ENGINE_CLIENT_INPUT_H

class CInput : public IEngineInput
{
	IEngineGraphics *m_pGraphics;

	int m_MouseModes;

	int m_LastMousePosX;
	int m_LastMousePosY;
	bool m_FirstWarp;

	int64 m_LastRelease;
	int64 m_ReleaseDelta;

	void AddEvent(int Unicode, int Key, int Flags);

	IEngineGraphics *Graphics() { return m_pGraphics; }

public:
	CInput();

	virtual void Init();

	virtual void SetMouseModes(int modes);
	virtual int GetMouseModes();
	virtual void GetMousePosition(float *x, float *y);
	virtual void GetRelativePosition(float *x, float *y);
	virtual bool MouseMoved();
	virtual int MouseDoubleClick();

	void ClearKeyStates();
	int KeyState(int Key);

	int ButtonPressed(int Button) { return m_aInputState[m_InputCurrent][Button]; }

	virtual int Update();
};

#endif
