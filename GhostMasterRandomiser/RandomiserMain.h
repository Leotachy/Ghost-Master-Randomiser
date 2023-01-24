#pragma once

#include <string>
#include <random>
#include <sstream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <format>

using namespace std;

void Randomise();
int GetHaunterData();
void OutputHaunterData(string fileName, int StockHaunterCount, int HaunterCount);
void OutputActGifts(string fileName);
bool DeleteAndRename(string fileName);
void GetActGiftsForEachAct(string fileName);
void OutputRandomiserInfo();
void OutputScenarioOrder(string* Sc_Available_Array, string* Sc_Completed_Array, string* Sc_Name_Array, string* Sc_ScriptInstance_Array, int* ScenarioIndexes);
void GetRandomScenarioOrder(int ScenarioIndexes[]);
void GetSpecialHaunters(int HaunterCount);
void SubtractActGifts(int TotalGiftCount, int StockHaunterCount);
int GetCountOfOtherHauntersAndSubtractRestlessSpirits(int HaunterCount);
int GetDialogueHashesAndCountASM(string DialogueHash_arr[]);
string GetPathToEnglishVdTxt();
int GetDialogueHashesTXTAndCount(string NewPath, string* vdDialogueHash_arr, string* SpeechName);
void ClearSoundSubtitles(string* DialogueHash_arr, string* vdDialogueHash_arr, int vdDialogueCount, int DialogueCount);
int OutputSoundSubtitles(string* DialogueHash_arr, int DialogueCount);
void OutputNarratorSpeechHashes(string* SpeechNamesInHex);
void RandomiseHaunterDialogue(string* DialogueHash_arr, int DialogueCount, string* vdDialogueHash_arr, int vdDialogueCount);
string string_to_hex(const string& input);
size_t crc32bin(const char* byte, size_t ArrayLenght);
size_t crc32(const char* String);
void RandScenario_Haunting101();
void RandScenario_WeirdSeance();
void RandScenario_Calamityville();
void RandScenario_Summoners();
void RandScenario_Deadfellas();
void RandScenario_Unusual();
void RandScenario_Poultrygeist();
void RandScenario_Facepacks();
void RandScenario_Phantom();
void RandScenario_Wisp();
void RandScenario_Spooky();
void RandScenario_Ghostbreakers();
void RandScenario_MortalJacket();
void RandScenario_Cuckoos();
int GetMortalData(string fileName);
void OutputRandomMortals(int* MortalIDArrayWithoutSpecials, int TotalMortalCountInLevels);
void GetMortalIcons();
void OutputIconData(int* MortalIDArrayWithoutSpecials, int TotalMortalCountInLevels);
void GetSpecialMortals(int TotalMortalCountInLevels);
string doesStringContainInvalidCharacters(string str);
void GetPowerData();
int ReturnBandIndex(int PowerID, int* PowerID_arr, int* Band_arr);
void GetRandomFetters(int HaunterCount);
void OutputPowerCrashFixes();
void GetSpecialHaunters__GetAnyHaunter(int neededHaunters, int* ReturningArray, int HaunterCount, int currentHaunters);
void GetRandomPowers(int HaunterCount);
//added in version 2.01
void RandomiseGhoulroom(int HaunterCount);
//added in version 2.02
void OutputMortalCrashFix();
//added in version 2.03
void RandomiseText();
string LE2BE(string LEstr);
string RidOfSpaces(string str);
//added in version 2.04
void PrintHighScareTableGhostExceptions();
void PrintDisablePoltergeistTricksterMortalImmunity();