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
static const char *ng0 = "/local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/sigen.v";
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



static void Always_69_0(char *t0)
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

LAB0:    t1 = (t0 + 8688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 9504);
    *((int *)t2) = 1;
    t3 = (t0 + 8720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(69, ng0);

LAB5:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 4336U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(79, ng0);

LAB10:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 6016);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5856);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 7136);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6976);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 7296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5056);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 256, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 7456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5216);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 7616);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5376);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 128, 0LL);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 7776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5536);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 6336);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6176);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 6816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6656);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 11, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(70, ng0);

LAB9:    xsi_set_current_line(71, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5856);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5056);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5216);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5376);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5536);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6656);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 11);
    goto LAB8;

}

static void Always_91_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 8936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 9520);
    *((int *)t2) = 1;
    t3 = (t0 + 8968);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(91, ng0);

LAB5:    xsi_set_current_line(93, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 5696);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 256);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 6176);
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

LAB7:    xsi_set_current_line(97, ng0);

LAB16:    xsi_set_current_line(98, ng0);
    t7 = ((char*)((ng4)));
    t8 = (t0 + 5696);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 256);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6496);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB9:    xsi_set_current_line(103, ng0);

LAB17:    xsi_set_current_line(104, ng0);
    t3 = ((char*)((ng7)));
    t5 = (t0 + 5696);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 6496);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB11:    xsi_set_current_line(109, ng0);

LAB18:    xsi_set_current_line(110, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 5696);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(111, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6496);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

LAB13:    xsi_set_current_line(115, ng0);

LAB19:    xsi_set_current_line(116, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 5696);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 256);
    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 6496);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    goto LAB15;

}

static void Always_124_2(char *t0)
{
    char t7[8];
    char t32[64];
    char t33[8];
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
    char *t34;

LAB0:    t1 = (t0 + 9184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 9536);
    *((int *)t2) = 1;
    t3 = (t0 + 9216);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(124, ng0);

LAB5:    xsi_set_current_line(125, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 4896);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 5856);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6016);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 5056);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7296);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 256);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 5376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7616);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 128);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 5216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7456);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 5536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7776);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 6976);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7136);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 6656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6816);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 11);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 6176);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6336);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 5856);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2240);
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
LAB12:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 5856);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB13:    t5 = (t0 + 2104);
    t6 = *((char **)t5);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t6, 32);
    if (t30 == 1)
        goto LAB14;

LAB15:    t2 = (t0 + 2240);
    t3 = *((char **)t2);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t30 == 1)
        goto LAB16;

LAB17:    t2 = (t0 + 2376);
    t3 = *((char **)t2);
    t30 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t30 == 1)
        goto LAB18;

LAB19:
LAB20:    goto LAB2;

LAB8:    t21 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(140, ng0);
    t28 = ((char*)((ng6)));
    t29 = (t0 + 4896);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 1);
    goto LAB12;

LAB14:    xsi_set_current_line(145, ng0);

LAB21:    xsi_set_current_line(146, ng0);
    t5 = ((char*)((ng1)));
    t8 = (t0 + 7136);
    xsi_vlogvar_assign_value(t8, t5, 0, 0, 8);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6816);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 11);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 5696);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 7296);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 256);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 6496);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 7616);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 128);
    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 7456);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 6176);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 2, t5, 2, t6, 2);
    t8 = (t0 + 6336);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 2);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 2240);
    t3 = *((char **)t2);
    t2 = (t0 + 6016);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);
    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7776);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB20;

LAB16:    xsi_set_current_line(157, ng0);

LAB22:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 4496U);
    t5 = *((char **)t2);
    t2 = (t5 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB23;

LAB24:
LAB25:    goto LAB20;

LAB18:    xsi_set_current_line(179, ng0);

LAB45:    xsi_set_current_line(180, ng0);
    t2 = (t0 + 6656);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 1968);
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
        goto LAB49;

LAB46:    if (t18 != 0)
        goto LAB48;

LAB47:    *((unsigned int *)t7) = 1;

LAB49:    t29 = (t7 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB50;

LAB51:    xsi_set_current_line(189, ng0);

LAB63:    xsi_set_current_line(190, ng0);
    t2 = (t0 + 6656);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 11, t5, 11, t6, 11);
    t8 = (t0 + 6816);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 11);

LAB52:    goto LAB20;

LAB23:    xsi_set_current_line(158, ng0);

LAB26:    xsi_set_current_line(159, ng0);
    t6 = ((char*)((ng3)));
    t8 = (t0 + 7616);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 128);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 6976);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1832);
    t8 = *((char **)t6);
    memset(t7, 0, 8);
    t6 = (t5 + 4);
    t21 = (t8 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t8);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t21);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t21);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB30;

LAB27:    if (t18 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t7) = 1;

LAB30:    t28 = (t7 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(163, ng0);

LAB35:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 5056);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng14)));
    xsi_vlog_unsigned_add(t32, 256, t5, 256, t6, 256);
    t8 = (t0 + 7296);
    xsi_vlogvar_assign_value(t8, t32, 0, 0, 256);
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 6976);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 8, t5, 8, t6, 8);
    t8 = (t0 + 7136);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 6976);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1832);
    t8 = *((char **)t6);
    t6 = ((char*)((ng15)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t8, 32, t6, 32);
    memset(t33, 0, 8);
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
        goto LAB39;

LAB36:    if (t18 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t33) = 1;

LAB39:    t29 = (t33 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t33);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(170, ng0);

LAB44:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 5056);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng14)));
    xsi_vlog_unsigned_add(t32, 256, t5, 256, t6, 256);
    t8 = (t0 + 7296);
    xsi_vlogvar_assign_value(t8, t32, 0, 0, 256);
    xsi_set_current_line(172, ng0);
    t2 = (t0 + 6976);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 8, t5, 8, t6, 8);
    t8 = (t0 + 7136);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 8);

LAB42:
LAB33:    goto LAB25;

LAB29:    t22 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(160, ng0);

LAB34:    xsi_set_current_line(161, ng0);
    t29 = (t0 + 2376);
    t31 = *((char **)t29);
    t29 = (t0 + 6016);
    xsi_vlogvar_assign_value(t29, t31, 0, 0, 2);
    goto LAB33;

LAB38:    t28 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB39;

LAB40:    xsi_set_current_line(166, ng0);

LAB43:    xsi_set_current_line(167, ng0);
    t31 = ((char*)((ng16)));
    t34 = (t0 + 7456);
    xsi_vlogvar_assign_value(t34, t31, 0, 0, 32);
    xsi_set_current_line(168, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 7776);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB42;

LAB48:    t28 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB49;

LAB50:    xsi_set_current_line(180, ng0);

LAB53:    xsi_set_current_line(181, ng0);
    t31 = ((char*)((ng1)));
    t34 = (t0 + 6816);
    xsi_vlogvar_assign_value(t34, t31, 0, 0, 11);
    xsi_set_current_line(182, ng0);
    t2 = (t0 + 6176);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng1)));
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
        goto LAB57;

LAB54:    if (t18 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t7) = 1;

LAB57:    t28 = (t7 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(185, ng0);

LAB62:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    t2 = (t0 + 6016);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB60:    goto LAB52;

LAB56:    t22 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB57;

LAB58:    xsi_set_current_line(182, ng0);

LAB61:    xsi_set_current_line(183, ng0);
    t29 = (t0 + 2376);
    t31 = *((char **)t29);
    t29 = (t0 + 6016);
    xsi_vlogvar_assign_value(t29, t31, 0, 0, 2);
    goto LAB60;

}


extern void work_m_18410814539903184349_0216608610_init()
{
	static char *pe[] = {(void *)Always_69_0,(void *)Always_91_1,(void *)Always_124_2};
	xsi_register_didat("work_m_18410814539903184349_0216608610", "isim/module_prototype_isim_beh.exe.sim/work/m_18410814539903184349_0216608610.didat");
	xsi_register_executes(pe);
}
