/**
 * Utils.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */
#ifndef UTILS_H
#define UTILS_H

#include "STD_TYPES.h"
#define REG32(BASE_ADDR, OFFSET)  (*(volatile uint32 *)((BASE_ADDR) + (OFFSET)))
#define OK 0U
#define NOK 1U

#endif /* UTILS_H */
