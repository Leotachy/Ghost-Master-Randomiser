#pragma once

#include "wx/wx.h"
#include <Windows.h>
#include "TransparentStaticText.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
	

public:
	wxButton* m_btn1 = nullptr;
	wxButton* m_GetRandomSeed = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxCheckBox* m_HaunterRandomiser = nullptr;
	wxCheckBox* m_RandHaunters = nullptr;
		wxCheckBox* m_RandHauntersFetter = nullptr;
		wxCheckBox* m_RandHaunterPowers = nullptr;
	wxCheckBox* m_RandDialogue = nullptr;
		wxCheckBox* m_DialogueNarrator = nullptr;
		wxCheckBox* m_DialogueHaunter = nullptr;
		wxCheckBox* m_DialogueIncludeTutorial = nullptr;
	wxCheckBox* m_ScenarioRandomiser = nullptr;
		wxCheckBox* m_RandScenarioOrder = nullptr;
		wxCheckBox* m_ScenarioUnfair = nullptr;
	wxCheckBox* m_MortalRandomiser = nullptr;
		wxCheckBox* m_RandMortals = nullptr;
		wxCheckBox* m_RandMortalDontRandKeyMortals = nullptr;
		wxCheckBox* m_RandMortalStats = nullptr;
	wxTextCtrl* m_Path = nullptr;
	wxButton* m_SelectPath = nullptr;
	wxCheckBox* m_RandGhoulroom = nullptr;

	wxColour* mainColour = nullptr;


	wxCheckBox* m_Extra_IncludeFMVSkip = nullptr;
	wxCheckBox* m_Extra_IncludeDarklingQoL = nullptr;
	wxStaticBitmap* image = nullptr;

	TransparentStaticText* m_FettersTrueRandom = nullptr;
	TransparentStaticText* m_FettersShuffle = nullptr;

	void GenerateRandomSeed(wxCommandEvent& evt);
	void Startup_GenerateRandomSeed();
	void OnCheckboxClicked(wxCommandEvent& evt);
	void SetRandomiserParameters(wxCommandEvent& evt);
	void SetPath(wxCommandEvent& evt);
	
	
	wxDECLARE_EVENT_TABLE();
};

bool isPathCorrect();

