/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ddf5b5d */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/module_prototype.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};
static int ng5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {3U, 0U};
static unsigned int ng8[] = {4U, 0U};



static void Initial_63_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 6040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);

LAB4:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 5848);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB1;

}

static void Always_81_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 6288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 6096);
    xsi_process_wait(t2, 3125LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(81, ng0);

LAB5:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 2728);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

}

static void Always_85_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 6536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 6344);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(85, ng0);

LAB5:    xsi_set_current_line(86, ng0);
    t4 = (t0 + 3048);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 3048);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

}

static void Always_94_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 6784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 7600);
    *((int *)t2) = 1;
    t3 = (t0 + 6816);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(94, ng0);

LAB5:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 2888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(98, ng0);

LAB10:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(95, ng0);

LAB9:    xsi_set_current_line(96, ng0);
    t13 = ((char*)((ng3)));
    t14 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 1, 0LL);
    goto LAB8;

}

static void Always_104_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;

LAB0:    t1 = (t0 + 7032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 7616);
    *((int *)t2) = 1;
    t3 = (t0 + 7064);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(104, ng0);

LAB5:    xsi_set_current_line(105, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 3688);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(106, ng0);

LAB9:    xsi_set_current_line(107, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 3688);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB8;

}

static void Always_133_5(char *t0)
{
    char t4[8];
    char t16[32];
    char t17[8];
    char t18[64];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    int t15;

LAB0:    t1 = (t0 + 7280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 7632);
    *((int *)t2) = 1;
    t3 = (t0 + 7312);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(133, ng0);

LAB5:    xsi_set_current_line(135, ng0);
    t5 = (t0 + 1048U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t4 + 4);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 2);
    *((unsigned int *)t4) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 2);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 7U);
    t13 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t13 & 7U);
    t14 = (t0 + 4808);
    xsi_vlogvar_assign_value(t14, t4, 0, 0, 4);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 2);
    *((unsigned int *)t4) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 2);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 7U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 7U);

LAB6:    t6 = ((char*)((ng3)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 3, t6, 3);
    if (t15 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t15 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t15 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng7)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t15 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t15 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(137, ng0);

LAB18:    xsi_set_current_line(138, ng0);
    t7 = (t0 + 1048U);
    t14 = *((char **)t7);
    xsi_vlog_get_part_select_value(t16, 128, t14, 137, 10);
    t7 = (t0 + 3848);
    xsi_vlogvar_assign_value(t7, t16, 0, 0, 128);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    *((unsigned int *)t17) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 5);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t6 = (t0 + 4648);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 5);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t6 = (t0 + 4968);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 1);
    goto LAB17;

LAB9:    xsi_set_current_line(142, ng0);

LAB19:    xsi_set_current_line(143, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlog_get_part_select_value(t18, 256, t5, 201, 10);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t18, 0, 0, 256);
    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4168);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    *((unsigned int *)t17) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 5);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t6 = (t0 + 4648);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 5);
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t6 = (t0 + 4968);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 1);
    goto LAB17;

LAB11:    xsi_set_current_line(148, ng0);

LAB20:    xsi_set_current_line(149, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlog_get_part_select_value(t18, 256, t5, 201, 74);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t18, 0, 0, 256);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlog_get_part_select_value(t18, 256, t3, 73, 10);
    t2 = (t0 + 4168);
    xsi_vlogvar_assign_value(t2, t18, 0, 0, 256);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    *((unsigned int *)t17) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 5);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t6 = (t0 + 4648);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 5);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t6 = (t0 + 4968);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 1);
    goto LAB17;

LAB13:    xsi_set_current_line(154, ng0);

LAB21:    xsi_set_current_line(155, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlog_get_part_select_value(t18, 256, t5, 201, 138);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t18, 0, 0, 256);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlog_get_part_select_value(t18, 256, t3, 137, 10);
    t2 = (t0 + 4168);
    xsi_vlogvar_assign_value(t2, t18, 0, 0, 256);
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    *((unsigned int *)t17) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 5);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t6 = (t0 + 4648);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 5);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t6 = (t0 + 4968);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 1);
    goto LAB17;

LAB15:    xsi_set_current_line(160, ng0);

LAB22:    xsi_set_current_line(161, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlog_get_part_select_value(t18, 256, t5, 201, 10);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t18, 0, 0, 256);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 5);
    *((unsigned int *)t17) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 5);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t12 & 31U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 31U);
    t6 = (t0 + 4648);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 5);
    xsi_set_current_line(163, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t17, 0, 8);
    t2 = (t17 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t6 = (t0 + 4968);
    xsi_vlogvar_assign_value(t6, t17, 0, 0, 1);
    goto LAB17;

}


extern void work_m_15951279185161148872_4086771943_init()
{
	static char *pe[] = {(void *)Initial_63_0,(void *)Always_81_1,(void *)Always_85_2,(void *)Always_94_3,(void *)Always_104_4,(void *)Always_133_5};
	xsi_register_didat("work_m_15951279185161148872_4086771943", "isim/module_prototype_isim_beh.exe.sim/work/m_15951279185161148872_4086771943.didat");
	xsi_register_executes(pe);
}
