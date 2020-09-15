/**
 * @file convert.h
 * @author Gabe de la Cruz
 * @date September 8, 2020
 */
#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h> 
#include <ctype.h>

enum StateType{NORMAL, INWORD};

enum StateType handleNormalState(char c);
enum StateType handleInWordState(char c);

#endif