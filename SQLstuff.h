#pragma once
#include <string>

using namespace std;

int sqlWrite(string textEntry, string entryID);

int sqlRead(string entryID);

int sqlDelete(string entryID);

int sqlList();

bool pwCheck(string password);