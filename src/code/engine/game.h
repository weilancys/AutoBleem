//
// Created by screemer on 2018-12-15.
//
#pragma once

#include "../main.h"

//******************
// Disc
//******************
class Disc {
public:
    std::string diskName;
    std::string cueName = "";
    // verifications

    bool cueFound = false;
    bool binVerified = false;
};

//******************
// Game
//******************
class Game {
public:
    int folder_id;
    std::string fullPath;
    std::string saveStatePath;
    std::string pathName;
    std::string title;
    std::string publisher;
    std::string memcard;
    int players;
    int year;
    std::vector<Disc> discs;
    std::string favorite;

    bool gameDataFound = false;
    bool pcsxCfgFound = false;
    bool gameIniFound = false;
    bool gameIniValid = false;
    bool imageFound = false;
    bool licFound = false;
    bool automationUsed = false;
    int imageType=IMAGE_CUE_BIN;
    bool highRes = false;
    std::string firstBinPath = "";

    void readIni(std::string path);
    void saveIni(std::string path);
    void recoverMissingFiles();
    bool verify();
    bool print();
    void updateObj();
    bool validateCue(std::string cuePath, std::string path);
private:

    std::map<std::string, std::string> iniValues;
    void parseIni(std::string path);
    std::string valueOrDefault(std::string name, std::string def);
};
