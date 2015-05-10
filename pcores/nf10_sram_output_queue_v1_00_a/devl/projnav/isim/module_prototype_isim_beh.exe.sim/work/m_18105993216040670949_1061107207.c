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
static const char *ng0 = "/local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/small_async_fifo.v";



static void Cont_235_0(char *t0)
{
    char t5[72];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    t1 = (t0 + 3728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(235, ng0);
    t2 = (t0 + 2816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 2816);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2816);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 1936U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t5, 262, t4, t8, t11, 2, 1, t13, 5, 2);
    t12 = (t0 + 4392);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    xsi_vlog_bit_copy(t17, 0, t5, 0, 262);
    xsi_driver_vfirst_trans(t12, 0, 261);
    t18 = (t0 + 4296);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_237_1(char *t0)
{
    char t6[8];
    char t17[8];
    char t26[8];
    char t34[8];
    char t74[8];
    char t75[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
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
    char *t72;
    char *t73;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    unsigned int t84;
    int t85;
    char *t86;
    unsigned int t87;
    int t88;
    int t89;
    unsigned int t90;
    unsigned int t91;
    int t92;
    int t93;

LAB0:    t1 = (t0 + 3976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(237, ng0);
    t2 = (t0 + 4312);
    *((int *)t2) = 1;
    t3 = (t0 + 4008);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(238, ng0);
    t4 = (t0 + 2096U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t4) != 0)
        goto LAB7;

LAB8:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB9;

LAB10:    memcpy(t34, t6, 8);

LAB11:    t66 = (t34 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t34);
    t70 = (t69 & t68);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB23;

LAB24:
LAB25:    goto LAB2;

LAB5:    *((unsigned int *)t6) = 1;
    goto LAB8;

LAB7:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB8;

LAB9:    t18 = (t0 + 2256U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t18 = (t19 + 4);
    t20 = *((unsigned int *)t18);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB15;

LAB13:    if (*((unsigned int *)t18) == 0)
        goto LAB12;

LAB14:    t25 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t25) = 1;

LAB15:    memset(t26, 0, 8);
    t27 = (t17 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t17);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t27) != 0)
        goto LAB18;

LAB19:    t35 = *((unsigned int *)t6);
    t36 = *((unsigned int *)t26);
    t37 = (t35 & t36);
    *((unsigned int *)t34) = t37;
    t38 = (t6 + 4);
    t39 = (t26 + 4);
    t40 = (t34 + 4);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB11;

LAB12:    *((unsigned int *)t17) = 1;
    goto LAB15;

LAB16:    *((unsigned int *)t26) = 1;
    goto LAB19;

LAB18:    t33 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB19;

LAB20:    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t34) = (t46 | t47);
    t48 = (t6 + 4);
    t49 = (t26 + 4);
    t50 = *((unsigned int *)t6);
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
    goto LAB22;

LAB23:    xsi_set_current_line(238, ng0);
    t72 = (t0 + 1616U);
    t73 = *((char **)t72);
    t72 = (t0 + 2816);
    t76 = (t0 + 2816);
    t77 = (t76 + 72U);
    t78 = *((char **)t77);
    t79 = (t0 + 2816);
    t80 = (t79 + 64U);
    t81 = *((char **)t80);
    t82 = (t0 + 1776U);
    t83 = *((char **)t82);
    xsi_vlog_generic_convert_array_indices(t74, t75, t78, t81, 2, 1, t83, 5, 2);
    t82 = (t74 + 4);
    t84 = *((unsigned int *)t82);
    t85 = (!(t84));
    t86 = (t75 + 4);
    t87 = *((unsigned int *)t86);
    t88 = (!(t87));
    t89 = (t85 && t88);
    if (t89 == 1)
        goto LAB26;

LAB27:    goto LAB25;

LAB26:    t90 = *((unsigned int *)t74);
    t91 = *((unsigned int *)t75);
    t92 = (t90 - t91);
    t93 = (t92 + 1);
    xsi_vlogvar_wait_assign_value(t72, t73, 0, *((unsigned int *)t75), t93, 0LL);
    goto LAB27;

}


extern void work_m_18105993216040670949_1061107207_init()
{
	static char *pe[] = {(void *)Cont_235_0,(void *)Always_237_1};
	xsi_register_didat("work_m_18105993216040670949_1061107207", "isim/module_prototype_isim_beh.exe.sim/work/m_18105993216040670949_1061107207.didat");
	xsi_register_executes(pe);
}
