#include "cMain.h"
#include "RandomiserMain.h"
#include "defines.h"




using namespace std;


string ModsPath;
string app_version = "v2.05";

bool RandHaunters = false;
bool SoftlockFix = false;
bool RandPowers = false;
int RandHaunterFetters = 0;
bool DialogueHaunter = false;
bool DialogueNarrator = false;
bool DialogueIncludeTutorial = false;
bool RandScenarioOrder = false;
bool ScenarioUnfair = false;
bool PrevImpSav = true;
bool RandMortalOrderOfAppearance = false;
bool RandMortalStats = false;
bool DontRandKeyMortals = false;
bool Extra_SkippableFMVs = false;
bool Extra_CuckoosQoL = false;
unsigned int crc_table[256] = { 0x00000000, 0x4C11DB7, 0x9823B6E, 0xD4326D9, 0x130476DC, 0x17C56B6B, 0x1A864DB2, 0x1E475005, 0x2608EDB8, 0x22C9F00F, 0x2F8AD6D6, 0x2B4BCB61, 0x350C9B64, 0x31CD86D3, 0x3C8EA00A, 0x384FBDBD, 0x4C11DB70, 0x48D0C6C7, 0x4593E01E, 0x4152FDA9, 0x5F15ADAC, 0x5BD4B01B, 0x569796C2, 0x52568B75, 0x6A1936C8, 0x6ED82B7F, 0x639B0DA6, 0x675A1011, 0x791D4014, 0x7DDC5DA3, 0x709F7B7A, 0x745E66CD, 0x9823B6E0, 0x9CE2AB57, 0x91A18D8E, 0x95609039, 0x8B27C03C, 0x8FE6DD8B, 0x82A5FB52, 0x8664E6E5, 0xBE2B5B58, 0xBAEA46EF, 0xB7A96036, 0xB3687D81, 0xAD2F2D84, 0xA9EE3033, 0xA4AD16EA, 0xA06C0B5D, 0xD4326D90, 0xD0F37027, 0xDDB056FE, 0xD9714B49, 0xC7361B4C, 0xC3F706FB, 0xCEB42022, 0xCA753D95, 0xF23A8028, 0xF6FB9D9F, 0xFBB8BB46, 0xFF79A6F1, 0xE13EF6F4, 0xE5FFEB43, 0xE8BCCD9A, 0xEC7DD02D, 0x34867077, 0x30476DC0, 0x3D044B19, 0x39C556AE, 0x278206AB, 0x23431B1C, 0x2E003DC5, 0x2AC12072, 0x128E9DCF, 0x164F8078, 0x1B0CA6A1, 0x1FCDBB16, 0x18AEB13, 0x54BF6A4, 0x808D07D, 0xCC9CDCA, 0x7897AB07, 0x7C56B6B0, 0x71159069, 0x75D48DDE, 0x6B93DDDB, 0x6F52C06C, 0x6211E6B5, 0x66D0FB02, 0x5E9F46BF, 0x5A5E5B08, 0x571D7DD1, 0x53DC6066, 0x4D9B3063, 0x495A2DD4, 0x44190B0D, 0x40D816BA, 0xACA5C697, 0xA864DB20, 0xA527FDF9, 0xA1E6E04E, 0xBFA1B04B, 0xBB60ADFC, 0xB6238B25, 0xB2E29692, 0x8AAD2B2F, 0x8E6C3698, 0x832F1041, 0x87EE0DF6, 0x99A95DF3, 0x9D684044, 0x902B669D, 0x94EA7B2A, 0xE0B41DE7, 0xE4750050, 0xE9362689, 0xEDF73B3E, 0xF3B06B3B, 0xF771768C, 0xFA325055, 0xFEF34DE2, 0xC6BCF05F, 0xC27DEDE8, 0xCF3ECB31, 0xCBFFD686, 0xD5B88683, 0xD1799B34, 0xDC3ABDED, 0xD8FBA05A, 0x690CE0EE, 0x6DCDFD59, 0x608EDB80, 0x644FC637, 0x7A089632, 0x7EC98B85, 0x738AAD5C, 0x774BB0EB, 0x4F040D56, 0x4BC510E1, 0x46863638, 0x42472B8F, 0x5C007B8A, 0x58C1663D, 0x558240E4, 0x51435D53, 0x251D3B9E, 0x21DC2629, 0x2C9F00F0, 0x285E1D47, 0x36194D42, 0x32D850F5, 0x3F9B762C, 0x3B5A6B9B, 0x315D626, 0x7D4CB91, 0xA97ED48, 0xE56F0FF, 0x1011A0FA, 0x14D0BD4D, 0x19939B94, 0x1D528623, 0xF12F560E, 0xF5EE4BB9, 0xF8AD6D60, 0xFC6C70D7, 0xE22B20D2, 0xE6EA3D65, 0xEBA91BBC, 0xEF68060B, 0xD727BBB6, 0xD3E6A601, 0xDEA580D8, 0xDA649D6F, 0xC423CD6A, 0xC0E2D0DD, 0xCDA1F604, 0xC960EBB3, 0xBD3E8D7E, 0xB9FF90C9, 0xB4BCB610, 0xB07DABA7, 0xAE3AFBA2, 0xAAFBE615, 0xA7B8C0CC, 0xA379DD7B, 0x9B3660C6, 0x9FF77D71, 0x92B45BA8, 0x9675461F, 0x8832161A, 0x8CF30BAD, 0x81B02D74, 0x857130C3, 0x5D8A9099, 0x594B8D2E, 0x5408ABF7, 0x50C9B640, 0x4E8EE645, 0x4A4FFBF2, 0x470CDD2B, 0x43CDC09C, 0x7B827D21, 0x7F436096, 0x7200464F, 0x76C15BF8, 0x68860BFD, 0x6C47164A, 0x61043093, 0x65C52D24, 0x119B4BE9, 0x155A565E, 0x18197087, 0x1CD86D30, 0x29F3D35, 0x65E2082, 0xB1D065B, 0xFDC1BEC, 0x3793A651, 0x3352BBE6, 0x3E119D3F, 0x3AD08088, 0x2497D08D, 0x2056CD3A, 0x2D15EBE3, 0x29D4F654, 0xC5A92679, 0xC1683BCE, 0xCC2B1D17, 0xC8EA00A0, 0xD6AD50A5, 0xD26C4D12, 0xDF2F6BCB, 0xDBEE767C, 0xE3A1CBC1, 0xE760D676, 0xEA23F0AF, 0xEEE2ED18, 0xF0A5BD1D, 0xF464A0AA, 0xF9278673, 0xFDE69BC4, 0x89B8FD09, 0x8D79E0BE, 0x803AC667, 0x84FBDBD0, 0x9ABC8BD5, 0x9E7D9662, 0x933EB0BB, 0x97FFAD0C, 0xAFB010B1, 0xAB710D06, 0xA6322BDF, 0xA2F33668, 0xBCB4666D, 0xB8757BDA, 0xB5365D03, 0xB1F740B4 };
unsigned long long seed = 0;

bool RandGhoulroom = false;

bool RandText = false;


string StockHaunterArray[100];
string HaunterEnumArray[100];
string ActHaunterEnumArray[100];
string HaunterScriptInstanceArray[100];
string HaunterFetterFlagStringArray[100];


int HasManifestPowerBaseKitArray[100]{};
int SpecialHaunters[10]{};
int HaunterIDArray[100]{};
int RemainingRestlessSpiritIDArray[100]{};
int StockHaunterAndActGiftIDArray[100]{};

int Act2GiftCount = 0;
int Act3GiftCount = 0;
int Act4GiftCount = 0;

string pB_Band1[100];
string pB_Band2[100];
string pB_Band3[100];
string pB_Band4[100];
string pB_Band5[100];
string pB_Band6[100];
string pB_Band7[100];
string pB_Band8[100];
string pB_Band9[100];
string pB_Band10[100];
string pL1_Band1[100];
string pL1_Band2[100];
string pL1_Band3[100];
string pL1_Band4[100];
string pL1_Band5[100];
string pL1_Band6[100];
string pL1_Band7[100];
string pL1_Band8[100];
string pL1_Band9[100];
string pL1_Band10[100];
string pL2_Band1[100];
string pL2_Band2[100];
string pL2_Band3[100];
string pL2_Band4[100];
string pL2_Band5[100];
string pL2_Band6[100];
string pL2_Band7[100];
string pL2_Band8[100];
string pL2_Band9[100];
string pL2_Band10[100];

int maxBaseBand_arr[100];
int pLBand1Count[100];
int pLBand2Count[100];
int pLBand3Count[100];
int pLBand4Count[100];
int pLBand5Count[100];
int pLBand6Count[100];
int pLBand7Count[100];
int pLBand8Count[100];
int pLBand9Count[100];
int pLBand10Count[100];

bool pBBand1Count[100];
bool pBBand2Count[100];
bool pBBand3Count[100];
bool pBBand4Count[100];
bool pBBand5Count[100];
bool pBBand6Count[100];
bool pBBand7Count[100];
bool pBBand8Count[100];
bool pBBand9Count[100];
bool pBBand10Count[100];

int Band1Powers[100];
int Band2Powers[100];
int Band3Powers[100];
int Band4Powers[100];
int Band5Powers[100];
int Band6Powers[100];
int Band7Powers[100];
int Band8Powers[100];
int Band9Powers[100];
int Band10Powers[100];

int Band1PowerCount = 0;
int Band2PowerCount = 0;
int Band3PowerCount = 0;
int Band4PowerCount = 0;
int Band5PowerCount = 0;
int Band6PowerCount = 0;
int Band7PowerCount = 0;
int Band8PowerCount = 0;
int Band9PowerCount = 0;
int Band10PowerCount = 0;



int Band_arr[150];
int PowerID_arr[150];

int HaunterType[100];

ofstream errorLog;






int HoboID = -1;
int CousinID = -1;
int NormanID = -1;
int BlairID = -1;
int GreenwoodID = -1;

string MortalFilename[350];
string MortalScript[350];
string MortalModel[350];
string MortalAnimation[350];
string MortalType[350];
string MortalName[350];
string MortalBio[350];
string MortalIcon[350];
string MortalGender[350];
string MortalMood[350];
string MortalSubfear[350];
string MortalFear[350];
string MortalTerror[350];
string MortalMadness[350];
string MortalBelief[350];
string MortalWillpower[350];


int MortalIDArray[350];
int SaneMortalIDArray[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int MaleMortalIDArray[] = { -1, -1 };

int MaleLines[12];
int SaneLines[12];





void Randomise()
{
    

    bool dialogueError = 0;


    filesystem::path filepath = (ModsPath + "Randomiser_Backup\\");
    if (!filesystem::is_directory(filepath.parent_path()))
        filesystem::copy(ModsPath, ModsPath + "Randomiser_Backup\\");



    for (const auto& folderIter : filesystem::directory_iterator(ModsPath))
    {
        cout << folderIter.path() << endl;
        if (folderIter.path().extension() == ".asm" || folderIter.path().extension() == ".txt" || folderIter.path().extension() == ".Randomiser_TEMP" || folderIter.path().extension() == ".ini")
            filesystem::remove(folderIter.path());
    }



    filesystem::copy(ModsPath + "Randomiser_Backup\\", ModsPath);




    if (Extra_SkippableFMVs)
    {
        ofstream asmOut(ModsPath + "SkippableLegal&Cliffhanger.asm");

        asmOut << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << R"([ENABLE]
//Allow the legal screen to be skipped

//And trainspooking cinematic

alloc(legal,40)

label(cliffhanger)

legal:
push 1 //2 bytes
push eax //1
call 004A6890 //5
jmp 004A6C9B //5

cliffhanger:
push 1
push ecx
call 004A6890
jmp 004A7195

004A6C94:
jmp legal
nop
nop

004A718E:
jmp cliffhanger
nop
nop



[DISABLE]

004A6C94:
push esi //is skippable
push eax //video name
call 004A6890

004A718E:
push esi
push ecx
call 004A6890

dealloc(legal))" << endl;

        asmOut.close();
    }

    if (Extra_CuckoosQoL)
    {
        ofstream asmOut(ModsPath + "CuckoosQoL.asm");

        asmOut << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;

        asmOut << R"(

[ENABLE]
alloc(RemoveWardsINITIAL,200)


RemoveWardsINITIAL:
push eax
push ecx
push edi
xor edi,edi
RemoveWards: //loop start
mov eax,[edi+00956838]
mov ecx,008CDE38
push eax
call 0061A9D0
test eax,eax
je skipLoop
mov ecx,eax
call 0061AA40
push 01 //ward type: red
mov ecx,eax
call 00486210
skipLoop:
add edi,4
cmp edi,50
jb RemoveWards //loop end
pop edi
pop ecx
pop eax
call 0079EF50
jmp 004DB495

004DB490:
jmp RemoveWardsINITIAL

[DISABLE]

dealloc(RemoveWardsINITIAL)

)";
    }

    if (RandHaunters || RandHaunterFetters || RandPowers || RandGhoulroom)
    {
        

        GetPowerData();

        int HaunterCount = GetHaunterData();


        switch (RandHaunterFetters)
        {
        case 1:
            GetRandomFetters(HaunterCount);
            break;
        case 2:
            int dragoonID = -1;
            for (int i = 0; i < HaunterCount; i++)
            {
                if (strcmp(HaunterScriptInstanceArray[i].c_str(), "64 72 61 67 6F 6F 6E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") == 0)
                {
                    dragoonID = i;
                }
            }

            if (dragoonID == -1)
            {
                errorLog << "Dragoon not found for fetter randomiser" << endl;
            }

            shuffle(HaunterFetterFlagStringArray, HaunterFetterFlagStringArray + dragoonID - 1, default_random_engine(seed + 2));
            shuffle(HaunterFetterFlagStringArray + dragoonID + 1, HaunterFetterFlagStringArray + HaunterCount, default_random_engine(seed + 3));

        }
       
            
        if (RandPowers)
        {
            GetRandomPowers(HaunterCount);


            OutputPowerCrashFixes();
        }
            
        
        

            int Ghost = 0;


            for (int Ghost = 0; Ghost < HaunterCount; Ghost++)
            {

                if (RandPowers)
                {
                    if ((strcmp(pB_Band3[Ghost].c_str(), "dd 3e") == 0) || (strcmp(pB_Band6[Ghost].c_str(), "dd 40") == 0))
                    {
                        HasManifestPowerBaseKitArray[Ghost] = 1;
                    }
                }
                else
                {
                    if ((strcmp(pB_Band3[Ghost].c_str(), "dd 0000003E") == 0) || (strcmp(pB_Band6[Ghost].c_str(), "dd 00000040") == 0))
                    {
                        HasManifestPowerBaseKitArray[Ghost] = 1;
                    }
                }
            }

            
            
        
            if (RandHaunters)
            {

                

                GetSpecialHaunters(HaunterCount);

                shuffle(RemainingRestlessSpiritIDArray, RemainingRestlessSpiritIDArray + (HaunterCount - 8), default_random_engine(seed));

                RandScenario_Haunting101();
                RandScenario_WeirdSeance();
                RandScenario_Calamityville();
                RandScenario_Summoners();
                RandScenario_Deadfellas();
                RandScenario_Unusual();
                RandScenario_Poultrygeist();
                RandScenario_Facepacks();
                RandScenario_Phantom();
                RandScenario_Wisp();
                RandScenario_Ghostbreakers();
                RandScenario_MortalJacket();
                RandScenario_Spooky();
                RandScenario_Cuckoos();

                
                
            }

            GetActGiftsForEachAct("ActsGhosts.asm");
            int TotalGiftCount = Act2GiftCount + Act3GiftCount + Act4GiftCount;


            int OtherHaunters = GetCountOfOtherHauntersAndSubtractRestlessSpirits(HaunterCount);


            int StockHaunterCount = OtherHaunters - TotalGiftCount;


            if (RandHaunters)
            {

                shuffle(StockHaunterAndActGiftIDArray, StockHaunterAndActGiftIDArray + OtherHaunters, default_random_engine(seed));


                shuffle(StockHaunterArray, StockHaunterArray + StockHaunterCount, default_random_engine(seed));

                PrintHighScareTableGhostExceptions();
            }
            SubtractActGifts(TotalGiftCount, StockHaunterCount);

            OutputActGifts("ActsGhosts.asm");
            DeleteAndRename("ActsGhosts.asm");
       





        
        OutputHaunterData("HaunterData.asm", StockHaunterCount, HaunterCount);
        DeleteAndRename("HaunterData.asm");


        if (RandGhoulroom)
        {
            RandomiseGhoulroom(HaunterCount);
            DeleteAndRename("GRSpawnData.asm");
        }

        if (RandHaunterFetters || RandPowers)
        {
            PrintDisablePoltergeistTricksterMortalImmunity();
        }

    }

    if (SoftlockFix || DialogueHaunter || DialogueNarrator)
    {

        string* DialogueHash_arr = new string[1000];
        string* vdDialogueHash_arr = new string[1000];
        string* SpeechNamesInHex = new string[1000];

        int DialogueCount = GetDialogueHashesAndCountASM(DialogueHash_arr);
        string NewPath = GetPathToEnglishVdTxt();
        if (NewPath.empty())
        {
           dialogueError = 1;

        }

        if (!dialogueError)
        {
            int vdDialogueCount = GetDialogueHashesTXTAndCount(NewPath, vdDialogueHash_arr, SpeechNamesInHex);


            if (SoftlockFix)
            {
                ClearSoundSubtitles(DialogueHash_arr, vdDialogueHash_arr, vdDialogueCount, DialogueCount);
            }



            if (DialogueHaunter || DialogueNarrator)
            {

                RandomiseHaunterDialogue(DialogueHash_arr, DialogueCount, vdDialogueHash_arr, vdDialogueCount);

                if (DialogueNarrator)
                {
                    OutputNarratorSpeechHashes(SpeechNamesInHex);
                }

                if (DialogueHaunter)
                {
                    OutputSoundSubtitles(DialogueHash_arr, DialogueCount);
                    DeleteAndRename("SoundSubtitles.asm");
                }

            }
        }


        delete[] DialogueHash_arr;
        delete[] vdDialogueHash_arr;
        delete[] SpeechNamesInHex;
        

      
    }

    if (RandScenarioOrder)
    {
        int ScenarioIndexes[15] = {};

        GetRandomScenarioOrder(ScenarioIndexes);

        string Sc_Available_Array[] = { "00951218", "00951250", "00951288", "009512C0", "009512F8", "00951330", "00951368", "009513A0", "009513D8", "00951410", "00951448", "00951480", "009514B8", "009514F0", "00951528" };
        //H101, WS, CH, SNI, DF, US, FB, PG, PH, BWP, SH, GB, FMJ, CN, FIN 
        string Sc_Completed_Array[] = { "00951214", "0095124C", "00951284", "009512BC", "009512F4", "0095132C", "00951364", "0095139C", "009513D4", "0095140C", "00951444", "0095147C", "009514B4", "009514EC", "00951524" }; //Always 4 bytes before available
        string Sc_ScriptInstance_Array[] = { "008C6528", "008C651C", "008C6510", "008C6504", "008C64F8", "008C64F0", "008C64E4", "008C64D4", "008C64CC", "008C5768", "008C64C4", "008C64B4", "008C64A4", "008C6494", "008C6480" };
        string Sc_Name_Array[] = { "0000035F", "00000360", "00000363" , "00000361", "00000362", "00000365", "00000367", "00000366", "0000036C", "00000368", "0000036A", "0000036D", "0000036E", "00000370", "00000902" };

        OutputScenarioOrder(Sc_Available_Array, Sc_Completed_Array, Sc_Name_Array, Sc_ScriptInstance_Array, ScenarioIndexes);

    }

    if (RandMortalOrderOfAppearance)
    {
        ofstream asmOut(ModsPath + "ExtraScenarioObjectives.asm");

        asmOut << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << endl;
        asmOut << R"([ENABLE]

alloc(newmem, 1000)

newmem:

checkSaneMortalsPhantom:
mov ecx, esi
call 004A7B40
test eax, eax
jne PhantomScript
push 3A6
push 0
push 0
push 1
mov ecx, esi
call 0061A400
jmp 004E005B
PhantomScript:
mov eax, [esi]
call dword ptr[eax+58]
jmp 004DFF82

checkSaneMortalsFacepacks:
mov ecx, esi
call 004A7B40
dec eax
test eax, eax
jne FacepacksScript
push 3A6
push 0
push 0
push 1
mov ecx, esi
call 0061A400
jmp 004E005B
FacepacksScript:
mov eax, [esi]
call dword ptr[eax+58]
jmp 0053CF62


004DFF7D:
jmp checkSaneMortalsPhantom


0053CF5D :
jmp checkSaneMortalsFacepacks






[DISABLE])" << endl;

        asmOut.close();


        int TotalMortalCountInLevels = GetMortalData("Scenarios.asm");


        GetMortalIcons();

        if (RandMortalOrderOfAppearance)
        {
            shuffle(MortalIDArray, MortalIDArray + TotalMortalCountInLevels, default_random_engine(seed));
        }

        if (RandMortalStats)
        {
            stringstream ss;
            float MadnessValue = 0;
            float WillpowerValue = 0;


            shuffle(MortalBelief, MortalBelief + TotalMortalCountInLevels, default_random_engine(seed + 1));
            shuffle(MortalMadness, MortalMadness + TotalMortalCountInLevels, default_random_engine(seed + 1));
            shuffle(MortalWillpower, MortalWillpower + TotalMortalCountInLevels, default_random_engine(seed+ 1));
            shuffle(MortalTerror, MortalTerror + TotalMortalCountInLevels, default_random_engine(seed+ 1));

            shuffle(MortalFear, MortalFear + TotalMortalCountInLevels, default_random_engine(seed + 2));
            shuffle(MortalSubfear, MortalSubfear + TotalMortalCountInLevels, default_random_engine(seed + 3));


            

        }

        GetSpecialMortals(TotalMortalCountInLevels);

        int MortalIDArrayWithoutSpecials[350]{};
        int CountNoSpecials = 0;
        for (int i = 0; i < TotalMortalCountInLevels; i++)
        {
            if (MortalIDArray[i] != -1)
            {
                MortalIDArrayWithoutSpecials[CountNoSpecials] = MortalIDArray[i];
                CountNoSpecials++;
            }

        }




    OutputRandomMortals(MortalIDArrayWithoutSpecials, TotalMortalCountInLevels);
    OutputIconData(MortalIDArrayWithoutSpecials, TotalMortalCountInLevels);


    OutputMortalCrashFix();



    DeleteAndRename("Scenarios.asm");
    DeleteAndRename("IconData.asm");






    }

    if (RandText)
    {
        RandomiseText();
        DeleteAndRename("StringHashMap.asm");
    }


    


    OutputRandomiserInfo();

    wxMessageBox("Your mod was successfully randomised! =)", "Hurray!");

}


int GetHaunterData()
{
    ifstream HaunterData;
    string uselessLine;
    HaunterData.open(ModsPath + "Randomiser_Backup\\" + "HaunterData.asm");
    bool FirstTime = true;
    bool FirstTimeEnum = true;
    bool FirstTimeScriptInstance = true;
    bool FirstTimePower = true;
    bool FirstTimeType = 1;

    int e = 0;
    int a = 0;
    int i = 0;
    int z = 0;
    int b = 0;

    int PowerID = 0;
    int HaunterCount = 0;
    int BandID = 0;

    int temp = 0;

    stringstream ss;

    while (uselessLine != "db 21")
    {
        std::getline(HaunterData, uselessLine);


        if (((a == 8 && FirstTimeScriptInstance) || a == 23))
        {

            HaunterScriptInstanceArray[HaunterCount] = uselessLine.substr(3);
            FirstTimeScriptInstance = false;
            a = 0;
        }

        if ((b == 14 && FirstTimeType) || b == 23)
        {
            ss << hex << uselessLine.substr(3);
            ss >> temp;
            ss.str("");
            ss.clear();

            HaunterType[HaunterCount] = temp;
            FirstTimeType = 0;
            b = 0;

        }

        if (((e == 15 && FirstTimeEnum) || e == 23))
        {
            HaunterEnumArray[HaunterCount] = uselessLine.substr(3, 8);
            FirstTimeEnum = false;
            e = 0;
        }

        if ((i == 22 && FirstTime) || i == 23)
        {
            StockHaunterArray[HaunterCount] = uselessLine;
            FirstTime = false;
            i = 0;
        }

        if ((z == 24 && FirstTimePower) || (z == 23 && !FirstTimePower))
        {

            pBBand1Count[HaunterCount] = 0;
            pBBand2Count[HaunterCount] = 0;
            pBBand3Count[HaunterCount] = 0;
            pBBand4Count[HaunterCount] = 0;
            pBBand5Count[HaunterCount] = 0;
            pBBand6Count[HaunterCount] = 0;
            pBBand7Count[HaunterCount] = 0;
            pBBand8Count[HaunterCount] = 0;
            pBBand9Count[HaunterCount] = 0;
            pBBand10Count[HaunterCount] = 0;

            for (int y = 0; y < 10; y++)
            {
                ss << hex << uselessLine.substr(3);
                ss >> PowerID;
                ss.str("");
                ss.clear();
                //test << PowerID << endl;


                BandID = ReturnBandIndex(PowerID, PowerID_arr, Band_arr);

                

                //test << BandID << endl;

                switch (BandID)
                {
                case 0:
                    goto escapeBandCheck;
                case 1:
                    pBBand1Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 2:
                    pBBand2Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 3:
                    pBBand3Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 4:
                    pBBand4Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 5:
                    pBBand5Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 6:
                    pBBand6Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 7:
                    pBBand7Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 8:
                    pBBand8Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 9:
                    pBBand9Count[HaunterCount] = 1;
                    goto escapeBandCheck;
                case 10:
                    pBBand10Count[HaunterCount] = 1;
                }

            escapeBandCheck:
                std::getline(HaunterData, uselessLine);
            }

            pLBand1Count[HaunterCount] = 0;
            pLBand2Count[HaunterCount] = 0;
            pLBand3Count[HaunterCount] = 0;
            pLBand4Count[HaunterCount] = 0;
            pLBand5Count[HaunterCount] = 0;
            pLBand6Count[HaunterCount] = 0;
            pLBand7Count[HaunterCount] = 0;
            pLBand8Count[HaunterCount] = 0;
            pLBand9Count[HaunterCount] = 0;
            pLBand10Count[HaunterCount] = 0;

            for (int y = 0; y < 20; y++)
            {
                ss << hex << uselessLine.substr(3);
                ss >> PowerID;
                ss.str("");
                ss.clear();

                BandID = ReturnBandIndex(PowerID, PowerID_arr, Band_arr);


                switch (BandID)
                {
                case 0:
                    goto escapeShopBandCheck;
                case 1:
                     pLBand1Count[HaunterCount]++; 
                    goto escapeShopBandCheck;
                case 2:
                    pLBand2Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 3:
                    pLBand3Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 4:
                    pLBand4Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 5:
                    pLBand5Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 6:
                    pLBand6Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 7:
                    pLBand7Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 8:
                    pLBand8Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 9:
                    pLBand9Count[HaunterCount]++;
                    goto escapeShopBandCheck;
                case 10:
                    pLBand10Count[HaunterCount]++;
                }

            escapeShopBandCheck:
                std::getline(HaunterData, uselessLine);
            }

            

            FirstTimePower = false;

            
            HaunterFetterFlagStringArray[HaunterCount] = uselessLine.substr(3, 8);
            
            
            HaunterIDArray[HaunterCount] = HaunterCount;
            HaunterCount++;
            z = 0;
        }

        e++;
        a++;
        i++;
        z++;
        b++;
    }

    HaunterData.close();

    return HaunterCount;
}




void OutputHaunterData(string fileName, int StockHaunterCount, int HaunterCount)
{

    ifstream filein(ModsPath + "Randomiser_Backup\\" + fileName);
    ofstream fileout(ModsPath + fileName + ".Randomiser_TEMP");

    string strTemp;

    bool firstTime = true;
    bool BecomeStockHaunter = false;
    bool startCopying = false;

    int powerLine = 0;
    bool firstTimePower = 1;
    int HaunterIDCount = 0;

    int PowerCount = 0;

    int BasePowerCount = 0;

    int z = 0;

    int a = 0;
    bool FirstTimeScriptInstance = 1;
    bool dontAddToFetterArray = 0;




    for (int i = 0; filein; i++)
    {
        std::getline(filein, strTemp);

        if (strcmp(strTemp.c_str(), "[ENABLE]") == 0)
        {
            startCopying = true;
        }

        if (!startCopying)
        {
            BecomeStockHaunter = false;

            if (((a == 8 && FirstTimeScriptInstance) || a == 23))
            {
                dontAddToFetterArray = 0;
                a = 0;
                FirstTimeScriptInstance = 0;

                if (strcmp(strTemp.c_str(), "db 64 72 61 67 6F 6F 6E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") == 0)
                {
                    dontAddToFetterArray = 1;
                }

            }

            if (RandHaunters && ((i == 22 && firstTime) || (i == 23 && RandPowers) || (i == 53 && !RandPowers)))
            {
                firstTime = false;
                i = 0;
                for (int xaxa = 0; xaxa < StockHaunterCount; xaxa++)
                {
                    if (HaunterIDCount == StockHaunterArray[xaxa])
                    {
                        BecomeStockHaunter = true;
                        goto escapeLoop;
                    }
                }

            
                if (BecomeStockHaunter == true)
                {
                escapeLoop:
                    strTemp = "dd 00000001";
                }
                else
                {
                    strTemp = "dd 00000000";
                }
            }

            if ((powerLine == 24 && firstTimePower && RandPowers) || (powerLine == 23 && !firstTimePower && RandPowers) || (powerLine == 53 && !firstTimePower && !RandPowers) || (powerLine == 54 && firstTimePower && !RandPowers))
            {
                firstTimePower = 0;
                powerLine = 0;
                
                BasePowerCount = 0;

                if (RandPowers)
                {
                    if (strcmp(pB_Band1[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band1[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band2[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band2[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band3[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band3[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band4[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band4[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band5[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {

                        strTemp = pB_Band5[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band6[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band6[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band7[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band7[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band8[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band8[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band9[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band9[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }
                    if (strcmp(pB_Band10[HaunterIDCount].c_str(), "dd 00000085") != 0)
                    {
                        strTemp = pB_Band10[HaunterIDCount];
                        fileout << strTemp << endl;
                        BasePowerCount++;
                        std::getline(filein, strTemp);
                    }

                    for (z = 0; z < (10 - BasePowerCount); z++)
                    {
                        strTemp = "dd 00000085";
                        fileout << strTemp << endl;
                        std::getline(filein, strTemp);
                    }




                    strTemp = pL1_Band1[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band1[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band2[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band2[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band3[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band3[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band4[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band4[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band5[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band5[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band6[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band6[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band7[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band7[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band8[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band8[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band9[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band9[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL1_Band10[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                    strTemp = pL2_Band10[HaunterIDCount];
                    fileout << strTemp << endl;
                    std::getline(filein, strTemp);
                }

                    
              

                


                if (RandHaunterFetters && !dontAddToFetterArray)
               strTemp = "dd " + HaunterFetterFlagStringArray[HaunterIDCount];
                    
                   


                HaunterIDCount++;

            }

            powerLine++;
            a++;

        }



        fileout << strTemp << endl;
    }


}

void GetActGiftsForEachAct(string fileName)
{
    ifstream filein;
    string strTemp;
    bool StartCountingAct3Gifts = false;
    bool StartCountingAct4Gifts = false;

    filein.open(ModsPath + "Randomiser_Backup\\" + fileName);



    while (true)
    {
        std::getline(filein, strTemp);
        if (strcmp(strTemp.substr(0, 3).c_str(), "Act") == 0)
        {
            while (strTemp != "[ENABLE]")
            {
                std::getline(filein, strTemp);
                if (strcmp(strTemp.substr(0, 4).c_str(), "push") == 0)
                {
                    if (StartCountingAct4Gifts)
                        Act4GiftCount++;
                    else
                    {
                        if (!StartCountingAct3Gifts)
                            Act2GiftCount++;
                        else
                            Act3GiftCount++;
                    }
                }


                if ((strcmp(strTemp.substr(0, 3).c_str(), "jmp") == 0) && StartCountingAct3Gifts)
                {
                    StartCountingAct3Gifts = false;
                    StartCountingAct4Gifts = true;
                }

                if (strcmp(strTemp.substr(0, 3).c_str(), "jmp") == 0)
                {
                    StartCountingAct3Gifts = true;
                }
            }

            filein.close();
            break;
        }


    }

}

void RandomiseHaunterDialogue(string* DialogueHash_arr, int DialogueCount, string* vdDialogueHash_arr, int vdDialogueCount)
{
    shuffle(vdDialogueHash_arr, vdDialogueHash_arr + vdDialogueCount, default_random_engine(seed));

    int u = 0;

    for (int i = 0; i < DialogueCount; i++)
    {
        if (strcmp(DialogueHash_arr[i].c_str(), "00000000") == 0)
        {
            DialogueHash_arr[i] = vdDialogueHash_arr[u];
            u++;
        }
    }

    shuffle(DialogueHash_arr, DialogueHash_arr + DialogueCount, default_random_engine(seed));
}

void OutputNarratorSpeechHashes(string* SpeechNamesInHex)
{
    ofstream OutputASM(ModsPath + "Random_NarratorSpeech.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,3000)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "NameEntry1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[0]) << endl;
    OutputASM << "NameEntry2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[1]) << endl;
    OutputASM << "NameEntry3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[2]) << endl;

    OutputASM << "Act1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[3]) << endl;
    OutputASM << "Act2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[4]) << endl;
    OutputASM << "Act3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[5]) << endl;

    OutputASM << "ExtraCommitee3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[6]) << endl;
    OutputASM << "ExtraCommitee4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[7]) << endl;
    OutputASM << "ExtraCommitee10:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[8]) << endl;

    OutputASM << "H101_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[9]) << endl;
    OutputASM << "H101_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[10]) << endl;

    OutputASM << "WS_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[11]) << endl;
    OutputASM << "WS_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[12]) << endl;

    OutputASM << "CH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[13]) << endl;
    OutputASM << "CH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[14]) << endl;
    OutputASM << "CH_Fail:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[15]) << endl;
    OutputASM << "CH_Handyman:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[16]) << endl;
    OutputASM << "CH_Police:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[17]) << endl;
    OutputASM << "CH_Witches:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[18]) << endl;
    OutputASM << "CH_WarningFlee:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[19]) << endl;
    OutputASM << "CH_MortalCorpse1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[20]) << endl;
    OutputASM << "CH_MortalCorpse2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[21]) << endl;
    OutputASM << "CH_PoliceCorpse1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[22]) << endl;
    OutputASM << "CH_PoliceCorpse2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[23]) << endl;

    OutputASM << "SNI_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[24]) << endl;
    OutputASM << "SNI_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[25]) << endl;
    OutputASM << "SNI_Warning:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[26]) << endl;
    OutputASM << "SNI_Won:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[27]) << endl;
    OutputASM << "SNI_Update:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[28]) << endl;
    OutputASM << "SNI_MovBook:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[29]) << endl;

    OutputASM << "DF_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[30]) << endl;
    OutputASM << "DF_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[31]) << endl;
    OutputASM << "DF_Minor:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[32]) << endl;
    OutputASM << "DF_Major:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[33]) << endl;
    OutputASM << "DF_Warning:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[34]) << endl;
    OutputASM << "DF_Pump:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[35]) << endl;

    OutputASM << "US_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[36]) << endl;
    OutputASM << "US_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[37]) << endl;

    OutputASM << "FP_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[38]) << endl;
    OutputASM << "FP_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[39]) << endl;
    OutputASM << "FP_Broken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[40]) << endl;
    OutputASM << "FP_Disabled:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[41]) << endl;

    OutputASM << "PG_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[42]) << endl;
    OutputASM << "PG_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[43]) << endl;
    OutputASM << "PG_Medium:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[44]) << endl;
    OutputASM << "PG_Ghostbreaker:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[45]) << endl;
    OutputASM << "PG_Banished:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[46]) << endl;


    OutputASM << "BWP_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[47]) << endl;
    OutputASM << "BWP_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[48]) << endl;
    OutputASM << "BWP_Succeed:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[49]) << endl;
    OutputASM << "BWP_Repeat:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[50]) << endl;
    OutputASM << "BWP_Bridge:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[51]) << endl;

    OutputASM << "SH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[52]) << endl;
    OutputASM << "SH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[53]) << endl;
    OutputASM << "SH_Help9:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[54]) << endl;
    OutputASM << "SH_Help8:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[55]) << endl;
    OutputASM << "SH_Help4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[56]) << endl;

    OutputASM << "PH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[57]) << endl;
    OutputASM << "PH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[58]) << endl;
    OutputASM << "PH_Ghostbreakers:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[59]) << endl;

    OutputASM << "GB_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[60]) << endl;
    OutputASM << "GB_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[61]) << endl;
    OutputASM << "GB_ESD1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[62]) << endl;
    OutputASM << "GB_ESD2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[63]) << endl;
    OutputASM << "GB_Windwalker1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[64]) << endl;
    OutputASM << "GB_Windwalker2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[65]) << endl;
    OutputASM << "GB_Banzai1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[66]) << endl;
    OutputASM << "GB_Banzai2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[67]) << endl;
    OutputASM << "GB_BlueMurder1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[68]) << endl;
    OutputASM << "GB_BlueMurder2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[69]) << endl;
    OutputASM << "GB_Electrospasm1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[70]) << endl;
    OutputASM << "GB_Electrospasm2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[71]) << endl;
    OutputASM << "GB_Arclight1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[72]) << endl;
    OutputASM << "GB_Arclight2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[73]) << endl;
    OutputASM << "GB_Static1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[74]) << endl;
    OutputASM << "GB_Static2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[75]) << endl;
    OutputASM << "GB_Maxine1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[76]) << endl;
    OutputASM << "GB_Maxine2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[77]) << endl;
    OutputASM << "GB_GreenWardDisabled:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[78]) << endl;
    OutputASM << "GB_GreenWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[79]) << endl;
    OutputASM << "GB_BlueWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[80]) << endl;
    OutputASM << "GB_RedWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[81]) << endl;
    OutputASM << "GB_AlarmTriggered:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[82]) << endl;
    OutputASM << "GB_AlarmBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[83]) << endl;

    OutputASM << "FMJ_Intro:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[84]) << endl;
    OutputASM << "FMJ_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[85]) << endl;

    OutputASM << "CN_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[86]) << endl;
    OutputASM << "CN_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[87]) << endl;
    OutputASM << "CN_Bruce:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[88]) << endl;
    OutputASM << "CN_EZWIN:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[89]) << endl;
    OutputASM << "CN_D1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[90]) << endl;
    OutputASM << "CN_D2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[91]) << endl;
    OutputASM << "CN_DL:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[92]) << endl;

    OutputASM << "Fin1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[93]) << endl;
    OutputASM << "Fin2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[94]) << endl;
    OutputASM << "Fin3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[95]) << endl;
    OutputASM << "Fin4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[96]) << endl;
    OutputASM << "Fin5:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[97]) << endl;
    OutputASM << "Fin6:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[98]) << endl;
    OutputASM << "Fin7:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[99]) << endl;
    OutputASM << "Fin8:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[100]) << endl;
    OutputASM << "Fin9:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[101]) << endl;
    OutputASM << "Fin10:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[102]) << endl;
    OutputASM << "Fin12:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[103]) << endl;
    OutputASM << "Fin13:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[104]) << endl;
    OutputASM << "Fin14:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[105]) << endl;
    OutputASM << "Fin15:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[106]) << endl;
    OutputASM << "Fin16:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[107]) << endl;
    OutputASM << "Fin17:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[108]) << endl;
    OutputASM << "Fin18:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[109]) << endl;
    OutputASM << "Fin19:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[110]) << endl;
    OutputASM << "Fin20:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[111]) << endl;
    OutputASM << "Fin21:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[112]) << endl;
    OutputASM << "Fin23:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[113]) << endl;
    OutputASM << "Fin24:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[114]) << endl;
    OutputASM << "Fin25:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[115]) << endl;
    OutputASM << "Fin30:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[116]) << endl;
    OutputASM << "Fin31:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[117]) << endl;
    OutputASM << "Fin32:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[118]) << endl;
    OutputASM << "Fin33:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[119]) << endl;
    OutputASM << "Fin34:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[120]) << endl;
    OutputASM << "Fin35:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[121]) << endl;
    OutputASM << "Fin36:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[122]) << endl;
    OutputASM << "Fin37:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[123]) << endl;
    OutputASM << "Fin38:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[124]) << endl;
    OutputASM << "Fin39:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[125]) << endl;
    OutputASM << "Fin40:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[126]) << endl;
    OutputASM << "Fin41:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[127]) << endl;
    OutputASM << "Fin42:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[128]) << endl;
    OutputASM << "Fin43:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[129]) << endl;
    OutputASM << "Fin44:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[130]) << endl;
    OutputASM << "Fin45:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[131]) << endl;
    OutputASM << "Fin46:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[132]) << endl;
    OutputASM << "Fin47:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[133]) << endl;
    OutputASM << "Fin48:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[134]) << endl;

    OutputASM << "HogwashTakenGadget:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[135]) << endl;
    OutputASM << "BrigitLTR:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[136]) << endl;
    OutputASM << "DaydreamerLTR1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[137]) << endl;
    OutputASM << "DaydreamerLTR2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[138]) << endl;
    OutputASM << "BlueMurderLTR:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[139]) << endl;
    OutputASM << "BlueMurderMoney:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[140]) << endl;
    OutputASM << "BlueMurderFear:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[141]) << endl;
    OutputASM << "GhoulRoom1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[142]) << endl;
    OutputASM << "GhoulRoom2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[143]) << endl;
    OutputASM << "GhoulRoom3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[144]) << endl;
    OutputASM << "GhoulRoom4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[145]) << endl;
    OutputASM << "GhoulRoom5:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[146]) << endl;
    OutputASM << "GhoulRoom6:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[147]) << endl;
    OutputASM << "GhoulRoom7:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[148]) << endl;
    OutputASM << "GhoulRoom8:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[149]) << endl;
    OutputASM << "FingersRightTune:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[150]) << endl;
    OutputASM << "FingersWrongTune:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[151]) << endl;
    OutputASM << "TriciaWrongMortal:" << endl;
    OutputASM << "db " << string_to_hex(SpeechNamesInHex[152]) << endl;



    OutputASM << "00537084:" << endl;
    OutputASM << "push TriciaWrongMortal" << endl;

    OutputASM << "00518A4C:" << endl;
    OutputASM << "push FingersWrongTune" << endl;
    OutputASM << "00518A9E:" << endl;
    OutputASM << "push FingersWrongTune" << endl;



    OutputASM << "005189EE:" << endl;
    OutputASM << "push FingersRightTune" << endl;
    OutputASM << "0051918E:" << endl;
    OutputASM << "push FingersRightTune" << endl;
    OutputASM << "005191F0:" << endl;
    OutputASM << "push FingersRightTune" << endl;
    OutputASM << "00519316:" << endl;
    OutputASM << "push FingersRightTune" << endl;
    OutputASM << "00519369:" << endl;
    OutputASM << "push FingersRightTune" << endl;




    OutputASM << "008DC8BC: " << endl;
    OutputASM << "dd GhoulRoom2" << endl;


    OutputASM << "008DC8B0:" << endl;
    OutputASM << "dd GhoulRoom1" << endl;
    OutputASM << "008DC8BC: " << endl;
    OutputASM << "dd GhoulRoom2" << endl;
    OutputASM << "008DC8C8: " << endl;
    OutputASM << "dd GhoulRoom3" << endl;
    OutputASM << "008DC8D4:" << endl;
    OutputASM << "dd GhoulRoom4" << endl;
    OutputASM << "008DC8E0: " << endl;
    OutputASM << "dd GhoulRoom5" << endl;
    OutputASM << "008DC8EC: " << endl;
    OutputASM << "dd GhoulRoom6" << endl;
    OutputASM << "008DC8F8: " << endl;
    OutputASM << "dd GhoulRoom7" << endl;
    OutputASM << "008DC904: " << endl;
    OutputASM << "dd GhoulRoom8" << endl;



    OutputASM << "005359CD:" << endl;
    OutputASM << "push HogwashTakenGadget" << endl;
    OutputASM << "004E0A08: " << endl;
    OutputASM << "push BrigitLTR" << endl;
    OutputASM << "004E0FCF: " << endl;
    OutputASM << "push DaydreamerLTR1" << endl;
    OutputASM << "004E10C6: " << endl;
    OutputASM << "push DaydreamerLTR2" << endl;
    OutputASM << "00527C69: " << endl;
    OutputASM << "push BlueMurderLTR" << endl;
    OutputASM << "005277A7: " << endl;
    OutputASM << "push BlueMurderMoney" << endl;
    OutputASM << "00527747: " << endl;
    OutputASM << "push BlueMurderFear" << endl;






    OutputASM << "00440CD3:" << endl;
    OutputASM << "push NameEntry1" << endl;
    OutputASM << "004416DA: " << endl;
    OutputASM << "push NameEntry2" << endl;
    OutputASM << "00441719: " << endl;
    OutputASM << "push NameEntry3" << endl;

    OutputASM << "00441CFE:" << endl;
    OutputASM << "mov [009468BC],Act1" << endl;
    OutputASM << "00441BF7: " << endl;
    OutputASM << "mov [009468BC],Act2" << endl;
    OutputASM << "00441BF7: " << endl;
    OutputASM << "mov [009468BC],Act2" << endl;
    OutputASM << "00441C58: " << endl;
    OutputASM << "mov [009468BC],Act3" << endl;
    OutputASM << "00441C77: " << endl;
    OutputASM << "mov [009468BC],Act3" << endl;

    OutputASM << "00526B33:" << endl;
    OutputASM << "push ExtraCommitee3" << endl;
    OutputASM << "005270DD:" << endl;
    OutputASM << "push ExtraCommitee3" << endl;

    OutputASM << "00526689: " << endl;
    OutputASM << "push ExtraCommitee4" << endl;
    OutputASM << "00526338: " << endl;
    OutputASM << "push ExtraCommitee4" << endl;
    OutputASM << "00526E8D: " << endl;
    OutputASM << "push ExtraCommitee4" << endl;

    OutputASM << "005065C5: " << endl;
    OutputASM << "push ExtraCommitee10" << endl;

    OutputASM << "005325B4: " << endl;
    OutputASM << "push H101_Intro1" << endl;
    OutputASM << "005325C8: " << endl;
    OutputASM << "push H101_Intro2" << endl;

    OutputASM << "005538B5: " << endl;
    OutputASM << "push WS_Intro1" << endl;
    OutputASM << "005538C9: " << endl;
    OutputASM << "push WS_Intro2" << endl;

    OutputASM << "0050631B: " << endl;
    OutputASM << "push CH_Intro1" << endl;
    OutputASM << "0050632F: " << endl;
    OutputASM << "push CH_Intro2" << endl;
    OutputASM << "00506639: " << endl;
    OutputASM << "push CH_Fail" << endl;
    OutputASM << "0050F2E2: " << endl;
    OutputASM << "push CH_Handyman" << endl;
    OutputASM << "00506BE2: " << endl;
    OutputASM << "push CH_Police" << endl;
    OutputASM << "00508907: " << endl;
    OutputASM << "push CH_Witches" << endl;
    OutputASM << "005067BB: " << endl;
    OutputASM << "push CH_WarningFlee" << endl;
    OutputASM << "005064E4: " << endl;
    OutputASM << "push CH_MortalCorpse1" << endl;
    OutputASM << "005064DD: " << endl;
    OutputASM << "push CH_MortalCorpse1" << endl;
    OutputASM << "00506552: " << endl;
    OutputASM << "push CH_PoliceCorpse1" << endl;
    OutputASM << "00506621: " << endl;
    OutputASM << "push CH_PoliceCorpse2" << endl;
    OutputASM << "00506794: " << endl;
    OutputASM << "push CH_PoliceCorpse2" << endl;
    OutputASM << "00506851: " << endl;
    OutputASM << "dd CH_PoliceCorpse2" << endl;

    OutputASM << "004F7ACD: " << endl;
    OutputASM << "push SNI_Intro1" << endl;
    OutputASM << "004F7AE1: " << endl;
    OutputASM << "push SNI_Intro2" << endl;
    OutputASM << "004ECA66: " << endl;
    OutputASM << "push SNI_Warning" << endl;
    OutputASM << "004FB78B: " << endl;
    OutputASM << "push SNI_Won" << endl;
    OutputASM << "004FB7A9: " << endl;
    OutputASM << "push SNI_Won" << endl;
    OutputASM << "004FCE79: " << endl;
    OutputASM << "push SNI_Update" << endl;
    OutputASM << "004FD7CA: " << endl;
    OutputASM << "push SNI_MovBook" << endl;

    OutputASM << "00516F21: " << endl;
    OutputASM << "push DF_Intro1" << endl;
    OutputASM << "00516F35: " << endl;
    OutputASM << "push DF_Intro2" << endl;
    OutputASM << "005173C4: " << endl;
    OutputASM << "push DF_Minor" << endl;
    OutputASM << "005173FE: " << endl;
    OutputASM << "push DF_Major" << endl;
    OutputASM << "005174A2: " << endl;
    OutputASM << "push DF_Warning" << endl;
    OutputASM << "005177F4: " << endl;
    OutputASM << "push DF_Pump" << endl;

    OutputASM << "0052E084: " << endl;
    OutputASM << "push US_Intro1" << endl;
    OutputASM << "0052E098: " << endl;
    OutputASM << "push US_Intro2" << endl;

    OutputASM << "0053CA21: " << endl;
    OutputASM << "push FP_Intro1" << endl;
    OutputASM << "0053CA35: " << endl;
    OutputASM << "push FP_Intro2" << endl;
    OutputASM << "00538CD9: " << endl;
    OutputASM << "push FP_Broken" << endl;
    OutputASM << "00539304: " << endl;
    OutputASM << "push FP_Broken" << endl;
    OutputASM << "00539736: " << endl;
    OutputASM << "push FP_Broken" << endl;
    OutputASM << "00539025: " << endl;
    OutputASM << "push FP_Disabled" << endl;
    OutputASM << "00539035: " << endl;
    OutputASM << "push FP_Disabled" << endl;
    OutputASM << "0053954E: " << endl;
    OutputASM << "push FP_Disabled" << endl;
    OutputASM << "00539562: " << endl;
    OutputASM << "push FP_Disabled" << endl;

    OutputASM << "0050A06B: " << endl;
    OutputASM << "push PG_Intro1" << endl;
    OutputASM << "0050A07F: " << endl;
    OutputASM << "push PG_Intro2" << endl;
    OutputASM << "0050A5AB: " << endl;
    OutputASM << "push PG_Ghostbreaker" << endl;
    OutputASM << "0050A224: " << endl;
    OutputASM << "push PG_Banished" << endl;
    OutputASM << "0050AD9C: " << endl;
    OutputASM << "push PG_Medium" << endl;

    OutputASM << "004DF6E2: " << endl;
    OutputASM << "push PH_Intro1" << endl;
    OutputASM << "004DF6F6: " << endl;
    OutputASM << "push PH_Intro2" << endl;
    OutputASM << "004E19D0: " << endl;
    OutputASM << "push PH_Ghostbreakers" << endl;



    OutputASM << "004EC404: " << endl;
    OutputASM << "push BWP_Intro1" << endl;
    OutputASM << "004EC418: " << endl;
    OutputASM << "push BWP_Intro2" << endl;
    OutputASM << "004F5424: " << endl;
    OutputASM << "push BWP_Succeed" << endl;
    OutputASM << "004F5442: " << endl;
    OutputASM << "push BWP_Succeed" << endl;
    OutputASM << "004EC917: " << endl;
    OutputASM << "push BWP_Repeat" << endl;
    OutputASM << "004EC9B3: " << endl;
    OutputASM << "push BWP_Bridge" << endl;

    OutputASM << "0054A8DD: " << endl;
    OutputASM << "push SH_Intro1" << endl;
    OutputASM << "0054A8F2: " << endl;
    OutputASM << "push SH_Intro2" << endl;
    OutputASM << "005420E5: " << endl;
    OutputASM << "push SH_Help9" << endl;
    OutputASM << "00541E4E: " << endl;
    OutputASM << "push SH_Help8" << endl;
    OutputASM << "0054672E: " << endl;
    OutputASM << "push SH_Help4" << endl;

    OutputASM << "0052198B: " << endl;
    OutputASM << "push GB_Intro1" << endl;
    OutputASM << "0052199F: " << endl;
    OutputASM << "push GB_Intro2" << endl;
    OutputASM << "0051F142: " << endl;
    OutputASM << "push GB_ESD1" << endl;
    OutputASM << "0051F3E9: " << endl;
    OutputASM << "push GB_ESD1" << endl;
    OutputASM << "0051E96D: " << endl;
    OutputASM << "push GB_ESD2" << endl;
    OutputASM << "0051F5D0: " << endl;
    OutputASM << "push GB_ESD2" << endl;
    OutputASM << "0051EB5B: " << endl;
    OutputASM << "push GB_Windwalker1" << endl;
    OutputASM << "0051EB6A: " << endl;
    OutputASM << "push GB_Windwalker2" << endl;
    OutputASM << "0051EB33: " << endl;
    OutputASM << "push GB_Banzai1" << endl;
    OutputASM << "0051EB3D: " << endl;
    OutputASM << "push GB_Banzai2" << endl;
    OutputASM << "0051EAFE: " << endl;
    OutputASM << "push GB_BlueMurder1" << endl;
    OutputASM << "0051EB0D: " << endl;
    OutputASM << "push GB_BlueMurder2" << endl;
    OutputASM << "0051EAD1: " << endl;
    OutputASM << "push GB_Electrospasm1" << endl;
    OutputASM << "0051EAE0: " << endl;
    OutputASM << "push GB_Electrospasm2" << endl;
    OutputASM << "0051EA4A: " << endl;
    OutputASM << "push GB_Arclight1" << endl;
    OutputASM << "0051EA59: " << endl;
    OutputASM << "push GB_Arclight2" << endl;
    OutputASM << "0051EA77: " << endl;
    OutputASM << "push GB_Static1" << endl;
    OutputASM << "0051EA86: " << endl;
    OutputASM << "push GB_Static2" << endl;
    OutputASM << "0051EAA4: " << endl;
    OutputASM << "push GB_Maxine1" << endl;
    OutputASM << "0051EAB3: " << endl;
    OutputASM << "push GB_Maxine2" << endl;
    OutputASM << "0051E7AE: " << endl;
    OutputASM << "push GB_GreenWardDisabled" << endl;
    OutputASM << "0051E6FF: " << endl;
    OutputASM << "push GB_GreenWardBroken" << endl;
    OutputASM << "0051E3B0: " << endl;
    OutputASM << "push GB_BlueWardBroken" << endl;
    OutputASM << "0051F058: " << endl;
    OutputASM << "push GB_RedWardBroken" << endl;
    OutputASM << "0051D616: " << endl;
    OutputASM << "push GB_AlarmTriggered" << endl;
    OutputASM << "0051D87A: " << endl;
    OutputASM << "push GB_AlarmTriggered" << endl;
    OutputASM << "0051D347: " << endl;
    OutputASM << "push GB_AlarmBroken" << endl;

    OutputASM << "004D08B2: " << endl;
    OutputASM << "push FMJ_Intro" << endl;
    OutputASM << "004D08C6: " << endl;
    OutputASM << "push FMJ_Intro2" << endl;


    OutputASM << "004D9346: " << endl;
    OutputASM << "push CN_Intro1" << endl;
    OutputASM << "004D935A: " << endl;
    OutputASM << "push CN_Intro2" << endl;
    OutputASM << "004DB838: " << endl;
    OutputASM << "push CN_Bruce" << endl;
    OutputASM << "004DB692: " << endl;
    OutputASM << "push CN_EZWIN" << endl;
    OutputASM << "004DA968: " << endl;
    OutputASM << "push CN_D1" << endl;
    OutputASM << "004DA989: " << endl;
    OutputASM << "push CN_D2" << endl;
    OutputASM << "004DA9A4: " << endl;
    OutputASM << "push CN_DL" << endl;


    OutputASM << "0055F557: " << endl;
    OutputASM << "push Fin1" << endl;
    OutputASM << "0055F56B: " << endl;
    OutputASM << "push Fin2" << endl;
    OutputASM << "00558761: " << endl;
    OutputASM << "push Fin3" << endl;
    OutputASM << "00558744: " << endl;
    OutputASM << "push Fin3" << endl;
    OutputASM << "0055BE00: " << endl;
    OutputASM << "push Fin4" << endl;
    OutputASM << "0055BF22: " << endl;
    OutputASM << "push Fin4" << endl;
    OutputASM << "0055B631: " << endl;
    OutputASM << "push Fin5" << endl;
    OutputASM << "0055B653: " << endl;
    OutputASM << "push Fin6" << endl;
    OutputASM << "0055B66D: " << endl;
    OutputASM << "push Fin6" << endl;
    OutputASM << "0055BF35: " << endl;
    OutputASM << "push Fin7" << endl;
    OutputASM << "0055B6B5: " << endl;
    OutputASM << "push Fin8" << endl;
    OutputASM << "0055BD6E: " << endl;
    OutputASM << "push Fin9" << endl;
    OutputASM << "00576FD5: " << endl;
    OutputASM << "push Fin10" << endl;
    OutputASM << "0055A362: " << endl;
    OutputASM << "push Fin12" << endl;
    OutputASM << "0055A437: " << endl;
    OutputASM << "push Fin12" << endl;
    OutputASM << "0055A48A: " << endl;
    OutputASM << "push Fin12" << endl;
    OutputASM << "0055A4EF: " << endl;
    OutputASM << "push Fin13" << endl;
    OutputASM << "00557FD7: " << endl;
    OutputASM << "push Fin14" << endl;
    OutputASM << "00558060: " << endl;
    OutputASM << "push Fin15" << endl;
    OutputASM << "00557EA0: " << endl;
    OutputASM << "push Fin16" << endl;
    OutputASM << "0055822E: " << endl;
    OutputASM << "push Fin17" << endl;
    OutputASM << "00556214: " << endl;
    OutputASM << "push Fin18" << endl;
    OutputASM << "00556263: " << endl;
    OutputASM << "push Fin19" << endl;
    OutputASM << "0055ABA6: " << endl;
    OutputASM << "push Fin20" << endl;
    OutputASM << "0055ADF1: " << endl;
    OutputASM << "push Fin21" << endl;
    OutputASM << "0055621B: " << endl;
    OutputASM << "push Fin23" << endl;
    OutputASM << "0055626A: " << endl;
    OutputASM << "push Fin24" << endl;
    OutputASM << "0055AC1B: " << endl;
    OutputASM << "push Fin25" << endl;
    OutputASM << "0055B149: " << endl;
    OutputASM << "push Fin30" << endl;
    OutputASM << "0055B155: " << endl;
    OutputASM << "push Fin31" << endl;
    OutputASM << "0055B16B: " << endl;
    OutputASM << "push Fin32" << endl;
    OutputASM << "0055B181: " << endl;
    OutputASM << "push Fin33" << endl;
    OutputASM << "0055B197: " << endl;
    OutputASM << "push Fin34" << endl;
    OutputASM << "0055B1AD: " << endl;
    OutputASM << "push Fin35" << endl;
    OutputASM << "0055B1C3: " << endl;
    OutputASM << "push Fin36" << endl;
    OutputASM << "0055B1D9: " << endl;
    OutputASM << "push Fin37" << endl;
    OutputASM << "0055B1EF: " << endl;
    OutputASM << "push Fin38" << endl;
    OutputASM << "0055B205: " << endl;
    OutputASM << "push Fin39" << endl;
    OutputASM << "0055B21B: " << endl;
    OutputASM << "push Fin40" << endl;
    OutputASM << "0055B237: " << endl;
    OutputASM << "push Fin41" << endl;
    OutputASM << "0055B253: " << endl;
    OutputASM << "push Fin42" << endl;
    OutputASM << "0055B26F: " << endl;
    OutputASM << "push Fin43" << endl;
    OutputASM << "0055B28B: " << endl;
    OutputASM << "push Fin44" << endl;
    OutputASM << "0055B2A7: " << endl;
    OutputASM << "push Fin45" << endl;
    OutputASM << "0055C5D6: " << endl;
    OutputASM << "push Fin46" << endl;
    OutputASM << "0055C812: " << endl;
    OutputASM << "push Fin47" << endl;
    OutputASM << "0055C64B: " << endl;
    OutputASM << "push Fin48" << endl;






    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();


}

string string_to_hex(const string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
        output += " ";
    }
    return output + "00";
}



void OutputActGifts(string fileName)
{

    if (!RandHaunters)
        return;

    ifstream filein(ModsPath + "Randomiser_Backup\\" + fileName);
    ofstream fileout(ModsPath + fileName + ".Randomiser_TEMP");

    string strTemp;

    int HaunterCount = 0;
    bool firstTime = true;

    bool Act2GiftsExist = false;
    bool Act3GiftsExist = false;
    bool Act4GiftsExist = false;

    if (Act2GiftCount > 0)
    {
        Act2GiftsExist = true;
    }

    if (Act3GiftCount > 0)
    {
        Act3GiftsExist = true;
    }

    if (Act4GiftCount > 0)
    {
        Act4GiftsExist = true;
    }


    for (int i = 0; i < 13; i++) //Until Act2
    {
        std::getline(filein, strTemp);
        strTemp += "\n";
        fileout << strTemp;
    }

    for (int i = 1; Act2GiftCount > 0; i++) //Act2
    {
        std::getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act2GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    int loopTimes = 2;

    if (Act2GiftsExist)
        loopTimes = 4;

    for (int i = 0; i < loopTimes; i++) //Between
    {
        std::getline(filein, strTemp);
        strTemp += "\n";
        fileout << strTemp;
    }




    for (int i = 1; Act3GiftCount > 0; i++) //Act3
    {
        std::getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act3GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    if (Act3GiftsExist)
        loopTimes = 5;
    else
        loopTimes = 3;


    for (int i = 0; i < loopTimes; i++) //Between
    {
        std::getline(filein, strTemp);
        strTemp += "\n";
        fileout << strTemp;
    }




    for (int i = 1; Act4GiftCount > 0; i++) //Act4
    {
        std::getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act4GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    if (Act4GiftsExist)
        loopTimes = 29;
    else
        loopTimes = 27;

    for (int i = 0; i < loopTimes; i++) //After
    {
        std::getline(filein, strTemp);
        strTemp += "\n";
        fileout << strTemp;
    }

}



void SubtractActGifts(int TotalGiftCount, int StockHaunterCount)
{
    int u = 0;

    for (int i = TotalGiftCount; i < (TotalGiftCount + StockHaunterCount); i++)
    {
        StockHaunterArray[u] = StockHaunterAndActGiftIDArray[i];
        u++;
    }
}



int GetCountOfOtherHauntersAndSubtractRestlessSpirits(int HaunterCount)
{
    int u = 0;
    for (int i = 25; i < HaunterCount - 8; i++)
    {
        StockHaunterAndActGiftIDArray[u] = RemainingRestlessSpiritIDArray[i];
        u++;
    }

    return u;

}




void GetRandomScenarioOrder(int ScenarioIndexes[])
{

    if (ScenarioUnfair)
    {


        int TempArray[20] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15 }; //Scenario indexes that dont matter when they appear

        


        int size = 15;

        shuffle(TempArray, TempArray + 12, default_random_engine(seed));

        bool Summoners = false;
        bool BlairWisp = false;
        bool CuckoosNestInAlready = false;


        int test[15]{};

        int ScenarioCount = 13;

        int a = 0;
        int b = 0;
        int j = 0;

        for (int i = 0; i < size; i++)
        {


            if (TempArray[i] == 4)
                Summoners = true;
            if (TempArray[i] == 10)
                BlairWisp = true;
            if (TempArray[i] == 3)
            {

                test[0] = 8;
                a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }

                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }

                ScenarioCount++;
            }

            if (TempArray[i] == 6)
            {
                test[0] = 12;
                a = 1;
                while ((i + a) < ScenarioCount)
                {

                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
            }

            if ((Summoners == true && BlairWisp && true) && CuckoosNestInAlready != true)
            {
                test[0] = 14;
                a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
                CuckoosNestInAlready = true;
            }

        }

        for (int i = 0; i < 15; i++)
        {
            ScenarioIndexes[i] = TempArray[i] - 1;
        }

    }
    else
    {

        int TempArray[20]{ 1, 2, 3, 4, 5, 6, 7, 9, 13 };
        int TempArraySize = 9;


        int size = 15;

        shuffle(TempArray, TempArray + TempArraySize, default_random_engine(seed));

        bool Summoners = false;
        bool BlairWisp = false;
        bool UnusualIn = false;
        bool CuckoosNestInAlready = false;
        bool GhostbrIn = false;


        int test[15]{};

        int a = 0;
        int b = 0;
        int c = 0;
        int j = 0;

        int ScenarioCount = TempArraySize + 1;

        for (int i = 0; i < size; i++)
        {

            if (i == 4)
            {
                test[0] = 10;
                test[1] = 11;
                test[2] = 15;
                a = 3;
                c = 1;
                while ((i + c) < ScenarioCount)
                {
                    test[a] = TempArray[i + c];
                    //cout << test[a] << endl;
                    a++;
                    c++;
                }

                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < (ScenarioCount + 2))
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }

                ScenarioCount += 3;
            }


            if (TempArray[i] == 4)
                Summoners = true;
            if (TempArray[i] == 10)
                BlairWisp = true;
            if (TempArray[i] == 3)
            {

                test[0] = 8;
                a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }

                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }

                ScenarioCount++;
            }

            if (TempArray[i] == 6)
            {
                UnusualIn = true;
            }

            if (i > 3 && UnusualIn == true && GhostbrIn == false)
            {
                GhostbrIn = true;
                test[0] = 12;
                a = 1;
                while ((i + a) < ScenarioCount)
                {

                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
            }

            if ((Summoners == true && BlairWisp && true) && CuckoosNestInAlready == false)
            {
                test[0] = 14;
                a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                b = i + 1;
                j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
                CuckoosNestInAlready = true;
            }



        }

        

        for (int i = 0; i < 15; i++)
        {
            ScenarioIndexes[i] = TempArray[i] - 1;
            //cout << ScenarioIndexes[i] << endl;
        }



    }


}

int GetDialogueHashesAndCountASM(string DialogueHash_arr[])
{
    ifstream ASM_input(ModsPath + "Randomiser_Backup\\" + "SoundSubtitles.asm");


    string TempString;

    int i = 0;

    while (TempString != "[ENABLE]")
    {
        std::getline(ASM_input, TempString);
        if (strcmp(TempString.substr(0, 2).c_str(), "db") == 0)
        {
            TempString = TempString.substr(3, 11);
            std::string::iterator end_pos = std::remove(TempString.begin(), TempString.end(), ' ');
            TempString.erase(end_pos, TempString.end());

            DialogueHash_arr[i] = TempString;
            //cout << DialogueHash_arr[i] << endl;
            i++;
        }
    }

    ASM_input.close();

    return i;
}

string GetPathToEnglishVdTxt()
{
    int i = 0;
    char temp = ModsPath[i];
    int BackslashCount = 0;
    while (temp)
    {
        temp = ModsPath[i];
        if (temp == '\\')
        {
            BackslashCount++;
        }
        i++;
    }

    //cout << BackslashCount << " This is the backslash count :) " << endl;

    int BackslashTreshold = BackslashCount - 2;
    BackslashCount = 0;

    string NewPath = "";

    for (int i = 0; BackslashCount != BackslashTreshold; i++)
    {
        if (ModsPath[i] == '\\')
            BackslashCount++;

        NewPath += ModsPath[i];
    }

    NewPath += "voice\\english\\english_vd.txt";

    ifstream CheckIfExists;
    CheckIfExists.open(NewPath);
    if (!CheckIfExists)
    {
        CheckIfExists.close();
        wxMessageBox("Softlock Fix/Random Dialogue error: Couldn't find voice\\english\\english_vd.txt\nIs the mod you are randomising located in 'GhostData/Mods/<yourModName>'?");
        return "";
    }
    else
    {
        CheckIfExists.close();
        return NewPath;
    }

}

int GetDialogueHashesTXTAndCount(string NewPath, string* vdDialogueHash_arr, string* SpeechName) 
{

    ifstream inputTXT(NewPath);

    string TempString;

    char checker;

    int hashCount = 0;

    stringstream ss;

    
        while (inputTXT) {

            std::getline(inputTXT, TempString);

            if (
                TempString[0]
                && TempString[0] != '#'
                && (DialogueIncludeTutorial || TempString.substr(0, 9) != "TUTORIAL_")
                ) {

                checker = TempString[0];
                int CharacterCountTillFirstComma = 0;

                while (checker != ',') {
                    checker = TempString[CharacterCountTillFirstComma];
                    CharacterCountTillFirstComma++;
                }



                TempString = TempString.substr(0, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(CharacterCountTillFirstComma) - 1);

                SpeechName[hashCount] = TempString;


                //cout << lalala << endl;

                
                ss << hex << crc32(TempString.c_str());
                string Hash(ss.str());
                ss.str("");
                ss.clear();

                std::transform(Hash.begin(), Hash.end(), Hash.begin(), ::toupper);

                vdDialogueHash_arr[hashCount] = LE2BE(Hash);
                //cout << vdDialogueHash_arr[hashCount] << endl;
                hashCount++;

            }
        }
   



    shuffle(SpeechName, SpeechName + hashCount, default_random_engine(seed + 69));

    return hashCount;

}

size_t crc32bin(const char* byte, size_t ArrayLenght)
{
    unsigned int Hash;
    unsigned int i;

    Hash = 0;

    for (i = 0; i < ArrayLenght; ++i)
    {
        Hash = crc_table[(Hash >> 24) ^ (unsigned __int8)byte[i]] ^ (Hash << 8);
    }
    return ArrayLenght ^ Hash;
}

size_t crc32(const char* String)
{
    return crc32bin(String, strlen(String));
}

void ClearSoundSubtitles(string* DialogueHash_arr, string* vdDialogueHash_arr, int vdDialogueCount, int DialogueCount)
{



    int u = 0;

    bool hashFound = false;

    while (u < DialogueCount)
    {
        int i = 0;

        hashFound = false;

        while (i < vdDialogueCount)
        {
            if (strcmp(DialogueHash_arr[u].c_str(), "00000000") == 0)
            {
                if (strcmp(DialogueHash_arr[u].c_str(), vdDialogueHash_arr[i].c_str()) == 0)
                {
                    hashFound = true;
                    goto PerformCheck;
                }
            }


            i++;
        }

    PerformCheck:
        if (hashFound == true)
        {
            DialogueHash_arr[u] = vdDialogueHash_arr[i];
        }

        else
        {
            DialogueHash_arr[u] = "00000000";
        }

        u++;


    }


}

int OutputSoundSubtitles(string* DialogueHash_arr, int DialogueCount)
{
    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "SoundSubtitles.asm");
    ofstream asmOut(ModsPath + "SoundSubtitles.asm.Randomiser_TEMP");

    string TempString = "";
    string Lalala;

    int i = 0;


    while (TempString != "[ENABLE]")
    {
        std::getline(asmIn, TempString);
        if (strcmp(TempString.substr(0, 2).c_str(), "db") == 0)
        {
            Lalala = DialogueHash_arr[i];
            asmOut << "db " << Lalala[0] << Lalala[1] << " " << Lalala[2] << Lalala[3] << " "
                << Lalala[4] << Lalala[5] << " " << Lalala[6] << Lalala[7] << endl;
            i++;
        }
        else
        {
            asmOut << TempString << endl;
        }


    }

    while (asmIn)
    {
        std::getline(asmIn, TempString);
        asmOut << TempString << endl;
    }

    return i;

}



void GetSpecialHaunters(int HaunterCount)
{
    
        int i = 0;
        int j = 0;
        int u = 0;
        int TempArray[100]{};
        int TempArray2[100]{};
        int fetter_flags = 0;

        stringstream ss;

        for (i = 0; i < HaunterCount; i++)
        {
            if (HasManifestPowerBaseKitArray[HaunterIDArray[i]] == 1 && 
                strcmp(HaunterScriptInstanceArray[i].c_str(), "64 72 61 67 6F 6F 6E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") != 0)
            {
                TempArray[j] = HaunterIDArray[i];
                pB_Band3[TempArray[j]] = "dd 0000003E";
                j++;
            }
        }

        if (j < 3)
        {


            GetSpecialHaunters__GetAnyHaunter(3, TempArray, HaunterCount, j);
            shuffle(TempArray, TempArray + 3, default_random_engine(seed));

            for (int i1 = j; i1 < 3; i1++)
            {
                pB_Band3[TempArray[i1]] = "dd 0000003E";
            }



            
        }
        else
        {
            shuffle(TempArray, TempArray + j, default_random_engine(seed));
        }

        SpecialHaunters[0] = TempArray[0];
        SpecialHaunters[1] = TempArray[1];
        SpecialHaunters[2] = TempArray[2];



        for (i = 0; i < HaunterCount; i++)
        {
            if (((HaunterIDArray[i] != SpecialHaunters[0]) && (HaunterIDArray[i] != SpecialHaunters[1]) && (HaunterIDArray[i] != SpecialHaunters[2])) && strcmp(HaunterScriptInstanceArray[i].c_str(), "64 72 61 67 6F 6F 6E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00") != 0)
            {
                TempArray[u] = HaunterIDArray[i];
                u++;
            }
        }

        u = 0;


        for (i = 0; i < (HaunterCount - 4); i++)
        {
            ss << hex << HaunterFetterFlagStringArray[(TempArray[i])];
            ss >> fetter_flags;
            ss.str("");
            ss.clear();


            if (fetter_flags & 0x8 && HaunterType[TempArray[i]] != 0x12) //has fire fetter AND not headless horsemen
            {
                TempArray2[u] = TempArray[i];
                u++;
            }
        }

        if (u < 1)
        {
            GetSpecialHaunters__GetAnyHaunter(1, TempArray2, HaunterCount, u);

        }
        else
        {
            shuffle(TempArray2, TempArray2 + u, default_random_engine(seed));
        }

        SpecialHaunters[3] = TempArray2[0]; //fire

        u = 0;

        for (i = 0; i < (HaunterCount - 4); i++)
        {
            if (TempArray[i] != SpecialHaunters[3])
            {
                TempArray2[u] = TempArray[i];
                u++;
            }
        }

        u = 0;

        for (i = 0; i < (HaunterCount - 5); i++)
        {
            ss << hex << HaunterFetterFlagStringArray[(TempArray2[i])];
            ss >> fetter_flags;
            ss.str("");
            ss.clear();

            if (fetter_flags & 0x40)
            {
                TempArray[u] = TempArray2[i];
                //cout << TempArray3[u] << " CHILD HAUNTER IDs" << endl;
                u++;
            }
        }

        if (u < 2)
        {
            GetSpecialHaunters__GetAnyHaunter(2, TempArray, HaunterCount, u);
            shuffle(TempArray, TempArray + 2, default_random_engine(seed));
        }
        else
        {
            shuffle(TempArray, TempArray + u, default_random_engine(seed));
        }


        SpecialHaunters[4] = TempArray[0]; //child
        SpecialHaunters[5] = TempArray[1];
        u = 0;

        for (i = 0; i < (HaunterCount - 5); i++)
        {
            if (TempArray2[i] != SpecialHaunters[4] && TempArray2[i] != SpecialHaunters[5])
            {
                TempArray[u] = TempArray2[i];
                u++;
            }
        }

        u = 0;
        for (i = 0; i < (HaunterCount - 7); i++)
        {

            ss << hex << HaunterFetterFlagStringArray[(TempArray[i])];
            ss >> fetter_flags;
            ss.str("");
            ss.clear();

            if (fetter_flags & 0x1)
            {
                TempArray2[u] = TempArray[i];
                u++;
            }
        }

        if (u < 1)
        {
            GetSpecialHaunters__GetAnyHaunter(1, TempArray2, HaunterCount, u);
            shuffle(TempArray2, TempArray2 + 1, default_random_engine(seed));
        }
        else
        {
            shuffle(TempArray2, TempArray2 + u, default_random_engine(seed));
        }

        SpecialHaunters[6] = TempArray2[0]; //electrical

        u = 0;


        for (i = 0; i < (HaunterCount - 7); i++)
        {
            if (TempArray[i] != SpecialHaunters[6])
            {
                RemainingRestlessSpiritIDArray[u] = TempArray[i];
                //cout << RemainingRestlessSpiritsIDArray[u] << endl;
                u++;
            }
        }
}

void GetSpecialHaunters__GetAnyHaunter(int neededHaunters, int* ReturningArray, int HaunterCount, int currentHaunters)
{
    bool alreadyExists = 0;
    int x = 0;
    int a = 0;

    while (currentHaunters < neededHaunters)
    {
        alreadyExists = 0;

        for (x = 0; x < HaunterCount; x++)
        {
            for (a = 0; a < currentHaunters; a++)
            {
                if (HaunterIDArray[x] == ReturningArray[a] && !alreadyExists)
                {
                    alreadyExists = 1;

                }
            }

            if (!alreadyExists)
            {
                ReturningArray[currentHaunters] = HaunterIDArray[x];
                currentHaunters++;
            }
        }
    }
}




void RandScenario_Haunting101()
{
    ofstream OutputASM(ModsPath + "Random_Haunting101.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DC7B8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << endl;
    OutputASM << "0053D158: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << "0053D1A7: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_WeirdSeance()
{
    ofstream OutputASM(ModsPath + "Random_WeirdSeance.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[1])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[2])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[3])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008E4308: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "005517E0: " << endl;
    OutputASM << "mov [008E4318]," << "ghostSI2" << endl;
    OutputASM << "005517EA: " << endl;
    OutputASM << "mov [008E4328]," << "ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << "00554061: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[1])] << endl;
    OutputASM << endl;
    OutputASM << "00554081: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "00550231: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[3])] << endl;
    OutputASM << endl;
    OutputASM << "00550298: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << "00554521: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[2])] << endl;
    OutputASM << endl;
    OutputASM << "0055462C: " << endl;
    OutputASM << "push ghostSI2" << endl;



    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Calamityville()
{
    ofstream OutputASM(ModsPath + "Random_Calamityville.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[4])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[6])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D5B90: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00504120: " << endl;
    OutputASM << "mov [008D5BA0]," << "ghostSI2" << endl;
    OutputASM << "0050412A: " << endl;
    OutputASM << "mov [008D5BB0]," << "ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << endl;
    OutputASM << "005124E1: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00510DF0: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[4])] << endl;


    OutputASM << "0050E08F: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[5])] << endl;
    OutputASM << endl;
    OutputASM << "0050E0EE: " << endl;
    OutputASM << "push ghostSI2" << endl;

    OutputASM << endl;
    OutputASM << "0050FD52: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "0050FD81: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[6])] << endl;


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Summoners()
{
    ofstream OutputASM(ModsPath + "Random_Summoners.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << "label(CrashFix1)" << endl;
    OutputASM << "label(CrashFix2)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl; //Darkling
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[0])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[8])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[9])] << endl;
    OutputASM << "CrashFix1:" << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "test eax,eax" << endl;
    OutputASM << "jne 0073FC8C" << endl;
    OutputASM << "push 00909108" << endl;
    OutputASM << "jmp 0073FC7C" << endl;

    OutputASM << "CrashFix2:" << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "test eax,eax" << endl;
    OutputASM << "jne 0073FCA3" << endl;
    OutputASM << "push 00909108" << endl;
    OutputASM << "jmp 0073FC93" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D3D08: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004F6383: " << endl;
    OutputASM << "mov [008D3D18]," << "ghostSI2" << endl;
    OutputASM << "mov [008D3D28]," << "ghostSI3" << endl;
    OutputASM << "mov [008D3D38]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "004F7B6E: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "004FAAF1: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << endl;

    OutputASM << "004FBE18: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[0])] << endl;
    OutputASM << "004FBE3D: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "005027B3: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[0])] << endl;
    OutputASM << "005027E4: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "004F84FF: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[8])] << endl;
    OutputASM << "004F8518: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << endl;
    OutputASM << "004F80D7: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "004F80E5: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "00500DF8: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "00500DB1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[9])] << endl;

    OutputASM << "0073FC87: " << endl;
    OutputASM << "jmp CrashFix1" << endl;

    OutputASM << "0073FC9E: " << endl;
    OutputASM << "jmp CrashFix2" << endl;


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Deadfellas()
{
    ofstream OutputASM(ModsPath + "Random_Deadfellas.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[10])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[11])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[12])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[13])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D8408: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00514E62: " << endl;
    OutputASM << "mov [008D8418]," << "ghostSI2" << endl;
    OutputASM << "mov [008D8428]," << "ghostSI3" << endl;
    OutputASM << "mov [008D8438]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "00518443: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00518C6A: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00518C1A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[10])] << endl;

    OutputASM << "00519967: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "00519F51: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[11])] << endl;
    OutputASM << "00519F86: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "0051A25A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[12])] << endl;
    OutputASM << "0051A277: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << endl;
    OutputASM << "0051A98A: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0051A977: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[13])] << endl;


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Facepacks()
{
    ofstream OutputASM(ModsPath + "Random_Facepacks.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[3])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[14])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[6])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DF118: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "0053BD12: " << endl;
    OutputASM << "mov [008DF128]," << "ghostSI2" << endl; //mirage
    OutputASM << "mov [008DF138]," << "ghostSI3" << endl; //hogwash
    OutputASM << "mov [008DF148]," << "ghostSI4" << endl; //weatherwitch
    OutputASM << endl;

    OutputASM << "00535651: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[3])] << endl;
    OutputASM << "00535670: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "005386EE: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[3])] << endl;
    OutputASM << "0053871C: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00538B25: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "00536568: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "0053654A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[14])] << endl;

    OutputASM << "00535780: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "00535761: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[6])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Unusual()
{
    ofstream OutputASM(ModsPath + "Random_Unusual.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[15])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[16])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DB368: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "0052D751: " << endl;
    OutputASM << "mov [008DB378]," << "ghostSI2" << endl;
    OutputASM << "mov [008DB388]," << "ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << "00529226: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "005293E0: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00528EC1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[15])] << endl;

    OutputASM << "00527391: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "00527324: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[16])] << endl;

    OutputASM << "0052F510: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "0052F4F1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[17])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Poultrygeist()
{
    ofstream OutputASM(ModsPath + "Random_Poultrygeist.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[4])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[6])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[4])] << endl;
    OutputASM << endl;

    OutputASM << endl;
    OutputASM << "008D65F8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00509E27: " << endl;
    OutputASM << "mov [008D6608]," << "ghostSI2" << endl;
    OutputASM << "mov [008D6618]," << "ghostSI3" << endl;
    OutputASM << "00509E41: " << endl;
    OutputASM << "mov [008D6628]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "0050A10F: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0050A193: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0050A182: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[4])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Phantom()
{
    ofstream OutputASM(ModsPath + "Random_Phantom.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(CrashFix)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[1])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[18])] << endl;
    OutputASM << "CrashFix:" << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "test eax,eax" << endl;
    OutputASM << "jne 006D4791" << endl;
    OutputASM << "push 00909108" << endl;
    OutputASM << "jmp 006D4781" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CF1D0: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004DE601: " << endl;
    OutputASM << "mov [008CF1E0]," << "ghostSI2" << endl;
    //OutputASM << "mov [008CF1E8],00000000" << endl; //Unlink Harriet
    OutputASM << "004DE615: " << endl;
    OutputASM << "mov [008CF1F0]," << "ghostSI3" << endl;

    OutputASM << endl;

    OutputASM << "004E045A: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "004E0431: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[1])] << endl;


    OutputASM << "004E1E00: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "004E1DE1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[5])] << endl;

    OutputASM << "004E0BDD: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004E0BB1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[18])] << endl;


    //DAYDREAMER PARTICLE FIX
    OutputASM << "006D478C: " << endl;
    OutputASM << "jmp CrashFix" << endl;
    OutputASM << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "006D478C: " << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Wisp()
{
    ofstream OutputASM(ModsPath + "Random_Wisp.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[0])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[19])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[2])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D2210: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004E9512: " << endl;
    OutputASM << "mov [008D2220]," << "ghostSI2" << endl; //darkling
    OutputASM << "mov [008D2230]," << "ghostSI3" << endl; //sparkle
    OutputASM << "mov [008D2240]," << "ghostSI4" << endl; //wisp
    OutputASM << endl;

    OutputASM << "004F4431: " << endl;
    OutputASM << "push ghostSI2" << endl;


    OutputASM << "004F24DA: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004F2DC0: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004F2DA1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[19])] << endl;

    OutputASM << "004EFABC: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "004EFA9E: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[2])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Spooky()
{
    ofstream OutputASM(ModsPath + "Random_Spooky.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    //OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    //OutputASM << "ghostSI1:" << endl;
    //OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[7])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[20])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[21])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[22])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    /*OutputASM << "008E0318: " << endl;
    OutputASM << "dd ghostSI1" << endl;*/
    OutputASM << "00548753: " << endl;
    OutputASM << "mov [008E0328]," << "ghostSI2" << endl;
    OutputASM << "mov [008E0338]," << "ghostSI3" << endl;
    OutputASM << "mov [008E0348]," << "ghostSI4" << endl;
    OutputASM << endl;

    /* OutputASM << "00544DE1: " << endl;
     OutputASM << "push ghostSI1" << endl;
     OutputASM << "0054AA37: " << endl;
     OutputASM << "push ghostSI1" << endl;*/

    OutputASM << "0054AAA8: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "0054AA75: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << "0054AADB: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Ghostbreakers()
{
    ofstream OutputASM(ModsPath + "Random_Ghostbreakers.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[15])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[16])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[23])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D9DD8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "008D9DE8: " << endl;
    OutputASM << "dd ghostSI2" << endl;
    OutputASM << "008D9DF8: " << endl;
    OutputASM << "dd ghostSI3" << endl;
    OutputASM << "008D9E08: " << endl;
    OutputASM << "dd ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "0051E900: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "0051E90A: " << endl;
    OutputASM << "push ghostSI2" << endl;

    OutputASM << "0051E919: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << "0051E928: " << endl;
    OutputASM << "push ghostSI4" << endl;

    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_MortalJacket()
{
    ofstream OutputASM(ModsPath + "Random_MortalJacket.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[24])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CC220: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << endl;

    OutputASM << "004D0347: " << endl;
    OutputASM << "push ghostSI1" << endl;


    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Cuckoos()
{
    ofstream OutputASM(ModsPath + "Random_Cuckoos.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[18])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CDB68: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004D741E: " << endl;
    OutputASM << "mov [008CDB78]," << "ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "004DA953: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "004DA942: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << "004DB465: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[7])] << endl;


    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}


void OutputScenarioOrder(string* Sc_Available_Array, string* Sc_Completed_Array, string* Sc_Name_Array, string* Sc_ScriptInstance_Array, int* ScenarioIndexes)
{
    ofstream OutputASM(ModsPath + "Random_ScenarioOrder.asm");

        /*188h = pg
        1c0h = ph
        230h = sh
        2a0h = fmj
        1f8h = bwp
        a8h = sum
        0 = h101
        268h = gb
        118h = us
        70h = cv
        38h = ws
        2d8h = cn
        e0h = df
        150h = fp
        ex_mission = fin*/



    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "004A8BC6: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[0]] << "]" << endl;
    OutputASM << "004A8BE6: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[0] << "], eax" << endl;
    OutputASM << "004A8BF7: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[1]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[1] << "], eax" << endl;
    OutputASM << "004A8C04: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[2] << "], eax" << endl;
    OutputASM << "004A8C14: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[2]] << "]" << endl;
    OutputASM << "004A8C22: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[3]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[3] << "], eax" << endl;
    OutputASM << "004A8C35: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[4]] << "]" << endl;
    OutputASM << "004A8C45: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[4] << "], eax" << endl;
    OutputASM << "mov [" << Sc_Available_Array[5] << "], eax" << endl;
    OutputASM << "004A8C51: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[6] << "], eax" << endl;
    OutputASM << "004A8C56: " << endl;
    OutputASM << "mov edi, [" << Sc_Completed_Array[ScenarioIndexes[5]] << "]" << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[7]] << "]" << endl;
    OutputASM << "004A8C68: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[7] << "], eax" << endl;
    OutputASM << "004A8C6F: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[8] << "], eax" << endl;
    OutputASM << "004A8C7C: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[6]] << "]" << endl;
    OutputASM << "004A8C9A: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[8]] << "]" << endl;
    OutputASM << "004A8CA4: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[9]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[9] << "], eax" << endl;
    OutputASM << "004A8CB3: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[11]] << "]" << endl;
    OutputASM << "004A8CC6: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[10] << "], eax" << endl;
    OutputASM << "mov [" << Sc_Available_Array[11] << "], eax" << endl;
    OutputASM << "004A8CD2: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[12] << "], eax" << endl;
    OutputASM << "004A8CD7: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[10]] << "]" << endl;
    OutputASM << "004A8CE5: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[12]] << "]" << endl;
    OutputASM << "004A8CEF: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[13]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[13] << "], eax" << endl;
    OutputASM << "004A8CFE: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[14] << "], eax" << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[14]] << "]" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "004A7E31: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[3]] << "]" << endl;
    OutputASM << "004A7E3E: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[3]] << endl;
    OutputASM << "004A7E54: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[9]] << "]" << endl;
    OutputASM << "004A7E61: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[9]] << endl;
    OutputASM << "004A7E77: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[12]] << "]" << endl;
    OutputASM << "004A7E84: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[12]] << endl;
    OutputASM << "004A7E9A: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[10]] << "]" << endl;
    OutputASM << "004A7EA7: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[10]] << endl;
    OutputASM << "004A7EB9: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[6]] << "]" << endl;
    OutputASM << "004A7EC2: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[6]] << endl;
    OutputASM << "004A7ED8: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[0]] << "]" << endl;
    OutputASM << "004A7EE5: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[0]] << endl;
    OutputASM << "004A7EF7: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[11]] << "]" << endl;
    OutputASM << "004A7F00: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[11]] << endl;
    OutputASM << "004A7F16: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[5]] << "]" << endl;
    OutputASM << "004A7F23: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[5]] << endl;
    OutputASM << "004A7F35: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[7]] << "]" << endl;
    OutputASM << "004A7F3E: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[7]] << endl;
    OutputASM << "004A7F54: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[2]] << "]" << endl;
    OutputASM << "004A7F61: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[2]] << endl;
    OutputASM << "004A7F77: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[1]] << "]" << endl;
    OutputASM << "004A7F80: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[1]] << endl;
    OutputASM << "004A7F92: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[13]] << "]" << endl;
    OutputASM << "004A7F9B: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[13]] << endl;
    OutputASM << "004A7FAD: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[8]] << "]" << endl;
    OutputASM << "004A7FB6: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[8]] << endl;
    OutputASM << "004A7FC8: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[4]] << "]" << endl;
    OutputASM << "004A7FD1: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[4]] << endl;
    OutputASM << "004A7FF5: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[14]] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    //Highscares order
    OutputASM << "00455452: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[0]] << endl;
    OutputASM << "00455477: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[1]] << endl;
    OutputASM << "00455496: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[2]] << endl;
    OutputASM << "004554AF: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[3]] << endl;
    OutputASM << "004554D4: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[4]] << endl;
    OutputASM << "004554F3: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[5]] << endl;
    OutputASM << "0045550C: " << endl;
    OutputASM << "mov [esp+2c]," << Sc_Name_Array[ScenarioIndexes[6]] << endl;
    OutputASM << "00455531: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[7]] << endl;
    OutputASM << "00455550: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[8]] << endl;
    OutputASM << "00455569: " << endl;
    OutputASM << "mov [esp+2c]," << Sc_Name_Array[ScenarioIndexes[9]] << endl;
    OutputASM << "0045558E: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[10]] << endl;
    OutputASM << "004555AD: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[11]] << endl;
    OutputASM << "004555C6: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[12]] << endl;
    OutputASM << "004555EB: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[13]] << endl;
    OutputASM << "0045560A: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[14]] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "00455446: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[0]] << "], ebx" << endl;
    OutputASM << "00455465: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[1]] << "], ebx" << endl;
    OutputASM << "00455484: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[2]] << "], ebx" << endl;
    OutputASM << "004554A3: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[3]] << "], ebx" << endl;
    OutputASM << "004554C2: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[4]] << "], ebx" << endl;
    OutputASM << "004554E1: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[5]] << "], ebx" << endl;
    OutputASM << "00455500: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[6]] << "], ebx" << endl;
    OutputASM << "0045551F: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[7]] << "], ebx" << endl;
    OutputASM << "0045553E: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[8]] << "], ebx" << endl;
    OutputASM << "0045555D: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[9]] << "], ebx" << endl;
    OutputASM << "0045557C: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[10]] << "], ebx" << endl;
    OutputASM << "0045559B: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[11]] << "], ebx" << endl;
    OutputASM << "004555BA: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[12]] << "], ebx" << endl;
    OutputASM << "004555D9: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[13]] << "], ebx" << endl;
    OutputASM << "004555F8: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[14]] << "], ebx" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    //map fixes
    OutputASM << "//map fixes" << endl;
   // OutputASM << "004A9D0E: " << endl; //h101
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[0]] << "]" << endl;
    OutputASM << "004A9DDB: " << endl; //h101
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[0]] << "], edi" << endl;

   // OutputASM << "004AA4B7: " << endl; //ws
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[1]] << "]" << endl;
    OutputASM << "004AA58B: " << endl; //ws
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[1]] << "]" << endl;
    


    //OutputASM << "004AAEAC: " << endl; //ch
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[2]] << "]" << endl;
    OutputASM << "004AAF7B: " << endl; //ch
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[2]] << "], edi" << endl;

    //OutputASM << "004AAAA9: " << endl; //sni
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[3]] << "]" << endl;
    OutputASM << "004AAB7D: " << endl; //sni
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[3]] << "]" << endl;


    //OutputASM << "004AA8AE: " << endl; //df
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[4]] << "]" << endl;
    OutputASM << "004AA982: " << endl; //df
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[4]] << "]" << endl;

    //OutputASM << "004AA2BF: " << endl; //us
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[5]] << "]" << endl;
    OutputASM << "004AA39A: " << endl; //us
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[5]] << "]" << endl;



   //OutputASM << "004A9D07: " << endl; //fp
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[6]] << "]" << endl;
    //OutputASM << "004A9DE3: " << endl; //fp
    //OutputASM << "cmp [" << Sc_Available_Array[ScenarioIndexes[6]] << "], edi" << endl;
    OutputASM << "004A9DEB: " << endl; //fp
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[6]] << "], edi" << endl;


    //OutputASM << "004AAEA5: " << endl; //pg
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[7]] << "]" << endl;
    //OutputASM << "004AAF83: " << endl; //pg
    //OutputASM << "cmp [" << Sc_Available_Array[ScenarioIndexes[7]] << "], edi" << endl;
    OutputASM << "004AAF8B: " << endl; //pg
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[7]] << "], edi" << endl;



    //OutputASM << "004AA6A3: " << endl; //ph
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[8]] << "]" << endl;
    OutputASM << "004AA772: " << endl; //ph
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[8]] << "], edi" << endl;


    //OutputASM << "004AACA3: " << endl; //bwp
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[9]] << "]" << endl;
    OutputASM << "004AAD77: " << endl; //bwp
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[9]] << "]" << endl;


    //OutputASM << "004AA0D7: " << endl;//sh
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[10]] << "]" << endl;
    OutputASM << "004AA1AB: " << endl;//sh
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[10]] << "]" << endl;

    //OutputASM << "004AA2B8: " << endl; //gb
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[11]] << "]" << endl;
   // OutputASM << "004AA3A3: " << endl; //gb
   // OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[11]] << "]" << endl;
    OutputASM << "004AA3AC: " << endl; //gb
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[11]] << "]" << endl;


    //OutputASM << "004A9EF7: " << endl; //fmj
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[12]] << "]" << endl;
    OutputASM << "004A9FCB: " << endl; //fmj
    OutputASM << "mov eax,[" << Sc_Completed_Array[ScenarioIndexes[12]] << "]" << endl;

    //OutputASM << "004AA69C: " << endl; //cn
    //OutputASM << "mov eax,[" << Sc_Available_Array[ScenarioIndexes[13]] << "]" << endl;
    //OutputASM << "004AA77A: " << endl; //cn
   // OutputASM << "cmp [" << Sc_Available_Array[ScenarioIndexes[13]] << "], edi" << endl;
    OutputASM << "004AA782: " << endl; //cn
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[13]] << "], edi" << endl;


   // OutputASM << "004AB0BD: " << endl; //ex
    //OutputASM << "cmp [" << Sc_Available_Array[ScenarioIndexes[14]] << "], edi" << endl;
    OutputASM << "004AB18B: " << endl; //ex
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[14]] << "], edi" << endl;








    OutputASM << "[DISABLE]" << endl;

    OutputASM.close();

}

void OutputRandomiserInfo()
{
    ofstream RandomiserInfo(ModsPath + "RandomiserLog.txt");
    RandomiserInfo << app_version << endl << endl;


    RandomiserInfo << "Random Haunters: ";
    if (RandHaunters)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Haunter Fetters: ";
    switch (RandHaunterFetters)
    {
    case 2:
        RandomiserInfo << "Enabled (shuffle)" << endl;
        break;
    case 1:
        RandomiserInfo << "Enabled (true random)" << endl;
        break;
    default:
        RandomiserInfo << "Disabled" << endl;
    }
        
    RandomiserInfo << "Random Haunter Powers: ";
    if (RandPowers)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Mortal Order of Appearance: ";
    if (RandMortalOrderOfAppearance)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Mortal Stats: ";
    if (RandMortalStats)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Don't Randomise Puzzle Mortals: ";
    if (DontRandKeyMortals)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;




    RandomiserInfo << "Random Scenario Order: ";
    if (RandScenarioOrder)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Allow Unfair Outcomes: ";
    if (ScenarioUnfair)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Ghoul Room: ";
    if (RandGhoulroom)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;
   

    RandomiserInfo << "Random Narrator Dialogue: ";
    if (DialogueNarrator)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Haunter Dialogue: ";
    if (DialogueHaunter)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Use Tutorial Lines: ";
    if (DialogueIncludeTutorial)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;




    RandomiserInfo << endl;
    RandomiserInfo << endl;
    RandomiserInfo << "Seed: " << seed;

    RandomiserInfo.close();
}


bool DeleteAndRename(string fileName)
{

    string filePath = ModsPath + fileName;
    string oldName = ModsPath + fileName + ".Randomiser_TEMP";

    remove(filePath.c_str());
    if (!rename(oldName.c_str(), filePath.c_str()))
        return 1;
    else
        return 0;
    

    


}


//New changes
int GetMortalData(string fileName)
{


    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + fileName);
    string tempLine = "";




    int MortalID = 0;

    int missionCount = 0;

    int FilenameLineCount = 0;
    int ScriptLineCount = 0;
    int ModelLineCount = 0;
    int AnimationLineCount = 0;
    int TypeLineCount = 0;
    int NameLineCount = 0;
    int BioLineCount = 0;
    int GenderLineCount = 0;
    int MoodLineCount = 0;
    int SubfearLineCount = 0;
    int FearLineCount = 0;
    int BeliefLineCount = 0;
    int MadnessLineCount = 0;
    int WillpowerLineCount = 0;
    int TerrorLineCount = 0;

    bool firstTimeFilename = true;
    bool firstTimeScript = true;
    bool firstTimeModel = true;
    bool firstTimeAnimation = true;
    bool firstTimeType = true;
    bool firstTimeName = true;
    bool firstTimeBio = true;
    bool firstTimeGender = true;
    bool firstTimeMood = true;
    bool firstTimeSubfear = true;
    bool firstTimeFear = true;
    bool firstTimeTerror = true;
    bool firstTimeMadness = true;
    bool firstTimeBelief = true;
    bool firstTimeWillpower = true;

    bool getNewMissionNumber = true;

    bool subtractThisMortal = false;

    /*bool firstTimeAge = true;
    bool firstTimeFetter = true;*/




    while (asmIn)
    {

        std::getline(asmIn, tempLine);
        if (tempLine.substr(0, 3) == "dd ")
        {
            
         
            getNewMissionNumber = true;

            if ((FilenameLineCount == 1 && firstTimeFilename == true) || FilenameLineCount == 26)
            {
                subtractThisMortal = false;

                if (tempLine == "dd 008E5308") //skip StayKold
                {
                    for (int i = 0; i < 26; i++)
                    {
                        std::getline(asmIn, tempLine);
                    }
                }
                firstTimeFilename = false;
                FilenameLineCount = 0;
                MortalFilename[MortalID] = tempLine;
            }

            if ((ScriptLineCount == 2 && firstTimeScript == true) || ScriptLineCount == 26)
            {
                firstTimeScript = false;
                ScriptLineCount = 0;
                MortalScript[MortalID] = tempLine;
            }

            if ((ModelLineCount == 3 && firstTimeModel == true) || ModelLineCount == 26)
            {
                firstTimeModel = false;
                ModelLineCount = 0;
                MortalModel[MortalID] = tempLine;

                if (missionCount == 4 && tempLine == "dd 008CDD1C")
                {
                    SaneLines[0] = MortalID;
                }

                if (missionCount == 11 && tempLine == "dd 008DF7B4")
                {
                    MaleLines[0] = MortalID;
                }

                if (missionCount == 8 && tempLine == "dd 008CF274")
                {
                    SaneLines[1] = MortalID;
                }

                if (missionCount == 2 && tempLine == "dd 008DA020")
                {
                    SaneLines[2] = MortalID;
                }

                if (missionCount == 6 && tempLine == "dd 008D9F78")
                {
                    if (DontRandKeyMortals)
                    {
                        NormanID = MortalID;
                        subtractThisMortal = true;

                    }
                        
                }

                if (missionCount == 7 && tempLine == "dd 008DC7E4")
                {
                    if (DontRandKeyMortals)
                    {
                        BlairID = MortalID;
                        subtractThisMortal = true;
                    }
                        
                }

                if (missionCount == 9 && tempLine == "dd 008C5A50") //lovedoctor
                {
                    if (DontRandKeyMortals)
                    {
                        GreenwoodID = MortalID;
                        subtractThisMortal = true;
                    } 
                }

                if (missionCount == 6 && tempLine == "dd 008D9F78") //PS_Policeman2
                {
                    if (DontRandKeyMortals)
                        MaleLines[1] = -1;
                    else
                    {
                        MaleLines[1] = MortalID;
                    }
                }

                if (missionCount == 7 && tempLine == "dd 008D5C18")
                {
                    SaneLines[3] = MortalID;
                }

                if (missionCount == 7 && tempLine == "dd 008D5BEC")
                {
                    SaneLines[4] = MortalID;
                }
                    
                if (missionCount == 7 && tempLine == "dd 008D5BE0")
                {
                    SaneLines[5] = MortalID;
                }

                if (missionCount == 9 && tempLine == "dd 008CDC24")
                {
                    SaneLines[6] = MortalID;
                }

                if (missionCount == 9 && tempLine == "dd 008CDD6C")
                {
                    SaneLines[7] = MortalID;
                }
                if (missionCount == 9 && tempLine == "dd 008CDD5C")
                {
                    SaneLines[8] = MortalID;
                }
                if (missionCount == 9 && tempLine == "dd 008C5A5C")
                {
                    SaneLines[9] = MortalID;
                }


                

            }

            if ((AnimationLineCount == 5 && firstTimeAnimation == true) || AnimationLineCount == 26)
            {
                firstTimeAnimation = false;
                AnimationLineCount = 0;
                MortalAnimation[MortalID] = tempLine;
            }

            if ((TypeLineCount == 9 && firstTimeType == true) || TypeLineCount == 26)
            {
                firstTimeType = false;
                TypeLineCount = 0;
                MortalType[MortalID] = tempLine;
            }

            if ((NameLineCount == 10 && firstTimeName == true) || NameLineCount == 26)
            {
                firstTimeName = false;
                NameLineCount = 0;
                MortalName[MortalID] = tempLine;
            }

            if ((BioLineCount == 11 && firstTimeBio == true) || BioLineCount == 26)
            {
                firstTimeBio = false;
                BioLineCount = 0;
                MortalBio[MortalID] = tempLine;


            }

            if ((GenderLineCount == 13 && firstTimeGender == true) || GenderLineCount == 26)
            {
                firstTimeGender = false;
                GenderLineCount = 0;
                MortalGender[MortalID] = tempLine;

            }

            if ((MoodLineCount == 14 && firstTimeMood == true) || MoodLineCount == 26)
            {
                firstTimeMood = false;
                MoodLineCount = 0;
                MortalMood[MortalID] = tempLine;

            }

            if ((SubfearLineCount == 15 && firstTimeSubfear == true) || SubfearLineCount == 26)
            {
                firstTimeSubfear = false;
                SubfearLineCount = 0;
                MortalSubfear[MortalID] = tempLine;

            }

            if ((FearLineCount == 16 && firstTimeFear == true) || FearLineCount == 26)
            {
                firstTimeFear = false;
                FearLineCount = 0;
                MortalFear[MortalID] = tempLine;

            }

            if ((BeliefLineCount == 20 && firstTimeBelief == true) || BeliefLineCount == 26)
            {
                firstTimeBelief = false;
                BeliefLineCount = 0;
                MortalBelief[MortalID] = tempLine;

            }

            if ((MadnessLineCount == 21 && firstTimeMadness == true) || MadnessLineCount == 26)
            {
                firstTimeMadness = false;
                MadnessLineCount = 0;
                MortalMadness[MortalID] = tempLine;
            }

            if ((WillpowerLineCount == 22 && firstTimeWillpower == true) || WillpowerLineCount == 26)
            {
                firstTimeWillpower = false;
                WillpowerLineCount = 0;
                MortalWillpower[MortalID] = tempLine;

            }

            if ((TerrorLineCount == 23 && firstTimeTerror == true) || TerrorLineCount == 26)
            {
                firstTimeTerror = false;
                TerrorLineCount = 0;
                MortalTerror[MortalID] = tempLine;

            
                
                if (!subtractThisMortal)
                {
                    MortalIDArray[MortalID] = MortalID;
                }
                else
                {
                    MortalIDArray[MortalID] = -1;
                }

                MortalID++;
                
            }





            FilenameLineCount++;
            ScriptLineCount++;
            ModelLineCount++;
            AnimationLineCount++;
            TypeLineCount++;
            NameLineCount++;
            BioLineCount++;
            GenderLineCount++;
            MoodLineCount++;
            SubfearLineCount++;
            FearLineCount++;
            BeliefLineCount++;
            MadnessLineCount++;
            WillpowerLineCount++;
            TerrorLineCount++;

        }
        else
        {


            if ((tempLine.substr(0, 7) == "mission" && tempLine.back() == ':') && getNewMissionNumber == true)
            {
                missionCount++;
                getNewMissionNumber = false;
            }


            FilenameLineCount = 0;
            ScriptLineCount = 0;
            ModelLineCount = 0;
            AnimationLineCount = 0;
            TypeLineCount = 0;
            NameLineCount = 0;
            BioLineCount = 0;
            GenderLineCount = 0;
            MoodLineCount = 0;
            SubfearLineCount = 0;
            FearLineCount = 0;
            BeliefLineCount = 0;
            MadnessLineCount = 0;
            WillpowerLineCount = 0;
            TerrorLineCount = 0;

            firstTimeFilename = true;
            firstTimeScript = true;
            firstTimeModel = true;
            firstTimeAnimation = true;
            firstTimeType = true;
            firstTimeName = true;
            firstTimeBio = true;
            firstTimeGender = true;
            firstTimeMood = true;
            firstTimeFear = true;
            firstTimeSubfear = true;
            firstTimeTerror = true;
            firstTimeMadness = true;
            firstTimeBelief = true;
            firstTimeWillpower = true;
        }

    }

    asmIn.close();

    return MortalID;

}

void GetMortalIcons()
{


    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "IconData.asm");

    string tempLine;

    std::getline(asmIn, tempLine);

    while (tempLine != "MortalIcon:")
    {
        std::getline(asmIn, tempLine);


    }

    bool firstTimeIcon = true;
    int MortalCount = 0;

    int IconLineCount = 0;

    while (tempLine != "GhostIcon:")
    {
        std::getline(asmIn, tempLine);

        if ((IconLineCount == 2 && firstTimeIcon == true) || (IconLineCount == 7))
        {
            if (tempLine == "dd 00000000")
            {
                for (int i = 0; i < 7; i++)
                {
                    std::getline(asmIn, tempLine);
                }
            }
            
            
            

            IconLineCount = 0;
            firstTimeIcon = false;
            MortalIcon[MortalCount] = tempLine;

            MortalCount++;
            

        }

        IconLineCount++;


    }







    asmIn.close();

}


void OutputIconData(int* MortalIDArrayWithoutSpecials, int TotalMortalCountInLevels)


{
    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "IconData.asm");
    ofstream asmOut(ModsPath + "IconData.asm.Randomiser_TEMP");

    string tempLine;

    while (tempLine != "MortalIcon:")
    {
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    bool firstTimeIcon = true;
    bool firstTimeName = true;

    int useSpecialArray = 0;

    int MaleLinesCount = 0;
    int SaneLinesCount = 0;

    int globalMortalCount = 0;

    int MortalCount = 0;
    int SaneMortalCount = 0;
    int MaleMortalCount = 0;

    int NameLineCount = 0;



    for (int IconLineCount = 0; globalMortalCount < TotalMortalCountInLevels; IconLineCount++)
    {
        std::getline(asmIn, tempLine);


        if ((NameLineCount == 0 && firstTimeName == true) || (NameLineCount == 7))
        {
            if (tempLine == "dw 377")
            {
                for (int i = 0; i < 7; i++)
                {
                    asmOut << tempLine << endl;
                    std::getline(asmIn, tempLine);
                }
            }


            if (globalMortalCount != MaleLines[0] && globalMortalCount != SaneLines[0] && globalMortalCount != SaneLines[1] && 
                globalMortalCount != SaneLines[2] && globalMortalCount != BlairID && globalMortalCount != NormanID && globalMortalCount != GreenwoodID &&
                globalMortalCount != MaleLines[1] && globalMortalCount != SaneLines[3] && globalMortalCount != SaneLines[4] && globalMortalCount != SaneLines[5] &&
                globalMortalCount != SaneLines[6] && globalMortalCount != SaneLines[7] && globalMortalCount != SaneLines[8] &&
                globalMortalCount != SaneLines[9])
            {


                tempLine = MortalName[(MortalIDArrayWithoutSpecials[MortalCount])];
                tempLine = "dw " + tempLine.substr(3);
                useSpecialArray = 0;
            }

            else
            {
                if (globalMortalCount == MaleLines[0])
                {
                    tempLine = MortalName[(MaleMortalIDArray[MaleMortalCount])];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 2;

                    goto escapeThisMadness;
                }

                if (globalMortalCount == MaleLines[1])
                {
                    tempLine = MortalName[(MaleMortalIDArray[MaleMortalCount])];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 2;

                    goto escapeThisMadness;
                }

                if (globalMortalCount == SaneLines[0] || globalMortalCount == SaneLines[1] || globalMortalCount == SaneLines[2] ||
                    globalMortalCount == SaneLines[3] || globalMortalCount == SaneLines[4] || globalMortalCount == SaneLines[5] ||
                    globalMortalCount == SaneLines[6] || globalMortalCount == SaneLines[7] || globalMortalCount == SaneLines[8] ||
                    globalMortalCount == SaneLines[9])
                {
                    tempLine = MortalName[(SaneMortalIDArray[SaneMortalCount])];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 1;

                    goto escapeThisMadness;
                }

                if (globalMortalCount == BlairID)
                {
                    tempLine = MortalName[BlairID];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 3;

                    goto escapeThisMadness;
                }

                if (globalMortalCount == NormanID)
                {
                    tempLine = MortalName[NormanID];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 4;
                    goto escapeThisMadness;
                }

                
                    tempLine = MortalName[GreenwoodID];
                    tempLine = "dw " + tempLine.substr(3);
                    useSpecialArray = 5;
                

                


                


            }


        escapeThisMadness:
            NameLineCount = 0;
            firstTimeName = false;


        }

        if ((IconLineCount == 2 && firstTimeIcon == true) || (IconLineCount == 7))
        {
            switch (useSpecialArray) {

            case 0:
                tempLine = MortalIcon[(MortalIDArrayWithoutSpecials[MortalCount])];
                MortalCount++;
                goto escapeSwitch;
            case 1:
                tempLine = MortalIcon[(SaneMortalIDArray[SaneMortalCount])];
                SaneMortalCount++;
                goto escapeSwitch;
            case 2:
                tempLine = MortalIcon[(MaleMortalIDArray[MaleMortalCount])];
                MaleMortalCount++;
                goto escapeSwitch;
            case 3:
                tempLine = MortalIcon[BlairID];
                goto escapeSwitch;
            case 4:
                tempLine = MortalIcon[NormanID];
                goto escapeSwitch;
            case 5:
                tempLine = MortalIcon[GreenwoodID];

            }



        escapeSwitch:
            globalMortalCount++;
            IconLineCount = 0;
            firstTimeIcon = false;
        }

        NameLineCount++;
        asmOut << tempLine << endl;
    }

    while (asmIn)
    {
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    asmIn.close();
    asmOut.close();
}


void GetSpecialMortals(int TotalMortalCountInLevels)
{
    int i = 0;


    int j = 0;

    stringstream ss;

    float MadnessValue = 0;
    float WillpowerValue = 0;
    int a = 0;
    while (i < 10 || a < 2)
    {

        if (MortalIDArray[j] != -1 && MortalIDArray[j] != - 2)
        {
            ss << (MortalMadness[(MortalIDArray[j])].substr(10));
            MadnessValue = 0;
            ss >> MadnessValue;
            ss.str("");
            ss.clear();


            ss << (MortalWillpower[(MortalIDArray[j])].substr(10));
            WillpowerValue = 0;
            ss >> WillpowerValue;
            ss.str("");
            ss.clear();


            if (MadnessValue < WillpowerValue)
            {
                if (MortalAnimation[(MortalIDArray[j])] == "dd 0096E160" && a < 2)
                {
                    MaleMortalIDArray[a] = MortalIDArray[j];
                    MortalIDArray[j] = -1;
                    a++;

                    if (DontRandKeyMortals)
                        a++;
                    
                }
                else
                {
                    if (i < 10)
                    {
                        SaneMortalIDArray[i] = MortalIDArray[j];
                        MortalIDArray[j] = -1;
                        i++;
                    }

                }

            }
        }

        j++;

    }
}

void OutputRandomMortals(int* MortalIDArrayWithoutSpecials, int TotalMortalCountInLevels)
{
    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "Scenarios.asm");
    ofstream asmOut(ModsPath + "Scenarios.asm.Randomiser_TEMP");

    string tempLine = "";

    int FilenameLineCount = 0;
    int ScriptLineCount = 0;
    int AnimationLineCount = 0;
    int TypeLineCount = 0;
    int NameLineCount = 0;
    int BioLineCount = 0;
    int GenderLineCount = 0;
    int MoodLineCount = 0;
    int SubfearLineCount = 0;
    int FearLineCount = 0;
    int BeliefLineCount = 0;
    int MadnessLineCount = 0;
    int WillpowerLineCount = 0;
    int TerrorLineCount = 0;
    int ModelLineCount = 0;

    int MortalCount = 0;
    int SaneMortalCount = 0;
    int MaleMortalCount = 0;

    int missionCount = 0;

    int globalMortalCount = 0;

    bool countScenario = true;

    bool firstTimeFilename = true;
    bool firstTimeScript = true;
    bool firstTimeAnimation = true;
    bool firstTimeType = true;
    bool firstTimeName = true;
    bool firstTimeBio = true;
    bool firstTimeGender = true;
    bool firstTimeMood = true;
    bool firstTimeSubfear = true;
    bool firstTimeFear = true;
    bool firstTimeBelief = true;
    bool firstTimeMadness = true;
    bool firstTimeWillpower = true;
    bool firstTimeTerror = true;
    bool firstTimeModel = true;

    int useSpecialArray = 0;

    int MaleLineCount = 0;
    int SaneLineCount = 0;

   while (asmIn)
    {
        std::getline(asmIn, tempLine);

        if (tempLine.substr(0, 3) == "dd ")
        {
            countScenario = true;

            if ((FilenameLineCount == 1 && firstTimeFilename == true) || FilenameLineCount == 26)
            {
                if (tempLine == "dd 008E5308") //skip staykold
                {
                    for (int i = 0; i < 26; i++)
                    {
                        asmOut << tempLine << endl;
                        std::getline(asmIn, tempLine);
                    }
                }


                if (globalMortalCount != SaneLines[0] && globalMortalCount != MaleLines[0] && globalMortalCount != SaneLines[1] && globalMortalCount != SaneLines[2] && 
                    globalMortalCount != BlairID && globalMortalCount != NormanID && globalMortalCount != GreenwoodID && globalMortalCount != MaleLines[1] &&
                    globalMortalCount != SaneLines[3] && globalMortalCount != SaneLines[4] && globalMortalCount != SaneLines[5] &&
                    globalMortalCount != SaneLines[6] && globalMortalCount != SaneLines[7] && globalMortalCount != SaneLines[8] &&
                    globalMortalCount != SaneLines[9])
                {

                    tempLine = MortalFilename[(MortalIDArrayWithoutSpecials[MortalCount])];
                    useSpecialArray = 0;
                }
                else
                {
                    if (globalMortalCount == MaleLines[0]) //cousin
                    {

                        tempLine = MortalFilename[(MaleMortalIDArray[MaleMortalCount])];
                        useSpecialArray = 2;
                        goto escapeShittyCode;
                    }

                    if (globalMortalCount == MaleLines[1])
                    {
                        tempLine = MortalFilename[MaleMortalIDArray[MaleMortalCount]];
                        useSpecialArray = 2;
                        goto escapeShittyCode;
                    }

                    if (globalMortalCount == SaneLines[0] || globalMortalCount == SaneLines[1] || globalMortalCount == SaneLines[2] || 
                        globalMortalCount == SaneLines[3] || globalMortalCount == SaneLines[4] || globalMortalCount == SaneLines[5] || 
                        globalMortalCount == SaneLines[6] || globalMortalCount == SaneLines[7] || globalMortalCount == SaneLines[8] || 
                        globalMortalCount == SaneLines[9])
                    {
                        tempLine = MortalFilename[(SaneMortalIDArray[SaneMortalCount])];
                        useSpecialArray = 1;
                        goto escapeShittyCode;
                    }
                    if (globalMortalCount == BlairID)
                    {
                        tempLine = MortalFilename[BlairID];
                        useSpecialArray = 3;
                        goto escapeShittyCode;
                    }

                    if (globalMortalCount == NormanID)
                    {
                        tempLine = MortalFilename[NormanID];
                        useSpecialArray = 4;
                        goto escapeShittyCode;
                    }

                    
                        tempLine = MortalFilename[GreenwoodID];
                        useSpecialArray = 5;
                    

                    
                       

                    
                    
                    

                }


            escapeShittyCode:
                firstTimeFilename = false;
                FilenameLineCount = 0;

            }

            if ((ScriptLineCount == 2 && firstTimeScript == true) || ScriptLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalScript[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeScriptSwitch;
                case 1:
                    tempLine = MortalScript[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeScriptSwitch;
                case 2:
                    tempLine = MortalScript[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeScriptSwitch;
                case 3:
                    tempLine = MortalScript[BlairID];
                    goto escapeScriptSwitch;
                case 4:
                    tempLine = MortalScript[NormanID];
                    goto escapeScriptSwitch;
                case 5:
                    tempLine = MortalScript[GreenwoodID];
                }

            escapeScriptSwitch:

                firstTimeScript = false;
                ScriptLineCount = 0;

            }

            if ((AnimationLineCount == 5 && firstTimeAnimation == true) || AnimationLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalAnimation[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeAnimationSwitch;
                case 1:
                    tempLine = MortalAnimation[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeAnimationSwitch;
                case 2:
                    tempLine = MortalAnimation[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeAnimationSwitch;
                case 3:
                    tempLine = MortalAnimation[BlairID];
                    goto escapeAnimationSwitch;
                case 4:
                    tempLine = MortalAnimation[NormanID];
                    goto escapeAnimationSwitch;
                case 5:
                    tempLine = MortalAnimation[GreenwoodID];
                }

            escapeAnimationSwitch:
                firstTimeAnimation = false;
                AnimationLineCount = 0;
            }

            if ((TypeLineCount == 9 && firstTimeType == true) || TypeLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalType[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeTypeSwitch;
                case 1:
                    tempLine = MortalType[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeTypeSwitch;
                case 2:
                    tempLine = MortalType[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeTypeSwitch;
                case 3:
                    tempLine = MortalType[BlairID];
                    goto escapeTypeSwitch;
                case 4:
                    tempLine = MortalType[NormanID];
                    goto escapeTypeSwitch;
                case 5:
                    tempLine = MortalType[GreenwoodID];
                }

            escapeTypeSwitch:
                firstTimeType = false;
                TypeLineCount = 0;
            }

            if ((NameLineCount == 10 && firstTimeName == true) || NameLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalName[(MortalIDArrayWithoutSpecials[MortalCount])];
                    if (missionCount == 11 && MortalModel[globalMortalCount] == "dd 008E0414")
                    {
                        HoboID = MortalIDArrayWithoutSpecials[MortalCount];
                    }
                    goto escapeNameSwitch;
                case 1:
                    tempLine = MortalName[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeNameSwitch;
                case 2:
                    tempLine = MortalName[(MaleMortalIDArray[MaleMortalCount])];
                    if (missionCount == 11 && MortalModel[globalMortalCount] == "dd 008DF7B4")
                    {
                        CousinID = MaleMortalIDArray[MaleMortalCount];
                    }
                    goto escapeNameSwitch;
                case 3:
                    tempLine = MortalName[BlairID];
                    goto escapeNameSwitch;
                case 4:
                    tempLine = MortalName[NormanID];
                    goto escapeNameSwitch;
                case 5:
                    tempLine = MortalName[GreenwoodID];
                }

            escapeNameSwitch:


                firstTimeName = false;
                NameLineCount = 0;
            }

            if ((BioLineCount == 11 && firstTimeBio == true) || BioLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalBio[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeBioSwitch;
                case 1:
                    tempLine = MortalBio[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeBioSwitch;
                case 2:
                    tempLine = MortalBio[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeBioSwitch;
                case 3:
                    tempLine = MortalBio[BlairID];
                    goto escapeBioSwitch;
                case 4:
                    tempLine = MortalBio[NormanID];
                    goto escapeBioSwitch;
                case 5:
                    tempLine = MortalBio[GreenwoodID];
                }

            escapeBioSwitch:
                firstTimeBio = false;
                BioLineCount = 0;
            }

            if ((GenderLineCount == 13 && firstTimeGender == true) || GenderLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalGender[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeGenderSwitch;
                case 1:
                    tempLine = MortalGender[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeGenderSwitch;
                case 2:
                    tempLine = MortalGender[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeGenderSwitch;
                case 3:
                    tempLine = MortalGender[BlairID];
                    goto escapeGenderSwitch;
                case 4:
                    tempLine = MortalGender[NormanID];
                    goto escapeGenderSwitch;
                case 5:
                    tempLine = MortalGender[GreenwoodID];
                }

            escapeGenderSwitch:
                firstTimeGender = false;
                GenderLineCount = 0;
            }

            if ((MoodLineCount == 14 && firstTimeMood == true) || MoodLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalMood[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeMoodSwitch;
                case 1:
                    tempLine = MortalMood[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeMoodSwitch;
                case 2:
                    tempLine = MortalMood[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeMoodSwitch;
                case 3:
                    tempLine = MortalMood[BlairID];
                    goto escapeMoodSwitch;
                case 4:
                    tempLine = MortalMood[NormanID];
                    goto escapeMoodSwitch;
                case 5:
                    tempLine = MortalMood[GreenwoodID];
                }

            escapeMoodSwitch:
                firstTimeMood = false;
                MoodLineCount = 0;
            }

            if ((SubfearLineCount == 15 && firstTimeSubfear == true) || SubfearLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalSubfear[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeSubfearSwitch;
                case 1:
                    tempLine = MortalSubfear[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeSubfearSwitch;
                case 2:
                    tempLine = MortalSubfear[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeSubfearSwitch;
                case 3:
                    tempLine = MortalSubfear[BlairID];
                    goto escapeSubfearSwitch;
                case 4:
                    tempLine = MortalSubfear[NormanID];
                    goto escapeSubfearSwitch;
                case 5:
                    tempLine = MortalSubfear[GreenwoodID];
                }

            escapeSubfearSwitch:
                firstTimeSubfear = false;
                SubfearLineCount = 0;
            }

            if ((FearLineCount == 16 && firstTimeFear == true) || FearLineCount == 26)
            {
                switch (useSpecialArray) {
                case 0:
                    tempLine = MortalFear[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeFearSwitch;
                case 1:
                    tempLine = MortalFear[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeFearSwitch;
                case 2:
                    tempLine = MortalFear[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeFearSwitch;
                case 3:
                    tempLine = MortalFear[BlairID];
                    goto escapeFearSwitch;
                case 4:
                    tempLine = MortalFear[NormanID];
                    goto escapeFearSwitch;
                case 5:
                    tempLine = MortalFear[GreenwoodID];
                }

            escapeFearSwitch:
                firstTimeFear = false;
                FearLineCount = 0;
            }

            if ((BeliefLineCount == 20 && firstTimeBelief == true) || BeliefLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalBelief[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeBeliefSwitch;
                case 1:
                    tempLine = MortalBelief[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeBeliefSwitch;
                case 2:
                    tempLine = MortalBelief[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeBeliefSwitch;
                case 3:
                    tempLine = MortalBelief[BlairID];
                    goto escapeBeliefSwitch;
                case 4:
                    tempLine = MortalBelief[NormanID];
                    goto escapeBeliefSwitch;
                case 5:
                    tempLine = MortalBelief[GreenwoodID];
                }

            escapeBeliefSwitch:
                firstTimeBelief = false;
                BeliefLineCount = 0;
            }

            if ((MadnessLineCount == 21 && firstTimeMadness == true) || MadnessLineCount == 26)
            {
                switch (useSpecialArray) {
                case 0:
                    tempLine = MortalMadness[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeMadnessSwitch;
                case 1:
                    tempLine = MortalMadness[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeMadnessSwitch;
                case 2:
                    tempLine = MortalMadness[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeMadnessSwitch;
                case 3:
                    tempLine = MortalMadness[BlairID];
                    goto escapeMadnessSwitch;
                case 4:
                    tempLine = MortalMadness[NormanID];
                    goto escapeMadnessSwitch;
                case 5:
                    tempLine = MortalMadness[GreenwoodID];
                }

            escapeMadnessSwitch:
                firstTimeMadness = false;
                MadnessLineCount = 0;
            }

            if ((WillpowerLineCount == 22 && firstTimeWillpower == true) || WillpowerLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalWillpower[(MortalIDArrayWithoutSpecials[MortalCount])];
                    goto escapeWillpowerSwitch;
                case 1:
                    tempLine = MortalWillpower[(SaneMortalIDArray[SaneMortalCount])];
                    goto escapeWillpowerSwitch;
                case 2:
                    tempLine = MortalWillpower[(MaleMortalIDArray[MaleMortalCount])];
                    goto escapeWillpowerSwitch;
                case 3:
                    tempLine = MortalWillpower[BlairID];
                    goto escapeWillpowerSwitch;
                case 4:
                    tempLine = MortalWillpower[NormanID];
                    goto escapeWillpowerSwitch;
                case 5:
                    tempLine = MortalWillpower[GreenwoodID];
                }

            escapeWillpowerSwitch:
                firstTimeWillpower = false;
                WillpowerLineCount = 0;

            }

            if ((TerrorLineCount == 23 && firstTimeTerror == true) || TerrorLineCount == 26)
            {
                switch (useSpecialArray) {

                case 0:
                    tempLine = MortalTerror[(MortalIDArrayWithoutSpecials[MortalCount])];
                    MortalCount++;
                    goto escapeTerrorSwitch;
                case 1:
                    tempLine = MortalTerror[(SaneMortalIDArray[SaneMortalCount])];
                    SaneMortalCount++;
                    goto escapeTerrorSwitch;
                case 2:
                    tempLine = MortalTerror[(MaleMortalIDArray[MaleMortalCount])];
                    MaleMortalCount++;
                    goto escapeTerrorSwitch;
                case 3:
                    tempLine = MortalTerror[BlairID];
                    goto escapeTerrorSwitch;
                case 4:
                    tempLine = MortalTerror[NormanID];
                    goto escapeTerrorSwitch;
                case 5:
                    tempLine = MortalTerror[GreenwoodID];
                }

            escapeTerrorSwitch:
                globalMortalCount++;
                firstTimeTerror = false;
                TerrorLineCount = 0;
            }

            FilenameLineCount++;
            ScriptLineCount++;
            AnimationLineCount++;
            TypeLineCount++;
            NameLineCount++;
            BioLineCount++;
            GenderLineCount++;
            MoodLineCount++;
            SubfearLineCount++;
            FearLineCount++;
            BeliefLineCount++;
            MadnessLineCount++;
            WillpowerLineCount++;
            TerrorLineCount++;


        }

        else
        {

            if (countScenario == true) {

                missionCount++;
                countScenario = false;

            }

            FilenameLineCount = 0;
            ScriptLineCount = 0;
            AnimationLineCount = 0;
            TypeLineCount = 0;
            NameLineCount = 0;
            BioLineCount = 0;
            GenderLineCount = 0;
            MoodLineCount = 0;
            SubfearLineCount = 0;
            FearLineCount = 0;
            BeliefLineCount = 0;
            MadnessLineCount = 0;
            WillpowerLineCount = 0;
            TerrorLineCount = 0;

            firstTimeFilename = true;
            firstTimeScript = true;
            firstTimeAnimation = true;
            firstTimeType = true;
            firstTimeName = true;
            firstTimeBio = true;
            firstTimeGender = true;
            firstTimeMood = true;
            firstTimeSubfear = true;
            firstTimeFear = true;
            firstTimeBelief = true;
            firstTimeMadness = true;
            firstTimeWillpower = true;
            firstTimeTerror = true;
        }

        asmOut << tempLine << endl;
    }

    asmIn.close();
    asmOut.close();

}


void OutputMortalCrashFix()
{
    ofstream asmOut(ModsPath + "Random_ScriptedMortalFixes.asm");

    asmOut << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl << endl << endl;

    asmOut << "[ENABLE]" << endl;

    asmOut << "" << endl;

    asmOut << "alloc(newmem,100)" << endl;
    asmOut << "newmem:" << endl;
    asmOut << "cmp eax, " << MortalName[CousinID].substr(3) << endl;
    asmOut << "je 0054B124" << endl;
    asmOut << "add eax,FFFFFF25" << endl;
    asmOut << "jmp 0054AFF8" << endl;

    asmOut << "004EC726:" << endl;
    asmOut << "push 00909108" << endl;
    asmOut << "004EC7A6:" << endl;
    asmOut << "push 00909108" << endl;
    asmOut << "004EC825:" << endl;
    asmOut << "push 00909108" << endl;

    asmOut << "005376E1:" << endl;
    asmOut << "push 00909108" << endl;

    asmOut << "//Crappy fix by removing the particle effects. Should fix this properly sometime." << endl;
    asmOut << "004DB119:" << endl;
    asmOut << "db 90 90 90 90 90" << endl;
    asmOut << "004DAE0D:" << endl;
    asmOut << "db 90 90 90 90 90" << endl;
    asmOut << "004DAE9E:" << endl;
    asmOut << "db 90 90 90 90 90" << endl;
    asmOut << "004DAF2B:" << endl;
    asmOut << "db 90 90 90 90 90" << endl;

    asmOut << "//Script that use Mortal names fixes" << endl;
    asmOut << "0054B096:" << endl;
    asmOut << "cmp [esi+44]," << MortalName[CousinID].substr(3) << endl;
    asmOut << "0054B117:" << endl;
    asmOut << "cmp [esi+44]," << MortalName[CousinID].substr(3) << endl;
    asmOut << "0054BB03:" << endl;
    asmOut << "cmp eax," << MortalName[CousinID].substr(3) << endl;

    asmOut << "0054AFF3:" << endl;
    asmOut << "jmp newmem" << endl;
    asmOut << "0054B63C:" << endl;
    asmOut << "db 00" << endl;

    asmOut << "0054B9AE:" << endl;
    asmOut << "cmp eax," << MortalName[HoboID].substr(3) << endl;




    asmOut << "[DISABLE]" << endl;

    asmOut.close();


}


string doesStringContainInvalidCharacters(string str)
{
    string allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789. ";
    string InvalidChars = "";

    for (int unsigned i = 0; i < str.length(); i++)
    {
        if (allowedChars.find(str[i]) == string::npos)
        {
            if (InvalidChars.find(str[i]) == string::npos)
            {
                InvalidChars += str[i];
                InvalidChars += " ";
            }
        }
    }



    return InvalidChars;
}

void GetPowerData()
{
    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "PowerData.asm");
    string tempLine = "";
    stringstream ss;

    int PowerCount = 0;


    Band1PowerCount = 0;
    Band2PowerCount = 0;
    Band3PowerCount = 0;
    Band4PowerCount = 0;
    Band5PowerCount = 0;
    Band6PowerCount = 0;
    Band7PowerCount = 0;
    Band8PowerCount = 0;
    Band9PowerCount = 0;
    Band10PowerCount = 0;



    while (tempLine != "[ENABLE]")
    {
        std::getline(asmIn, tempLine);

        if (tempLine.substr(0, 3) == "db ")
        {

            PowerID_arr[PowerCount] = PowerCount;
            ss << hex << tempLine.substr(28, 2);
            ss >> Band_arr[PowerCount];
            ss.str("");
            ss.clear();

            switch (Band_arr[PowerCount])
            {
            case 1:
                Band1Powers[Band1PowerCount] = PowerCount;
                Band1PowerCount++;
                goto escapeShitCode;
            case 2:
                Band2Powers[Band2PowerCount] = PowerCount;
                Band2PowerCount++;
                goto escapeShitCode;
            case 3:
                Band3Powers[Band3PowerCount] = PowerCount;
                Band3PowerCount++;
                goto escapeShitCode;
            case 4:
                Band4Powers[Band4PowerCount] = PowerCount;
                Band4PowerCount++;
                goto escapeShitCode;
            case 5:
                Band5Powers[Band5PowerCount] = PowerCount;
                Band5PowerCount++;
                goto escapeShitCode;
            case 6:
                Band6Powers[Band6PowerCount] = PowerCount;
                Band6PowerCount++;
                goto escapeShitCode;
            case 7:
                Band7Powers[Band7PowerCount] = PowerCount;
                Band7PowerCount++;
                goto escapeShitCode;
            case 8:
                Band8Powers[Band8PowerCount] = PowerCount;
                Band8PowerCount++;
                goto escapeShitCode;
            case 9:
                Band9Powers[Band9PowerCount] = PowerCount;
                Band9PowerCount++;
                goto escapeShitCode;
            case 10:
                Band10Powers[Band10PowerCount] = PowerCount;
                Band10PowerCount++;

            }

            escapeShitCode:

            PowerCount++;
        }
    }

    asmIn.close();

}

int ReturnBandIndex(int PowerID, int* PowerID_arr, int* Band_arr)
{
    if (PowerID == 133)
        return 0;
 
    for (int i = 0; i < 132; i++)
    {
        if (PowerID_arr[i] == PowerID)
        {
            return Band_arr[i];
        }
    }

    string fuckthisshit;
    stringstream ss;
    ss << PowerID;
    ss >> fuckthisshit;
    ss.str("");
    ss.clear();

    string error = "Power ID: " + fuckthisshit + " was not found.";

    const char* invalidChars_array = error.c_str();

    wxString invalidCharsUsageError(invalidChars_array, wxConvUTF8);

    wxMessageBox(error, "Error :(");

    return 0;
}

void GetRandomFetters(int HaunterCount)
{
    stringstream ss;

    int FetterValue = 0;
    int FetterCount = 0;
    int FetterFlag = 0;
    int tempValue = 0;

    int x = 0;

    for (int i = 0; i < HaunterCount; i++)
    {
        FetterCount = 0;
        FetterFlag = 0;
        tempValue = 0;

        ss << hex << HaunterFetterFlagStringArray[i];
        ss >> FetterValue;
        ss.str("");
        ss.clear();


        if (FetterValue & 0x1) //electrical
        {
            FetterCount++;
        }

        if (FetterValue & 0x2) //mirror
        {
            FetterCount++;
        }

        if (FetterValue & 0x4) //air
        {
            FetterCount++;
        }

        if (FetterValue & 0x8) //fire
        {
            FetterCount++;
        }

        if (FetterValue & 0x10) //water
        {
            FetterCount++;
        }

        if (FetterValue & 0x20) //corpse
        {
            FetterCount++;
        }

        if (FetterValue & 0x40) //child
        {
            FetterCount++;
        }

        if (FetterValue & 0x80) //inside
        {
            FetterCount++;
        }

        if (FetterValue & 0x100) //earth
        {
            FetterCount++;
        }

        if (FetterValue & 0x200) //outside
        {
            FetterCount++;
        }

        if (FetterValue & 0x400) //thoroughfare
        {
            FetterCount++;
        }

        if (FetterValue & 0x800) //emotional
        {
            FetterCount++;
        }

        if (FetterValue & 0x1000) //violence
        {
            FetterCount++;
        }

        if (FetterValue & 0x2000) //murder
        {
            FetterCount++;
        }

        if (FetterValue & 0x4000) //sleeping
        {
            FetterCount++;
        }

        if (FetterValue & 0x20000) //road
        {
            FetterCount++;
        }



        for (int z = 0; z < FetterCount; z++)
        {
        getNewFetter:

            srand(seed + z + 69 + x);
            x++;
            tempValue = rand() % 16;

            if (tempValue == 15)
                tempValue += 2;

            if (((tempValue == 1 || tempValue == 14) && (pBBand7Count[i] == 0 && pLBand7Count[i] == 0)) || FetterFlag & (1 << tempValue))
            {
                goto getNewFetter;
            }

            FetterFlag = FetterFlag + (1 << tempValue);
        }

        ss << hex << FetterFlag;
        HaunterFetterFlagStringArray[i] = ss.str();
        ss.str("");
        ss.clear();

        x++;

    }
}

void OutputPowerCrashFixes()
{
    ofstream OutputASM(ModsPath + "PowerCrashFixes.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "005C2DAD: //disable scattered swarm particle effects" << endl;
    OutputASM << "db 90 90 90 90 90" << endl;
    OutputASM << "005C4685: //disable legion particle effects" << endl;
    OutputASM << "db 90 90 90 90 90" << endl;
    OutputASM << "005C53B2: //disable swarm strike particle effects" << endl;
    OutputASM << "db 90 90 90 90 90" << endl;
    OutputASM << "005C3128: //scattered" << endl;
    OutputASM << "db 90 90" << endl;
    OutputASM << "005C49D4: //legion" << endl;
    OutputASM << "db 90 90" << endl;
    OutputASM << "005C3D7E: //dense swarm" << endl;
    OutputASM << "db 90 90" << endl;

    OutputASM << "[DISABLE]" << endl;
    OutputASM << "005C2DAD: //disable scattered swarm particle effects" << endl;
    OutputASM << "call 0063A440" << endl;
    OutputASM << "005C4685: //disable legion particle effects" << endl;
    OutputASM << "call 0063A440" << endl;
    OutputASM << "005C53B2: //disable swarm strike particle effects" << endl;
    OutputASM << "call 0063A440" << endl;


    



    OutputASM.close();
}


void GetRandomPowers(int HaunterCount)
{
    int inc = 5;
    int i;
    int LCount;

    int tempL1Power = -1;
    int tempL2Power = -1;
    int tempBPower = -1;
    int tempValue = -1;




    stringstream ss;

    for (int GhostID = 0; GhostID < HaunterCount; GhostID++)
    {

       

        pB_Band1[GhostID] = "dd 00000085";
        pB_Band2[GhostID] = "dd 00000085";
        pB_Band3[GhostID] = "dd 00000085";
        pB_Band4[GhostID] = "dd 00000085";
        pB_Band5[GhostID] = "dd 00000085";
        pB_Band6[GhostID] = "dd 00000085";
        pB_Band7[GhostID] = "dd 00000085";
        pB_Band8[GhostID] = "dd 00000085";
        pB_Band9[GhostID] = "dd 00000085";
        pB_Band10[GhostID] = "dd 00000085";



        pL1_Band1[GhostID] = "dd 00000085";
        pL1_Band2[GhostID] = "dd 00000085";
        pL1_Band3[GhostID] = "dd 00000085";
        pL1_Band4[GhostID] = "dd 00000085";
        pL1_Band5[GhostID] = "dd 00000085";
        pL1_Band6[GhostID] = "dd 00000085";
        pL1_Band7[GhostID] = "dd 00000085";
        pL1_Band8[GhostID] = "dd 00000085";
        pL1_Band9[GhostID] = "dd 00000085";
        pL1_Band10[GhostID] = "dd 00000085";
        pL2_Band1[GhostID] = "dd 00000085";
        pL2_Band2[GhostID] = "dd 00000085";
        pL2_Band3[GhostID] = "dd 00000085";
        pL2_Band4[GhostID] = "dd 00000085";
        pL2_Band5[GhostID] = "dd 00000085";
        pL2_Band6[GhostID] = "dd 00000085";
        pL2_Band7[GhostID] = "dd 00000085";
        pL2_Band8[GhostID] = "dd 00000085";
        pL2_Band9[GhostID] = "dd 00000085";
        pL2_Band10[GhostID] = "dd 00000085";
        
        tempBPower = -1;
        if (pBBand1Count[GhostID])
        {
        pissOffNonePower:
            srand(seed + inc);
            inc++;
            tempBPower = Band1Powers[rand() % Band1PowerCount];
            if (tempBPower == 0x83)
            {
                goto pissOffNonePower;
            }
            ss << hex << tempBPower;
            pB_Band1[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand1Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
                getAnother:
                srand(seed + inc);
                inc++;
                tempL2Power = Band1Powers[rand() % Band1PowerCount];
                if (tempL2Power == tempL1Power || tempL2Power == 0x83 || tempL2Power == tempBPower)
                {
                    goto getAnother;
                }
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band1[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                getAnotherL1B1:
                srand(seed + inc);
                inc++;
                tempL1Power = Band1Powers[rand() % Band1PowerCount];
                if (tempL1Power == 0x83 || tempL1Power == tempBPower)
                {
                    goto getAnotherL1B1;
                }
                ss << hex << tempL1Power;
                LCount++;
                pL1_Band1[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }

        tempBPower = -1;
        if (pBBand2Count[GhostID])
        {
            srand(seed + inc);
            inc++;
            tempBPower = Band2Powers[rand() % Band2PowerCount];
            ss << hex << tempBPower;
            pB_Band2[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand2Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother2:
                srand(seed + inc);
                inc++;
                tempL2Power = Band2Powers[rand() % Band2PowerCount];
                if (tempL2Power == tempL1Power || tempL2Power == tempBPower)
                {
                    goto getAnother2;
                }
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band2[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                getAnother4678321:
                srand(seed + inc);
                inc++;
                tempL1Power = Band2Powers[rand() % Band2PowerCount];
                if (tempL1Power == tempBPower)
                {
                    goto getAnother4678321;
                }
                ss << hex << tempL1Power;
                LCount++;
                pL1_Band2[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }

        tempBPower = -1;
        if (pBBand3Count[GhostID])
        {
        fuckoffuselessMirrorPower:
            srand(seed + inc);
            inc++;
            tempBPower = Band3Powers[rand() % Band3PowerCount];
            ss << hex << HaunterFetterFlagStringArray[GhostID];
            ss >> tempValue;
            ss.str("");
            ss.clear();
            if (tempBPower == 0x43 && !(tempValue & 0x2))
            {
                goto fuckoffuselessMirrorPower;
            }
            ss << hex << tempBPower;
            pB_Band3[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand3Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother3:
                srand(seed + inc);
                inc++;
                tempL2Power = Band3Powers[rand() % Band3PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if (tempL2Power == tempL1Power  || tempL2Power == tempBPower || (tempL2Power == 0x43 && !(tempValue & 0x2)))
                {
                    
                    goto getAnother3;
                }
                inc++;
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band3[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                fuckoffuselessMirrorPower2:
                srand(seed + inc);
                inc++;
                tempL1Power = Band3Powers[rand() % Band3PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if ((tempL1Power == 0x43 && !(tempValue & 0x2)) || tempL1Power == tempBPower)
                {
                    goto fuckoffuselessMirrorPower2;
                }
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band3[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand4Count[GhostID])
        {
        fuckoffThing:
            srand(seed + inc);
            inc++;
            tempBPower = Band4Powers[rand() % Band4PowerCount];
            ss << hex << HaunterFetterFlagStringArray[GhostID];
            ss >> tempValue;
            ss.str("");
            ss.clear();
            if (tempBPower == 0x44 && !(tempValue & 2))
            {
                goto fuckoffThing;
            }
            ss << hex << tempBPower;
            pB_Band4[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand4Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother4:
                srand(seed + inc);
                inc++;
                tempL2Power = Band4Powers[rand() % Band4PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if (tempL2Power == tempBPower || tempL2Power == tempL1Power || (tempL2Power == 0x44 && !(tempValue & 2)))
                {
                    
                    goto getAnother4;
                }
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band4[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                isee:
                srand(seed + inc);
                inc++;
                tempL1Power = Band4Powers[rand() % Band4PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if ((tempL1Power == 0x44 && !(tempValue & 2) || tempL1Power == tempBPower))
                {
                    goto isee;
                }
                ss << hex << tempL1Power;
                LCount++;
                pL1_Band4[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand5Count[GhostID])
        {
            srand(seed + inc);
            inc++;
            tempBPower = Band5Powers[rand() % Band5PowerCount];
            ss << hex << tempBPower;
            pB_Band5[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand5Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother5:
                srand(seed + inc);
                inc++;
                tempL2Power = Band5Powers[rand() % Band5PowerCount];
                if (tempL2Power == tempL1Power || tempL2Power == tempBPower)
                {
                    goto getAnother5;
                }
                inc++;
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band5[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                awerhasjedr:
                srand(seed + inc);
                inc++;
                tempL1Power = Band5Powers[rand() % Band5PowerCount];
                if (tempL1Power == tempBPower)
                    goto awerhasjedr;
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band5[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand6Count[GhostID])
        {
        fuckoffThing69:
            srand(seed + inc);
            inc++;
            tempBPower = Band6Powers[rand() % Band6PowerCount];
            ss << hex << HaunterFetterFlagStringArray[GhostID];
            ss >> tempValue;
            ss.str("");
            ss.clear();
            if (tempBPower == 0x45 && !(tempValue & 2))
            {
                goto fuckoffThing69;
            }
            ss << hex << tempBPower;
            pB_Band6[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand6Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother6:
                srand(seed + inc);
                inc++;
                tempL2Power = Band6Powers[rand() % Band6PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if (tempL2Power == tempBPower || tempL2Power == tempL1Power || (tempL2Power == 0x45 && !(tempValue & 2)))
                {
 
                    goto getAnother6;
                }
                inc++;
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band6[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                fuckoffThing169:
                srand(seed + inc);
                inc++;
                tempL1Power = Band6Powers[rand() % Band6PowerCount];
                ss << hex << HaunterFetterFlagStringArray[GhostID];
                ss >> tempValue;
                ss.str("");
                ss.clear();
                if ((tempL1Power == 0x45 && !(tempValue & 2) || tempL1Power == tempBPower))
                {
                    goto fuckoffThing169;
                }
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band6[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand7Count[GhostID])
        {

        fuckoffSleepwalk2:
            srand(seed + inc);
            inc++;
            tempBPower = Band7Powers[rand() % Band7PowerCount];
            if ((tempBPower == 0x24 && ((HaunterFetterFlagStringArray[GhostID] != "4000") && HaunterFetterFlagStringArray[GhostID] != "00004000")) || tempBPower == 0x11)
            {
                
                goto fuckoffSleepwalk2;
            }


            if (HaunterFetterFlagStringArray[GhostID] == "4000" || HaunterFetterFlagStringArray[GhostID] == "00004000")
            {
                tempBPower = 0x24;
            }
            if (HaunterFetterFlagStringArray[GhostID] == "2" || HaunterFetterFlagStringArray[GhostID] == "00000002")
            {
                tempBPower = 0x46;
            }
            ss << hex << tempBPower;
            pB_Band7[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand7Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother7:
                srand(seed + inc);
                inc++;
                tempL2Power = Band7Powers[rand() % Band7PowerCount];
                if (tempL2Power == tempL1Power || (tempL2Power == 0x24 && ((HaunterFetterFlagStringArray[GhostID] != "4000") && HaunterFetterFlagStringArray[GhostID] != "00004000")) || tempL2Power == 0x11 || tempL2Power == tempBPower)
                {
                    goto getAnother7;
                }
                inc++;
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band7[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                fuckoffSleepwalk:
                srand(seed + inc);
                inc++;
                tempL1Power = Band7Powers[rand() % Band7PowerCount];
                if ((tempL1Power == 0x24 && ((HaunterFetterFlagStringArray[GhostID] != "4000") && HaunterFetterFlagStringArray[GhostID] != "00004000")) || tempL1Power == 0x11 || tempL1Power == tempBPower)
                {
                    goto fuckoffSleepwalk;
                }
                if (HaunterFetterFlagStringArray[GhostID] == "4000" || HaunterFetterFlagStringArray[GhostID] == "00004000")
                    tempL1Power = 0x24; //sleepwalk
                if (HaunterFetterFlagStringArray[GhostID] == "2" || HaunterFetterFlagStringArray[GhostID] == "00000002")
                    tempL1Power = 0x46; //clone
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band7[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand8Count[GhostID])
        {
        pissoffloathsomeshitpower:
            srand(seed + inc);
            inc++;
            tempBPower = Band8Powers[rand() % Band8PowerCount];
            if (tempBPower == 0x1b && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A")) //1a - shapeshifter 1d - abhorrent 1b- loathsome
            {
                goto pissoffloathsomeshitpower;
            }
            ss << hex << tempBPower;
            pB_Band8[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand8Count[GhostID]; i++)
        {
            

            if (LCount == 1)
            {
            getAnother8:
                srand(seed + inc);
                inc++;
                tempL2Power = Band8Powers[rand() % Band8PowerCount];
                if (tempL2Power == tempBPower || tempL2Power == tempL1Power || (tempL2Power == 0x1b && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A")))
                {
                   
                    goto getAnother8;
                }
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band8[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
            pissoffloathsoneshitpower2:
                srand(seed + inc);
                inc++;
                tempL1Power = Band8Powers[rand() % Band8PowerCount];
                if (tempL1Power == tempBPower || (tempL1Power == 0x1b && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A"))) //1a - shapeshifter 1d - abhorrent 1b- loathsome
                {
                    goto pissoffloathsoneshitpower2;
                }
                ss << hex << tempL1Power;
                LCount++;
                pL1_Band8[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand9Count[GhostID])
        {
            srand(seed + inc);
            inc++;
            tempBPower = Band9Powers[rand() % Band9PowerCount];
            ss << hex << tempBPower;
            pB_Band9[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand9Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother9:
                srand(seed + inc);
                inc++;
                tempL2Power = Band9Powers[rand() % Band9PowerCount];
                if (tempL2Power == tempBPower || tempL2Power == tempL1Power)
                {
                    goto getAnother9;
                }
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band9[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                axwexdawxewa:
                srand(seed + inc);
                inc++;
                tempL1Power = Band9Powers[rand() % Band9PowerCount];
                if (tempL1Power == tempBPower)
                    goto axwexdawxewa;
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band9[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }
        tempBPower = -1;
        if (pBBand10Count[GhostID])
        {
        pissoffaspect:
            srand(seed + inc);
            inc++;
            tempBPower = Band10Powers[rand() % Band10PowerCount];
            if (tempBPower == 0x1d && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A")) //1a - shapeshifter 1d - abhorrent 1b- loathsome
            {
                goto pissoffaspect;
            }
            ss << hex << tempBPower;
            pB_Band10[GhostID] = "dd " + ss.str();
            ss.str("");
            ss.clear();
        }
        tempL1Power = -1;
        tempL2Power = -1;
        LCount = 0;
        for (i = 0; i < pLBand10Count[GhostID]; i++)
        {

            if (LCount == 1)
            {
            getAnother10:
                srand(seed + inc);
                inc++;
                tempL2Power = Band10Powers[rand() % Band10PowerCount];
                if (tempL2Power == tempBPower || tempL2Power == tempL1Power || (tempL2Power == 0x1d && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A")))
                {
                    
                    goto getAnother10;
                }
                inc++;
                LCount++;
                ss << hex << tempL2Power;
                pL2_Band10[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
            else
            {
                pissoffaspect69:
                srand(seed + inc);
                inc++;
                tempL1Power = Band10Powers[rand() % Band10PowerCount];
                if (tempL1Power == tempBPower || (tempL1Power == 0x1d && (pB_Band7[GhostID] != "dd 46" && pB_Band7[GhostID] != "dd 00000046" && pB_Band7[GhostID] != "dd 1a" && pB_Band7[GhostID] != "dd 0000001A" && pL1_Band7[GhostID] != "dd 46" && pL1_Band7[GhostID] != "dd 00000046" && pL1_Band7[GhostID] != "dd 0000001A" && pL2_Band7[GhostID] != "dd 46" && pL2_Band7[GhostID] != "dd 00000046" && pL2_Band7[GhostID] != "dd 1a" && pL2_Band7[GhostID] != "dd 0000001A"))) //1a - shapeshifter 1d - abhorrent 1b- loathsome
                {
                    goto pissoffaspect69;
                }
                ss << hex << tempL1Power;
                inc++;
                LCount++;
                pL1_Band10[GhostID] = "dd " + ss.str();
                ss.str("");
                ss.clear();
            }
        }




    }


}


void RandomiseGhoulroom(int HaunterCount)
{

    ifstream asmIn (ModsPath + "Randomiser_Backup\\" + "GRSpawnData.asm");
    ofstream asmOut(ModsPath + "GRSpawnData.asm" + ".Randomiser_TEMP");

    string* tempScriptArr = new string[100];

    string tempLine;

    int i = 0;

    while (tempLine != "grSpawn:")
    {
        std::getline(asmIn, tempLine);
    }

    while (69)
    {
        std::getline(asmIn, tempLine);
        if (tempLine == "db B4 75 8C 00")
            break;
        if (tempLine != "dd 008C5724")
        {
            tempScriptArr[i] = tempLine;
            i++;
        }
        
        std::getline(asmIn, tempLine);
        std::getline(asmIn, tempLine);
        std::getline(asmIn, tempLine);
       
    }


    shuffle(tempScriptArr, tempScriptArr + HaunterCount - 1, default_random_engine(seed + 16));

    asmIn.clear();
    asmIn.seekg(0);

    while (tempLine != "grSpawn:")
    {
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }


    for (i = 0; asmIn; i++)
    {
        std::getline(asmIn, tempLine);
        if (tempLine == "db B4 75 8C 00")
            break;
        if (tempLine != "dd 008C5724")
            asmOut << tempScriptArr[i] << endl;
        else
        {
            asmOut << tempLine << endl;
            i--;
        }
            
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    asmOut << tempLine << endl;
    std::getline(asmIn, tempLine);
    asmOut << tempLine << endl;
    std::getline(asmIn, tempLine);
    asmOut << tempLine << endl;
    std::getline(asmIn, tempLine);
    asmOut << tempLine << endl;
    std::getline(asmIn, tempLine);
    asmOut << tempLine << endl;


    for (i = 0; asmIn; i++)
    {
        std::getline(asmIn, tempLine);
        if (tempLine == "db B4 75 8C 00")
            break;
        if (tempLine != "dd 008C5724")
            asmOut << tempScriptArr[i] << endl;
        else
        {
            asmOut << tempLine << endl;
            i--;
        }
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;

    }

    asmOut << tempLine << endl;

    while (asmIn)
    {
        std::getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    asmIn.close();
    asmOut.close();

    delete[] tempScriptArr;
}

////screw this method, let's try randomising the IDs
//void RandomiseText()
//{
//
//    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "StringHashMap.asm");
//    ofstream asmOut(ModsPath + "StringHashMap.asm" + ".Randomiser_TEMP");
//
//    string tempLine = "";
//
//    string* textEXEAddressesSTR = new string[3000];
//    string* textScriptLabelsSTR = new string[3000];
//
//
//    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
//    {
//        getline(asmIn, tempLine);
//    }
//
//    int i;
//
//    int exeCount = 0;
//    int labelCount = 0;
//
//    while (true)
//    {
//        getline(asmIn, tempLine);
//
//        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
//        {
//            textEXEAddressesSTR[exeCount] = tempLine.substr(15);
//            exeCount++;
//        }
//        else
//        {
//            for (i = 0; strcmp(tempLine.c_str(), "EndOfSHM:") != 0; i++)
//            {
//                if (strcmp(tempLine.substr(0, 2).c_str(), "dd") == 0) //first two characters are 'dd'
//                {
//                    getline(asmIn, tempLine);
//                    textScriptLabelsSTR[labelCount] = tempLine.substr(3);
//                    labelCount++;
//                    getline(asmIn, tempLine);
//                    
//
//                }
//            }
//
//            break;
//        }
//
//            
//            
//    }
//
//    while (asmIn)
//    {
//        getline(asmIn, tempLine);
//    }
//
//
//    //Reading done
//
//    
//
//
//
//    shuffle(textEXEAddressesSTR, textEXEAddressesSTR + exeCount - 1, default_random_engine(seed));
//    shuffle(textScriptLabelsSTR, textScriptLabelsSTR + labelCount - 1, default_random_engine(seed));
//    
//
//    //writing
//
//    asmIn.clear();
//    asmIn.seekg(0);
//
//    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
//    {
//        getline(asmIn, tempLine);
//        asmOut << tempLine << endl;
//    }
//
//    exeCount = 0;
//    labelCount = 0;
//
//    while (true)
//    {
//        getline(asmIn, tempLine);
//
//        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
//        {
//            asmOut << tempLine.substr(0, 15) + textEXEAddressesSTR[exeCount] << endl;
//            exeCount++;
//        }
//        else
//        {
//            while (strcmp(tempLine.c_str(), "EndOfSHM:") != 0)
//            {
//                if (strcmp(tempLine.substr(0, 2).c_str(), "dd") == 0) //first two characters are 'dd'
//                {
//                    asmOut << tempLine << endl;
//                    getline(asmIn, tempLine);
//                    asmOut << tempLine.substr(0, 3) + textScriptLabelsSTR[labelCount] << endl;
//                    labelCount++;
//                    getline(asmIn, tempLine);
//                    
//
//
//                }
//
//                
//            }
//
//            asmOut << tempLine << endl;
//
//            break;
//        }
//    }
//
//    while (asmIn)
//    {
//        getline(asmIn, tempLine);
//        asmOut << tempLine << endl;
//    }
//
//    asmIn.close();
//    asmOut.close();
//
//    delete[] textEXEAddressesSTR;
//    delete[] textScriptLabelsSTR;
//
//
//}
////
//
//void RandomiseText()
//{
//
//    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "StringHashMap.asm");
//    ofstream asmOut(ModsPath + "StringHashMap.asm" + ".Randomiser_TEMP");
//
//    string tempLine = "";
//
//    string* IDs = new string[3000];
//    int IDcount = 0;
//
//
//    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
//    {
//        getline(asmIn, tempLine);
//    }
//
//    string ZeroString;
//    string newString;
//
//    while (true)
//    {
//        getline(asmIn, tempLine);
//
//        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
//        {
//            IDs[IDcount] = tempLine.substr(3, 11);
//            IDcount++;
//        }
//        else
//        {
//            while (strcmp(tempLine.c_str(), "EndOfSHM:") != 0)
//            {
//                
//                tempLine = tempLine.substr(3);
//
//
//                string ZeroString = "";
//
//                for (int i = 0; i < (8 - tempLine.length()); i++)
//                {
//                    ZeroString += '0';
//                }
//
//                tempLine = ZeroString + tempLine;
//
//                char a = tempLine[6];
//                char b = tempLine[7];
//                char c = tempLine[4];
//                char d = tempLine[5];
//                char e = tempLine[2];
//                char f = tempLine[3];
//                char g = tempLine[0];
//                char h = tempLine[1];
//
//                tempLine = std::string() + a + b + ' ' + c + d + ' ' + e + f + ' ' + g + h;
//
//
//
//                IDs[IDcount] = tempLine;
//                IDcount++;
//
//
//                getline(asmIn, tempLine);
//                getline(asmIn, tempLine);
//            }
//
//            break;
//        }
//
//
//
//    }
//
//    while (asmIn)
//    {
//        getline(asmIn, tempLine);
//    }
//
//
//    //Reading done
//
//
//
//
//
//    shuffle(IDs, IDs + IDcount - 1, default_random_engine(seed));
//
//
//    //writing
//
//    asmIn.clear();
//    asmIn.seekg(0);
//
//    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
//    {
//        getline(asmIn, tempLine);
//        asmOut << tempLine << endl;
//    }
//
//    IDcount = 0;
//
//    while (true)
//    {
//        getline(asmIn, tempLine);
//
//        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
//        {
//            asmOut << "db " + IDs[IDcount] + ' ' + tempLine.substr(15, 11) << endl;
//            IDcount++;
//        }
//        else
//        {
//            while (strcmp(tempLine.c_str(), "EndOfSHM:") != 0)
//            {
//                if (strcmp(tempLine.substr(0, 2).c_str(), "dd") == 0) //first two characters are 'dd'
//                {
//                    asmOut << "db " + IDs[IDcount] << endl;
//                    IDcount++;
//                    
//                    getline(asmIn, tempLine);
//                    asmOut << tempLine << endl;
//                    getline(asmIn, tempLine);
//
//
//
//                }
//
//
//            }
//
//            asmOut << tempLine << endl;
//
//            break;
//        }
//    }
//
//    while (asmIn)
//    {
//        getline(asmIn, tempLine);
//        asmOut << tempLine << endl;
//    }
//
//    asmIn.close();
//    asmOut.close();
//
//    delete[] IDs;
//
//
//}

void RandomiseText()
{

    ifstream asmIn(ModsPath + "Randomiser_Backup\\" + "StringHashMap.asm");
    ofstream asmOut(ModsPath + "StringHashMap.asm" + ".Randomiser_TEMP");

    string tempLine = "";

    string* textAddressesSTR = new string[3000];


    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
    {
        getline(asmIn, tempLine);
    }


    int exeCount = 0;

    while (true)
    {
        getline(asmIn, tempLine);

        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
        {
            textAddressesSTR[exeCount] = LE2BE(RidOfSpaces(tempLine.substr(15)));
            exeCount++;
        }
        else
        {
           while (strcmp(tempLine.c_str(), "EndOfSHM:") != 0)
            {
                if (strcmp(tempLine.substr(0, 2).c_str(), "dd") == 0) //first two characters are 'dd'
                {
                    getline(asmIn, tempLine);
                    textAddressesSTR[exeCount] = tempLine.substr(3);
                    exeCount++;
                    getline(asmIn, tempLine);


                }
            }

            break;
        }



    }

    while (asmIn)
    {
        getline(asmIn, tempLine);
    }


    //Reading done





    shuffle(textAddressesSTR, textAddressesSTR + exeCount - 1, default_random_engine(seed));


    //writing

    asmIn.clear();
    asmIn.seekg(0);

    while (strcmp(tempLine.c_str(), "StringHashMap:") != 0) //not equal
    {
        getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    exeCount = 0;

    while (true)
    {
        getline(asmIn, tempLine);

        if (strcmp(tempLine.substr(0, 2).c_str(), "db") == 0) //first two characters are 'db'
        {
            asmOut << tempLine.substr(0, 14) << endl;
            asmOut << "dd " + textAddressesSTR[exeCount] << endl;
            exeCount++;
        }
        else
        {
            while (strcmp(tempLine.c_str(), "EndOfSHM:") != 0)
            {
                if (strcmp(tempLine.substr(0, 2).c_str(), "dd") == 0) //first two characters are 'dd'
                {
                    asmOut << tempLine << endl;
                    getline(asmIn, tempLine);
                    asmOut << tempLine.substr(0, 3) + textAddressesSTR[exeCount] << endl;
                    exeCount++;
                    getline(asmIn, tempLine);



                }


            }

            asmOut << tempLine << endl;

            break;
        }
    }

    while (asmIn)
    {
        getline(asmIn, tempLine);
        asmOut << tempLine << endl;
    }

    asmIn.close();
    asmOut.close();

    delete[] textAddressesSTR;


}
//


string LE2BE(string LEstr)
{
    
    
    string ZeroString = "";
    
    for (unsigned int i = 0; i < (8 - LEstr.length()); i++)
    {
        ZeroString += '0';
    }
    
    string eightCharLE = ZeroString + LEstr;
    
    char a = eightCharLE[6];
    char b = eightCharLE[7];
    char c = eightCharLE[4];
    char d = eightCharLE[5];
    char e = eightCharLE[2];
    char f = eightCharLE[3];
    char g = eightCharLE[0];
    char h = eightCharLE[1];
    
    return std::string() + a + b + c + d  + e + f  + g + h;
}

string RidOfSpaces(string str)
{
    string retStr = "";

    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            retStr += str[i];
        }
    }

    return retStr;
}

void PrintHighScareTableGhostExceptions()
{
    ofstream OutputASM(ModsPath + "Random_HiddenHighScareGhosts.asm");


    OutputASM << "//Only darkling and banzai" << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << "alloc(newmem,100)" << endl;
    OutputASM << "newmem: //check if Darkling" << endl;
    OutputASM << "je 004579D0" << endl;
    OutputASM << "mov eax,[ecx+ebp*4]" << endl;
    OutputASM << "sub eax, " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << "jne 004579E5" << endl;
    OutputASM << "jmp 004579BE" << endl;
    OutputASM << "004579B2:" << endl;
    OutputASM << "sub eax, " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << "004579D0:" << endl;
    OutputASM << "push "<< HaunterEnumArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << "004579B7:" << endl;
    OutputASM << "jmp newmem" << endl;
    OutputASM << "[DISABLE]" << endl;

    OutputASM.close();
}

void PrintDisablePoltergeistTricksterMortalImmunity()
{
    ofstream OutputASM(ModsPath + "Random_DisableMortalImmunity.asm");

    OutputASM << R"(
[ENABLE]

005F9700:
	mov eax,0
	ret
	
[DISABLE]
)";

    OutputASM.close();
}