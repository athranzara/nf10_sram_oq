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
static const char *ng0 = "/local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/test_sigen.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng3[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng4[] = {50U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng5[] = {2936012801U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng6[] = {1U, 0U};
static unsigned int ng7[] = {150U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng8[] = {3925868545U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng9[] = {2U, 0U};
static unsigned int ng10[] = {250U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng11[] = {3U, 0U};
static unsigned int ng12[] = {350U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng13[] = {4294967295U, 0U};
static unsigned int ng14[] = {1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static int ng15[] = {1, 0};
static unsigned int ng16[] = {65535U, 0U};



static void Always_71_0(char *t0)
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
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 9144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 9960);
    *((int *)t2) = 1;
    t3 = (t0 + 9176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(71, ng0);

LAB5:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 4472U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(81, ng0);

LAB10:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 6472);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6312);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 7592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 7752);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 256, 0LL);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 7912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5672);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 8072);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5832);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 128, 0LL);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 8232);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5992);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 6792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6632);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 7272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7112);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 11, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(72, ng0);

LAB9:    xsi_set_current_line(73, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 6312);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 0LL);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6632);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5512);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5672);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5832);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5992);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7112);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 11);
    goto LAB8;

}

static void Always_93_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 9392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 9976);
    *((int *)t2) = 1;
    t3 = (t0 + 9424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(93, ng0);

LAB5:    xsi_set_current_line(95, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6152);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 256);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 6632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t5, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(99, ng0);

LAB16:    xsi_set_current_line(100, ng0);
    t7 = ((char*)((ng4)));
    t8 = (t0 + 6152);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 256);
    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB9:    xsi_set_current_line(105, ng0);

LAB17:    xsi_set_current_line(106, ng0);
    t3 = ((char*)((ng7)));
    t5 = (t0 + 6152);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 6952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB11:    xsi_set_current_line(111, ng0);

LAB18:    xsi_set_current_line(112, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 6152);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB13:    xsi_set_current_line(117, ng0);

LAB19:    xsi_set_current_line(118, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 6152);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 6952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

}

static void Always_126_2(char *t0)
{
    char t7[8];
    char t40[64];
    char t41[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    int t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;

LAB0:    t1 = (t0 + 9640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 9992);
    *((int *)t2) = 1;
    t3 = (t0 + 9672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(126, ng0);

LAB5:    xsi_set_current_line(127, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 5352);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6472);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 5512);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7752);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 256);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 5832);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8072);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 128);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 5672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7912);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 5992);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8232);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 7432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7592);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 7112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7272);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 11);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 6632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6792);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2104);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t5 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t7) = 1;

LAB9:    t22 = (t7 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB13:    t5 = (t0 + 1832);
    t6 = *((char **)t5);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t6, 32);
    if (t30 == 1)
        goto LAB14;

LAB15:    t2 = (t0 + 1968);
    t3 = *((char **)t2);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t30 == 1)
        goto LAB16;

LAB17:    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t30 == 1)
        goto LAB18;

LAB19:    t2 = (t0 + 2240);
    t3 = *((char **)t2);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t30 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB2;

LAB8:    t21 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(142, ng0);
    t28 = ((char*)((ng6)));
    t29 = (t0 + 5352);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 1);
    goto LAB12;

LAB14:    xsi_set_current_line(146, ng0);

LAB23:    xsi_set_current_line(147, ng0);
    t5 = ((char*)((ng1)));
    t8 = (t0 + 7592);
    xsi_vlogvar_assign_value(t8, t5, 0, 0, 8);
    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 11);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 1968);
    t3 = *((char **)t2);
    t2 = (t0 + 6472);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);
    goto LAB22;

LAB16:    xsi_set_current_line(153, ng0);

LAB24:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 6152);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 7752);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 256);
    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 7912);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 6632);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 2, t5, 2, t6, 2);
    t8 = (t0 + 6792);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 2);
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    t2 = (t0 + 6472);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);
    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 8232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB22;

LAB18:    xsi_set_current_line(162, ng0);

LAB25:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 4952U);
    t5 = *((char **)t2);
    t2 = (t5 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB26;

LAB27:
LAB28:    goto LAB22;

LAB20:    xsi_set_current_line(184, ng0);

LAB48:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 7112);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 2512);
    t21 = *((char **)t8);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t22 = (t21 + 4);
    t9 = *((unsigned int *)t6);
    t10 = *((unsigned int *)t21);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t8);
    t13 = *((unsigned int *)t22);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t22);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB52;

LAB49:    if (t18 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t7) = 1;

LAB52:    t29 = (t7 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(194, ng0);

LAB66:    xsi_set_current_line(195, ng0);
    t2 = (t0 + 7112);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 11, t5, 11, t6, 11);
    t8 = (t0 + 7272);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 11);

LAB55:    goto LAB22;

LAB26:    xsi_set_current_line(163, ng0);

LAB29:    xsi_set_current_line(165, ng0);
    t6 = (t0 + 7432);
    t8 = (t6 + 56U);
    t21 = *((char **)t8);
    t22 = (t0 + 2376);
    t28 = *((char **)t22);
    memset(t7, 0, 8);
    t22 = (t21 + 4);
    t29 = (t28 + 4);
    t14 = *((unsigned int *)t21);
    t15 = *((unsigned int *)t28);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t22);
    t18 = *((unsigned int *)t29);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t23 = *((unsigned int *)t22);
    t24 = *((unsigned int *)t29);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t20 & t26);
    if (t27 != 0)
        goto LAB33;

LAB30:    if (t25 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t7) = 1;

LAB33:    t32 = (t7 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t7);
    t36 = (t35 & t34);
    t37 = (t36 != 0);
    if (t37 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(168, ng0);

LAB38:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 5512);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng14)));
    xsi_vlog_unsigned_add(t40, 256, t5, 256, t6, 256);
    t8 = (t0 + 7752);
    xsi_vlogvar_assign_value(t8, t40, 0, 0, 256);
    xsi_set_current_line(170, ng0);
    t2 = (t0 + 7432);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 8, t5, 8, t6, 8);
    t8 = (t0 + 7592);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);
    xsi_set_current_line(171, ng0);
    t2 = (t0 + 7432);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2376);
    t8 = *((char **)t6);
    t6 = ((char*)((ng15)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t8, 32, t6, 32);
    memset(t41, 0, 8);
    t21 = (t5 + 4);
    t22 = (t7 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t21);
    t13 = *((unsigned int *)t22);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t21);
    t17 = *((unsigned int *)t22);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB42;

LAB39:    if (t18 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t41) = 1;

LAB42:    t29 = (t41 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t41);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB43;

LAB44:    xsi_set_current_line(175, ng0);

LAB47:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 5512);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng14)));
    xsi_vlog_unsigned_add(t40, 256, t5, 256, t6, 256);
    t8 = (t0 + 7752);
    xsi_vlogvar_assign_value(t8, t40, 0, 0, 256);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 7432);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 8, t5, 8, t6, 8);
    t8 = (t0 + 7592);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);

LAB45:
LAB36:    goto LAB28;

LAB32:    t31 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(165, ng0);

LAB37:    xsi_set_current_line(166, ng0);
    t38 = (t0 + 2240);
    t39 = *((char **)t38);
    t38 = (t0 + 6472);
    xsi_vlogvar_assign_value(t38, t39, 0, 0, 2);
    goto LAB36;

LAB41:    t28 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(171, ng0);

LAB46:    xsi_set_current_line(172, ng0);
    t31 = ((char*)((ng16)));
    t32 = (t0 + 7912);
    xsi_vlogvar_assign_value(t32, t31, 0, 0, 32);
    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 8232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB45;

LAB51:    t28 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(185, ng0);

LAB56:    xsi_set_current_line(186, ng0);
    t31 = ((char*)((ng1)));
    t32 = (t0 + 7272);
    xsi_vlogvar_assign_value(t32, t31, 0, 0, 11);
    xsi_set_current_line(187, ng0);
    t2 = (t0 + 6632);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng11)));
    memset(t7, 0, 8);
    t8 = (t5 + 4);
    t21 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t8);
    t13 = *((unsigned int *)t21);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t8);
    t17 = *((unsigned int *)t21);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB60;

LAB57:    if (t18 != 0)
        goto LAB59;

LAB58:    *((unsigned int *)t7) = 1;

LAB60:    t28 = (t7 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB61;

LAB62:    xsi_set_current_line(190, ng0);

LAB65:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 1832);
    t3 = *((char **)t2);
    t2 = (t0 + 6472);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB63:    goto LAB55;

LAB59:    t22 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB60;

LAB61:    xsi_set_current_line(187, ng0);

LAB64:    xsi_set_current_line(188, ng0);
    t29 = (t0 + 2240);
    t31 = *((char **)t29);
    t29 = (t0 + 6472);
    xsi_vlogvar_assign_value(t29, t31, 0, 0, 2);
    goto LAB63;

}


extern void work_m_14957676160082612700_4288439993_init()
{
	static char *pe[] = {(void *)Always_71_0,(void *)Always_93_1,(void *)Always_126_2};
	xsi_register_didat("work_m_14957676160082612700_4288439993", "isim/sigen_testfix_isim_beh.exe.sim/work/m_14957676160082612700_4288439993.didat");
	xsi_register_executes(pe);
}
