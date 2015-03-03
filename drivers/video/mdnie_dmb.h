#ifndef __MDNIE_DMB_H__
#define __MDNIE_DMB_H__

#include "mdnie.h"

static unsigned short tune_dynamic_dmb[] = {
/*start Delos dynamic dmb*/
0x0007,0x0007,	/*DNR roi latency clk on 00 01 1 0*/
0x0009,0x0007,	/*DE roi latency clk on 00 01 1 0*/
0x000a,0x0007,	/*CS roi latency clk on 00 01 1 0*/
0x000b,0x0007,	/*CC roi latency clk on 00 01 1 0*/
0x000c,0x0007,	/*SCR roi latency clk on 00 01 1 0*/
0x0030,0x0fff,	/*DNR dirTh*/
0x0031,0x19ff,	/*DNR dirnumTh decon7Th*/
0x0032,0xff04,	/*DNR decon5Th maskTh*/
0x0033,0x0000,	/*DNR blTh*/
0x0040,0x0080,	/*DE egth*/
0x0042,0x00b0,	/*DE pe*/
0x0043,0x00b0,	/*DE pf*/
0x0044,0x00b0,	/*DE pb*/
0x0045,0x00b0,	/*DE ne*/
0x0046,0x00b0,	/*DE nf*/
0x0047,0x00b0,	/*DE nb*/
0x0048,0x1000,	/*DE max ratio*/
0x0049,0x0100,	/*DE min ratio*/
0x0050,0x0a0a,	/*CS hg ry*/
0x0051,0x1010,	/*CS hg gc*/
0x0052,0x1010,	/*CS hg bm*/
0x0053,0x2204,	/*CS weight grayTH*/
0x005f,0x0080,	/*CC chsel strength*/
0x0060,0x0000,	/*CC lut r  0*/
0x0061,0x0893,	/*CC lut r  16 144 */
0x0062,0x1aa5,	/*CC lut r  32 160*/
0x0063,0x29b7,	/*CC lut r  48 176*/
0x0064,0x39c8,	/*CC lut r  64 192*/
0x0065,0x4bd8,	/*CC lut r  80 208*/
0x0066,0x5de6,	/*CC lut r  96 224*/
0x0067,0x6ff4,	/*CC lut r 112 240*/
0x0068,0x81ff,	/*CC lut r 128 255*/
0x0091,0xff00,	/*SCR RrCr*/
0x0092,0x00ff,	/*SCR RgCg*/
0x0093,0x00ff,	/*SCR RbCb*/
0x0094,0x00ff,	/*SCR GrMr*/
0x0095,0xff00,	/*SCR GgMg*/
0x0096,0x00ff,	/*SCR GbMb*/
0x0097,0x00ff,	/*SCR BrYr*/
0x0098,0x00f0,	/*SCR BgYg*/
0x0099,0xff00,	/*SCR BbYb*/
0x009a,0x00ff,	/*SCR KrWr*/
0x009b,0x00ff,	/*SCR KgWg*/
0x009c,0x00ff,	/*SCR KbWb*/
0x00ff,0x0000,	/*Mask Release*/
/*end*/
	END_SEQ, 0x0000,	/* finish code */
};

static unsigned short tune_standard_dmb[] = {
/*start Delos standard dmb*/
0x0007,0x0007,	/*DNR roi latency clk on 00 01 1 0*/
0x0009,0x0007,	/*DE roi latency clk on 00 01 1 0*/
0x000a,0x0007,	/*CS roi latency clk on 00 01 1 0*/
0x000b,0x0006,	/*CC roi latency clk on 00 01 1 0*/
0x000c,0x0007,	/*SCR roi latency clk on 00 01 1 0*/
0x0030,0x0fff,	/*DNR dirTh*/
0x0031,0x19ff,	/*DNR dirnumTh decon7Th*/
0x0032,0xff00,	/*DNR decon5Th maskTh*/
0x0033,0x0000,	/*DNR blTh*/
0x0040,0x0080,	/*DE egth*/
0x0042,0x0100,	/*DE pe*/
0x0043,0x0100,	/*DE pf*/
0x0044,0x0100,	/*DE pb*/
0x0045,0x0100,	/*DE ne*/
0x0046,0x0100,	/*DE nf*/
0x0047,0x0100,	/*DE nb*/
0x0048,0x1000,	/*DE max ratio*/
0x0049,0x0100,	/*DE min ratio*/
0x0050,0x0a0a,	/*CS hg ry*/
0x0051,0x1010,	/*CS hg gc*/
0x0052,0x1010,	/*CS hg bm*/
0x0053,0x3004,	/*CS weight grayTH*/
0x0091,0xff00,	/*SCR RrCr*/
0x0092,0x00ff,	/*SCR RgCg*/
0x0093,0x00ff,	/*SCR RbCb*/
0x0094,0x00ff,	/*SCR GrMr*/
0x0095,0xff00,	/*SCR GgMg*/
0x0096,0x00ff,	/*SCR GbMb*/
0x0097,0x00ff,	/*SCR BrYr*/
0x0098,0x00f0,	/*SCR BgYg*/
0x0099,0xff00,	/*SCR BbYb*/
0x009a,0x00ff,	/*SCR KrWr*/
0x009b,0x00ff,	/*SCR KgWg*/
0x009c,0x00ff,	/*SCR KbWb*/
0x00ff,0x0000,	/*Mask Release*/
/*end*/
	END_SEQ, 0x0000,	/* finish code */
};

static unsigned short tune_movie_dmb[] = {
/*start Delos movie dmb*/
0x0007,0x0007,	/*DNR roi latency clk on 00 01 1 0*/
0x0009,0x0007,	/*DE roi latency clk on 00 01 1 0*/
0x000a,0x0007,	/*CS roi latency clk on 00 01 1 0*/
0x000b,0x0006,	/*CC roi latency clk on 00 01 1 0*/
0x000c,0x0007,	/*SCR roi latency clk on 00 01 1 0*/
0x0030,0x0fff,	/*DNR dirTH*/
0x0031,0x19ff,	/*DNR dirnumTh decon7Th*/
0x0032,0xff04,	/*DNR decon5Th maskTh*/
0x0033,0x0000,	/*DNR blTh*/
0x0040,0x0080,	/*DE egth*/
0x0042,0x0060,	/*DE pe*/
0x0043,0x0060,	/*DE pf*/
0x0044,0x0060,	/*DE pb*/
0x0045,0x0060,	/*DE ne*/
0x0046,0x0060,	/*DE nf*/
0x0047,0x0060,	/*DE nb*/
0x0048,0x1000,	/*DE max ratio*/
0x0049,0x0100,	/*DE min ratio*/
0x0050,0x1010,	/*CS hg ry*/
0x0051,0x1010,	/*CS hg gc*/
0x0052,0x1010,	/*CS hg bm*/
0x0053,0x1004,	/*CS weight grayTH*/
0x0091,0xff00,	/*SCR RrCr*/
0x0092,0x00ff,	/*SCR RgCg*/
0x0093,0x00ff,	/*SCR RbCb*/
0x0094,0x00ff,	/*SCR GrMr*/
0x0095,0xff00,	/*SCR GgMg*/
0x0096,0x00ff,	/*SCR GbMb*/
0x0097,0x00ff,	/*SCR BrYr*/
0x0098,0x00ff,	/*SCR BgYg*/
0x0099,0xff00,	/*SCR BbYb*/
0x009a,0x00ff,	/*SCR KrWr*/
0x009b,0x00e8,	/*SCR KgWg*/
0x009c,0x00eb,	/*SCR KbWb*/
0x00ff,0x0000,	/*Mask Release*/
/*end*/
	END_SEQ, 0x0000,	/* finish code */
};

static unsigned short tune_auto_dmb[] = {
/*start Delos auto dmb*/
0x0007,0x0007,	/*DNR roi latency clk on 00 01 1 0*/
0x0009,0x0007,	/*DE roi latency clk on 00 01 1 0*/
0x000a,0x0007,	/*CS roi latency clk on 00 01 1 0*/
0x000b,0x0006,	/*CC roi latency clk on 00 01 1 0*/
0x000c,0x0007,	/*SCR roi latency clk on 00 01 1 0*/
0x0030,0x0fff,	/*DNR dirTh*/
0x0031,0x19ff,	/*DNR dirnumTh decon7Th*/
0x0032,0xff04,	/*DNR decon5Th maskTh*/
0x0033,0x0000,	/*DNR blTh*/
0x0040,0x0080,	/*DE egth*/
0x0042,0x00a0,	/*DE pe*/
0x0043,0x00a0,	/*DE pf*/
0x0044,0x00a0,	/*DE pb*/
0x0045,0x00a0,	/*DE ne*/
0x0046,0x00a0,	/*DE nf*/
0x0047,0x00a0,	/*DE nb*/
0x0048,0x1000,	/*DE max ratio*/
0x0049,0x0100,	/*DE min ratio*/
0x0050,0x0a0a,	/*CS hg ry*/
0x0051,0x1010,	/*CS hg gc*/
0x0052,0x1010,	/*CS hg bm*/
0x0053,0x2004,	/*CS weight grayTH*/
0x0091,0xff00,	/*SCR RrCr*/
0x0092,0x00ff,	/*SCR RgCg*/
0x0093,0x00ff,	/*SCR RbCb*/
0x0094,0x00ff,	/*SCR GrMr*/
0x0095,0xff00,	/*SCR GgMg*/
0x0096,0x00ff,	/*SCR GbMb*/
0x0097,0x00ff,	/*SCR BrYr*/
0x0098,0x00f0,	/*SCR BgYg*/
0x0099,0xff00,	/*SCR BbYb*/
0x009a,0x00ff,	/*SCR KrWr*/
0x009b,0x00ff,	/*SCR KgWg*/
0x009c,0x00ff,	/*SCR KbWb*/
0x00ff,0x0000,	/*Mask Release*/
/*end*/
	END_SEQ, 0x0000,	/* finish code */
};

static unsigned short tune_natural_dmb[] = {
/*start Delos standard dmb*/ 
0x0007,0x0007,	/*DNR roi latency clk on 00 01 1 0*/
0x0009,0x0007,	/*DE roi latency clk on 00 01 1 0*/
0x000a,0x0007,	/*CS roi latency clk on 00 01 1 0*/
0x000b,0x0006,	/*CC roi latency clk on 00 01 1 0*/
0x000c,0x0007,	/*SCR roi latency clk on 00 01 1 0*/
0x0030,0x0fff,	/*DNR dirTh*/
0x0031,0x19ff,	/*DNR dirnumTh decon7Th*/
0x0032,0xff00,	/*DNR decon5Th maskTh*/
0x0033,0x0000,	/*DNR blTh*/
0x0040,0x0080,	/*DE egth*/
0x0042,0x0100,	/*DE pe*/
0x0043,0x0100,	/*DE pf*/
0x0044,0x0100,	/*DE pb*/
0x0045,0x0100,	/*DE ne*/
0x0046,0x0100,	/*DE nf*/
0x0047,0x0100,	/*DE nb*/
0x0048,0x1000,	/*DE max ratio*/
0x0049,0x0100,	/*DE min ratio*/
0x0050,0x0a0a,	/*CS hg ry*/
0x0051,0x1010,	/*CS hg gc*/
0x0052,0x1010,	/*CS hg bm*/
0x0053,0x3004,	/*CS weight grayTH*/
0x0091,0xff00,	/*SCR RrCr*/
0x0092,0x00ff,	/*SCR RgCg*/
0x0093,0x00ff,	/*SCR RbCb*/
0x0094,0x00ff,	/*SCR GrMr*/
0x0095,0xff00,	/*SCR GgMg*/
0x0096,0x00ff,	/*SCR GbMb*/
0x0097,0x00ff,	/*SCR BrYr*/
0x0098,0x00f0,	/*SCR BgYg*/
0x0099,0xff00,	/*SCR BbYb*/
0x009a,0x00ff,	/*SCR KrWr*/
0x009b,0x00ff,	/*SCR KgWg*/
0x009c,0x00ff,	/*SCR KbWb*/
0x00ff,0x0000,	/*Mask Release*/
/*end*/
	END_SEQ, 0x0000,	/* finish code */
};

struct mdnie_tuning_info tune_dmb[MODE_MAX] = {
	{"DYNAMIC_DMB",    tune_dynamic_dmb },
	{"STANDARD_DMB",   tune_standard_dmb},
#if !defined(CONFIG_FB_MDNIE_PWM)
	{"NATURAL_DMB",   tune_natural_dmb},
#endif
	{"MOVIE_DMB",      tune_movie_dmb},
	{"AUTO_DMB",   tune_auto_dmb},
};
#endif /* __MDNIE_DMB_H__ */