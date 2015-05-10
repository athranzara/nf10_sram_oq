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
static const char *ng0 = "/local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/qdr2_tb/testbench.v";
static const char *ng1 = "vectors.dump";
static int ng2[] = {0, 0};
static int ng3[] = {2, 0, 0, 0};
static int ng4[] = {9, 0, 0, 0};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {0U, 0U, 0U, 0U};
static unsigned int ng7[] = {1U, 0U};
static int ng8[] = {1, 0};
static unsigned int ng9[] = {1U, 1U};
static int ng10[] = {1000, 0};
static const char *ng11 = "qdr2_vectors.txt";
static int ng12[] = {110, 0};
static int ng13[] = {17, 0};
static int ng14[] = {7, 0};
static int ng15[] = {12, 0};
static int ng16[] = {8, 0};
static int ng17[] = {15, 0};
static int ng18[] = {13, 0};
static int ng19[] = {16, 0};
static int ng20[] = {18, 0};
static int ng21[] = {3, 0};
static int ng22[] = {2, 0};
static int ng23[] = {35, 0};
static const char *ng24 = "Line:%d OUTPUT DATA OK  data = %h test = %h";
static const char *ng25 = "Line:%d ERROR data = %h test = %h";



static void Initial_33_0(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(34, ng0);

LAB2:    xsi_set_current_line(35, ng0);
    xsi_vcd_dumpfile(ng1);
    xsi_set_current_line(36, ng0);
    t1 = ((char*)((ng2)));
    xsi_vcd_dumpvars_args(*((unsigned int *)t1), t0, (char)109, t0, (char)101);

LAB1:    return;
}

static void Initial_41_1(char *t0)
{
    char *t1;
    double t2;
    char *t3;
    char *t4;
    char *t5;
    double t6;
    double t7;
    char *t8;
    double t9;
    double t10;
    char *t11;

LAB0:    xsi_set_current_line(42, ng0);

LAB2:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 6088);
    xsi_vlogvar_assign_value_double(t1, 1.5000000000000000, 0);
    xsi_set_current_line(44, ng0);
    t1 = (t0 + 6248);
    xsi_vlogvar_assign_value_double(t1, 0.80000000000000004, 0);
    xsi_set_current_line(45, ng0);
    t1 = (t0 + 6408);
    xsi_vlogvar_assign_value_double(t1, 0.40000000000000002, 0);
    xsi_set_current_line(46, ng0);
    t1 = (t0 + 6568);
    xsi_vlogvar_assign_value_double(t1, 0.010000000000000000, 0);
    xsi_set_current_line(47, ng0);
    t1 = ((char*)((ng3)));
    t2 = xsi_vlog_convert_to_real(t1, 32, 1);
    t3 = (t0 + 6088);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = *((double *)t5);
    t7 = (t2 * t6);
    t8 = ((char*)((ng4)));
    t9 = xsi_vlog_convert_to_real(t8, 32, 1);
    t10 = (t7 * t9);
    t11 = (t0 + 6728);
    xsi_vlogvar_assign_value_double(t11, t10, 0);

LAB1:    return;
}

static void Initial_53_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(54, ng0);

LAB2:    xsi_set_current_line(56, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 3048);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 2888);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t1 = ((char*)((ng6)));
    t2 = (t0 + 2088);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 36);
    xsi_set_current_line(59, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 5448);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 4);
    xsi_set_current_line(60, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 4488);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 5608);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t1 = ((char*)((ng7)));
    t2 = (t0 + 4648);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 4168);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 5768);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t1 = ((char*)((ng7)));
    t2 = (t0 + 4328);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t1 = ((char*)((ng7)));
    t2 = (t0 + 5928);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t1 = ((char*)((ng8)));
    t2 = (t0 + 4808);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t1 = ((char*)((ng8)));
    t2 = (t0 + 4968);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t1 = ((char*)((ng8)));
    t2 = (t0 + 5288);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 19);

LAB1:    return;
}

static void Initial_75_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(76, ng0);

LAB2:    xsi_set_current_line(77, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3688);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(78, ng0);
    t1 = ((char*)((ng8)));
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t1 = ((char*)((ng9)));
    t2 = (t0 + 4008);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Initial_82_4(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 8632U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(83, ng0);

LAB4:    xsi_set_current_line(84, ng0);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB5:    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng10)));
    memset(t6, 0, 8);
    xsi_vlog_signed_leq(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:
LAB1:    return;
LAB6:    xsi_set_current_line(85, ng0);

LAB8:    xsi_set_current_line(86, ng0);
    t13 = (t0 + 8440);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(86, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 3688);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 8440);
    xsi_process_wait(t2, 90000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(87, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3688);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB5;

}

static void Initial_133_5(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 8880U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(134, ng0);

LAB4:    xsi_set_current_line(135, ng0);
    t2 = (t0 + 8688);
    xsi_process_wait(t2, 800LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(136, ng0);

LAB6:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB7;

LAB8:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB9:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 8688);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB7:    t5 = 0.0000000000000000;
    goto LAB9;

LAB10:    xsi_set_current_line(136, ng0);
    t9 = (t0 + 2888);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t12) == 0)
        goto LAB11;

LAB13:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB14:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB16;

LAB15:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 2888);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB6;

LAB11:    *((unsigned int *)t8) = 1;
    goto LAB14;

LAB16:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB15;

LAB17:    goto LAB1;

}

static void Initial_140_6(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 9128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(141, ng0);

LAB4:    xsi_set_current_line(142, ng0);

LAB5:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB6;

LAB7:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB8:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 8936);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB9;

LAB1:    return;
LAB6:    t5 = 0.0000000000000000;
    goto LAB8;

LAB9:    xsi_set_current_line(142, ng0);
    t9 = (t0 + 4168);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB13;

LAB11:    if (*((unsigned int *)t12) == 0)
        goto LAB10;

LAB12:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB13:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB15;

LAB14:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 4168);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB5;

LAB10:    *((unsigned int *)t8) = 1;
    goto LAB13;

LAB15:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB14;

LAB16:    goto LAB1;

}

static void Initial_145_7(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 9376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(146, ng0);

LAB4:    xsi_set_current_line(147, ng0);

LAB5:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB6;

LAB7:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB8:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 9184);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB9;

LAB1:    return;
LAB6:    t5 = 0.0000000000000000;
    goto LAB8;

LAB9:    xsi_set_current_line(147, ng0);
    t9 = (t0 + 4328);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB13;

LAB11:    if (*((unsigned int *)t12) == 0)
        goto LAB10;

LAB12:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB13:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB15;

LAB14:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 4328);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB5;

LAB10:    *((unsigned int *)t8) = 1;
    goto LAB13;

LAB15:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB14;

LAB16:    goto LAB1;

}

static void Initial_150_8(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 9624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(151, ng0);

LAB4:    xsi_set_current_line(152, ng0);
    t2 = (t0 + 9432);
    xsi_process_wait(t2, 1300LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(153, ng0);

LAB6:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB7;

LAB8:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB9:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 9432);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB7:    t5 = 0.0000000000000000;
    goto LAB9;

LAB10:    xsi_set_current_line(153, ng0);
    t9 = (t0 + 4488);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t12) == 0)
        goto LAB11;

LAB13:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB14:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB16;

LAB15:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 4488);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB6;

LAB11:    *((unsigned int *)t8) = 1;
    goto LAB14;

LAB16:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB15;

LAB17:    goto LAB1;

}

static void Initial_156_9(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 9872U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(157, ng0);

LAB4:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 9680);
    xsi_process_wait(t2, 1300LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(159, ng0);

LAB6:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB7;

LAB8:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB9:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 9680);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB7:    t5 = 0.0000000000000000;
    goto LAB9;

LAB10:    xsi_set_current_line(159, ng0);
    t9 = (t0 + 4648);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t12) == 0)
        goto LAB11;

LAB13:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB14:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB16;

LAB15:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 4648);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB6;

LAB11:    *((unsigned int *)t8) = 1;
    goto LAB14;

LAB16:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB15;

LAB17:    goto LAB1;

}

static void Initial_162_10(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    double t5;
    double t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 10120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(163, ng0);

LAB4:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 6408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB5;

LAB6:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB7:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 9928);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB8;

LAB1:    return;
LAB5:    t5 = 0.0000000000000000;
    goto LAB7;

LAB8:    xsi_set_current_line(165, ng0);

LAB9:    xsi_set_current_line(165, ng0);
    t2 = (t0 + 6088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = *((double *)t4);
    t5 = (t5 * 100.00000000000000);
    t6 = (t5 < 0.0000000000000000);
    if (t6 == 1)
        goto LAB10;

LAB11:    t5 = (t5 + 0.50000000000000000);
    t5 = ((int64)(t5));

LAB12:    t5 = (t5 * 10.000000000000000);
    t7 = (t0 + 9928);
    xsi_process_wait(t7, t5);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB10:    t5 = 0.0000000000000000;
    goto LAB12;

LAB13:    xsi_set_current_line(165, ng0);
    t9 = (t0 + 5768);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t8, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t12) == 0)
        goto LAB14;

LAB16:    t18 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t18) = 1;

LAB17:    t19 = (t8 + 4);
    t20 = (t11 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    *((unsigned int *)t8) = t22;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB19;

LAB18:    t27 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t27 & 1U);
    t28 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t28 & 1U);
    t29 = (t0 + 5768);
    xsi_vlogvar_assign_value(t29, t8, 0, 0, 1);
    goto LAB9;

LAB14:    *((unsigned int *)t8) = 1;
    goto LAB17;

LAB19:    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t20);
    *((unsigned int *)t8) = (t23 | t24);
    t25 = *((unsigned int *)t19);
    t26 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t25 | t26);
    goto LAB18;

LAB20:    goto LAB1;

}

static void Initial_262_11(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

LAB0:    t1 = (t0 + 10368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(263, ng0);

LAB4:    xsi_set_current_line(264, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(264, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(265, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(265, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(266, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(266, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(267, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(267, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(268, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(268, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(269, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(269, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(270, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(271, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(271, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(272, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(272, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(273, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(273, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(274, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(274, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 3848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(275, ng0);
    t2 = (t0 + 10176);
    xsi_process_wait(t2, 10000000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(275, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}

static void Initial_278_12(char *t0)
{
    char t6[8];
    char t18[16];
    char t29[8];
    char t30[8];
    char t31[8];
    char t55[8];
    char t56[8];
    char t57[8];
    char t81[8];
    char t90[8];
    char t101[8];
    char t102[8];
    char t103[8];
    char t127[8];
    char t128[8];
    char t129[8];
    char t153[8];
    char t154[8];
    char t155[8];
    char t179[8];
    char t180[8];
    char t181[8];
    char t205[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    unsigned int t38;
    int t39;
    char *t40;
    unsigned int t41;
    int t42;
    int t43;
    char *t44;
    unsigned int t45;
    int t46;
    int t47;
    unsigned int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    int t53;
    char *t54;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    int t65;
    char *t66;
    unsigned int t67;
    int t68;
    int t69;
    char *t70;
    unsigned int t71;
    int t72;
    int t73;
    unsigned int t74;
    int t75;
    unsigned int t76;
    unsigned int t77;
    int t78;
    int t79;
    char *t80;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    unsigned int t87;
    int t88;
    char *t89;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    unsigned int t96;
    int t97;
    char *t98;
    char *t99;
    char *t100;
    char *t104;
    char *t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    unsigned int t110;
    int t111;
    char *t112;
    unsigned int t113;
    int t114;
    int t115;
    char *t116;
    unsigned int t117;
    int t118;
    int t119;
    unsigned int t120;
    int t121;
    unsigned int t122;
    unsigned int t123;
    int t124;
    int t125;
    char *t126;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    unsigned int t136;
    int t137;
    char *t138;
    unsigned int t139;
    int t140;
    int t141;
    char *t142;
    unsigned int t143;
    int t144;
    int t145;
    unsigned int t146;
    int t147;
    unsigned int t148;
    unsigned int t149;
    int t150;
    int t151;
    char *t152;
    char *t156;
    char *t157;
    char *t158;
    char *t159;
    char *t160;
    char *t161;
    unsigned int t162;
    int t163;
    char *t164;
    unsigned int t165;
    int t166;
    int t167;
    char *t168;
    unsigned int t169;
    int t170;
    int t171;
    unsigned int t172;
    int t173;
    unsigned int t174;
    unsigned int t175;
    int t176;
    int t177;
    char *t178;
    char *t182;
    char *t183;
    char *t184;
    char *t185;
    char *t186;
    char *t187;
    unsigned int t188;
    int t189;
    char *t190;
    unsigned int t191;
    int t192;
    int t193;
    char *t194;
    unsigned int t195;
    int t196;
    int t197;
    unsigned int t198;
    int t199;
    unsigned int t200;
    unsigned int t201;
    int t202;
    int t203;
    char *t204;
    char *t206;
    char *t207;
    char *t208;
    char *t209;
    char *t210;
    unsigned int t211;
    int t212;

LAB0:    t1 = (t0 + 10616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(279, ng0);

LAB4:    xsi_set_current_line(281, ng0);
    t2 = (t0 + 1928);
    xsi_vlogfile_readmemb(ng11, 0, t2, 0, 0, 0, 0);
    xsi_set_current_line(282, ng0);
    xsi_set_current_line(282, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB5:    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng12)));
    memset(t6, 0, 8);
    xsi_vlog_signed_leq(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(292, ng0);
    t2 = (t0 + 10424);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB38;

LAB1:    return;
LAB6:    xsi_set_current_line(283, ng0);
    t13 = (t0 + 11184);
    *((int *)t13) = 1;
    t14 = (t0 + 10648);
    *((char **)t14) = t13;
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(284, ng0);

LAB9:    xsi_set_current_line(285, ng0);
    t15 = (t0 + 1928);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t19 = (t0 + 1928);
    t20 = (t19 + 72U);
    t21 = *((char **)t20);
    t22 = (t0 + 1928);
    t23 = (t22 + 64U);
    t24 = *((char **)t23);
    t25 = (t0 + 3208);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 59, t17, t21, t24, 2, 1, t27, 32, 1);
    t28 = (t0 + 2408);
    t32 = (t0 + 2408);
    t33 = (t32 + 72U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng13)));
    t36 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t34)), 2, t35, 32, 1, t36, 32, 1);
    t37 = (t29 + 4);
    t38 = *((unsigned int *)t37);
    t39 = (!(t38));
    t40 = (t30 + 4);
    t41 = *((unsigned int *)t40);
    t42 = (!(t41));
    t43 = (t39 && t42);
    t44 = (t31 + 4);
    t45 = *((unsigned int *)t44);
    t46 = (!(t45));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB10;

LAB11:    t54 = (t0 + 2568);
    t58 = (t0 + 2568);
    t59 = (t58 + 72U);
    t60 = *((char **)t59);
    t61 = ((char*)((ng13)));
    t62 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t55, t56, t57, ((int*)(t60)), 2, t61, 32, 1, t62, 32, 1);
    t63 = (t55 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (!(t64));
    t66 = (t56 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (!(t67));
    t69 = (t65 && t68);
    t70 = (t57 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (!(t71));
    t73 = (t69 && t72);
    if (t73 == 1)
        goto LAB12;

LAB13:    t80 = (t0 + 5448);
    t82 = (t0 + 5448);
    t83 = (t82 + 72U);
    t84 = *((char **)t83);
    t85 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t81, t84, 2, t85, 32, 1);
    t86 = (t81 + 4);
    t87 = *((unsigned int *)t86);
    t88 = (!(t87));
    if (t88 == 1)
        goto LAB14;

LAB15:    t89 = (t0 + 5448);
    t91 = (t0 + 5448);
    t92 = (t91 + 72U);
    t93 = *((char **)t92);
    t94 = ((char*)((ng8)));
    xsi_vlog_generic_convert_bit_index(t90, t93, 2, t94, 32, 1);
    t95 = (t90 + 4);
    t96 = *((unsigned int *)t95);
    t97 = (!(t96));
    if (t97 == 1)
        goto LAB16;

LAB17:    t98 = (t0 + 4968);
    xsi_vlogvar_assign_value(t98, t18, 38, 0, 1);
    t99 = (t0 + 4808);
    xsi_vlogvar_assign_value(t99, t18, 39, 0, 1);
    t100 = (t0 + 2248);
    t104 = (t0 + 2248);
    t105 = (t104 + 72U);
    t106 = *((char **)t105);
    t107 = ((char*)((ng14)));
    t108 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t101, t102, t103, ((int*)(t106)), 2, t107, 32, 1, t108, 32, 1);
    t109 = (t101 + 4);
    t110 = *((unsigned int *)t109);
    t111 = (!(t110));
    t112 = (t102 + 4);
    t113 = *((unsigned int *)t112);
    t114 = (!(t113));
    t115 = (t111 && t114);
    t116 = (t103 + 4);
    t117 = *((unsigned int *)t116);
    t118 = (!(t117));
    t119 = (t115 && t118);
    if (t119 == 1)
        goto LAB18;

LAB19:    t126 = (t0 + 2248);
    t130 = (t0 + 2248);
    t131 = (t130 + 72U);
    t132 = *((char **)t131);
    t133 = ((char*)((ng15)));
    t134 = ((char*)((ng16)));
    xsi_vlog_convert_partindices(t127, t128, t129, ((int*)(t132)), 2, t133, 32, 1, t134, 32, 1);
    t135 = (t127 + 4);
    t136 = *((unsigned int *)t135);
    t137 = (!(t136));
    t138 = (t128 + 4);
    t139 = *((unsigned int *)t138);
    t140 = (!(t139));
    t141 = (t137 && t140);
    t142 = (t129 + 4);
    t143 = *((unsigned int *)t142);
    t144 = (!(t143));
    t145 = (t141 && t144);
    if (t145 == 1)
        goto LAB20;

LAB21:    t152 = (t0 + 2248);
    t156 = (t0 + 2248);
    t157 = (t156 + 72U);
    t158 = *((char **)t157);
    t159 = ((char*)((ng17)));
    t160 = ((char*)((ng18)));
    xsi_vlog_convert_partindices(t153, t154, t155, ((int*)(t158)), 2, t159, 32, 1, t160, 32, 1);
    t161 = (t153 + 4);
    t162 = *((unsigned int *)t161);
    t163 = (!(t162));
    t164 = (t154 + 4);
    t165 = *((unsigned int *)t164);
    t166 = (!(t165));
    t167 = (t163 && t166);
    t168 = (t155 + 4);
    t169 = *((unsigned int *)t168);
    t170 = (!(t169));
    t171 = (t167 && t170);
    if (t171 == 1)
        goto LAB22;

LAB23:    t178 = (t0 + 2248);
    t182 = (t0 + 2248);
    t183 = (t182 + 72U);
    t184 = *((char **)t183);
    t185 = ((char*)((ng13)));
    t186 = ((char*)((ng19)));
    xsi_vlog_convert_partindices(t179, t180, t181, ((int*)(t184)), 2, t185, 32, 1, t186, 32, 1);
    t187 = (t179 + 4);
    t188 = *((unsigned int *)t187);
    t189 = (!(t188));
    t190 = (t180 + 4);
    t191 = *((unsigned int *)t190);
    t192 = (!(t191));
    t193 = (t189 && t192);
    t194 = (t181 + 4);
    t195 = *((unsigned int *)t194);
    t196 = (!(t195));
    t197 = (t193 && t196);
    if (t197 == 1)
        goto LAB24;

LAB25:    t204 = (t0 + 2248);
    t206 = (t0 + 2248);
    t207 = (t206 + 72U);
    t208 = *((char **)t207);
    t209 = ((char*)((ng20)));
    xsi_vlog_generic_convert_bit_index(t205, t208, 2, t209, 32, 1);
    t210 = (t205 + 4);
    t211 = *((unsigned int *)t210);
    t212 = (!(t211));
    if (t212 == 1)
        goto LAB26;

LAB27:    xsi_set_current_line(286, ng0);
    t2 = (t0 + 5448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 3U);
    t38 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t38 & 3U);
    t13 = (t0 + 5448);
    t14 = (t0 + 5448);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng21)));
    t19 = ((char*)((ng22)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t16)), 2, t17, 32, 1, t19, 32, 1);
    t20 = (t29 + 4);
    t41 = *((unsigned int *)t20);
    t39 = (!(t41));
    t21 = (t30 + 4);
    t45 = *((unsigned int *)t21);
    t42 = (!(t45));
    t43 = (t39 && t42);
    t22 = (t31 + 4);
    t48 = *((unsigned int *)t22);
    t46 = (!(t48));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB28;

LAB29:    xsi_set_current_line(287, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 262143U);
    t38 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t38 & 262143U);
    t13 = (t0 + 2568);
    t14 = (t0 + 2568);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng23)));
    t19 = ((char*)((ng20)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t16)), 2, t17, 32, 1, t19, 32, 1);
    t20 = (t29 + 4);
    t41 = *((unsigned int *)t20);
    t39 = (!(t41));
    t21 = (t30 + 4);
    t45 = *((unsigned int *)t21);
    t42 = (!(t45));
    t43 = (t39 && t42);
    t22 = (t31 + 4);
    t48 = *((unsigned int *)t22);
    t46 = (!(t48));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB30;

LAB31:    xsi_set_current_line(288, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 262143U);
    t38 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t38 & 262143U);
    t13 = (t0 + 2088);
    t14 = (t0 + 2088);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng23)));
    t19 = ((char*)((ng20)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t16)), 2, t17, 32, 1, t19, 32, 1);
    t20 = (t29 + 4);
    t41 = *((unsigned int *)t20);
    t39 = (!(t41));
    t21 = (t30 + 4);
    t45 = *((unsigned int *)t21);
    t42 = (!(t45));
    t43 = (t39 && t42);
    t22 = (t31 + 4);
    t48 = *((unsigned int *)t22);
    t46 = (!(t48));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB32;

LAB33:    xsi_set_current_line(289, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 262143U);
    t38 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t38 & 262143U);
    t13 = (t0 + 2088);
    t14 = (t0 + 2088);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng13)));
    t19 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t16)), 2, t17, 32, 1, t19, 32, 1);
    t20 = (t29 + 4);
    t41 = *((unsigned int *)t20);
    t39 = (!(t41));
    t21 = (t30 + 4);
    t45 = *((unsigned int *)t21);
    t42 = (!(t45));
    t43 = (t39 && t42);
    t22 = (t31 + 4);
    t48 = *((unsigned int *)t22);
    t46 = (!(t48));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB34;

LAB35:    xsi_set_current_line(290, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 262143U);
    t38 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t38 & 262143U);
    t13 = (t0 + 2408);
    t14 = (t0 + 2408);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng23)));
    t19 = ((char*)((ng20)));
    xsi_vlog_convert_partindices(t29, t30, t31, ((int*)(t16)), 2, t17, 32, 1, t19, 32, 1);
    t20 = (t29 + 4);
    t41 = *((unsigned int *)t20);
    t39 = (!(t41));
    t21 = (t30 + 4);
    t45 = *((unsigned int *)t21);
    t42 = (!(t45));
    t43 = (t39 && t42);
    t22 = (t31 + 4);
    t48 = *((unsigned int *)t22);
    t46 = (!(t48));
    t47 = (t43 && t46);
    if (t47 == 1)
        goto LAB36;

LAB37:    xsi_set_current_line(282, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB5;

LAB10:    t48 = *((unsigned int *)t31);
    t49 = (t48 + 0);
    t50 = *((unsigned int *)t29);
    t51 = *((unsigned int *)t30);
    t52 = (t50 - t51);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t28, t18, t49, *((unsigned int *)t30), t53);
    goto LAB11;

LAB12:    t74 = *((unsigned int *)t57);
    t75 = (t74 + 18);
    t76 = *((unsigned int *)t55);
    t77 = *((unsigned int *)t56);
    t78 = (t76 - t77);
    t79 = (t78 + 1);
    xsi_vlogvar_assign_value(t54, t18, t75, *((unsigned int *)t56), t79);
    goto LAB13;

LAB14:    xsi_vlogvar_assign_value(t80, t18, 36, *((unsigned int *)t81), 1);
    goto LAB15;

LAB16:    xsi_vlogvar_assign_value(t89, t18, 37, *((unsigned int *)t90), 1);
    goto LAB17;

LAB18:    t120 = *((unsigned int *)t103);
    t121 = (t120 + 40);
    t122 = *((unsigned int *)t101);
    t123 = *((unsigned int *)t102);
    t124 = (t122 - t123);
    t125 = (t124 + 1);
    xsi_vlogvar_assign_value(t100, t18, t121, *((unsigned int *)t102), t125);
    goto LAB19;

LAB20:    t146 = *((unsigned int *)t129);
    t147 = (t146 + 48);
    t148 = *((unsigned int *)t127);
    t149 = *((unsigned int *)t128);
    t150 = (t148 - t149);
    t151 = (t150 + 1);
    xsi_vlogvar_assign_value(t126, t18, t147, *((unsigned int *)t128), t151);
    goto LAB21;

LAB22:    t172 = *((unsigned int *)t155);
    t173 = (t172 + 53);
    t174 = *((unsigned int *)t153);
    t175 = *((unsigned int *)t154);
    t176 = (t174 - t175);
    t177 = (t176 + 1);
    xsi_vlogvar_assign_value(t152, t18, t173, *((unsigned int *)t154), t177);
    goto LAB23;

LAB24:    t198 = *((unsigned int *)t181);
    t199 = (t198 + 56);
    t200 = *((unsigned int *)t179);
    t201 = *((unsigned int *)t180);
    t202 = (t200 - t201);
    t203 = (t202 + 1);
    xsi_vlogvar_assign_value(t178, t18, t199, *((unsigned int *)t180), t203);
    goto LAB25;

LAB26:    xsi_vlogvar_assign_value(t204, t18, 58, *((unsigned int *)t205), 1);
    goto LAB27;

LAB28:    t50 = *((unsigned int *)t31);
    t49 = (t50 + 0);
    t51 = *((unsigned int *)t29);
    t64 = *((unsigned int *)t30);
    t52 = (t51 - t64);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t13, t6, t49, *((unsigned int *)t30), t53);
    goto LAB29;

LAB30:    t50 = *((unsigned int *)t31);
    t49 = (t50 + 0);
    t51 = *((unsigned int *)t29);
    t64 = *((unsigned int *)t30);
    t52 = (t51 - t64);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t13, t6, t49, *((unsigned int *)t30), t53);
    goto LAB31;

LAB32:    t50 = *((unsigned int *)t31);
    t49 = (t50 + 0);
    t51 = *((unsigned int *)t29);
    t64 = *((unsigned int *)t30);
    t52 = (t51 - t64);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t13, t6, t49, *((unsigned int *)t30), t53);
    goto LAB33;

LAB34:    t50 = *((unsigned int *)t31);
    t49 = (t50 + 0);
    t51 = *((unsigned int *)t29);
    t64 = *((unsigned int *)t30);
    t52 = (t51 - t64);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t13, t6, t49, *((unsigned int *)t30), t53);
    goto LAB35;

LAB36:    t50 = *((unsigned int *)t31);
    t49 = (t50 + 0);
    t51 = *((unsigned int *)t29);
    t64 = *((unsigned int *)t30);
    t52 = (t51 - t64);
    t53 = (t52 + 1);
    xsi_vlogvar_assign_value(t13, t6, t49, *((unsigned int *)t30), t53);
    goto LAB37;

LAB38:    xsi_set_current_line(292, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}

static void Always_296_13(char *t0)
{
    char t8[8];
    char t9[8];
    char t25[8];
    char t26[8];
    char t34[8];
    char t72[16];
    char t75[16];
    char t78[16];
    char t89[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t73;
    char *t74;
    char *t76;
    char *t77;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t90;
    char *t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 10864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(296, ng0);
    t2 = (t0 + 11200);
    *((int *)t2) = 1;
    t3 = (t0 + 10896);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(297, ng0);

LAB5:    xsi_set_current_line(298, ng0);
    t4 = (t0 + 3208);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng8)));
    memset(t8, 0, 8);
    xsi_vlog_signed_greater(t8, 32, t6, 32, t7, 32);
    memset(t9, 0, 8);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t8);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t10) != 0)
        goto LAB8;

LAB9:    t17 = (t9 + 4);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t17);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB10;

LAB11:    memcpy(t34, t9, 8);

LAB12:    t66 = (t34 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t34);
    t70 = (t69 & t68);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB20;

LAB21:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB8:    t16 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB9;

LAB10:    t21 = (t0 + 3208);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = ((char*)((ng12)));
    memset(t25, 0, 8);
    xsi_vlog_signed_leq(t25, 32, t23, 32, t24, 32);
    memset(t26, 0, 8);
    t27 = (t25 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t25);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t27) != 0)
        goto LAB15;

LAB16:    t35 = *((unsigned int *)t9);
    t36 = *((unsigned int *)t26);
    t37 = (t35 & t36);
    *((unsigned int *)t34) = t37;
    t38 = (t9 + 4);
    t39 = (t26 + 4);
    t40 = (t34 + 4);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB15:    t33 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB16;

LAB17:    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t34) = (t46 | t47);
    t48 = (t9 + 4);
    t49 = (t26 + 4);
    t50 = *((unsigned int *)t9);
    t51 = (~(t50));
    t52 = *((unsigned int *)t48);
    t53 = (~(t52));
    t54 = *((unsigned int *)t26);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & t60);
    t63 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t63 & t61);
    t64 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t64 & t60);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    goto LAB19;

LAB20:    xsi_set_current_line(299, ng0);

LAB23:    xsi_set_current_line(300, ng0);
    t73 = (t0 + 1048U);
    t74 = *((char **)t73);
    xsi_vlog_get_part_select_value(t72, 36, t74, 35, 0);
    t73 = (t0 + 2408);
    t76 = (t73 + 56U);
    t77 = *((char **)t76);
    xsi_vlog_get_part_select_value(t75, 36, t77, 35, 0);
    xsi_vlog_unsigned_case_eq(t78, 36, t72, 36, t75, 36);
    t79 = (t78 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (~(t80));
    t82 = *((unsigned int *)t78);
    t83 = (t82 & t81);
    t84 = (t83 != 0);
    if (t84 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(303, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t8, 0, 8);
    xsi_vlog_signed_minus(t8, 32, t4, 32, t5, 32);
    t6 = (t0 + 1048U);
    t7 = *((char **)t6);
    t6 = (t0 + 2408);
    t10 = (t6 + 56U);
    t16 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng25, 4, t0, (char)119, t8, 32, (char)118, t7, 36, (char)118, t16, 36);

LAB26:    goto LAB22;

LAB24:    xsi_set_current_line(301, ng0);
    t85 = (t0 + 3208);
    t86 = (t85 + 56U);
    t87 = *((char **)t86);
    t88 = ((char*)((ng8)));
    memset(t89, 0, 8);
    xsi_vlog_signed_minus(t89, 32, t87, 32, t88, 32);
    t90 = (t0 + 1048U);
    t91 = *((char **)t90);
    t90 = (t0 + 2408);
    t92 = (t90 + 56U);
    t93 = *((char **)t92);
    xsi_vlogfile_write(1, 0, 0, ng24, 4, t0, (char)119, t89, 32, (char)118, t91, 36, (char)118, t93, 36);
    goto LAB26;

}


extern void work_m_05690380516475629181_3943644159_init()
{
	static char *pe[] = {(void *)Initial_33_0,(void *)Initial_41_1,(void *)Initial_53_2,(void *)Initial_75_3,(void *)Initial_82_4,(void *)Initial_133_5,(void *)Initial_140_6,(void *)Initial_145_7,(void *)Initial_150_8,(void *)Initial_156_9,(void *)Initial_162_10,(void *)Initial_262_11,(void *)Initial_278_12,(void *)Always_296_13};
	xsi_register_didat("work_m_05690380516475629181_3943644159", "isim/rw_test_isim_beh.exe.sim/work/m_05690380516475629181_3943644159.didat");
	xsi_register_executes(pe);
}
