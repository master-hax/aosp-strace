/*
 * Copyright (c) 2014-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

{ 0,			"PC(L)" },
{ 4,			"PC(U)" },
{ 8,			"SR(L)" },
{ 12,			"SR(U)" },
{ 16,			"syscall no.(L)" },
{ 20,			"syscall_no.(U)" },
{ 24,			"R0(L)" },
{ 28,			"R0(U)" },
{ 32,			"R1(L)" },
{ 36,			"R1(U)" },
{ 40,			"R2(L)" },
{ 44,			"R2(U)" },
{ 48,			"R3(L)" },
{ 52,			"R3(U)" },
{ 56,			"R4(L)" },
{ 60,			"R4(U)" },
{ 64,			"R5(L)" },
{ 68,			"R5(U)" },
{ 72,			"R6(L)" },
{ 76,			"R6(U)" },
{ 80,			"R7(L)" },
{ 84,			"R7(U)" },
{ 88,			"R8(L)" },
{ 92,			"R8(U)" },
{ 96,			"R9(L)" },
{ 100,			"R9(U)" },
{ 104,			"R10(L)" },
{ 108,			"R10(U)" },
{ 112,			"R11(L)" },
{ 116,			"R11(U)" },
{ 120,			"R12(L)" },
{ 124,			"R12(U)" },
{ 128,			"R13(L)" },
{ 132,			"R13(U)" },
{ 136,			"R14(L)" },
{ 140,			"R14(U)" },
{ 144,			"R15(L)" },
{ 148,			"R15(U)" },
{ 152,			"R16(L)" },
{ 156,			"R16(U)" },
{ 160,			"R17(L)" },
{ 164,			"R17(U)" },
{ 168,			"R18(L)" },
{ 172,			"R18(U)" },
{ 176,			"R19(L)" },
{ 180,			"R19(U)" },
{ 184,			"R20(L)" },
{ 188,			"R20(U)" },
{ 192,			"R21(L)" },
{ 196,			"R21(U)" },
{ 200,			"R22(L)" },
{ 204,			"R22(U)" },
{ 208,			"R23(L)" },
{ 212,			"R23(U)" },
{ 216,			"R24(L)" },
{ 220,			"R24(U)" },
{ 224,			"R25(L)" },
{ 228,			"R25(U)" },
{ 232,			"R26(L)" },
{ 236,			"R26(U)" },
{ 240,			"R27(L)" },
{ 244,			"R27(U)" },
{ 248,			"R28(L)" },
{ 252,			"R28(U)" },
{ 256,			"R29(L)" },
{ 260,			"R29(U)" },
{ 264,			"R30(L)" },
{ 268,			"R30(U)" },
{ 272,			"R31(L)" },
{ 276,			"R31(U)" },
{ 280,			"R32(L)" },
{ 284,			"R32(U)" },
{ 288,			"R33(L)" },
{ 292,			"R33(U)" },
{ 296,			"R34(L)" },
{ 300,			"R34(U)" },
{ 304,			"R35(L)" },
{ 308,			"R35(U)" },
{ 312,			"R36(L)" },
{ 316,			"R36(U)" },
{ 320,			"R37(L)" },
{ 324,			"R37(U)" },
{ 328,			"R38(L)" },
{ 332,			"R38(U)" },
{ 336,			"R39(L)" },
{ 340,			"R39(U)" },
{ 344,			"R40(L)" },
{ 348,			"R40(U)" },
{ 352,			"R41(L)" },
{ 356,			"R41(U)" },
{ 360,			"R42(L)" },
{ 364,			"R42(U)" },
{ 368,			"R43(L)" },
{ 372,			"R43(U)" },
{ 376,			"R44(L)" },
{ 380,			"R44(U)" },
{ 384,			"R45(L)" },
{ 388,			"R45(U)" },
{ 392,			"R46(L)" },
{ 396,			"R46(U)" },
{ 400,			"R47(L)" },
{ 404,			"R47(U)" },
{ 408,			"R48(L)" },
{ 412,			"R48(U)" },
{ 416,			"R49(L)" },
{ 420,			"R49(U)" },
{ 424,			"R50(L)" },
{ 428,			"R50(U)" },
{ 432,			"R51(L)" },
{ 436,			"R51(U)" },
{ 440,			"R52(L)" },
{ 444,			"R52(U)" },
{ 448,			"R53(L)" },
{ 452,			"R53(U)" },
{ 456,			"R54(L)" },
{ 460,			"R54(U)" },
{ 464,			"R55(L)" },
{ 468,			"R55(U)" },
{ 472,			"R56(L)" },
{ 476,			"R56(U)" },
{ 480,			"R57(L)" },
{ 484,			"R57(U)" },
{ 488,			"R58(L)" },
{ 492,			"R58(U)" },
{ 496,			"R59(L)" },
{ 500,			"R59(U)" },
{ 504,			"R60(L)" },
{ 508,			"R60(U)" },
{ 512,			"R61(L)" },
{ 516,			"R61(U)" },
{ 520,			"R62(L)" },
{ 524,			"R62(U)" },
{ 528,			"TR0(L)" },
{ 532,			"TR0(U)" },
{ 536,			"TR1(L)" },
{ 540,			"TR1(U)" },
{ 544,			"TR2(L)" },
{ 548,			"TR2(U)" },
{ 552,			"TR3(L)" },
{ 556,			"TR3(U)" },
{ 560,			"TR4(L)" },
{ 564,			"TR4(U)" },
{ 568,			"TR5(L)" },
{ 572,			"TR5(U)" },
{ 576,			"TR6(L)" },
{ 580,			"TR6(U)" },
{ 584,			"TR7(L)" },
{ 588,			"TR7(U)" },
/* Other fields in "struct user" */
/* This entry is in case pt_regs contains dregs (depends on
the kernel build options). */
XLAT_UOFF(regs),
XLAT_UOFF(fpu),
#include "../sh/userent0.h"