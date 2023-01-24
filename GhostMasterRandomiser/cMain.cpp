#include "cMain.h"
#include "cApp.h"
#include "base64.h"
#include "RandomiserMain.h"

using namespace std;

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(169, SetRandomiserParameters)
EVT_BUTTON(171, SetPath)
EVT_BUTTON(102, GenerateRandomSeed)
EVT_CHECKBOX(310, OnCheckboxClicked)
EVT_CHECKBOX(311, OnCheckboxClicked)
EVT_CHECKBOX(312, OnCheckboxClicked)
EVT_CHECKBOX(313, OnCheckboxClicked)
EVT_CHECKBOX(320, OnCheckboxClicked)
EVT_CHECKBOX(321, OnCheckboxClicked)
EVT_CHECKBOX(322, OnCheckboxClicked)
EVT_CHECKBOX(323, OnCheckboxClicked)
EVT_CHECKBOX(330, OnCheckboxClicked)
EVT_CHECKBOX(331, OnCheckboxClicked)
EVT_CHECKBOX(332, OnCheckboxClicked)
EVT_CHECKBOX(333, OnCheckboxClicked)
EVT_CHECKBOX(340, OnCheckboxClicked)
EVT_CHECKBOX(341, OnCheckboxClicked)
EVT_CHECKBOX(342, OnCheckboxClicked)
EVT_CHECKBOX(343, OnCheckboxClicked)
EVT_CHECKBOX(wxID_ANY, OnCheckboxClicked)
wxEND_EVENT_TABLE()




extern bool RandHaunters;
extern bool SoftlockFix;
extern bool RandPowers;
extern int RandHaunterFetters;
extern bool DialogueHaunter;
extern bool DialogueNarrator;
extern bool DialogueIncludeTutorial;
extern bool RandScenarioOrder;
extern bool ScenarioUnfair;
extern bool RandGhoulroom;
extern bool PrevImpSav;
extern bool RandMortalOrderOfAppearance;
extern bool RandMortalStats;
extern bool DontRandKeyMortals;
extern bool Extra_SkippableFMVs;
extern bool Extra_CuckoosQoL;
extern unsigned int crc_table[256];
extern unsigned long long seed;

extern string ModsPath;
extern string app_version;


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Ghost Master Randomiser " + app_version + " by Leotachy", wxPoint(wxDefaultPosition), wxSize(800, 600), (wxDEFAULT_FRAME_STYLE - wxRESIZE_BORDER - wxMAXIMIZE_BOX))
{
	CenterOnScreen(wxBOTH);

	srand((unsigned int)time(NULL));

	wxStaticBitmap* image = new wxStaticBitmap(this, wxID_ANY, wxBitmap("IDB_BITMAP1", wxBITMAP_TYPE_PNG_RESOURCE), wxPoint(wxDefaultPosition), wxSize(800, 600)); //1014x728
	
	
	wxFont Font_RandParameters(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont Font_SubRandParameters(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont Font_ExtraNotes(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	wxColour* mainColour = new wxColour(255, 255, 255, 255);
	
	unsigned const int diff = 25;
	unsigned const int initial = 113;
	

	m_Path = new wxTextCtrl(image, wxID_ANY, "", wxPoint(215, 30), wxSize(350, 20));
	m_SelectPath = new wxButton(image, 171, "Select Path", wxPoint(340, 60), wxSize(100, 20));
	m_txt1 = new wxTextCtrl(image, wxID_ANY, "", wxPoint(580, 116), wxSize(150, 20));
	m_GetRandomSeed = new wxButton(image, 102, "Generate Seed", wxPoint(605, 153), wxSize(100, 20));
	m_btn1 = new wxButton(image, 169, "Randomise!", wxPoint(340, 490), wxSize(100, 50));


	m_HaunterRandomiser = new wxCheckBox(image, 310, "Randomise Haunters:", wxPoint(15, initial), wxSize(180, 20));
	m_RandHaunters = new wxCheckBox(image, 311, "Stock, Act, Lay to Rest", wxPoint(30, initial+diff), wxSize(180, 20));
	m_RandHauntersFetter = new wxCheckBox(image, 312, "Fetters", wxPoint(30, initial+(diff*2)), wxSize(65, 20), wxCHK_ALLOW_3RD_STATE_FOR_USER | wxCHK_3STATE);
	m_RandHaunterPowers = new wxCheckBox(image, 313, "Powers", wxPoint(30, initial+(diff*3)), wxSize(70, 20));
	m_MortalRandomiser = new wxCheckBox(image, 320, "Randomise Mortals:", wxPoint(15, initial + (diff * 4)), wxSize(170, 20));
	m_RandMortals = new wxCheckBox(image, 321, "Order of Appearance", wxPoint(30, initial+(diff * 5)), wxSize(180, 20));
	m_RandMortalStats = new wxCheckBox(image, 323, "Stats", wxPoint(45, initial +(diff * 6)), wxSize(60, 20));
	m_RandMortalDontRandKeyMortals = new wxCheckBox(image, 322, "Don't Randomise Puzzle Mortals", wxPoint(45, initial + (diff * 7)), wxSize(250, 20));
	m_ScenarioRandomiser = new wxCheckBox(image, 330, "Randomise Scenarios:", wxPoint(15, initial + (diff * 8)), wxSize(180, 20));
	m_RandScenarioOrder = new wxCheckBox(image, 331, "Scenario Order", wxPoint(30, initial + (diff * 9)), wxSize(150, 20));
	m_ScenarioUnfair = new wxCheckBox(image, 332, "Allow Unfair Outcomes", wxPoint(45, initial+(diff*10)), wxSize(180, 20));
	m_RandGhoulroom = new wxCheckBox(image, 333, "Ghoul Room Spawns", wxPoint(30, initial + (diff * 11)), wxSize(190, 20));
	m_RandDialogue = new wxCheckBox(image, 340, "Randomise Voice Lines:", wxPoint(15, initial+(diff*12)), wxSize(200, 20));
	m_DialogueNarrator = new wxCheckBox(image, 341, "Narrator", wxPoint(30, initial+(diff*13)), wxSize(160, 20));
	m_DialogueHaunter = new wxCheckBox(image, 342, "Haunter", wxPoint(30, initial+(diff*14)), wxSize(160, 20));
    m_DialogueIncludeTutorial = new wxCheckBox(image, 343, "Include Tutorial Lines", wxPoint(30, initial+(diff*15)), wxSize(180, 20));
	
	TransparentStaticText* m_Extras = new TransparentStaticText(this, wxID_ANY, "Extra:", wxPoint(636, initial + (diff * 11)), wxSize(150, 20));
	m_Extra_IncludeFMVSkip = new wxCheckBox(image, 500, "Skippable FMVs", wxPoint(580, initial + (diff * 12)), wxSize(150, 20));
	m_Extra_IncludeDarklingQoL = new wxCheckBox(image, 501, "Cuckoo's Nest QoL", wxPoint(580, initial + (diff * 13)), wxSize(150,20));

	m_FettersShuffle = new TransparentStaticText(this, wxID_ANY, "(Shuffle)", wxPoint(100, initial + 1 + (diff * 2)), wxSize(150, 20));
	m_FettersTrueRandom = new TransparentStaticText(this, wxID_ANY, "(True Random)", wxPoint(100, initial + 1 + (diff * 2)), wxSize(150, 20));

	m_FettersShuffle->Hide();
	m_FettersTrueRandom->Hide();
	

	m_HaunterRandomiser->SetFont(Font_RandParameters);
	m_RandDialogue->SetFont(Font_RandParameters);
	m_ScenarioRandomiser->SetFont(Font_RandParameters);
	m_MortalRandomiser->SetFont(Font_RandParameters);

	m_RandHaunters->SetFont(Font_SubRandParameters);
	m_RandHauntersFetter->SetFont(Font_SubRandParameters);
	m_RandHaunterPowers->SetFont(Font_SubRandParameters);
	m_DialogueNarrator->SetFont(Font_SubRandParameters);
	m_DialogueHaunter->SetFont(Font_SubRandParameters);
	m_RandScenarioOrder->SetFont(Font_SubRandParameters);
    m_ScenarioUnfair->SetFont(Font_SubRandParameters);
	m_RandMortals->SetFont(Font_SubRandParameters);
    m_RandMortalDontRandKeyMortals->SetFont(Font_SubRandParameters);
	m_RandMortalStats->SetFont(Font_SubRandParameters);
    m_DialogueIncludeTutorial->SetFont(Font_SubRandParameters);
	m_Extras->SetFont(Font_SubRandParameters);
	m_Extra_IncludeFMVSkip->SetFont(Font_SubRandParameters);
	m_Extra_IncludeDarklingQoL->SetFont(Font_SubRandParameters);
	m_FettersShuffle->SetFont(Font_ExtraNotes);
	m_FettersTrueRandom->SetFont(Font_ExtraNotes);
	m_RandGhoulroom->SetFont(Font_SubRandParameters);

	m_RandHaunters->SetBackgroundColour(*mainColour);
	m_RandHauntersFetter->SetBackgroundColour(*mainColour);
	m_RandHaunterPowers->SetBackgroundColour(*mainColour);
	m_RandDialogue->SetBackgroundColour(*mainColour);
	m_DialogueNarrator->SetBackgroundColour(*mainColour);
	m_DialogueHaunter->SetBackgroundColour(*mainColour);
	m_RandScenarioOrder->SetBackgroundColour(*mainColour);
	m_ScenarioUnfair->SetBackgroundColour(*mainColour);
	m_RandMortals->SetBackgroundColour(*mainColour);
	m_RandMortalDontRandKeyMortals->SetBackgroundColour(*mainColour);
	m_RandMortalStats->SetBackgroundColour(*mainColour);
	m_DialogueIncludeTutorial->SetBackgroundColour(*mainColour);
	m_HaunterRandomiser->SetBackgroundColour(*mainColour);
	m_RandDialogue->SetBackgroundColour(*mainColour);
	m_ScenarioRandomiser->SetBackgroundColour(*mainColour);
	m_MortalRandomiser->SetBackgroundColour(*mainColour);
	m_RandGhoulroom->SetBackgroundColour(*mainColour);

	

	



	Startup_GenerateRandomSeed();

	

}


cMain::~cMain()
{
}

bool isPathCorrect()
{

	ifstream CheckIfExists;

	CheckIfExists.open(ModsPath + "HaunterData.asm");
	if (!CheckIfExists)
	{
		CheckIfExists.close();
		wxMessageBox("Could not find HaunterData.asm. Are you sure the path is correct?");
		wxMessageBox(ModsPath);
		return 0;
	}
	else
	{
		CheckIfExists.close();
		return 1;
	}


}





void cMain::SetPath(wxCommandEvent& evt)
{
	wxDirDialog* d = new wxDirDialog(this, ("Choose a directory to a Mod"), wxEmptyString, 0, wxDefaultPosition);

	if (d->ShowModal() == wxID_OK)
	{
		m_Path->Clear();
		m_Path->AppendText(d->GetPath());
	}

	delete d;
}




void cMain::SetRandomiserParameters(wxCommandEvent& evt)
{
	string stringSeed = string((m_txt1->GetValue()).mb_str());
	stringstream ss;

	if (stringSeed.empty())
	{
		
		seed = rand();
		ss << seed;
		string StringSeed(ss.str());
		ss.str("");
		ss.clear();
		m_txt1->AppendText(StringSeed);
		stringSeed = string((m_txt1->GetValue()).mb_str());
		goto skipBadCode;

	}

	
	

        if (!all_of(stringSeed.begin(), stringSeed.end(), ::isdigit))
        {
            string invalidChars = doesStringContainInvalidCharacters(stringSeed);

            

            if (invalidChars.empty())
            {
                if (stringSeed.length() == 1)
                {
                    stringSeed += " ";
                }
                std::vector<BYTE> decodedData = base64_decode(stringSeed);
                seed = (decodedData[0] << 16) | (decodedData[1] << 16) | (decodedData[2] << 16) | (decodedData[3] << 16) | (decodedData[4] << 16) | (decodedData[5] << 16) | (decodedData[6] << 16) | (decodedData[7] << 16) | (decodedData[8] << 16)  | (decodedData[9]);
                
            }
            else
            {
                invalidChars = "Your seed contains invalid characters: " + invalidChars;

                const char* invalidChars_array = invalidChars.c_str();

                wxString invalidCharsUsageError(invalidChars_array, wxConvUTF8);


                wxMessageBox(invalidCharsUsageError, "Error :(");
                evt.Skip();
                return;
            }

            
        }
        else
        {
			skipBadCode:
			ss << stringSeed;
			ss >> seed;
			ss.str("");
			ss.clear();
            
        }
        

	

	

	ModsPath = std::string((m_Path->GetValue()).mb_str());

	if (ModsPath.empty())
	{
		wxMessageBox("Please direct a path to a Mod folder which contains .asm files.", "Error :(");
		evt.Skip();
		return;
	}

	if (ModsPath.back() != 0x5C) //5C is backwards slash
	{
		ModsPath += 0x5C;
	}

	if (!isPathCorrect())
	{
		evt.Skip();
		return;
	}

	if (m_RandHaunters->IsChecked())
	{
		RandHaunters = true;
		SoftlockFix = true;
	}
		
	else
	{
		RandHaunters = false;
		SoftlockFix = false;
	}
		

	if (m_DialogueNarrator->IsChecked())
		DialogueNarrator = true;
	else
		DialogueNarrator = false;

	if (m_DialogueHaunter->IsChecked())
		DialogueHaunter = true;
	else
		DialogueHaunter = false;
    if (m_DialogueIncludeTutorial->IsChecked())
        DialogueIncludeTutorial = true;
    else
        DialogueIncludeTutorial = false;

	if (m_RandScenarioOrder->IsChecked())
		RandScenarioOrder = true;
	else
		RandScenarioOrder = false;

    if (m_ScenarioUnfair->IsChecked())
        ScenarioUnfair = true;
    else 
        ScenarioUnfair = false;

	if (m_RandMortals->IsChecked())
		RandMortalOrderOfAppearance = true;
	else
		RandMortalOrderOfAppearance = false;

	if (m_RandMortalStats->IsChecked())
		RandMortalStats = true;
	else
		RandMortalStats = false;
    if (m_RandMortalDontRandKeyMortals->IsChecked())
        DontRandKeyMortals = true;
    else
        DontRandKeyMortals = false;

	switch (m_RandHauntersFetter->Get3StateValue())
	{
	case wxCHK_CHECKED:
		RandHaunterFetters = 2;
		break;
	case wxCHK_UNDETERMINED:
		RandHaunterFetters = 1;
		break;
	default:
		RandHaunterFetters = 0;
	}

	if (m_RandHaunterPowers->IsChecked())
		RandPowers = true;
	else
		RandPowers = false;

	if (m_Extra_IncludeFMVSkip->IsChecked())
		Extra_SkippableFMVs = true;
	else
		Extra_SkippableFMVs = false;

	if (m_Extra_IncludeDarklingQoL->IsChecked())
		Extra_CuckoosQoL = true;
	else
		Extra_CuckoosQoL = false;

	if (m_RandGhoulroom->IsChecked())
		RandGhoulroom = 1;
	else
		RandGhoulroom = 0;



	if (!RandHaunters && !RandHaunterFetters && !RandPowers && !DialogueNarrator && !DialogueHaunter && !RandScenarioOrder && !RandMortalOrderOfAppearance && !RandMortalStats && !Extra_CuckoosQoL && !Extra_SkippableFMVs && !RandGhoulroom)
	{
		wxMessageBox("Please select at least one parameter.", "Error :(");
		evt.Skip();
		return;
	}


	Randomise();

	evt.Skip();
}



void cMain::GenerateRandomSeed(wxCommandEvent& evt)
{
	m_txt1->Clear();
	Startup_GenerateRandomSeed();
	evt.Skip();
}

void cMain::Startup_GenerateRandomSeed()
{
	std::stringstream ss;
	seed = rand();
	ss << seed;
	std::string StringSeed(ss.str());
	ss.str("");
	ss.clear();
	m_txt1->AppendText(StringSeed);

}

void cMain::OnCheckboxClicked(wxCommandEvent &evt)
{

	switch (evt.GetId())
	{
	case 310:
		if (m_HaunterRandomiser->IsChecked())
		{
			m_RandHaunters->SetValue(1);
			m_RandHauntersFetter->SetValue(1);
			m_FettersTrueRandom->Hide();
			m_FettersShuffle->Show();
			m_RandHaunterPowers->SetValue(1);
		}
		else
		{
			m_RandHaunters->SetValue(0);
			m_RandHauntersFetter->SetValue(0);
			m_RandHaunterPowers->SetValue(0);
			m_FettersShuffle->Hide();
			m_FettersTrueRandom->Hide();
		}
		break;
	case 311:
		if (m_RandHaunters->IsChecked())
		{
			m_HaunterRandomiser->SetValue(1);
		}
		else if (!(m_RandHaunterPowers->IsChecked()) && !(m_RandHauntersFetter->IsChecked()))
		{
			m_HaunterRandomiser->SetValue(0);
		}
		break;
	case 312:
		if (m_RandHauntersFetter->IsChecked())
		{
			m_HaunterRandomiser->SetValue(1);
			if (m_RandHauntersFetter->Get3StateValue() == wxCHK_UNDETERMINED)
			{
				m_FettersShuffle->Hide();
				m_FettersTrueRandom->Show();
			}
			if (m_RandHauntersFetter->Get3StateValue() == wxCHK_CHECKED)
			{
				m_FettersShuffle->Show();
				m_FettersTrueRandom->Hide();
			}
		
		}
		else
		{
			m_FettersShuffle->Hide();
			m_FettersTrueRandom->Hide();
			if (!(m_RandHaunterPowers->IsChecked()) && !(m_RandHaunters->IsChecked()))
			{
				m_HaunterRandomiser->SetValue(0);
			}
		}
		break;
	case 313:
		if (m_RandHaunterPowers->IsChecked())
		{
			m_HaunterRandomiser->SetValue(1);
		}
		else if (!(m_RandHauntersFetter->IsChecked()) && !(m_RandHaunters->IsChecked()))
		{
			m_HaunterRandomiser->SetValue(0);
		}
		break;
	case 320:
		if (m_MortalRandomiser->IsChecked())
		{
			m_RandMortals->SetValue(1);
			m_RandMortalStats->SetValue(1);
			m_RandMortalDontRandKeyMortals->SetValue(1);
		}
		else
		{
			m_RandMortals->SetValue(0);
			m_RandMortalStats->SetValue(0);
			m_RandMortalDontRandKeyMortals->SetValue(0);
		}
		break;

	case 321:
		if (m_RandMortals->IsChecked())
		{
			m_MortalRandomiser->SetValue(1);
			m_RandMortalDontRandKeyMortals->SetValue(1);
			m_RandMortalStats->SetValue(1);
		}
		else
		{
			m_MortalRandomiser->SetValue(0);
			m_RandMortalDontRandKeyMortals->SetValue(0);
			m_RandMortalStats->SetValue(0);
		}
		break;
	case 322:
		if (m_RandMortalDontRandKeyMortals->IsChecked())
		{
			m_MortalRandomiser->SetValue(1);
			m_RandMortals->SetValue(1);
		}
		break;
	case 323:
		if (m_RandMortalStats->IsChecked())
		{
			m_MortalRandomiser->SetValue(1);
			m_RandMortals->SetValue(1);
		}
		break;
	case 330:
		if (m_ScenarioRandomiser->IsChecked())
		{
			m_RandScenarioOrder->SetValue(1);
			m_RandGhoulroom->SetValue(1);
		}
		else
		{
			m_RandScenarioOrder->SetValue(0);
			m_ScenarioUnfair->SetValue(0);
			m_RandGhoulroom->SetValue(0);

		}
		break;
	case 331:
		if (m_RandScenarioOrder->IsChecked())
		{
			m_ScenarioRandomiser->SetValue(1);
		}
		else
		{
			m_ScenarioRandomiser->SetValue(0);
			m_ScenarioUnfair->SetValue(0);
		}
		break;
	case 332:
		if (m_ScenarioUnfair->IsChecked())
		{
			m_RandScenarioOrder->SetValue(1);
			m_ScenarioRandomiser->SetValue(1);
		}
		break;
	case 333:
		if (m_RandGhoulroom->IsChecked())
		{
			m_ScenarioRandomiser->SetValue(1);
		}
		else if (!m_RandScenarioOrder->IsChecked())
		{
			m_ScenarioRandomiser->SetValue(0);
		}
		
		break;

	case 340:
		if (m_RandDialogue->IsChecked())
		{
			m_DialogueHaunter->SetValue(1);
			m_DialogueNarrator->SetValue(1);
		}
		else
		{
			m_DialogueHaunter->SetValue(0);
			m_DialogueNarrator->SetValue(0);
            m_DialogueIncludeTutorial->SetValue(0);
		}
		break;
	case 341:
		if (m_DialogueNarrator->IsChecked())
		{
			m_RandDialogue->SetValue(1);
		}
		else if (!m_DialogueHaunter->IsChecked())
		{
			m_RandDialogue->SetValue(0);
			m_DialogueIncludeTutorial->SetValue(0);
		}
		break;
	case 342:
		if (m_DialogueHaunter->IsChecked())
		{
			m_RandDialogue->SetValue(1);
		}
		else if (!m_DialogueNarrator->IsChecked())
		{
			m_RandDialogue->SetValue(0);
			m_DialogueIncludeTutorial->SetValue(0);
		}
		break;
    case 343:
        if (m_DialogueIncludeTutorial->IsChecked())
        {
            m_RandDialogue->SetValue(1);
			if (!(m_DialogueHaunter->IsChecked()) && !((m_DialogueNarrator->IsChecked())))
			{
				m_DialogueHaunter->SetValue(1);
				m_DialogueNarrator->SetValue(1);
			}
        }
		else if (!(m_DialogueHaunter->IsChecked()) && !(m_DialogueNarrator->IsChecked()))
		{
			m_RandDialogue->SetValue(0);
		}
		break;
	default:
		break;
	}

	evt.Skip();
	
}

