// Authors: Rafał Surdej, Adam Stec -- 01.2021

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <random>

#define EOW '\0'

struct Range
{
	int begin;
	int end;
};